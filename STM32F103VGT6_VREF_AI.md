# STM32F103VGT6 — AI Agent Context (LQFP100, VREF+ = 3.0 В)

> **ИНСТРУКЦИЯ ДЛЯ AI-АГЕНТА.** Читай этот файл полностью перед генерацией любого кода,
> схемы или ответа по проекту. Все данные проверены по datasheet STM32F103xF/xG
> (DocID16554 Rev 4, May 2015) и RM0008. Файл самодостаточен — внешних
> инструкций (`See!.txt`, `Шпаргалка*.txt`) больше нет.
>
> **Корпус: ТОЛЬКО LQFP100. Не упоминай и не используй пины других корпусов.**
>
> Структура: §0 правила → §1 quick reference (1 страница) → §2 устройство → §3 питание →
> §4 databook → §5 SPL ADC → §6 SPL DAC → §7 HAL ADC+DMA → §8 HAL DAC+DMA2+TIM6 (синус) →
> §9 чек-лист → §10 ошибки → §11 FAQ → §12 troubleshooting → §13 порядок калибровки → §14 ссылки.

---

## 0. КРИТИЧЕСКИЕ ПРАВИЛА (НЕ НАРУШАТЬ)

1. **VREF+ = 3.0 В** — внешний опорный источник на пине 21. Все формулы raw→V: `* 3.0f / 4096.0f`.
   **НЕ 3.3, НЕ VDDA.** Никогда.
2. **В STM32F103 НЕТ бита выбора VREF+.** АЦП/ЦАП всегда используют напряжение на пине 21.
   Никакого регистра для переключения. Не предлагать «выбрать внутренний VREF» — такой опции нет.
3. **VREF+ ≠ VDDA.** Не коротить пин 21 (VREF+) с пином 22 (VDDA). Внешняя опора зашунтируется на 3.3 В.
4. **Условие:** 2.4 В ≤ VREF+ ≤ VDDA. У нас: 3.0 ≤ 3.3 ✓.
5. **Калибровка ADC выполняется ПОСЛЕ `ADC_Cmd(ENABLE)` и ПОСЛЕ установления VREF+.**
6. **DAC trigger — только TIM6.** Не TIM2/3/4/5.
7. **DMA для ADC1 → DMA1_Channel1. DMA для DAC1 → DMA2_Channel3.** HalfWord, Circular.
8. **Max ток на пине VREF+ = 220 мкА** (Table 62, characterized). Источник 3.0 В должен это обеспечить.
9. **TIM6 clock = 72 МГц (APB1 timer clock = PCLK1 × 2 = 36 × 2).** PSC = 71 для базы 1 МГц.

---

## 1. QUICK REFERENCE (ШПАРГАЛКА НА 1 СТРАНИЦУ)

> Копия на рабочий стол / для быстрого просмотра при пайке и отладке.

### Критические правила
```
[1] VREF+ = 3.0 В. ВСЕ формулы: * 3.0f / 4096.0f. НЕ 3.3.
[2] В STM32F103 НЕТ бита выбора VREF+. АЦП/ЦАП всегда берут с пина 21.
[3] НЕ коротить VREF+ (21) с VDDA (22). Внешняя опора зашунтируется.
[4] Калибровка ADC — ПОСЛЕ ADC_Cmd(ENABLE) и ПОСЛЕ установления VREF+.
[5] DAC trigger — ТОЛЬКО TIM6 (TRGO = Update).
[6] TIM6 clock = 72 МГц. PSC = 71 (НЕ 35). ARR = 1e6/hz - 1.
[7] DMA ADC1 = DMA1_Channel1. DMA DAC1 = DMA2_Channel3. HalfWord, Circular.
[8] Imax источника VREF+ >= 220 мкА. REF5030 (10 мкА) — только с буфером.
```

### Пины LQFP100 (подтверждены)
```
Pin 19: VSSA    — аналоговая земля
Pin 20: VREF-   — через 0 Ом на VSSA (pin 19)
Pin 21: VREF+   — ВНЕШНИЙ ИСТОЧНИК 3.0 В
Pin 22: VDDA    — 3.3 В
```

### Формулы
```
ADC:  V   = raw * 3.0f / 4096.0f        (raw 0..4095)
ADC:  raw = V / 3.0f * 4096             (округлить, clamp 0..4095)
DAC:  code = V / 3.0f * 4096 + 0.5f     (clamp 0..4095)
DAC:  V    = code * 3.0f / 4096.0f
LSB ADC = 3.0 / 4096 = 0.732 мВ
DAC полный выход (buffer ON) = VREF+ - 10 мВ = 2.990 В
```

### Тайминги
```
TIM6 (APB1 timer clock) = 72 МГц (при HCLK=72, APB1 prescaler=2)
PSC = 71 -> база 1 МГц -> ARR = 1e6/hz - 1
Пример: hz=1000 -> ARR=999 -> период 1 мс

fADC = PCLK2 / prescaler <= 14 МГц. При HCLK=72 -> RCC_PCLK2_Div6 (12 МГц)
```
> ⚠️ Это для **DAC update** (§6.3, PSC=71). Для **синуса через DMA2** (§8)
> используется PSC=0 и ARR рассчитывается от f_TRGO = N × f_sine. См. §8.1.

### Калибровка ADC (строго по порядку) — см. §13
```
1 RCC  2 RCC_ADCCLKConfig  3 GPIO AIN  4 ADC_DeInit  5 ADC_Init
6 ADC_RegularChannelConfig  7 ADC_Cmd(ENABLE) [ДО КАЛИБРОВКИ]
8 ADC_ResetCalibration  9 while(reset)  10 ADC_StartCalibration
11 while(cal)  12 ADC_SoftwareStartConvCmd
```

### Аппаратная обвязка (Fig. 57) — см. §3.3
```
VREF+ (21): 10 нФ C0G + 1 мкФ -> VSSA
VDDA  (22): 10 нФ C0G + 1 мкФ -> VSSA
VREF- (20): 0 Ом -> VSSA (19)
VSSA  (19): single-point star -> VSS (digital GND)
C0G/NP0, НЕ X7R. Конденсаторы — максимально близко к чипу.
```

### Источник 3.0 В — см. §3.4
```
REF3030 (TI)    3.0 В  Imax ~25 мА  от 3.3 В: ДА   РЕКОМЕНДУЕТСЯ
MAX6030 (Maxim) 3.0 В  Imax ~5 мА   от 3.3 В: ДА   Альтернатива
REF5030 (TI)    3.0 В  Imax 10 мкА  от 3.3 В: ДА   ТОЛЬКО С БУФЕРОМ (OPA350)
```

