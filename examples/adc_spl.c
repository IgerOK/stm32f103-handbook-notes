/*
 * examples/adc_spl.c
 * STM32F103VGT6 (LQFP100, VREF+ = 3.0 В external) — ADC, SPL
 *
 * Sources: §5.1–5.4 STM32F103VGT6_VREF_AI.md
 * - VREF+ (pin 21) = 3.0 В external reference, NOT VDDA (3.3 V)
 * - Calibration: ADC_Cmd(ENABLE) BEFORE ResetCalibration/StartCalibration
 * - SoftwareStartConvCmd strictly AFTER calibration
 * - F103 (512 KB, XL-density): no factory VREFINT_CAL in memory,
 *   self-test via direct VREF+ measurement (jumper VREF+ -> PA0)
 */

#include "stm32f10x.h"

#define VREF_PLUS   3.0f    /* external VREF+, NOT 3.3 */
#define ADC_FULL    4096.0f

/*
 * Self-test jumper: VREF+ (pin 21) -> PA0 for test duration,
 * open the jumper afterwards.
 */
#define VREF_SELF_TEST_CHANNEL   ADC_Channel_0   /* PA0 */

typedef enum {
    VREF_TEST_OK = 0,          /* raw 4094..4095 */
    VREF_TEST_SHORTED_VDDA,    /* raw ~3720 (VREF+ = 3.3 V) */
    VREF_TEST_NOT_CONNECTED,   /* raw ~0 */
    VREF_TEST_OUT_OF_RANGE
} vref_test_t;

/* --- 1) clocks, GPIO, ADC init + calibration, software trigger --- */
void ADC1_Init(void)
{
    ADC_InitTypeDef  adc;
    GPIO_InitTypeDef gpio;

    /* 1) Clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);   /* 72/6 = 12 MHz (<= 14 MHz max) */

    /* 2) PA0 = analog input */
    gpio.GPIO_Pin  = GPIO_Pin_0;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    /* 3) ADC init
     * NOTE: fields ADC_ExternalTrigInjConv / ADC_InjectedDiscontinuousConvMode
     * may be absent in your SPL version - remove them if the compiler complains.
     */
    ADC_DeInit(ADC1);
    adc.ADC_Mode                 = ADC_Mode_Independent;
    adc.ADC_ScanConvMode         = DISABLE;
    adc.ADC_ContinuousConvMode   = ENABLE;
    adc.ADC_ExternalTrigConv     = ADC_ExternalTrigConv_None;
    adc.ADC_DataAlign            = ADC_DataAlign_Right;
    adc.ADC_NbrOfChannel         = 1;
    ADC_Init(ADC1, &adc);

    /* 4) Channel 0, rank 1 */
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);

    /* 5) ENABLE (MANDATORY BEFORE CALIBRATION) */
    ADC_Cmd(ADC1, ENABLE);

    /* 6) CALIBRATION */
    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));

    /* 7) Start */
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

/* --- read one value (current channel) --- */
u16 ADC1_Read(void)
{
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
    return ADC_GetConversionValue(ADC1);
}

/* --- raw -> V (VREF+ = 3.0) --- */
float ADC1_RawToV(u16 raw)
{
    return (float)raw * VREF_PLUS / ADC_FULL;
}

/* --- V -> raw (for reference) --- */
u16 V_ToRaw(float v)
{
    u16 code = (u16)(v / VREF_PLUS * ADC_FULL + 0.5f);
    return (code > 4095) ? 4095 : code;
}

/* --- read an arbitrary channel (helper for self-test / temperature) --- */
u16 ADC1_ReadChannel(uint8_t channel)
{
    u16 raw = 0;
    ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConv(ADC1);
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
    raw = ADC_GetConversionValue(ADC1);
    return raw;
}

/* --- direct VREF+ self-test (jumper VREF+ -> PA0) ---
 * F103 XL-density: do NOT use VREFINT_CAL (0x1FFFF7C0/BA) - not present.
 * 3.0 V on PA0 -> full scale. 3.3 V -> also full scale, indistinguishable
 * from a short VREF+ to VDDA. V_IN max = VDDA + 0.3 V (Table 62), safe.
 */
