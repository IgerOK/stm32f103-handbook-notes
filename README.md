# STM32F103 VREF Handbook Notes

Пакет конспектов и проверенных эталонных кодов для STM32F103VGT6 (Cortex-M3, LQFP100)
с **внешним опорным напряжением VREF+ = 3.0 В** (REF3030 / MAX6030 / REF5030 + buffer).

Всё проверено по datasheet STM32F103xF/xG (DocID16554 Rev 4) и RM0008.

## Состав
- `STM32F103VGT6_VREF_AI.md` — основной файл: правила, пины, формулы, код SPL и HAL, чек-листы.
- `examples/adc_spl.c` — SPL: init + calibration, scan+DMA, self-test VREF+.
- `examples/dac_hal.c` — HAL/CubeMX: генерация синуса через DAC + DMA2 + TIM6.
- `LICENSE` — MIT.

## Ключевые факты (коротко)
- VREF+ = 3.0 В (pin 21), НЕ 3.3 и НЕ VDDA. Формулы: `raw * 3.0f / 4096.0f`.
- Пины LQFP100: VSSA=19, VREF−=20, VREF+=21, VDDA=22.
- Калибровка ADC — строго ПОСЛЕ `ADC_Cmd(ENABLE)` и ПОСЛЕ установления VREF+.
- DAC trigger — только TIM6. DMA для DAC1 = **DMA2_Channel3** (не DMA1).
- На F103 (512 КБ) НЕТ заводского VREFINT_CAL — self-test через прямое измерение VREF+.

## Лицензия
MIT. См. `LICENSE`.