### Быстрая диагностика — см. §12
```
ADC = 4095 всегда        -> VREF+ = 0 В / вход притянут к 3.3 В
ADC = 0 всегда           -> VREF+ не подключён / канал не настроен
ADC ~10% завышен         -> формула * 3.3 вместо * 3.0
Калибровка зависла       -> ADC_Cmd(ENABLE) не был вызван до калибровки
DAC не обновляется       -> TRGO не настроен / trigger != T6
DAC частота в 2 раза выше-> PSC = 35, а не 71
DAC+DMA не работает      -> DMA1 вместо DMA2_Channel3
VREF+ не пришёл          -> VREFINT sanity (ch17) raw ~ 0; или делитель ~ 0
```

### Self-test VREF+ (быстро) — см. §5.4
```
НА F103 (512 КБ) НЕТ фабричного VREFINT_CAL — НЕ пользоваться VREFINT_CAL_ADDR! (§5.5)

Основной (перемычка VREF+ → PA0, §5.4):
  raw ≈ 4094..4095 -> VREF+ OK (3.0 В)
  raw ≈ 3650..3790 -> VREF+ закорочен на VDDA (3.3 В)
  raw ≈ 0          -> VREF+ не подключён

Sanity (VREFINT ch 17, §5.5): raw ~ 1580..1722; ≈ 0 → VREF+ не пришёл
```

---

## 2. УСТРОЙСТВО

| Параметр | Значение |
|---|---|
| MCU | STM32F103VGT6 |
| Core | ARM Cortex-M3, 72 МГц |
| Flash | 512 КБ |
| RAM | 64 КБ (16 КБ + 4 КБ CCM) |
| ADC | 3 × 12-бит (21 канал) |
| DAC | 2 × 12-бит |
| Timer для DAC trigger | **TIM6** (и TIM7) |
| DMA ADC1 | **DMA1_Channel1** |
| DMA DAC1 | **DMA2_Channel3** |
| DMA DAC2 | **DMA2_Channel4** |
| Corpus | **LQFP100 (100 выводов)** |
| Datasheet | DocID16554 Rev 4 |
| Reference Manual | RM0008 (STM32F10x) |
| Framework | SPL (StdPeriph) — основной; HAL/CubeMX — допустимый |

---

## 3. ПИТАНИЕ И ПИНЫ LQFP100

### 3.1 Аналоговые и опорные пины (ПОДТВЕРЖДЕНЫ)

| Pin | Signal | Напряжение | Примечание |
|---|---|---|---|
| **19** | **VSSA** | 0 В | Аналоговая земля |
| **20** | **VREF−** | 0 В | → соединить с VSSA (pin 19) через 0 Ω |
| **21** | **VREF+** | **3.0 В (внешний источник)** | **Ключевой пин проекта** |
| **22** | **VDDA** | 3.3 В | Аналоговое питание |

> Номера VDD/VSS (digital) — см. Table 5 datasheet.

### 3.2 Критические правила питания

1. **VREF+ (pin 21) = 3.0 В от внешнего источника. НЕ от VDDA.**
2. **VREF− (pin 20) → 0 Ω → VSSA (pin 19).**
3. VDDA и VDD — от одного LDO или разница ≤ 300 мВ.
4. Power-up: **VREF+ не должен опережать VDDA.**
   - REF50xx имеет встроенный soft-start (~150–200 мс) → VDDA встаёт за 1–5 мс → OK.
   - Быстрый источник (без soft-start) → выбрать один из:
     • **Soft-Start самого источника опорного** (REF3030/REF5030 имеют его —
       проще всего, рекомендуется).
     • **Транзисторный power-switch**: MOSFET/NPN на линии VREF+, управляемый
       от сигнала Power Good основного LDO 3.3 В. VREF+ подаётся только после
       того, как VDDA стабилен.
     • **Низкоомный RC-фильтр**: 10–100 Ом + 1–10 мкF. ⚠️ НО не 100 кОм:
       падение на резисторе = I_VREF × R (до 220 мкА × R).
       При 100 кОм: 220 мкА × 100 кОм = 22 В → опора просядет в ноль.
       Резистором не «затягивают» VREF+ — только soft-start или ключ.
   - **Проверка осциллографом:** VDDA достигает 3.3 В раньше, чем VREF+
     достигает 2.4 В. Иначе калибровка ADC пройдёт некорректно.
5. VREF+ = 21 **никогда не опережает** VDDA = 22.

### 3.3 Обвязка (Fig. 57 datasheet, «VREF+ не связан с VDDA»)

```
VREF+ (pin 21)
 ├─[10 nF C0G/NP0]──┐
 └─[1 µF]───────────┴── VSSA (pin 19)     ← максимально близко к чипу

VDDA (pin 22)
 ├─[10 nF C0G/NP0]──┐
 └─[1 µF]───────────┴── VSSA (pin 19)

VSSA (pin 19)
 └── single-point star ──► VSS (digital GND) в ОДНОЙ точке у чипа
     + VREF− (pin 20) [через 0 Ω]
     + GND всех конденсаторов VDDA/VREF+
     НЕ разносить по плате.
```

> **C0G/NP0 (не X7R/X5R):** MLCC X7R смещает ёмкость при смещении > 0.5 В.

### 3.4 Внешний источник 3.0 В

| IC | Vout | Vmin | Imax | От 3.3 В | Статус |
|---|---|---|---|---|---|
| **REF3030 (TI)** | 3.0 В | 2.7 В | **~25 мА** | ✓ | **РЕКОМЕНДУЕТСЯ** |
| **MAX6030 (Maxim)** | 3.0 В | 2.7 В | ~5 мА | ✓ | Хорошая альтернатива |
| **REF5030 (TI)** | 3.0 В | 2.7 В | 10 мкА | ✓ | Только с буфером |
| **MCR6030** | 3.0 В | 4.0 В | 100 мкА | ✗ | Нужен 5 В rail |
| **ADR4530 (ADI)** | 3.0 В | 4.0 В | ~10 мА | ✗ | Нужен 5 В rail |

> **⚠️ REF5030 Imax = 10 мкА < 220 мкА (STM32 VREF+ max).** Без буфера — провал VREF+.
> **Рекомендация: REF3030 (Imax ~25 мА)** — закрывает нагрузку без буфера.
> Все спецификации (Imax, TC, Vmin) **ПРОВЕРИТЬ ПО DATASHEET ВЕНДОРА** перед покупкой.

**Схема подключения (REF3030 или REF5030 + OPA buffer):**

```
Источник 3.0 В (REF3030 / REF5030):
  Vout  ──[0 Ω]──► VREF+ (pin 21 STM32F103VGT6)
  VDD   ─────────► VDDA (pin 22)  [3.3 В]
  GND   ─────────► VSSA (pin 19)

  На выводе VREF+ (pin 21):
    ├─[10 nF C0G]── VSSA
    └─[1 µF]─────── VSSA

Если REF5030 (Imax=10 мкА) — вставить unity-gain buffer (OPA350 / OPA378):
  REF5030 Vout → OPA in+
  OPA out → [0Ω] → VREF+ (pin 21)
  OPA in- → out (unity)
  OPA V+ → VDDA (3.3 В), GND → VSSA
```