vref_test_t adc_self_test_vref(uint16_t *raw_out)
{
    uint16_t raw = ADC1_ReadChannel(VREF_SELF_TEST_CHANNEL);
    if (raw_out) *raw_out = raw;

    if (raw >= 4094 && raw <= 4095) return VREF_TEST_OK;
    if (raw >= 3650 && raw <= 3790) return VREF_TEST_SHORTED_VDDA;
    if (raw <= 10)                  return VREF_TEST_NOT_CONNECTED;
    return VREF_TEST_OUT_OF_RANGE;
}

/* --- scan + DMA (4 channels, circular) --- */
#define ADC_BUF_SIZE  4
volatile u16 adc_buf[ADC_BUF_SIZE];   /* [0]=ch0, [1]=ch1, [2]=ch2, [3]=ch3 */

static const uint8_t adc_channels[ADC_BUF_SIZE] = {
    ADC_Channel_0, ADC_Channel_1, ADC_Channel_2, ADC_Channel_3
};

void ADC1_ScanDMA_Init(void)
{
    DMA_InitTypeDef dma;
    ADC_InitTypeDef adc;
    GPIO_InitTypeDef gpio;

    /* Clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);

    /* PA0..PA3 = analog */
    gpio.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    /* DMA1_Channel1 (hardwired to ADC1 DR) */
    DMA_DeInit(DMA1_Channel1);
    dma.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
    dma.DMA_MemoryBaseAddr     = (uint32_t)adc_buf;
    dma.DMA_DIR                = DMA_DIR_PeripheralSRC;
    dma.DMA_BufferSize        = ADC_BUF_SIZE;
    dma.DMA_PeripheralInc     = DMA_PeripheralInc_Disable;
    dma.DMA_MemoryInc         = DMA_MemoryInc_Enable;
    dma.DMA_PeripheralDataSize= DMA_PeripheralDataSize_HalfWord;
    dma.DMA_MemoryDataSize    = DMA_MemoryDataSize_HalfWord;
    dma.DMA_Mode              = DMA_Mode_Circular;
    dma.DMA_Priority          = DMA_Priority_High;
    dma.DMA_M2M               = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &dma);
    DMA_Cmd(DMA1_Channel1, ENABLE);

    /* ADC scan */
    ADC_DeInit(ADC1);
    adc.ADC_Mode                 = ADC_Mode_Independent;
    adc.ADC_ScanConvMode         = ENABLE;
    adc.ADC_ContinuousConvMode   = ENABLE;
    adc.ADC_ExternalTrigConv     = ADC_ExternalTrigConv_None;
    adc.ADC_DataAlign            = ADC_DataAlign_Right;
    adc.ADC_NbrOfChannel        = ADC_BUF_SIZE;
    ADC_Init(ADC1, &adc);

    /* Channels */
    for (u8 i = 0; i < ADC_BUF_SIZE; i++)
        ADC_RegularChannelConfig(ADC1, adc_channels[i], i + 1, ADC_SampleTime_55Cycles5);

    /* DMA + ADC + calibration */
    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);

    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));

    /* SoftwareStartConvCmd strictly AFTER calibration, otherwise DMA
     * would transfer uncalibrated (garbage) results into adc_buf. */
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

float adc_buf_v(int idx)  { return (float)adc_buf[idx] * VREF_PLUS / ADC_FULL; }

/* --- temperature sensor (channel 16, rough, +/-2 C, monitoring only) --- */
float temp_celsius(u16 raw_temp)
{
    /* V_sensor ~1.43 V at 25 C (typ), slope ~ -4 mV/C (typ, Table 21).
     * Values are typical; verify against RM0008 and your board. */
    float v_sensor = (float)raw_temp * VREF_PLUS / ADC_FULL;
    return 25.0f + (1.43f - v_sensor) / 0.004f;
}

int main(void)
{
    ADC1_Init();
    while (1) {
        u16 raw = ADC1_Read();
        float v = ADC1_RawToV(raw);
        /* v = voltage on PA0 (0..3.0 V) */
    }
}
