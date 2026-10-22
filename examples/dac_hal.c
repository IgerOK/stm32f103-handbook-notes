/*
 * examples/dac_hal.c
 * STM32F103VGT6 (LQFP100, VREF+ = 3.0 V external) - sine on PA4
 * via DAC1 + DMA2_Channel3 + TIM6 TRGO, HAL / CubeMX.
 *
 * Sources: §8 STM32F103VGT6_VREF_AI.md
 * - VREF+ (pin 21) = 3.0 V external reference, NOT VDDA (3.3 V)
 * - DAC trigger = TIM6 TRGO ONLY (never TIM2/3/4/5)
 * - DMA for DAC1 = DMA2_Channel3 (NOT DMA1), HalfWord, Circular
 * - sine_table must live in RAM (non-const) - DMA reads it
 * - TIM6 clock = 72 MHz (APB1 timer clock), PSC = 0 for the sine case
 *
 * CubeMX (STM32F103VGT6) - required configuration:
 *   Clock: HCLK = 72 MHz, APB1 = 36 MHz (prescaler 2)
 *   DAC:
 *     OUT1  -> PA4
 *     Trigger Source:  TIM6 TRGO
 *     Output Buffer:   Enable
 *     Mode:            Connected to external pin only
 *   DMA:
 *     DAC1_OUT1  -> DMA2  Channel 3
 *       Priority:  High (or Very High)
 *       Mode:      Circular
 *   TIM6:
 *     Prescaler:  0
 *     Counter Period (ARR): 1124
 *
 * Result: 64 points x 1 kHz = 64 kHz TRGO, sine = 1 kHz on PA4,
 *         amplitude ~0..3.0 V (VREF+ based).
 */

#include <math.h>
#include "main.h"

#define VREF_PLUS     3.0f
#define DAC_FULL      4096.0f
#define SINE_POINTS   64
#define SINE_FREQ     1000.0f
#define SINE_AMP      1.5f
#define SINE_OFFSET   1.5f

extern DAC_HandleTypeDef hdac;
extern TIM_HandleTypeDef htim6;

/* Non-const: DMA2_Channel3 reads this table from RAM continuously. */
uint16_t sine_table[SINE_POINTS];

void sine_table_init(void)
{
    for (int i = 0; i < SINE_POINTS; i++) {
        float v = SINE_OFFSET + SINE_AMP * sinf(2.0f * 3.14159265f * i / SINE_POINTS);
        if (v < 0.0f) v = 0.0f;
        if (v > VREF_PLUS) v = VREF_PLUS;
        uint16_t code = (uint16_t)(v / VREF_PLUS * DAC_FULL + 0.5f);
        if (code > 4095) code = 4095;
        sine_table[i] = code;
    }
}

/* Start order matters: DAC -> DMA2 -> TIM6.
 * If TIM6 starts first, the first few TRGO events are lost (DAC/DMA not
 * ready yet) and a visible step appears at the sine start. Not fatal,
 * but observable on the scope. */
void dac_sine_start(void)
{
    sine_table_init();

    if (HAL_DAC_Start(&hdac, DAC_CHANNEL_1) != HAL_OK) {
        Error_Handler();
    }
    if (HAL_DAC_Start_DMA(&hdac,
                          DAC_CHANNEL_1,
                          (uint32_t*)sine_table,
                          SINE_POINTS,
                          DAC_ALIGN_12B_R) != HAL_OK) {
        Error_Handler();
    }
    if (HAL_TIM_Base_Start(&htim6) != HAL_OK) {
        Error_Handler();
    }
}

void dac_sine_stop(void)
{
    HAL_TIM_Base_Stop(&htim6);
    HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
    HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
}

/* Optional DMA callbacks (only needed if you monitor half/complete events). */
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac)
{
    /* First half of sine_table has been consumed by DMA (0..N/2-1). */
}

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac)
{
    /* Second half of sine_table has been consumed by DMA (N/2..N-1).
     * In circular mode the buffer wraps here; safe to read/replace. */
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();   /* from CubeMX: 72 MHz, APB1 = 36 MHz */
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_DAC_Init();
    MX_TIM6_Init();

    dac_sine_start();

    while (1)
    {
        /* CPU idle. Sine is generated continuously by DMA + TIM6. */
    }
}