---

## 4. ДАННЫЕ DATABOOK (TABLES)

### 4.1 ADC — Table 62 (§5.3.19)

| Параметр | Min | Typ | Max | Unit |
|---|---|---|---|---|
| VDDA | 2.4 | — | 3.6 | V |
| **VREF+** | **2.4** | — | **VDDA** | **V** |
| IVREF | — | 160 | 220 | µA |
| fADC | 0.6 | — | 14 | MHz |
| VAIN | 0 | — | VREF+ | V |
| RAIN max | — | — | 50 | kΩ |
| RADC (switch) | — | — | 1 | kΩ |
| CADC (S/H cap) | — | — | 8 | pF |
| tCAL | 5.9 | — | 83/fADC | µs |

> **VREF+ = 3.0 В → LSB = 3.0/4096 ≈ 0.732 мВ.**

### 4.2 VREFINT — Table 13 (§5.3.4)

| Параметр | Значение |
|---|---|
| VREFINT (typ) | **1.20 В** (1.16 – 1.26 В, −40…+105 °C) |
| Разброс по T | ±10 мВ при VDD = 3 В |
| TCoeff | ±100 ppm/°C |
| Sample time | ≥ 55.5 циклов при fADC = 14 МГц |

### 4.3 RAIN vs sample time — Table 63 (fADC = 14 МГц)

| Ts (цикл) | tS (мкс) | RAIN max (кОм) |
|---|---|---|
| 1.5 | 0.11 | 0.4 |
| 7.5 | 0.54 | 5.9 |
| 13.5 | 0.96 | 11.4 |
| 28.5 | 2.04 | 25.2 |
| 55.5 | 3.96 | **50** |
| 71.5 | 5.11 | NA |
| 239.5 | 17.1 | NA |

> R_in ≤ 1 кОм → **13.5 циклов**. R_in > 10 кОм → **55.5 циклов**. Макс: **239.5**.

### 4.4 DAC — Table 66 (§5.3.20)

| Параметр | Значение |
|---|---|
| VDDA | 2.4 – 3.6 В |
| VREF+ | 2.4 – 3.6 В (**всегда < VDDA**) |
| RLOAD | 1 кΩ (min) |
| Полный выход DAC при VREF+ = 3.0 В | 0…2.990 В (buffer ON: VREF+ − 10 мВ) |

---

## 5. АЦП (ADC) — КОД (SPL)

### 5.1 Инициализация + калибровка (1 канал, software trigger)

```c
#include "stm32f10x.h"

#define VREF_PLUS   3.0f    // ВНЕШНИЙ VREF+ — НЕ 3.3!
#define ADC_FULL    4096.0f

void ADC1_Init(void)
{
    ADC_InitTypeDef  adc;
    GPIO_InitTypeDef gpio;

    // 1) Clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);   // 72/6 = 12 МГц (≤ 14 МГц max)

    // 2) PA0 = analog input
    gpio.GPIO_Pin  = GPIO_Pin_0;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    // 3) ADC init
    //    ⚠️ Поля ADC_ExternalTrigInjConv и ADC_InjectedDiscontinuousConvMode
    //    могут отсутствовать в вашей версии SPL — если компилятор ругается, удалить.
    ADC_DeInit(ADC1);
    adc.ADC_Mode                 = ADC_Mode_Independent;
    adc.ADC_ScanConvMode         = DISABLE;
    adc.ADC_ContinuousConvMode   = ENABLE;
    adc.ADC_ExternalTrigConv     = ADC_ExternalTrigConv_None;
    adc.ADC_DataAlign            = ADC_DataAlign_Right;
    adc.ADC_NbrOfChannel         = 1;
    ADC_Init(ADC1, &adc);

    // 4) Channel 0, rank 1
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);

    // 5) ENABLE (ОБЯЗАТЕЛЬНО ДО КАЛИБРОВКИ)
    ADC_Cmd(ADC1, ENABLE);

    // 6) CALIBRATION
    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));

    // 7) Start
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

// --- Чтение одного значения (current channel) ---
u16 ADC1_Read(void)
{
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
    return ADC_GetConversionValue(ADC1);
}

// --- Пересчёт raw → В ---
float ADC1_RawToV(u16 raw)
{
    return (float)raw * VREF_PLUS / ADC_FULL;   // * 3.0 / 4096
}

// --- main ---
int main(void)
{
    ADC1_Init();
    while (1) {
        u16 raw = ADC1_Read();
        float v  = ADC1_RawToV(raw);
        // v = напряжение на PA0 (0…3.0 В)
    }
}
```

### 5.2 Скан + DMA (4 канала, circular buffer)

```c
#define ADC_BUF_SIZE  4
#define VREF_PLUS     3.0f
#define ADC_FULL      4096.0f

volatile u16 adc_buf[ADC_BUF_SIZE];   // [0]=ch0, [1]=ch1, [2]=ch2, [3]=ch3

// Явный массив каналов (лучше, чем i)
static const uint8_t adc_channels[ADC_BUF_SIZE] = {
    ADC_Channel_0, ADC_Channel_1, ADC_Channel_2, ADC_Channel_3
};

void ADC1_ScanDMA_Init(void)
{
    DMA_InitTypeDef dma;
    ADC_InitTypeDef adc;
    GPIO_InitTypeDef gpio;

    // Clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);

    // PA0..PA3 = analog
    gpio.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    // DMA1_Channel1 (hardwired to ADC1 DR)
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

    // ADC scan
    ADC_DeInit(ADC1);
    adc.ADC_Mode                 = ADC_Mode_Independent;
    adc.ADC_ScanConvMode         = ENABLE;
    adc.ADC_ContinuousConvMode   = ENABLE;
    adc.ADC_ExternalTrigConv     = ADC_ExternalTrigConv_None;
    adc.ADC_DataAlign            = ADC_DataAlign_Right;
    adc.ADC_NbrOfChannel        = ADC_BUF_SIZE;
    ADC_Init(ADC1, &adc);

    // Channels
    for (u8 i = 0; i < ADC_BUF_SIZE; i++)
        ADC_RegularChannelConfig(ADC1, adc_channels[i], i + 1, ADC_SampleTime_55Cycles5);

    // DMA + ADC + calibration
    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);

    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));

    // ⚠️ ADC_SoftwareStartConvCmd — СТРОГО ПОСЛЕ КАЛИБРОВКИ.
    // Если запустить преобразования раньше — DMA начнёт пересылать
    // некалброванный результат (мусор) в adc_buf до стабилизации ADC.
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

float adc_buf_v(int idx)  { return (float)adc_buf[idx] * VREF_PLUS / ADC_FULL; }
```

### 5.3 Helper: чтение произвольного канала

```c
// Однократное чтение произвольного канала (regular group, software trigger).
// ВНИМАНИЕ: временно меняет конфигурацию regular-группы.
// После чтения — восстановить исходный канал, если нужен.
u16 ADC1_ReadChannel(uint8_t channel)
{
    ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
    return ADC_GetConversionValue(ADC1);
}

// Для VREFINT (channel 17) — sample time ≥ 55.5 циклов:
//   ADC_RegularChannelConfig(ADC1, ADC_Channel_17, 1, ADC_SampleTime_55Cycles5);
```

### 5.4 Self-test: прямое измерение VREF+ (рекомендуется для F103)

**Схема:** временная перемычка VREF+ (pin 21) → PA0 (ADC_Channel_0) на время теста.
Вход подключён к собственной опоре, поэтому при VREF+ = 3.0 В ADC даёт full scale.

```c
// Замкнуть перемычку VREF+ (pin 21) -> PA0 перед вызовом. Разомкнуть после теста.
#define VREF_SELF_TEST_CHANNEL   ADC_Channel_0   // PA0
#define VREF_SELF_TEST_EXPECTED 4095            // 3.0 В -> full scale

typedef enum {
    VREF_TEST_OK = 0,          // raw 4094..4095
    VREF_TEST_SHORTED_VDDA,    // raw ~3720 (VREF+ = 3.3 В)
    VREF_TEST_NOT_CONNECTED,   // raw ~0
    VREF_TEST_OUT_OF_RANGE
} vref_test_t;

vref_test_t adc_self_test_vref(uint16_t *raw_out)
{
    uint16_t raw = ADC1_ReadChannel(VREF_SELF_TEST_CHANNEL);
    if (raw_out) *raw_out = raw;

    if (raw >= 4094 && raw <= 4095) return VREF_TEST_OK;
    if (raw >= 3650 && raw <= 3790) return VREF_TEST_SHORTED_VDDA; // ~3.3/3.0*4096 ≈ 3720
    if (raw <= 10)                  return VREF_TEST_NOT_CONNECTED;
    return VREF_TEST_OUT_OF_RANGE;
}
```

> ⚠️ **Никогда не подавать 3.3 В на PA0 во время теста** — АЦП насытится (raw = 4095),
> тест невалиден. Чип не сгорит: V_IN max = VDDA + 0.3 В (Table 62). Но вы не
> отличите «VREF+ = 3.0 В, вход = 3.3 В» от «VREF+ = 3.3 В, вход = 3.3 В» — оба
> дадут 4095. На PA0 во время теста должно быть **именно напряжение с пина VREF+
> (pin 21)**, а не VDDA.
> **Альтернатива перемычке:** делитель от VDDA (10k+10k = 1.65 В) на известном
> канале — raw ≈ 1.65/3.0*4096 ≈ 2240, допуск ~±40 LSB (1% резисторы + INL/DNL).
>
> ⚠️ Тест проверяет только **full-scale**, не линейность. Для проверки линейности
> нужен эталонный внешний источник и прогон по всему диапазону.
>
> ⚠️ Если используется **REF5030 без буфера** — прямое подключение VREF+ к PA0
> может просадить VREF+ (источник не рассчитан на заряд C_ADC; Imax = 10 мкА).
> В этом случае тест делить только через буфер (OPA350/OPA378) или не делать.

### 5.5 VREFINT_CAL — НЕ использовать на F103

> В STM32F103 (включая XL-density, 512 КБ Flash) **заводской калибровки VREFINT
> в памяти нет**. Она появилась только в F0/F3/F4/L1. Адреса 0x1FFFF7C0 /
> 0x1FFFF7BA в F103 содержат device-id или калибровку термодатчика (и то не в
> всех ревизиях).
>
> **Функция vref_check() на основе VREFINT_CAL_ADDR для F103 неприменима — не использовать.**
> Если нужна самопроверка VREF+ — используйте прямое измерение VREF+ (§5.4) или
> внешний источник с известным напряжением.
>
> Внутренний VREFINT (ch 17) остаётся только как быстрый sanity-индикатор:
> raw ≈ 1580…1722 при VREF+ = 3.0 В (≈1.16…1.26 В); raw ≈ 0 → VREF+ не пришёл.
> Точное VREF+ из него не выводится (нет cal-слова).

### 5.6 Термодатчик (channel 16, опционально)

```c
// Грубый термометр (±2 °C). Для мониторинга, НЕ для точных измерений.
// V_sensor ≈ 1.43 В при 25 °C (typ). TCoeff ≈ −4 мВ/°C (typ, Table 21).
float temp_celsius(u16 raw_temp)
{
    float v_sensor = (float)raw_temp * 3.0f / 4096.0f;
    float v_25     = 1.43f;
    return 25.0f + (v_25 - v_sensor) / 0.004f;
}
```

### 5.7 DMA-прерывания для ADC (Half-Transfer + Complete)

```c
// При Circular DMA без прерываний CPU может прочитать «половину старого,
// половину нового» (race condition). HT/TC решают:
// пока DMA пишет во вторую половину, CPU обрабатывает первую — и наоборот.

#define ADC_BUF_SIZE_IRQ  8   // ⚠️ ОБЯЗАТЕЛЬНО ЧЁТНОЕ (лучше степень 2),
                              // иначе HT/TC на границе половин некорректны.
volatile uint16_t adc_buf_irq[ADC_BUF_SIZE_IRQ];
volatile uint8_t  adc_half_ready = 0;
volatile uint8_t  adc_full_ready = 0;

void DMA1_Channel1_IRQHandler(void)
{
    // else if (НЕ два if!): если оба флага HT+TC установлены одновременно
    // (задержка обработки / breakpoint), при двух if adc_full_ready
    // перезапишет adc_half_ready и половина данных потеряется.
    if (DMA_GetITStatus(DMA1_IT_HT1)) {
        DMA_ClearITPendingBit(DMA1_IT_HT1);
        adc_half_ready = 1;   // готова первая половина (0..N/2-1)
    }
    else if (DMA_GetITStatus(DMA1_IT_TC1)) {
        DMA_ClearITPendingBit(DMA1_IT_TC1);
        adc_full_ready = 1;   // готова вторая половина (N/2..N-1)
    }
}

void ADC1_DMA_IRQ_Init(void)
{
    DMA_ITConfig(DMA1_Channel1, DMA_IT_HT | DMA_IT_TC, ENABLE);

    NVIC_InitTypeDef nvic;
    nvic.NVIC_IRQChannel                   = DMA1_Channel1_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority        = 0;
    nvic.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&nvic);
}
```

---

## 6. ЦАП (DAC) — КОД (SPL)

### 6.1 Формулы (VREF+ = 3.0 В, НЕ 3.3)

```
code  = (V_out / 3.0f) * 4096.0f   // округлить, clamp 0..4095
V_out = (code / 4096.0f) * 3.0f
LSB   = 3.0 / 4096 ≈ 0.732 мВ
Полный выход (buffer ON): VREF+ − 10 мВ = 2.990 В
```

### 6.2 Programmatic (без триггера)

```c
#define VREF_PLUS  3.0f
#define DAC_FULL   4096.0f

void DAC1_Init(void)
{
    DAC_InitTypeDef dac;
    GPIO_InitTypeDef gpio;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    gpio.GPIO_Pin  = GPIO_Pin_4;   // PA4 = DAC_OUT1
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    DAC_StructInit(&dac);
    dac.DAC_Trigger                      = DAC_Trigger_None;
    dac.DAC_WaveGeneration               = DAC_WaveGeneration_None;
    dac.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
    dac.DAC_OutputBuffer                 = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &dac);

    DAC_Cmd(DAC_Channel_1, ENABLE);
}

void DAC_SetVoltage(float v)
{
    if (v < 0.0f) v = 0.0f;
    if (v > VREF_PLUS) v = VREF_PLUS;
    u16 code = (u16)((v / VREF_PLUS) * DAC_FULL + 0.5f);
    if (code > 4095) code = 4095;
    DAC_SetChannel1Data(DAC_Align_12b_R, code);
}
```

### 6.3 Триггер от TIM6 (автоматическое обновление)

> **⚠️ TIM6 clock = 72 МГц (APB1 timer clock = PCLK1 × 2 = 36 × 2), НЕ 36 МГц.**
> **PSC = 71 → 72e6 / 72 = 1 МГц база.** НЕ PSC = 35 (это даст 2 МГц и частота в 2× выше).

```c
void TIM6_DAC_Init(float hz_update)
{
    // TIM6 clock = 72 МГц (APB1 timer clock)
    // PSC = 71 → 72e6 / 72 = 1 МГц
    // f_TRGO = 1e6 / (ARR+1),  ARR = 1e6 / hz - 1
    u16 arr = (u16)((1000000.0f / hz_update) - 1.0f);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

    TIM_TimeBaseInitTypeDef tb;
    tb.TIM_Period        = arr;
    tb.TIM_Prescaler     = 71;       // ← 71, НЕ 35
    tb.TIM_ClockDivision = 0;
    tb.TIM_CounterMode   = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM6, &tb);

    TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);  // TRGO = UEV
    TIM_Cmd(TIM6, ENABLE);
}

void DAC1_Triggered_Init(void)
{
    DAC_InitTypeDef  dac;
    GPIO_InitTypeDef gpio;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    gpio.GPIO_Pin  = GPIO_Pin_4;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    DAC_StructInit(&dac);
    dac.DAC_Trigger                      = DAC_Trigger_T6_TRGO;  // ← ключевое
    dac.DAC_WaveGeneration               = DAC_WaveGeneration_None;
    dac.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
    dac.DAC_OutputBuffer                 = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &dac);
    DAC_Cmd(DAC_Channel_1, ENABLE);
}

void DAC_SetCode(u16 code)
{
    if (code > 4095) code = 4095;
    DAC_SetChannel1Data(DAC_Align_12b_R, code);
}

// Пример: пила 1 кГц
int main(void)
{
    TIM6_DAC_Init(1000.0f);  // PSC=71, ARR=999 → 1 кГц
    DAC1_Triggered_Init();

    u16 i = 0;
    while (1) {
        DAC_SetCode(i);
        i = (i + 64) & 0x0FFF;
    }
}
```

### 6.4 СИНУС через DAC + DMA2 + TIM6 (SPL)

```c
// ⚠️ DMA для DAC — это DMA2_Channel3 (DAC1) / DMA2_Channel4 (DAC2). НЕ DMA1!

#include <math.h>
#include "stm32f10x.h"

#define VREF_PLUS     3.0f
#define DAC_FULL      4096.0f
#define SINE_POINTS   64
#define SINE_FREQ     1000.0f
#define SINE_AMP      1.5f
#define SINE_OFFSET   1.5f

uint16_t sine_table[SINE_POINTS];

void sine_table_init(void)
{
    for (int i = 0; i < SINE_POINTS; i++) {
        float v = SINE_OFFSET + SINE_AMP * sinf(2.0f * 3.14159265f * i / SINE_POINTS);
        if (v < 0.0f) v = 0.0f;
        if (v > VREF_PLUS) v = VREF_PLUS;
        sine_table[i] = (uint16_t)(v / VREF_PLUS * DAC_FULL + 0.5f);
        if (sine_table[i] > 4095) sine_table[i] = 4095;
    }
}

void DAC_Sine_DMA_Init(void)
{
    GPIO_InitTypeDef gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    gpio.GPIO_Pin  = GPIO_Pin_4;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC | RCC_APB1Periph_TIM6, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // DMA2_Channel3 (DAC_Channel1 → DHR12R1)
    DMA_InitTypeDef dma;
    DMA_DeInit(DMA2_Channel3);
    dma.DMA_PeripheralBaseAddr = (uint32_t)&DAC->DHR12R1;
    dma.DMA_MemoryBaseAddr     = (uint32_t)sine_table;
    dma.DMA_DIR                = DMA_DIR_PeripheralDST;
    dma.DMA_BufferSize        = SINE_POINTS;
    dma.DMA_PeripheralInc     = DMA_PeripheralInc_Disable;
    dma.DMA_MemoryInc         = DMA_MemoryInc_Enable;
    dma.DMA_PeripheralDataSize= DMA_PeripheralDataSize_HalfWord;
    dma.DMA_MemoryDataSize    = DMA_MemoryDataSize_HalfWord;
    dma.DMA_Mode              = DMA_Mode_Circular;
    dma.DMA_Priority          = DMA_Priority_High;
    dma.DMA_M2M               = DMA_M2M_Disable;
    DMA_Init(DMA2_Channel3, &dma);
    DMA_Cmd(DMA2_Channel3, ENABLE);

    // DAC: trigger = TIM6 TRGO, DMA enable
    DAC_InitTypeDef dac;
    DAC_StructInit(&dac);
    dac.DAC_Trigger                      = DAC_Trigger_T6_TRGO;
    dac.DAC_WaveGeneration               = DAC_WaveGeneration_None;
    dac.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
    dac.DAC_OutputBuffer                 = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &dac);
    DAC_DMACmd(DAC_Channel_1, ENABLE);
    DAC_Cmd(DAC_Channel_1, ENABLE);

    // TIM6: f_TRGO = SINE_POINTS * SINE_FREQ = 64 кГц, PSC=0 → f = 72e6/(ARR+1)
    float f_trgo = SINE_POINTS * SINE_FREQ;   // 64000 Гц
    u16 arr = (u16)((72000000.0f / f_trgo) - 1.0f + 0.5f);  // 1124

    TIM_TimeBaseInitTypeDef tb;
    tb.TIM_Period        = arr;
    tb.TIM_Prescaler     = 0;
    tb.TIM_ClockDivision = 0;
    tb.TIM_CounterMode   = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM6, &tb);
    TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
    TIM_Cmd(TIM6, ENABLE);
}

int main(void)
{
    sine_table_init();
    DAC_Sine_DMA_Init();
    while (1) { }
}
```

> **Проверка:** f_sine = f_TRGO / SINE_POINTS. 64 точки × 1 кГц = 64 кГц TRGO → ARR = 1124.
> Осциллограф на PA4: синус 1 кГц, размах 0…3.0 В.

---

## 7. HAL + ADC + DMA (CUBEMX)

> Сценарий: ADC1 сканирует 4 канала (PA0..PA3), DMA1_Channel1, Circular.
> VREF+ = 3.0 В (внешний). Формула пересчёта: `* 3.0f / 4096.0f`.

### 7.1 Настройка в CubeMX

```
ADC1:
  Mode: Independent
  Clock Prescaler: /6 (PCLK2/6 = 12 МГц при HCLK=72)
  Scan Conversion Mode: Enable
  Continuous Conversion Mode: Enable
  Discontinuous Conversion Mode: Disable
  DMA Continuous Requests: Enable
  Number of Conversion: 4
  Rank 1: Channel 0, Sampling Time: 55.5 Cycles
  Rank 2: Channel 1, Sampling Time: 55.5 Cycles
  Rank 3: Channel 2, Sampling Time: 55.5 Cycles
  Rank 4: Channel 3, Sampling Time: 55.5 Cycles

ADC1 -> DMA Settings:
  Add -> DMA1 Channel 1
  Mode: Circular
  Data Width (Peripheral): Half Word
  Data Width (Memory):     Half Word
  Increment Address (Memory): Enable
  Increment Address (Peripheral): Disable

NVIC:
  DMA1 Channel1 global interrupt: Enable (если нужны HT/TC)

GPIO:
  PA0..PA3: Analog
```

### 7.2 Код (main.c)

```c
#include "main.h"

#define VREF_PLUS   3.0f
#define ADC_FULL    4096.0f
#define ADC_BUF_LEN 4

extern ADC_HandleTypeDef hadc1;

volatile uint16_t adc_buf[ADC_BUF_LEN];

void adc_init_dma(void)
{
    // Калибровка ОБЯЗАТЕЛЬНА после MX_ADC1_Init() и после установления VREF+
    if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK) {
        Error_Handler();
    }

    // ⚠️ HAL_ADC_Start_DMA() принимает uint32_t* даже для 12-битного ADC —
    // это нормальный HAL-паттерн (приведение (uint32_t*)adc_buf безопасно).
    // Не менять на uint16_t*.
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, ADC_BUF_LEN) != HAL_OK) {
        Error_Handler();
    }
}

static inline float adc_raw_to_v(uint16_t raw)
{
    return (float)raw * VREF_PLUS / ADC_FULL;   // * 3.0 / 4096
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
    // готова первая половина adc_buf[0 .. ADC_BUF_LEN/2 - 1]
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    // готова вторая половина adc_buf[ADC_BUF_LEN/2 .. ADC_BUF_LEN - 1]
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_ADC1_Init();

    adc_init_dma();

    while (1)
    {
        float v0 = adc_raw_to_v(adc_buf[0]);   // PA0, 0..3.0 В
        float v1 = adc_raw_to_v(adc_buf[1]);   // PA1
        float v2 = adc_raw_to_v(adc_buf[2]);   // PA2
        float v3 = adc_raw_to_v(adc_buf[3]);   // PA3
        (void)v0; (void)v1; (void)v2; (void)v3;
        HAL_Delay(10);
    }
}
```

### 7.3 Важные замечания для HAL

```
[1] Калибровку вызывать ОДИН РАЗ после MX_ADC1_Init() и после того, как
    VREF+ = 3.0 В установился. Если VREF+ включается позже VDDA —
    добавить задержку или проверку PGOOD перед калибровкой.
[2] HAL_ADC_Start_DMA() запускает DMA в режиме, заданном в CubeMX (Circular).
    Не вызывать повторно в цикле — только один раз.
[3] Остановка: HAL_ADC_Stop_DMA(&hadc1);
[4] adc_buf должен быть volatile, иначе оптимизация «закеширует» значение в регистре.
[5] Для HT/TC: в CubeMX включить NVIC -> DMA1 Channel1 global interrupt.
    HAL вызовет HAL_ADC_ConvHalfCpltCallback() и HAL_ADC_ConvCpltCallback().
[6] НЕ смешивать HAL_ADC_Start_DMA() с ручным ADC_GetConversionValue().
    При активном DMA регистр DR читается DMA, ручное чтение даст мусор.
[7] Формула пересчёта — ВСЕГДА * 3.0f / 4096.0f. Не 3.3.
```

### 7.4 Чек-лист для HAL ADC+DMA

```
[ ] CubeMX: ADC1 Continuous = Enable, DMA Continuous Requests = Enable
[ ] CubeMX: DMA1 Channel1, Circular, HalfWord
[ ] В коде: HAL_ADCEx_Calibration_Start() после MX_ADC1_Init()
[ ] В коде: HAL_ADC_Start_DMA() один раз в setup
[ ] adc_buf объявлен volatile
[ ] Формула * 3.0f / 4096.0f
[ ] При необходимости: NVIC DMA1_Channel1 + HT/TC callbacks
[ ] VREF+ = 3.0 В физически на пине 21
```

---

## 8. HAL + DAC + DMA2 + TIM6: ГЕНЕРАЦИЯ СИНУСА

> Сценарий: синус 1 кГц, размах 0..3.0 В (offset 1.5 В, амплитуда 1.5 В).
> Таблица: 64 точки. TIM6 TRGO = 64 кГц (64 точки × 1 кГц).
> DMA: DMA2_Channel3 → DAC->DHR12R1, Circular, HalfWord. CPU свободен.
> VREF+ = 3.0 В (внешний). НЕ 3.3.

### 8.1 Настройка в CubeMX

```
DAC:
  OUT1 Configuration:
    Output Buffer: Enable (рекомендуется)
    Mode: Connected to external pin only
    Trigger: TIM6 TRGO   <-- КЛЮЧЕВОЕ, НЕ TIM2/3/4/5
    (Если в вашей версии CubeMX опции "Connected to external pin only" нет —
     оставить по умолчанию; главное — Output Buffer: Enable)
  OUT1 -> DMA Settings:
    Add -> DMA2 Channel3
    Mode: Circular
    Data Width (Peripheral): Half Word
    Data Width (Memory):     Half Word
    Increment Address (Memory): Enable
    Increment Address (Peripheral): Disable

TIM6:
  Prescaler (PSC): 0
  Counter Period (ARR): 1124      (64 кГц TRGO при 72 МГц TIM6 clock)
  Trigger Event Selection: Update Event

NVIC:
  DMA2 Channel3 global interrupt: Enable (опционально, если нужен callback)

GPIO:
  PA4 = Analog (DAC_OUT1)

ВАЖНО:
  TIM6 clock = 72 МГц (APB1 timer clock = PCLK1 × 2 = 36 × 2).
  НЕ 36 МГц. Если поставить PSC = 35 — частота синуса будет в 2 раза выше.
  При SINE_POINTS = 64, SINE_FREQ = 1 кГц:
    f_TRGO = 64 × 1000 = 64 кГц
    ARR = 72e6 / 64e3 − 1 = 1124
    PSC = 0
```

### 8.2 Код (main.c, пользовательские функции)

```c
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

uint16_t sine_table[SINE_POINTS];   // НЕ const: DMA читает из RAM

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

void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef* hdac)
{
    // Первая половина sine_table отправлена DMA (0..N/2-1)
}

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef* hdac)
{
    // Вторая половина sine_table отправлена DMA (N/2..N-1)
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_DAC_Init();
    MX_TIM6_Init();

    dac_sine_start();

    while (1)
    {
        // CPU свободен. Синус генерируется автоматически.
    }
}
```

### 8.3 Проверка частоты и размаха

```
f_sine = f_TRGO / SINE_POINTS
f_TRGO = TIM6_clock / (PSC + 1) / (ARR + 1)
TIM6_clock = 72 МГц (APB1 timer clock)

При SINE_POINTS = 64, PSC = 0, ARR = 1124:
  f_TRGO  = 72e6 / 1 / 1125 = 64000 Гц
  f_sine  = 64000 / 64 = 1000 Гц

Осциллограф на PA4:
  размах 0..3.0 В (низ 0, верх = VREF+)
  offset 1.5 В, амплитуда 1.5 В
  частота 1 кГц

Если частота в 2 раза выше — PSC = 35 вместо 0 (или ARR = 562).
Если верхняя граница ≈ 3.3 В — VREF+ закорочен на VDDA (проверить пин 21).
Если верхняя граница ниже 3.0 В — buffer ON: VREF+ − 10 мВ = 2.990 В (норма).
```

### 8.4 Важные замечания для HAL

```
[1] DMA для DAC — DMA2_Channel3 (DAC1) / DMA2_Channel4 (DAC2).
    НЕ DMA1. Если в CubeMX добавить DAC1 -> DMA1, код скомпилируется,
    но DMA не запустится (аппаратной связи нет).
[2] sine_table объявлена НЕ const, потому что HAL_DAC_Start_DMA()
    принимает uint32_t* и не помечает его const. Формально можно
    привести const_cast, но проще держать в RAM.
[3] HAL_DAC_Start_DMA() сам настраивает DMA на основе CubeMX.
    Вручную DMA_Init() вызывать НЕ НУЖНО.
[4] Порядок запуска: HAL_DAC_Start -> HAL_DAC_Start_DMA -> HAL_TIM_Base_Start.
    Если запустить TIM6 раньше DMA, первые триггеры уйдут впустую — на выходе
    появится «ступенька» в начале (DAC не готов, а триггер уже идёт).
    Не критично для работы, но заметно на осциллографе. Соблюдайте порядок.
[5] HAL_DAC_Stop_DMA() останавливает DMA, но DAC продолжает выдавать
    последнее значение. Полное выключение:
      HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
      HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
[6] Для DAC2 (PA5): DMA2_Channel4, DAC_CHANNEL_2, HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_2, ...).
[7] Формула — ВСЕГДА * 3.0f / 4096.0f. Не 3.3.
```

### 8.5 Чек-лист для HAL + DAC + DMA + TIM6

```
[ ] CubeMX: DAC1 OUT1, Trigger = TIM6 TRGO
[ ] CubeMX: DMA2 Channel3, Circular, HalfWord, Memory Inc = Enable
[ ] CubeMX: TIM6, PSC = 0, ARR = 1124, Trigger = Update Event
[ ] В коде: sine_table_init() ДО HAL_DAC_Start_DMA()
[ ] В коде: HAL_DAC_Start -> HAL_DAC_Start_DMA -> HAL_TIM_Base_Start
[ ] sine_table НЕ const
[ ] Формула * 3.0f / 4096.0f
[ ] Осциллограф: частота 1 кГц, размах 0..3.0 В
[ ] VREF+ = 3.0 В физически на пине 21
```

---

## 9. ЧЕК-ЛИСТ (АППАРАТ + SOFTWARE)

### Аппарат
- [ ] VREF+ (pin 21) ← источник 3.0 В (REF3030 / REF5030+buffer), 0 Ω
- [ ] 10 нF C0G + 1 мкF → VSSA на VREF+ (pin 21)
- [ ] VREF− (pin 20) → 0 Ω → VSSA (pin 19)
- [ ] VDDA (pin 22) → 3.3 В, 10 нF C0G + 1 мкF → VSSA
- [ ] VSSA (pin 19) → single-point star → VSS (digital GND)
- [ ] Imax источника ≥ 220 мкА (REF5030 = 10 мкА → нужен буфер или REF3030)
- [ ] C0G/NP0 (не X7R) на VREF+ и VDDA
- [ ] VDDA и VDD — один LDO или Δ ≤ 300 мВ
- [ ] VREF+ не опережает VDDA (soft-start / RC-затяжка)
- [ ] Осциллографом: VDDA раньше VREF+

### Software
- [ ] `RCC_ADCCLKConfig` → fADC ≤ 14 МГц
- [ ] `ADC_Cmd(ENABLE)` → `ResetCalibration` → `StartCalibration` → `while(Status)`
- [ ] Все формулы: `* 3.0f / 4096.0f`
- [ ] DAC: `code = V / 3.0f * 4096`
- [ ] Self-test: VREF+ через прямое измерение (перемычка VREF+→PA0, §5.4) или делитель
- [ ] НЕ полагаться на VREFINT_CAL на F103 (такого слова в памяти нет, §5.5)
- [ ] При DAC trigger: TIM6, TRGO = Update, **PSC = 71** (не 35)
- [ ] При ADC + DMA: **DMA1_Channel1**, Circular, HalfWord
- [ ] При DAC + DMA: **DMA2_Channel3** (не DMA1!)
- [ ] При DMA с прерываниями: HT + TC, NVIC настроен
- [ ] `adc_buf` / `sine_table` объявлены volatile / non-const

---

## 10. ЧАСТЫЕ ОШИБКИ (НЕ ДЕЛАТЬ)

| Ошибка | Последствие |
|---|---|
| `* 3.3f / 4096` в формулах | Систематическая ошибка ~10% |
| Коротить VREF+ с VDDA | Опора = 3.3 В, не 3.0 В |
| Калибровка ДО `ADC_Cmd(ENABLE)` | Калибровка не работает |
| **PSC = 35** для TIM6 | Частота в 2× выше расчётной (f = 2 МГц / ARR) |
| **DMA1 для DAC** | Не работает, DAC не обновляется (нужен **DMA2_Channel3**) |
| REF5030 без буфера при Imax=10 мкА | Провал VREF+ → ошибка |
| X7R MLCC на VREF+ / VDDA | Дрейф ёмкости = дрейф опорного |
| VSSA → digital GND (не single-point) | Цифровой шум на ADC |
| TIM2/3/4/5 для DAC trigger | Не работает |
| DMA не Circular + переполнение | Потеря данных |
| Чтение без ожидания EOC | Stale value |
| `adc_buf` без volatile | Оптимизатор кэширует, буфер «не обновляется» |

---

## 11. ОТВЕТЫ НА ЧАСТЫЕ ВОПРОСЫ

**Q: Нужен ли бит выбора VREF+?**
A: Нет. В STM32F103 АЦП/ЦАП всегда используют напряжение на пине 21. Переключателей нет.

**Q: Можно ли VREF+ = VDDA = 3.3 В?**
A: Да, это вариант 1 (Fig. 58). У нас вариант 2 (VREF+=3.0 В, Fig. 57) — прецизионнее.

**Q: Почему TIM6?**
A: В RM0008: trigger input DAC привязан к TIM6 TRGO. У TIM1/2/3/4/5 нет этого коннектора.

**Q: VREF+ не пришёл?**
A: ADC → 0, DAC → 0 В. Self-test VREFINT: raw ≈ 0.

**Q: PSC для TIM6 = 35 или 71?**
A: **71.** APB1 timer clock = PCLK1 × 2 = 72 МГц (когда APB1 prescaler = 2).
72e6 / 72 = 1 МГц → ARR = 1e6/hz − 1. При hz=1000 → ARR=999, период=1 мс.

**Q: Какой DMA для DAC?**
A: **DMA2_Channel3** (DAC1) или **DMA2_Channel4** (DAC2). Не DMA1.

**Q: Как проверить, что VREF+ пришёл (self-test)?**
A: На F103 (512 КБ) в памяти НЕТ слова VREFINT_CAL — не использовать VREFINT_CAL_ADDR (§5.5).
Основной: прямое измерение VREF+ перемычкой VREF+→PA0 (§5.4): raw 4094–4095 = OK,
3650–3790 = закорочен на VDDA, ≈0 = не подключён. Альтернатива — делитель от VDDA.
Быстрый sanity: VREFINT ch 17 (raw ~1580–1722; ≈0 → VREF+ не пришёл).

**Q: SPL или HAL?**
A: SPL (§5, §6) — если нужен полный контроль регистров. HAL/CubeMX (§7, §8) — если
проще и быстрее. Формулы `* 3.0 / 4096` одинаковы в обоих.

---

## 12. ТРАУБЛ-ШУТИНГ (ЕСЛИ СЛОМАЛОСЬ)

| Симптом | Причина | Смотреть |
|---|---|---|
| ADC всегда 4095 | VREF+ = 0 В, вход притянут к 3.3 В | §3.2, §5.4 |
| ADC всегда 0 | VREF+ не подключён / канал не настроен | §5.4, §5.1 |
| ADC шумит / скачет | X7R на VREF+, плохой single-point | §3.3 |
| ADC показывает ~10% больше | Формула `* 3.3` вместо `* 3.0` | §0 |
| Калибровка «зависает» | `ADC_Cmd(ENABLE)` не вызван до калибровки | §5.1 шаг 5, §13 |
| DAC не обновляется | TIM6 TRGO не настроен / trigger ≠ T6 | §6.3 |
| DAC частота в 2× выше | PSC = 35 (старое значение), а не 71 | §6.3, §8 |
| DAC + DMA не работает | Использован DMA1 вместо **DMA2_Channel3** | §6.4, §8 |
| Синус «рвётся» | DMA buffer не Circular / N не то | §6.4, §8 |
| VREF+ не пришёл | self-test (VREF+→PA0) raw ~0; VREFINT ch17 raw ~0 | §5.4 |
| VREF+ ≠ 3.0 В (закорочен на VDDA) | self-test raw ~3650–3790 (≈3.3 В); VREFINT ch17 raw вне 1580–1722 | §5.4 |
| REF5030 греется / просаживается | Нагрузка > Imax = 10 мкА | §3.4 |

---

## 13. ПОРЯДОК КАЛИБРОВКИ (СТРОГО, НЕ ПЕРЕМЕШАТЬ)

```
 1. RCC: включить тактирование ADC1, GPIO
 2. RCC_ADCCLKConfig (fADC ≤ 14 МГц)
 3. GPIO: настроить входы как GPIO_Mode_AIN
 4. ADC_DeInit
 5. ADC_Init (режим, каналы, выравнивание)
 6. ADC_RegularChannelConfig
 7. ADC_Cmd(ADC1, ENABLE)          ← ОБЯЗАТЕЛЬНО ДО КАЛИБРОВКИ
 8. ADC_ResetCalibration
 9. while (ADC_GetResetCalibrationStatus)
10. ADC_StartCalibration
11. while (ADC_GetCalibrationStatus)
12. ADC_SoftwareStartConvCmd
```

> Если шаг 7 пропущен — калибровка не выполнится.
> Если VREF+ ещё не установился — калибровка зафиксирует неверное значение.
> Повторная калибровка: после power-on / смены VDDA/VREF+. По температуре — не нужна.
> В HAL: `HAL_ADCEx_Calibration_Start(&hadc1)` после `MX_ADC1_Init()`.

---

## 14. СТРУКТУРА РЕПОЗИТОРИЯ

| Файл | Что |
|---|---|
| `STM32F103VGT6_VREF_AI.md` | **ЭТОТ ФАЙЛ** — полный контекст для AI-агента (самодостаточный) |
| `examples/adc_spl.c` | SPL: init + calibration, scan+DMA, self-test VREF+ |
| `examples/dac_hal.c` | HAL/CubeMX: генерация синуса через DAC + DMA2 + TIM6 |
| `docs/datasheet.pdf` | оригинал даташита ST (DocID16554 Rev 4, ~1.9 МБ) |
| `docs/datasheet.md` | тот же даташит в текстовом виде (~220 КБ, TOC, для `search`/`read` AI-агентом) |
| `README.md` | описание репо |
| `LICENSE` | MIT |

> Рабочие файлы из каталога проекта (`STM32F103VGT6.pdf`, `datasheet.md`,
> `extracted.txt`, `See!.txt`, `Шпаргалка*.txt`) НЕ попадают в репо — их данные
> полностью погашены в этом файле и в `docs/datasheet.pdf`.
> Для переноса на другой ПК достаточно этого репозитория.

Сгенерировано: 2026-10-22. Самодостаточный контекст для AI-агента.*
*Corpus: LQFP100 ONLY.*
*Основано на: STM32F103xF/xG Datasheet DocID16554 Rev 4 + RM0008 + SPL + See!.txt v2.1 + Шпаргалка1/2/3.txt*
*Пины подтверждены пользователем: VSSA=19, VREF−=20, VREF+=21, VDDA=22.*
*IC спецификации — типовые значения. ПРОВЕРИТЬ ПО DATASHEET ВЕНДОРА перед проектированием.*
