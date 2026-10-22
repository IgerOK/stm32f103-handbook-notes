# STM32F103xF / STM32F103xG Datasheet

> **DocID16554 Rev 4** (May 2015) - production data.  
> 32-bit ARM Cortex-M3 MCU, 72 MHz, 768 KB-1 MB Flash, 96 KB SRAM.  
> Source: `STM32F103VGT6.pdf` -> `extracted.txt`.

## Quick index (top-level chapters)

- [**1 Introduction**](#1-introduction)
- [**2 Description**](#2-description)
- [**3 Pinouts and pin descriptions**](#3-pinouts-and-pin-descriptions)
- [**4 Memory mapping**](#4-memory-mapping)
- [**5 Electrical characteristics**](#5-electrical-characteristics)
- [**6 Package information**](#6-package-information)
- [**7 Part numbering**](#7-part-numbering)
- [**8 Revision history**](#8-revision-history)

## Table of Contents

- [Front matter: features, device summary, contents](#front-matter)
- [1 Introduction](#1-introduction)
- [2 Description](#2-description)
- [2.1 Device overview](#2-1-device-overview)
- [2.2 Full compatibility throughout the family](#2-2-full-compatibility-throughout-the-family)
- [2.3 Overview](#2-3-overview)
  - [2.3.1 ARM ® Cortex®-M3 core with embedded Flash and SRAM](#2-3-1-arm-cortex-m3-core-with-embedded-flash-and-sram)
  - [2.3.2 Memory protection unit](#2-3-2-memory-protection-unit)
  - [2.3.3 Embedded Flash memory](#2-3-3-embedded-flash-memory)
  - [2.3.4 CRC (cyclic redundan cy check) calculation unit](#2-3-4-crc-cyclic-redundan-cy-check-calculation-unit)
  - [2.3.5 Embedded SRAM](#2-3-5-embedded-sram)
  - [2.3.6 FSMC (flexible static memory controller)](#2-3-6-fsmc-flexible-static-memory-controller)
  - [2.3.7 LCD parallel interface](#2-3-7-lcd-parallel-interface)
  - [2.3.8 Nested vectored interrupt controller (NVIC)](#2-3-8-nested-vectored-interrupt-controller-nvic)
  - [2.3.9 External interrupt /event controller (EXTI)](#2-3-9-external-interrupt-event-controller-exti)
  - [2.3.10 Clocks and startup](#2-3-10-clocks-and-startup)
  - [2.3.11 Boot modes](#2-3-11-boot-modes)
  - [2.3.12 Power supply schemes](#2-3-12-power-supply-schemes)
  - [2.3.13 Power supply supervisor](#2-3-13-power-supply-supervisor)
  - [2.3.14 Voltage regulator](#2-3-14-voltage-regulator)
  - [2.3.15 Low-power modes](#2-3-15-low-power-modes)
  - [2.3.16 DMA](#2-3-16-dma)
  - [2.3.17 RTC (real-time cl ock) and backup registers](#2-3-17-rtc-real-time-cl-ock-and-backup-registers)
  - [2.3.18 Timers and watchdogs](#2-3-18-timers-and-watchdogs)
  - [2.3.19 I²C bus](#2-3-19-i-c-bus)
  - [2.3.20 Universal synchr onous/asynchronous receiver transmitters (USARTs)](#2-3-20-universal-synchr-onous-asynchronous-receiver-transmitters-usarts)
  - [2.3.21 Serial peripheral interface (SPI)](#2-3-21-serial-peripheral-interface-spi)
  - [2.3.22 Inter-integrated sound (I 2S)](#2-3-22-inter-integrated-sound-i-2s)
  - [2.3.23 SDIO](#2-3-23-sdio)
  - [2.3.24 Controller area network (CAN)](#2-3-24-controller-area-network-can)
  - [2.3.25 Universal serial bus (USB)](#2-3-25-universal-serial-bus-usb)
  - [2.3.26 GPIOs (general- purpose inputs/outputs)](#2-3-26-gpios-general-purpose-inputs-outputs)
  - [2.3.27 ADC (analog to digital converter)](#2-3-27-adc-analog-to-digital-converter)
  - [2.3.28 DAC (digital-to-analog converter)](#2-3-28-dac-digital-to-analog-converter)
  - [2.3.29 Temperature sensor](#2-3-29-temperature-sensor)
  - [2.3.30 Serial wire JTAG debug port (SWJ-DP)](#2-3-30-serial-wire-jtag-debug-port-swj-dp)
  - [2.3.31 Embedded Trace Macrocell™](#2-3-31-embedded-trace-macrocell)
- [3 Pinouts and pin descriptions](#3-pinouts-and-pin-descriptions)
- [4 Memory mapping](#4-memory-mapping)
- [5 Electrical characteristics](#5-electrical-characteristics)
- [5.1 Parameter conditions](#5-1-parameter-conditions)
  - [5.1.1 Minimum and maximum values](#5-1-1-minimum-and-maximum-values)
  - [5.1.2 Typical values](#5-1-2-typical-values)
  - [5.1.3 Typical curves](#5-1-3-typical-curves)
  - [5.1.4 Loading capacitor](#5-1-4-loading-capacitor)
  - [5.1.5 Pin input voltage](#5-1-5-pin-input-voltage)
  - [5.1.6 Power supply scheme](#5-1-6-power-supply-scheme)
  - [5.1.7 Current consumption measurement](#5-1-7-current-consumption-measurement)
- [5.2 Absolute maximum ratings](#5-2-absolute-maximum-ratings)
- [5.3 Operating conditions](#5-3-operating-conditions)
  - [5.3.1 General operating conditions](#5-3-1-general-operating-conditions)
  - [5.3.2 Operating conditions at power-up / power-down](#5-3-2-operating-conditions-at-power-up-power-down)
  - [5.3.3 Embedded reset and power control block characteristics](#5-3-3-embedded-reset-and-power-control-block-characteristics)
  - [5.3.4 Embedded reference voltage](#5-3-4-embedded-reference-voltage)
  - [5.3.5 Supply current characteristics](#5-3-5-supply-current-characteristics)
  - [5.3.6 External clock source characteristics](#5-3-6-external-clock-source-characteristics)
  - [5.3.7 Internal clock source characteristics](#5-3-7-internal-clock-source-characteristics)
  - [5.3.8 PLL characteristics](#5-3-8-pll-characteristics)
  - [5.3.9 Memory characteristics](#5-3-9-memory-characteristics)
  - [5.3.10 FSMC characteristics](#5-3-10-fsmc-characteristics)
  - [5.3.11 EMC characteristics](#5-3-11-emc-characteristics)
  - [5.3.12 Absolute maximum ratings (electrical sensitivity)](#5-3-12-absolute-maximum-ratings-electrical-sensitivity)
  - [5.3.13 I/O current in jection characteristics](#5-3-13-i-o-current-in-jection-characteristics)
  - [5.3.14 I/O port characteristics](#5-3-14-i-o-port-characteristics)
  - [5.3.15 NRST pin characteristics](#5-3-15-nrst-pin-characteristics)
  - [5.3.16 TIM time r characteristics](#5-3-16-tim-time-r-characteristics)
  - [5.3.17 Communications interfaces](#5-3-17-communications-interfaces)
  - [5.3.18 CAN (controller ar ea network) interface](#5-3-18-can-controller-ar-ea-network-interface)
  - [5.3.19 12-bit ADC characteristics](#5-3-19-12-bit-adc-characteristics)
  - [5.3.20 DAC electri cal specifications](#5-3-20-dac-electri-cal-specifications)
  - [5.3.21 Temperature sensor characteristics](#5-3-21-temperature-sensor-characteristics)
- [6 Package information](#6-package-information)
- [6.1 LFBGA144 package information](#6-1-lfbga144-package-information)
- [6.2 LQFP144 package information](#6-2-lqfp144-package-information)
- [6.3 LQFP100 package information](#6-3-lqfp100-package-information)
- [6.4 LQFP64 package information](#6-4-lqfp64-package-information)
- [6.5 Thermal characteristics](#6-5-thermal-characteristics)
  - [6.5.1 Reference document](#6-5-1-reference-document)
  - [6.5.2 Selecting the product temperature range](#6-5-2-selecting-the-product-temperature-range)
- [7 Part numbering](#7-part-numbering)
- [8 Revision history](#8-revision-history)

---


## Front matter: features, device summary, contents
May 2015 DocID16554 Rev 4 1/136
STM32F103xF STM32F103xG
XL-density performance line ARM®-based 32-bit MCU with 768 KB 
to 1 MB Flash, USB, CAN, 17 timers, 3 ADCs, 13 com. interfaces
Datasheet − production data
Features
• Core: ARM® 32-bit Cortex®-M3 CPU with MPU
– 72 MHz maximum frequency, 
1.25 DMIPS/MHz (Dhrystone 2.1) 
performance at 0 wait state memory 
access
– Single-cycle multiplic ation and hardware 
division
• Memories
– 768 Kbytes to 1 Mbyte of Flash memory
– 96 Kbytes of SRAM
– Flexible static memo ry controller with 4 
Chip Select. Supports Compact Flash, 
SRAM, PSRAM, NOR and NAND memories
– LCD parallel interface, 8080/6800 modes
• Clock, reset and supply management
– 2.0 to 3.6 V application supply and I/Os 
– POR, PDR, and programmable voltage 
detector (PVD)
– 4-to-16 MHz cr ystal oscillator 
– Internal 8 MHz factory-trimmed RC
– Internal 40 kHz RC with calibration 
– 32 kHz oscillator for RTC with calibration
• Low power
– Sleep, Stop and Standby modes
–V BAT supply for RTC and backup registers
• 3 × 12-bit, 1 µs A/D converters (up to 21 
channels)
– Conversion range: 0 to 3.6 V
– Triple-sample and hold capability
– Temperature sensor
• 2 × 12-bit D/A converters
• DMA: 12-channel DMA controller
– Supported peripherals: timers, ADCs, DAC, 
SDIO, I2Ss, SPIs, I2Cs and USARTs
• Debug mode
– Serial wire debug (SWD) & JTAG 
interfaces
–C o r t e x®-M3 Embedded Trace Macrocell™
• Up to 112 fast I/O ports
– 51/80/112 I/Os, all mappable on 16 
external interrupt vectors and almost all 
5 V-tolerant
• Up to 17 timers
– Up to ten 16-bit timers, each with up to 4 
IC/OC/PWM or pulse counter and 
quadrature (incremental) encoder input
– 2 × 16-bit motor control PWM timers with 
dead-time generation and emergency stop
– 2 × watchdog timers (Independent and 
Window)
– SysTick timer: a 24-bit downcounter
– 2 × 16-bit basic timers to drive the DAC
• Up to 13 communication interfaces
– Up to 2 × I 2C interfaces (SMBus/PMBus)
– Up to 5 USARTs (ISO 7816 interface, LIN, 
IrDA capability, modem control)
– Up to 3 SPIs (18 Mbit/s), 2 with I 2S 
interface multiplexed
– CAN interface (2.0B Active)
– USB 2.0 full speed interface
– SDIO interface
• CRC calculation unit, 96-bit unique ID
• ECOPACK® packages
          
Table 1. Device summary
Reference Part number
STM32F103xF STM32F103RF STM32F103VF STM32F103ZF
STM32F103xG STM32F103RG STM32F103VG STM32F103ZG
&"'!
LQFP64 10 × 10 mm, 
LQFP100 14 × 14 mm, 
LQFP144 20 × 20 mm
LFBGA144 10 × 10 mm
www.st.com
Contents STM32F103xF, STM32F103xG
2/136 DocID16554 Rev 4
Contents
1 Introduction . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9
2 Description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10
2.1 Device overview . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .11
2.2 Full compatibility throughout the family  . . . . . . . . . . . . . . . . . . . . . . . . . . 14
2.3 Overview  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
2.3.1 ARM ® Cortex®-M3 core with embedded Flash and SRAM . . . . . . . . . . 15
2.3.2 Memory protection unit  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
2.3.3 Embedded Flash memory  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
2.3.4 CRC (cyclic redundancy check) calculation unit  . . . . . . . . . . . . . . . . . . 15
2.3.5 Embedded SRAM  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
2.3.6 FSMC (flexible static memory controller) . . . . . . . . . . . . . . . . . . . . . . . . 16
2.3.7 LCD parallel interface  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
2.3.8 Nested vectored interrupt controller (NVIC)  . . . . . . . . . . . . . . . . . . . . . . 16
2.3.9 External interrupt/event controller (EXTI)  . . . . . . . . . . . . . . . . . . . . . . . 16
2.3.10 Clocks and startup . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
2.3.11 Boot modes  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
2.3.12 Power supply schemes  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
2.3.13 Power supply supervisor  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
2.3.14 Voltage regulator  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18
2.3.15 Low-power modes . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18
2.3.16 DMA . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18
2.3.17 RTC (real-time clock) and backup register s . . . . . . . . . . . . . . . . . . . . . . 19
2.3.18 Timers and watchdogs . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 19
2.3.19 I²C bus . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 21
2.3.20 Universal synchronous/asynchronous  receiver transmitters (USARTs) . 21
2.3.21 Serial peripheral interface (SPI) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.22 Inter-integrated sound (I 2S) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.23 SDIO  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.24 Controller area network (CAN)  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.25 Universal serial bus (USB) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.26 GPIOs (general-purpose inputs/outputs) . . . . . . . . . . . . . . . . . . . . . . . . 22
2.3.27 ADC (analog to digital converter) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
2.3.28 DAC (digital-to-analog converter)  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
DocID16554 Rev 4 3/136
STM32F103xF, STM32F103xG Contents
4
2.3.29 Temperature sensor . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
2.3.30 Serial wire JTAG debug port (SWJ-DP) . . . . . . . . . . . . . . . . . . . . . . . . . 24
2.3.31 Embedded Trace Macrocell™ . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
3 Pinouts and pin descriptions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25
4 Memory mapping . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 38
5 Electrical characteristi cs  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1 Parameter conditions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.1 Minimum and maximum values . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.2 Typical values  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.3 Typical curves  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.4 Loading capacitor  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.5 Pin input voltage  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
5.1.6 Power supply scheme  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41
5.1.7 Current consumption measurement  . . . . . . . . . . . . . . . . . . . . . . . . . . . 42
5.2 Absolute maximum ratings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 43
5.3 Operating conditions  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 44
5.3.1 General operating conditions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 44
5.3.2 Operating conditions at power-up / powe r-down . . . . . . . . . . . . . . . . . . 45
5.3.3 Embedded reset and power control bloc k characteristics . . . . . . . . . . . 45
5.3.4 Embedded reference voltage . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46
5.3.5 Supply current characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46
5.3.6 External clock source characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . 57
5.3.7 Internal clock source charac teristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . 63
5.3.8 PLL characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65
5.3.9 Memory characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65
5.3.10 FSMC characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 67
5.3.11 EMC characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88
5.3.12 Absolute maximum ratings (electrical sensitivity)  . . . . . . . . . . . . . . . . . 89
5.3.13 I/O current injection characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 90
5.3.14 I/O port characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 91
5.3.15 NRST pin characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 96
5.3.16 TIM timer characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 97
5.3.17 Communications interfaces . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 98
5.3.18 CAN (controller area network) interface  . . . . . . . . . . . . . . . . . . . . . . . 108
Contents STM32F103xF, STM32F103xG
4/136 DocID16554 Rev 4
5.3.19 12-bit ADC characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108
5.3.20 DAC electrical specifications . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113
5.3.21 Temperature sensor characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . 115
6 Package information . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 116
6.1 LFBGA144 package information  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .117
6.2 LQFP144 package information . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .119
6.3 LQFP100 package information . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 123
6.4 LQFP64 package information . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 126
6.5 Thermal characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129
6.5.1 Reference document . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129
6.5.2 Selecting the product temperature range  . . . . . . . . . . . . . . . . . . . . . . 130
7 Part numbering  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 132
8 Revision history  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 133
DocID16554 Rev 4 5/136
STM32F103xF, STM32F103xG List of tables
6
List of tables
Table 1. Device summary . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . 1
Table 2. STM32F103xF and STM32F103xG features and peri pheral counts  . . . . . . . . . . . . . . . . . 11
Table 3. STM32F103xx family  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14
Table 4. STM32F103xF and STM32F103xG timer feature comp arison. . . . . . . . . . . . . . . . . . . . . . 19
Table 5. STM32F103xF and STM32F103xG pin definitions. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 29
Table 6. FSMC pin definition  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 36
Table 7. Voltage characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 43
Table 8. Current characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 43
Table 9. Thermal characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 44
Table 10. General operating conditions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . 44
Table 11. Operating conditions at power-up / power-down  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45
Table 12. Embedded reset and power control block characterist ics. . . . . . . . . . . . . . . . . . . . . . . . . . 45
Table 13. Embedded internal reference voltage. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4 6
Table 14. Maximum current consumption in Run mode, code with data processing  
running from Flash . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47
Table 15. Maximum current consumption in Run mode, code with data processing  
running from RAM. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47
Table 16. Maximum current consumption in Sleep mode, code running from Flash or RAM. . . . . . . 49
Table 17. Typical and maximum current consumptions in  Stop and Standby modes  . . . . . . . . . . . . 50
Table 18. Typical current consumption in  Run mode, code with data processing 
running from Flash . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
Table 19. Typical current consumption in Sleep mode, code running from Flash or  
RAM . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 54
Table 20. Peripheral current consumption . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55
Table 21. High-speed external user clock characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58
Table 22. Low-speed external user clock characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58
Table 23. HSE 4-16 MHz oscillator characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6 0
Table 24. LSE oscillator characteristics (f LSE = 32.768 kHz) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 62
Table 25. HSI oscillator characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63
Table 26. LSI oscillator characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 64
Table 27. Low-power mode wakeup timings  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 64
Table 28. PLL characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . 65
Table 29. Flash memory characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65
Table 30. Flash memory endurance and data  retention . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 66
Table 31. Asynchronous non-multiplexed SRAM/PSRAM/NOR  read timings . . . . . . . . . . . . . . . . . . 68
Table 32. Asynchronous non-multiplexed SRAM/PSRAM/NOR write timings . . . . . . . . . . . . . . . . . . 69
Table 33. Asynchronous multiplexed read timings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 69
Table 34. Asynchronous multiplexed PSRAM/NOR read timings. . . . . . . . . . . . . . . . . . . . . . . . . . . . 70
Table 35. Asynchronous multiplexed PSRAM/NOR write timings  . . . . . . . . . . . . . . . . . . . . . . . . . . . 71
Table 36. Synchronous multiplexed NOR/PS RAM read timings  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74
Table 37. Synchronous multiplexed PSRAM write timings. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76
Table 38. Synchronous non-multiplexed NOR/PSRAM read timi ngs . . . . . . . . . . . . . . . . . . . . . . . . . 77
Table 39. Synchronous non-multiplexed PSRAM write timings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78
Table 40. Switching characteristics for PC Card/CF read and write cycles in 
attribute/common space . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 83
Table 41. Switching characteristics for PC Card/CF read and write cycles in I/O space . . . . . . . . . . 84
Table 42. Switching characteristics for NAND Flash read cycles .  . . . . . . . . . . . . . . . . . . . . . . . . . . . 86
Table 43. Switching characteristics for NAND Flash write cycles . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87
List of tables STM32F103xF, STM32F103xG
6/136 DocID16554 Rev 4
Table 44. EMS characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 88
Table 45. EMI characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . 89
Table 46. ESD absolute maximum ratings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 89
Table 47. Electrical sensitivities . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . . 90
Table 48. I/O current injection susceptibility . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 90
Table 49. I/O static characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . 91
Table 50. Output voltage characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . 93
Table 51. I/O AC characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 95
Table 52. NRST pin characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . 96
Table 53. TIMx characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . 97
Table 54. I 2C characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 98
Table 55. SCL frequency (f PCLK1= 36 MHz.,VDD_I2C = 3.3 V) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 99
Table 56. SPI characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 100
Table 57. I 2S characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 103
Table 58. SD / MMC characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 105
Table 59. USB startup time. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 106
Table 60. USB DC electrical characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 107
Table 61. USB: full-speed electrical characte ristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1 07
Table 62. ADC characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 108
Table 63. R AIN max for fADC = 14 MHz. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109
Table 64. ADC accuracy - limited test  conditions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 109
Table 65. ADC accuracy  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110
Table 66. DAC characteristics  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 113
Table 67. TS characteristics . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 115
Table 68. LFBGA144 – 144-ball low profile fine pitch ball grid array, 10 x 10 mm,  
0.8 mm pitch, package mechanical data  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 117
Table 69. LQFP144 - 144-pin, 20 x 20 mm low-profile quad flat package  
mechanical data . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  120
Table 70. LQPF100 – 14 x 14 mm 100-pin low-profile quad flat package  
mechanical data . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  123
Table 71. LQFP64 – 10 x 10 mm 64 pin low-profile quad flat package mechanical data. . . . . . . . . 126
Table 72. Package thermal characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 129
Table 73. STM32F103xF and STM32F103xG ordering informa tion scheme . . . . . . . . . . . . . . . . . . 132
DocID16554 Rev 4 7/136
STM32F103xF, STM32F103xG List of figures
8
List of figures
Figure 1. STM32F103xF and STM32F103xG performance line block diagram. . . . . . . . . . . . . . . . . 12
Figure 2. Clock tree . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . . . . 13
Figure 3. STM32F103xF/G BGA144 ballout  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25
Figure 4. STM32F103xF/G performance line LQFP144 pinout . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26
Figure 5. STM32F103xF/G performance line LQFP100 pinout . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 27
Figure 6. STM32F103xF/G performance line LQFP64 pinout . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 28
Figure 7. Memory map. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 39
Figure 8. Pin loading conditions. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
Figure 9. Pin input voltage . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . . 40
Figure 10. Power supply scheme. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41
Figure 11. Current consumption measurement scheme . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 42
Figure 12. Typical current consumption in Run mode versus frequency (at 3.6 V) - 
code with data processing running from RAM, peripherals enabled  . . . . . . . . . . . . . . . . . 48
Figure 13. Typical current consumption in  Run mode versus frequency (at 3.6 V)- 
code with data processing running from RAM, peripherals disabled   . . . . . . . . . . . . . . . . 48
Figure 14. Typical current consumption on V BAT with RTC on vs. temperature at different VBAT 
values . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50
Figure 15. Typical current consumption in Stop mode with regulator in run mode  
versus temperature at different VDD values   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
Figure 16. Typical current consumption in Stop mode with regulator in low-power 
mode versus temperature at different VDD values . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52
Figure 17. Typical current consumption in Standby mode versus temperature at 
different VDD values . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52
Figure 18. High-speed external clock source AC timing diagra m  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 59
Figure 19. Low-speed external clock source AC timing diagram.  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 59
Figure 20. Typical application with an 8 MHz crystal . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
Figure 21. Typical application with a 32.768 kHz crystal . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63
Figure 22. Asynchronous non-multip lexed SRAM/PSRAM/NOR read waveforms . . . . . . . . . . . . . . . 67
Figure 23. Asynchronous non-multiple xed SRAM/PSRAM/NOR write waveforms . . . . . . . . . . . . . . . 68
Figure 24. Asynchronous multiplexed PSRAM/NOR read wavefo rms. . . . . . . . . . . . . . . . . . . . . . . . . 70
Figure 25. Asynchronous multiplexed PSRAM/NOR write wave forms  . . . . . . . . . . . . . . . . . . . . . . . . 71
Figure 26. Synchronous multiplexed NOR/ PSRAM read timings  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 73
Figure 27. Synchronous multiplexed PSRAM write timings. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75
Figure 28. Synchronous non-multiplexed NOR/PSRAM read ti mings . . . . . . . . . . . . . . . . . . . . . . . . . 77
Figure 29. Synchronous non-multiplexed PSRAM write timings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78
Figure 30. PC Card/CompactFlash controller waveforms for common memory read access . . . . . . . 79
Figure 31. PC Card/CompactFlash co ntroller waveforms for common memory write access. . . . . . . 80
Figure 32. PC Card/CompactFlash controlle r waveforms for attribute memory read 
access. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 81
Figure 33. PC Card/CompactFlash controlle r waveforms for attribute memory write 
access. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . 82
Figure 34. PC Card/CompactFlash cont roller waveforms for I/O space read access . . . . . . . . . . . . . 82
Figure 35. PC Card/CompactFlash cont roller waveforms for I/O space write access . . . . . . . . . . . . . 83
Figure 36. NAND controller waveforms for re ad access . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85
Figure 37. NAND controller waveforms for wr ite access . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 85
Figure 38. NAND controller waveforms for common memory read access . . . . . . . . . . . . . . . . . . . . . 86
Figure 39. NAND controller waveforms for common memory wr ite access. . . . . . . . . . . . . . . . . . . . . 86
Figure 40. Standard I/O input characterist ics - CMOS port . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 92
List of figures STM32F103xF, STM32F103xG
8/136 DocID16554 Rev 4
Figure 41. Standard I/O input characteristics - TTL port . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9 2
Figure 42. 5 V tolerant I/O inpu t characteristics - CMOS port . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 92
Figure 43. 5 V tolerant I/O inpu t characteristics - TTL port  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 93
Figure 44. I/O AC characteristics definition . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 96
Figure 45. Recommended NRST pin protection  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 97
Figure 46. I 2C bus AC waveforms and measurement circuit . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 99
Figure 47. SPI timing diagram - slave mode and CPHA = 0 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101
Figure 48. SPI timing diagram - slave mode and CPHA = 1 (1)  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 101
Figure 49. SPI timing diagram - master mode (1) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 102
Figure 50. I 2S slave timing diagram (Philips protocol)(1) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 104
Figure 51. I 2S master timing diagram (Philips protocol)(1) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 104
Figure 52. SDIO high-speed mode  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 105
Figure 53. SD default mode . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 105
Figure 54. USB timings: definition of data signal rise and fall time  . . . . . . . . . . . . . . . . . . . . . . . . . . 107
Figure 55. ADC accuracy characteristics. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 110
Figure 56. Typical connection diagram using the ADC . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 111
Figure 57. Power supply and reference decoupling (V REF+ not connected to VDDA). . . . . . . . . . . . . 111
Figure 58. Power supply and reference decoupling (V REF+ connected to VDDA). . . . . . . . . . . . . . . . 112
Figure 59. 12-bit buffered /non-buffered DAC . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 115
Figure 60. LFBGA144 – 144-ball low profile fine pitch ball grid array, 10 x 10 mm,  
0.8 mm pitch, package outline  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 117
Figure 61. LFBGA144 marking example (package top view)  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 118
Figure 62. LQFP144 - 144-pin, 20 x 20 mm low-profile quad flat package outline  . . . . . . . . . . . . . . 119
Figure 63. LQFP144 - 144-pin,20 x 20 mm low-profile quad flat package  
recommended footprint. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 121
Figure 64. LQFP144 marking example (package top view). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 122
Figure 65. LFP100 – 14 x 14 mm 100 pin low-profile quad flat package outline . . . . . . . . . . . . . . . . 123
Figure 66. LQFP100 recommended footprint  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 124
Figure 67. LQFP100 marking example (package top view). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 125
Figure 68. LFP64 – 10 x 10 mm 64 pin low-profile quad flat  package outline . . . . . . . . . . . . . . . . . . 126
Figure 69. LQFP64 - 64-pin, 10 x 10 mm low-profile quad  flat recommended footprint  . . . . . . . . . . 127
Figure 70. LQFP64 marking example (package top view). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 128
Figure 71. LQFP100 P D max vs. TA  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 131
DocID16554 Rev 4 9/136
STM32F103xF, STM32F103xG Introduction
132

## 1 Introduction
This datasheet provides the ordering information and mechanical device characteristics of 
the STM32F103xF and STM32F103xG XL-density performance line microcontrollers. For 
more details on the whole STMicroelectronics STM32F103xF/G family, please refer to 
Section 2.2: Full compatibility throughout the family.
The XL-density STM32F103xF/G datasheet should be read in conjunction with the 
STM32F10xxx reference manual. 
For information on programming, erasing and protection of the internal Flash memory 
please refer to the STM32F10xxx Flash programming manual. 
The reference and Flash programming manuals are both available from the 
STMicroelectronics website www.st.com.
For information on the Cortex®-M3 core please refer to the Cortex®-M3 Technical Reference 
Manual, available from the www.arm.com website at the following address: 
http://infocenter.arm.com.
          

Description STM32F103xF, STM32F103xG
10/136 DocID16554 Rev 4

## 2 Description
The STM32F103xF and STM32F103xG performance line family incorporates the high-
performance ARM® Cortex®-M3 32-bit RISC core operating at a 72 MHz frequency, high-
speed embedded memories (Flash memory up to 1 Mbyte and SRAM up to 96 Kbytes), and 
an extensive range of enhanced I/Os and peripherals connected to two APB buses. All 
devices offer three 12-bit ADCs, ten general-purpose 16-bit timers plus two PWM timers, as 
well as standard and advanced communication interfaces: up to two I2Cs, three SPIs, two 
I2Ss, one SDIO, five USARTs, an USB and a CAN.
The STM32F103xF/G XL-density performance line family operates in the –40 to +105 °C 
temperature range, from a 2.0 to 3.6 V power supply. A comprehensive set of power-saving 
mode allows the design of low-power applications.
These features make the STM32F103xF/G high-density performance line microcontroller 
family suitable for a wide range of applications such as motor drives, application control, 
medical and handheld equipment, PC and gaming peripherals, GPS platforms, industrial 
applications, PLCs, inverters, printers, scanners, alarm systems and video intercom.
DocID16554 Rev 4 11/136
STM32F103xF, STM32F103xG Description
132

## 2.1 Device overview
The STM32F103xF/G XL-density performance line family offers devices in four different 
package types: from 64 pins to 144 pins. Depending on the device chosen, different sets of 
peripherals are included, the description below gives an overview of the complete range of 
peripherals proposed in this family.
Figure 1 shows the general block diagram of the device family.
          
Table 2. STM32F103xF and STM32F103xG features and peripheral counts
Peripherals STM32F103Rx STM32F103Vx STM32F103Zx
Flash memory 768 KB 1 MB 768 KB 1 MB 768 KB 1 MB
SRAM in Kbytes 96 96 96
FSMC No Yes (1)
1. For the LQFP100 package, only FSMC Bank1 and Bank2 are available. Bank1 can only support a 
multiplexed NOR/PSRAM memory using the NE1 Chip Select. Bank2 can only support a 16- or 8-bit NAND 
Flash memory using the NCE2 Chip Select. The interrupt line cannot be used since Port G is not available 
in this package.
Yes
Timers
General-purpose 10
Advanced-control 2
Basic 2
Comm
SPI(I2S)(2)
2. The SPI2 and SPI3 interfaces give the flexibility to wo rk in an exclusive way in either the SPI mode or the 
I2S audio mode.
3(2)
I2C2
USART 5
USB 1
CAN 1
SDIO 1
GPIOs 51 80 112
12-bit ADC  
Number of channels
3
16
3
16
3
21
12-bit DAC 
Number of channels
2
2
CPU frequency 72 MHz
Operating voltage 2.0 to 3.6 V
Operating temperatures Ambient temperatures: –40 to +85 °C /–40 to +105 °C (see Table 10)Junction temperature: –40 to + 125 °C (see Table 10)
Package LQFP64 LQFP 100 LQFP144, BGA144
Description STM32F103xF, STM32F103xG
12/136 DocID16554 Rev 4
Figure 1. STM32F103xF and STM32F103xG performance line block diagram
1. T A = –40 °C to +85 °C (suffix 6, see Table 73) or –40 °C to +105 °C (suffix 7, see Table 73), junction temperature up to 105 °C or 125 °C, respectively.
2. AF = alternate function on I/O port pin.9
3$>@
(;7,7
::'*
19,&
ELW $'&
 $',1V FRPPRQ
-7',
-7&.6:&/.
-7066:'$7
1-7567
-7'2
  WR 9
$)
$+%
026,6'0,62
:.83
)PD[0+]
966
6&/6'$60%$,&
*3 '0$
;7$/ 26&
0+]
;7$/N+]
$3% )PD[  0 +]
+&/.
3&/.
DV $)
)ODVK.%
92/7 5(*
9729
32:(5
%DFNXS LQWHUIDFH
DV $)
%XVPDWUL[
ELW
57&
5&+6
&RUWH[0&38
,EXV
'EXV
REO
65$0%
86$57
86$57
63,,6
E[&$1GHYLFH
FKDQQHOV
%DFNXS
UHJ
FKDQQHOV
7,0FRPSO
6&/6'$60%$,&
DV $)
5;7;&76 57686$57
7HPS VHQVRU
& K( 75DV$)
)&/.
5&/6
6WDQGE\
,:'*
\#96:
325  3'5
6833/<
\#9''$
9%$7 9 WR 9
&. DV $)
5;7; &76576
&. DV $)
5;7;&76576
&. DV $)
$3% )PD[    0+]
19,&
63,026,0,626&.166DV $)
ELW $'&
,)
,)
LQWHUIDFH
683(59,6,21
39'
5HVHW
,QW
$:8
325
7$03(557&
6\VWHP
6&.&.166:6
8$57
5;7; DV $)8$57
5;7;DV $)
5HVHW	
FORFN
FRQWUROOHU
3&/.
3//
ELW '$&,),)
,)
ELW '$&
'$&B287DV$)
WRWKH$' & V
$',1V FRPPRQ
WR WKH$'&	
*3 '0$
FKDQQHOV
$/$50287
0&/. DV $)
026,6'0,62
6&.&.166:6
0&/. DV $)
6:-7$*
73,8 (70
7UDFH7ULJ
75$&(&/.
75$&(>@
DV$)
6',2
)60&
3&/.
65$0
.E\WH
ELW
ELW $'& ,)
$' ,1 VRQ$' & 

FRPSO
%.,1(75LQSXWDV$)
3%>@
3&>@
3'>@
3(>@
3)>@
3*>@
038
D V $ )
D V $ )
D V $ )
& K( 75DV$)
& K(7 5DV$)
& K
'>@ &0'
&. DV $)
)ODVK.%
$>@
'>@
&/.
12(
1:(
1(>@
1%/>@
1:$,7
1/
DV$)
FKDQQHOV
FKDQQHOV
FKDQQHOV
FKDQQHOV
FKDQQHO
FKDQQHO
7,0
7,0
7,0
7,0
95()
95()±
7,0
7,0
7,0
7,0
7,0
7,0
7,0
7,0
7,0
26&B,1
26&B287
26&B,1
26&B287
9''
\#9''
1567
9''$966$
9''
\#9''
\#9''$
\#9''$
)ODVK
LQWHUIDFH
)ODVK
LQWHUIDFH
REO
FKDQQHOVDV$)
FKDQQHODV$)
FKDQQHODV$)
DL9
\#9''$
*3,2SRUW$
*3,2SRUW%
*3,2SRUW&
*3,2SRUW'
*3,2SRUW(
*3,2SRUW)
*3,2SRUW*
$3% $3% $3%
%.,1(75LQSXWDV$)
86%)6GHYLFH
63,,6
'$&B287DV$)
86%B'3&$1B7;
86%B'0&$1B5;
DocID16554 Rev 4 13/136
STM32F103xF, STM32F103xG Description
132
Figure 2. Clock tree
1. When the HSI is used as a PLL clock input, the maxi mum system clock frequency that can be achieved is 
64 MHz.
2. For the USB function to be available, both HSE and PLL must be enabled, with the USBCLK at 48 MHz.
3. To have an ADC conversion time of 1 µs, APB2 must be at 14 MHz, 28 MHz or 56 MHz.
DL
+6(26&
0+]
26&B,1
26&B287
26&B,1
26&B287
/6(26&
N+]
+6,5&
0+]
/6,5&
N+]
WR,QGHSHQGHQW:DWFKGRJ,:'*
3//
[[[
3//08/
+6( +LJKVSHHGH[WHUQDOFORFNVLJQDO
/6( 
/6, 
+6, 
/HJHQG
0&2
&ORFN2XWSXW
0DLQ
3//;735(

[ $+%
3UHVFDOHU

 3//&/.
+6,
+6(
$3%
3UHVFDOHU

$'&
3UHVFDOHU
 $'&&/.
3&/.
+&/.
3//&/.
WR$+%EXVFRUH
PHPRU\DQG'0$
86%&/.
WR86%LQWHUIDFH
86%
3UHVFDOHU

WR$'&RU
/6(
/6,
+6,


+6,
+6(
SHULSKHUDOV
WR$3%
3HULSKHUDO&ORFN
(QDEOH
(QDEOH
3HULSKHUDO&ORFN
$3%
3UHVFDOHU

3&/.
7,0 WR7,0DQG7,0
SHULSKHUDOVWR$3%
3HULSKHUDO&ORFN
(QDEOH
(QDEOH
3HULSKHUDO&ORFN
0+]
0+]PD[
0+]
0+]PD[
0+]PD[
WR57&
3//65& 6:
0&2
&66
WR&RUWH[6\VWHPWLPHU
&ORFN
(QDEOH
6<6&/.
PD[
57&&/.
57&6(/>@
7,0[&/.
7,0[&/.
,:'*&/.
6<6&/.
)&/.&RUWH[
IUHHUXQQLQJFORFN

7,0 WR7,0DQG7,0
7R6',2$+%LQWHUIDFH
3HULSKHUDOFORFN
HQDEOH
+&/.
WR)60&)60&&/.
WR6',2
3HULSKHUDOFORFN
HQDEOH
3HULSKHUDOFORFN
HQDEOH
WR,6
WR,6
3HULSKHUDOFORFN
HQDEOH
3HULSKHUDOFORFN
HQDEOH
,6&/.
,6&/.
6',2&/.
,I$3%SUHVFDOHU [
HOVH[
,I$3%SUHVFDOHU [
HOVH[
+LJKVSHHGLQWHUQDOFORFNVLJQDO
/RZVSHHGLQWHUQDOFORFNVLJQDO
/RZVSHHGH[WHUQDOFORFNVLJQDO
)/,7)&/.
WR)ODVKSURJUDPPLQJLQWHUIDFH
Description STM32F103xF, STM32F103xG
14/136 DocID16554 Rev 4

## 2.2 Full compatibility throughout the family
The STM32F103xF/G is a complete family whose members are fully pin-to-pin, software 
and feature compatible. In the reference manual, the STM32F103x4 and STM32F103x6 are 
identified as low-density devices, the STM32F103x8 and STM32F103xB are referred to as 
medium-density devices, the STM32F103xF, STM32F103xD and STM32F103xG are 
referred to as high-density devices and the STM32F103xF and STM32F103xG are called 
XL-density devices.
Low-density, high-density and XL-density devices are an extension of the STM32F103x8/B 
medium-density devices, they are specified in the STM32F103x4/6, STM32F103xC/D/E 
and STM32F103xF/G datasheets, respectively. Low-density devices feature lower Flash 
memory and RAM capacities, less timers and peripherals. High-density devices have higher 
Flash memory and RAM capacities, and additional peripherals like SDIO, FSMC, I2S and 
DAC. XL-density devices bring even more Flash and RAM memory, and extra features, 
namely an MPU, a greater number of timers and a dual bank Flash structure while 
remaining fully compatible with the other members of the family.
The STM32F103x4, STM32F103x6, STM32F103xF, STM32F103xD, STM32F103xG, 
STM32F103xF and STM32F103xG are a drop-in replacement for the STM32F103x8/B 
devices, allowing the user to try different memory densities and providing a greater degree 
of freedom during the development cycle.
Moreover, the STM32F103xx performance line family is fully compatible with all existing 
STM32F101xx access line and STM32F102xx USB access line devices.
          
Table 3. STM32F103xx family
Pinout
Low-density 
devices
Medium-density 
devices High-density devices XL-density devices
16 KB 
Flash
32 KB 
Flash(1)
64 KB 
Flash
128 KB 
Flash
256 KB 
Flash
384 KB 
Flash
512 KB 
Flash 768 KB Flash 1 MB Flash
6 KB 
RAM
10 KB 
RAM
20 KB 
RAM
20 KB 
RAM
48 or 
64 KB(2) 
RAM
64 KB 
RAM
64 KB 
RAM 96 KB RAM 96 KB RAM
144 5 × USARTs 
4 × 16-bit timers, 
2 × basic timers 
3 × SPIs, 2 × I2Ss, 2 × I2Cs 
USB, CAN, 2 × PWM timers 
3 × ADCs, 2 × DACs, 
1 × SDIO 
FSMC (100- and 144-pin 
packages(3))
5 × USARTs 
10 × 16-bit timers, 
2 × basic timers 
3 × SPIs, 2 × I2Ss, 2 × I2Cs 
USB, CAN, 2 × PWM timers 
3 × ADCs, 2 × DACs, 1 × 
SDIO, Cortex-M3 with MPU 
FSMC (100- and 144-pin 
packages(4)), dual bank Flash 
memory
100
3 × USARTs 
3 × 16-bit timers 
2 × SPIs, 2 × I2Cs, 
USB, CAN, 
1 × PWM timer 
2 × ADCs
64
2 × USARTs 
2 × 16-bit timers 
1 × SPI, 1 × I2C, 
USB, CAN, 
1 × PWM timer 
2 × ADCs48
36
1. For orderable part numbers that do not show the A internal code after the temperature range code (6 or 7), the reference 
datasheet for electrical characteristics is that of the STM32F103x8/B medium-density devices.
2. 64 KB RAM for 256 KB Flash are available on devices delivered in CSP packages only.
3. Ports F and G are not available in devices delivered in 100-pin packages. 
4. Ports F and G are not available in devices delivered in 100-pin packages. 
DocID16554 Rev 4 15/136
STM32F103xF, STM32F103xG Description
132

## 2.3 Overview

### 2.3.1 ARM ® Cortex®-M3 core with embedded Flash and SRAM
The ARM Cortex®-M3 processor is the latest generation of ARM processors for embedded 
systems. It has been developed to provide a low-cost platform that meets the needs of MCU 
implementation, with a reduced pin count and low-power consumption, while delivering 
outstanding computational performance and an advanced system response to interrupts.
The ARM Cortex®-M3 32-bit RISC processor features exceptional code-efficiency, 
delivering the high-performance expected from an ARM core in the memory size usually 
associated with 8- and 16-bit devices.
With its embedded ARM core, STM32F103xF and STM32F103xG performance line family 
is compatible with all ARM tools and software.
Figure 1 shows the general block diagram of the device family.

### 2.3.2 Memory protection unit
The memory protection unit (MPU) is used to separate the processing of tasks from the data 
protection. The MPU can manage up to 8 protection areas that can all be further divided up 
into 8 subareas. The protection area sizes are between 32 bytes and the whole 4 gigabytes 
of addressable memory.
The memory protection unit is especially helpful for applications where some critical or 
certified code has to be protected against the misbehavior of other tasks. It is usually 
managed by an RTOS (real-time operating system). If a program accesses a memory 
location that is prohibited by the MPU, the RTOS can detect it and take action. In an RTOS 
environment, the kernel can dynamically update the MPU area setting, based on the 
process to be executed.
The MPU is optional and can be bypassed for applications that do not need it.

### 2.3.3 Embedded Flash memory
768 Kbytes to 1 Mbyte of embedded Flash are available for storing programs and data. The 
Flash memory is organized as two banks. The first bank has a size of 512 Kbytes. The 
second bank is either 256 or 512 Kbytes depending on the device. This gives the device the 
capability of writing to one bank while executing code from the other bank (read-while-write 
capability).

### 2.3.4 CRC (cyclic redundan cy check) calculation unit
The CRC (cyclic redundancy check) calculation unit is used to get a CRC code from a 32-bit 
data word and a fixed generator polynomial.
Among other applications, CRC-based techniques are used to verify data transmission or 
storage integrity. In the scope of the EN/IEC 60335-1 standard, they offer a means of 
verifying the Flash memory integrity. The CRC calculation unit helps compute a signature of 
the software during runtime, to be compared with a reference signature generated at link-
time and stored at a given memory location.
Description STM32F103xF, STM32F103xG
16/136 DocID16554 Rev 4

### 2.3.5 Embedded SRAM
96 Kbytes of embedded SRAM accessed (read/write) at CPU clock speed with 0 wait states.

### 2.3.6 FSMC (flexible static memory controller)
The FSMC is embedded in the STM32F103xF and STM32F103xG performance line family. 
It has four Chip Select outputs supporting the following modes: PC Card/Compact Flash, 
SRAM, PSRAM, NOR and NAND.
Functionality overview:
• The three FSMC interrupt lines are ORed in order to be connected to the NVIC
• Write FIFO
• Code execution from external memory except for NAND Flash and PC Card
• The targeted frequency, fCLK, is HCLK/2, so external access is at 36 MHz when HCLK 
is at 72 MHz and external access is at 24 MHz when HCLK is at 48 MHz

### 2.3.7 LCD parallel interface
The FSMC can be configured to interface seamlessly with most graphic LCD controllers. It 
supports the Intel 8080 and Motorola 6800 modes, and is flexible enough to adapt to 
specific LCD interfaces. This LCD parallel interface capability makes it easy to build cost-
effective graphic applications using LCD modules with embedded controllers or high-
performance solutions using external controllers with dedicated acceleration.

### 2.3.8 Nested vectored interrupt controller (NVIC)
The STM32F103xF and STM32F103xG performance line embeds a nested vectored 
interrupt controller able to handle up to 60 maskable interrupt channels (not including the 16 
interrupt lines of Cortex®-M3) and 16 priority levels. 
• Closely coupled NVIC gives low latency interrupt processing
• Interrupt entry vector table address passed directly to the core
• Closely coupled NVIC core interface
• Allows early processing of interrupts
• Processing of late arriving higher priority interrupts
• Support for tail-chaining
• Processor state automatically saved
• Interrupt entry restored on interrupt exit with no instruction overhead
This hardware block provides flexible interrupt management features with minimal interrupt 
latency.

### 2.3.9 External interrupt /event controller (EXTI)
The external interrupt/event controller consists of 19 edge detector lines used to generate 
interrupt/event requests. Each line can be independently configured to select the trigger 
event (rising edge, falling edge, both) and can be masked independently. A pending register 
maintains the status of the interrupt requests. The EXTI can detect an external line with a 
pulse width shorter than the Internal APB2 clock period. Up to 112 GPIOs can be connected 
to the 16 external interrupt lines.
DocID16554 Rev 4 17/136
STM32F103xF, STM32F103xG Description
132

### 2.3.10 Clocks and startup
System clock selection is performed on startup, however the internal RC 8 MHz oscillator is 
selected as default CPU clock on reset. An external 4-16 MHz clock can be selected, in 
which case it is monitored for failure. If failure is detected, the system automatically switches 
back to the internal RC oscillator. A software interrupt is generated if enabled. Similarly, full 
interrupt management of the PLL clock entry is available when necessary (for example with 
failure of an indirectly used external oscillator).
Several prescalers allow the configuration of the AHB frequency, the high speed APB 
(APB2) and the low speed APB (APB1) domains. The maximum frequency of the AHB and 
the high speed APB domains is 72 MHz. The maximum allowed frequency of the low speed 
APB domain is 36 MHz. See Figure 2 for details on the clock tree.

### 2.3.11 Boot modes
At startup, boot pins are used to select one of three boot options:
• Boot from user Flash: you have an option to boot from any of two memory banks. By 
default, boot from Flash memory bank 1 is selected. You can choose to boot from Flash 
memory bank 2 by setting a bit in the option bytes.
• Boot from system memory
• Boot from embedded SRAM
The boot loader is located in system memory. It is used to reprogram the Flash memory by 
using USART1. 

### 2.3.12 Power supply schemes
• VDD = 2.0 to 3.6 V: external power supply for I/Os and the internal regulator.  
Provided externally through VDD pins.
• VSSA, VDDA = 2.0 to 3.6 V: external analog power supplies for ADC, DAC, Reset 
blocks, RCs and PLL (minimum voltage to be applied to VDDA is 2.4 V when the ADC 
or DAC is used). VDDA and VSSA must be connected to VDD and VSS, respectively.
• VBAT = 1.8 to 3.6 V: power supply for RTC, external clock 32 kHz oscillator and backup 
registers (through power switch) when VDD is not present.
For more details on how to connect power pins, refer to Figure 10: Power supply scheme.

### 2.3.13 Power supply supervisor
The device has an integrated power-on reset (POR)/power-down reset (PDR) circuitry. It is 
always active, and ensures proper operation starting from/down to 2 V. The device remains 
in reset mode when VDD is below a specified threshold, VPOR/PDR, without the need for an 
external reset circuit.
The device features an embedded programmable voltage detector (PVD) that monitors the 
VDD/VDDA power supply and compares it to the VPVD threshold. An interrupt can be 
generated when VDD/VDDA drops below the VPVD threshold and/or when VDD/VDDA is 
higher than the VPVD threshold. The interrupt service routine can then generate a warning 
message and/or put the MCU into a safe state. The PVD is enabled by software. Refer to 
Table 12: Embedded reset and power control block characteristics for the values of 
VPOR/PDR and VPVD.
Description STM32F103xF, STM32F103xG
18/136 DocID16554 Rev 4

### 2.3.14 Voltage regulator
The regulator has three operation modes: main (MR), low-power (LPR) and power down.
• MR is used in the nominal regulation mode (Run) 
• LPR is used in the Stop modes.
• Power down is used in Standby mode: the regulator output is in high impedance: the 
kernel circuitry is powered down, inducing zero consumption (but the contents of the 
registers and SRAM are lost)
This regulator is always enabled after reset. It is disabled in Standby mode.

### 2.3.15 Low-power modes
The STM32F103xF and STM32F103xG performance line supports three low-power modes 
to achieve the best compromise between low-power consumption, short startup time and 
available wakeup sources:
• Sleep mode
In Sleep mode, only the CPU is stopped. All peripherals continue to operate and can 
wake up the CPU when an interrupt/event occurs.
• Stop mode
Stop mode achieves the lowest power consumption while retaining the content of 
SRAM and registers. All clocks in the 1.8 V domain are stopped, the PLL, the HSI RC 
and the HSE crystal oscillators are disabled. The voltage regulator can also be put 
either in normal or in low-power mode.  
The device can be woken up from Stop mode by any of the EXTI line. The EXTI line 
source can be one of the 16 external lines, the PVD output, the RTC alarm or the USB 
wakeup. 
• Standby mode
The Standby mode is used to achieve the lowest power consumption. The internal 
voltage regulator is switched off so that the entire 1.8 V domain is powered off. The 
PLL, the HSI RC and the HSE crystal oscillators are also switched off. After entering 
Standby mode, SRAM and register contents are lost except for registers in the Backup 
domain and Standby circuitry. 
The device exits Standby mode when an external reset (NRST pin), an IWDG reset, a 
rising edge on the WKUP pin, or an RTC alarm occurs.
Note: The RTC, the IWDG, and the corresponding clock sources are not stopped by entering Stop 
or Standby mode.

### 2.3.16 DMA
The flexible 12-channel general-purpose DMAs (7 channels for DMA1 and 5 channels for 
DMA2) are able to manage memory-to-memory, peripheral-to-memory and memory-to-
peripheral transfers. The two DMA controllers support circular buffer management, 
removing the need for user code intervention when the controller reaches the end of the 
buffer.
Each channel is connected to dedicated hardware DMA requests, with support for software 
trigger on each channel. Configuration is made by software and transfer sizes between 
source and destination are independent.
DocID16554 Rev 4 19/136
STM32F103xF, STM32F103xG Description
132
The DMA can be used with the main peripherals: SPI, I2C, USART, general-purpose, basic 
and advanced-control timers TIMx, DAC, I2S, SDIO and ADC.

### 2.3.17 RTC (real-time cl ock) and backup registers
The RTC and the backup registers are supplied through a switch that takes power either on 
VDD supply when present or through the VBAT pin. The backup registers are forty-two 16-bit 
registers used to store 84 bytes of user application data when VDD power is not present. 
They are not reset by a system or power reset, and they are not reset when the device 
wakes up from the Standby mode.
The real-time clock provides a set of continuously running counters which can be used with 
suitable software to provide a clock calendar function, and provides an alarm interrupt and a 
periodic interrupt. It is clocked by a 32.768 kHz external crystal, resonator or oscillator, the 
internal low-power RC oscillator or the high-speed external clock divided by 128. The 
internal low-speed RC has a typical frequency of 40 kHz. The RTC can be calibrated using 
an external 512 Hz output to compensate for any natural quartz deviation. The RTC features 
a 32-bit programmable counter for long term measurement using the Compare register to 
generate an alarm. A 20-bit prescaler is used for the time base clock and is by default 
configured to generate a time base of 1 second from a clock at 32.768 kHz. 

### 2.3.18 Timers and watchdogs
The XL-density STM32F103xF/G performance line devices include up to two advanced-
control timers, up to ten general-purpose timers, two basic timers, two watchdog timers and 
a SysTick timer.
Table 4 compares the features of the advanced-control, general-purpose and basic timers.
          
Table 4. STM32F103xF and STM32F103xG timer feature comparison
Timer Counter resolution Counter type Prescaler factor DMA request generation Capture/compare channels Complementaryoutputs
TIM1, TIM8 16-bit
Up, 
down, 
up/down
Any integer between 
1 and 65536 Yes 4 Yes
TIM2, TIM3, 
TIM4, TIM5 16-bit
Up, 
down, 
up/down
Any integer between 
1 and 65536 Yes 4 No
TIM9, TIM12 16-bit Up Any integer between 1 and 65536 No 2 No
TIM10, TIM11 
TIM13, TIM14 16-bit Up Any integer between 1 and 65536 No 1 No
TIM6, TIM7 16-bit Up Any integer between 1 and 65536 Yes 0 No
Description STM32F103xF, STM32F103xG
20/136 DocID16554 Rev 4
Advanced-control timers (TIM1 and TIM8)
The two advanced-control timers (TIM1 and TIM8) can each be seen as a three-phase 
PWM multiplexed on 6 channels. They have complementary PWM outputs with 
programmable inserted dead-times. They can also be seen as a complete general-purpose 
timer. The 4 independent channels can be used for:
• Input capture
• Output compare
• PWM generation (edge or center-aligned modes)
• One-pulse mode output
If configured as a standard 16-bit timer, it has the same features as the TIMx timer. If 
configured as the 16-bit PWM generator, it has full modulation capability (0-100%). 
In debug mode, the advanced-control timer counter can be frozen and the PWM outputs 
disabled to turn off any power switch driven by these outputs.
Many features are shared with those of the general-purpose TIM timers which have the 
same architecture. The advanced-control timer can therefore work together with the TIM 
timers via the Timer Link feature for synchronization or event chaining. 
General-purpose timers (TIMx)
There are10 synchronizable general-purpose timers embedded in the STM32F103xF and 
STM32F103xG performance line devices (see Table 4 for differences).
• TIM2, TIM3, TIM4, TIM5
There are up to 4 synchronizable general-purpose timers (TIM2, TIM3, TIM4 and TIM5) 
embedded in the STM32F103xF and STM32F103xG access line devices.
These timers are based on a 16-bit auto-reload up/down counter, a 16-bit prescaler 
and feature 4 independent channels each for input capture/output compare, PWM or 
one-pulse mode output. This gives up to 16 input captures / output compares / PWMs 
on the largest packages.
Their counter can be frozen in debug mode. Any of the general-purpose timers can be 
used to generate PWM outputs. They all have independent DMA request generation.
These timers are capable of handling quadrature (incremental) encoder signals and the 
digital outputs from 1 to 3 hall-effect sensors.
• TIM10, TIM11 and TIM9
These timers are based on a 16-bit auto-reload upcounter and a 16-bit prescaler. 
TIM10 and TIM11 feature one independent channel, whereas TIM9 has two 
independent channels for input capture/output compare, PWM or one-pulse mode 
output. They can be synchronized with the TIM2, TIM3, TIM4, TIM5 full-featured 
general-purpose timers. They can also be used as simple time bases.
• TIM13, TIM14 and TIM12
These timers are based on a 16-bit auto-reload upcounter and a 16-bit prescaler. 
TIM13 and TIM14 feature one independent channel, whereas TIM12 has two 
independent channels for input capture/output compare, PWM or one-pulse mode 
output. They can be synchronized with the TIM2, TIM3, TIM4, TIM5 full-featured 
general-purpose timers. They can also be used as simple time bases.
DocID16554 Rev 4 21/136
STM32F103xF, STM32F103xG Description
132
Basic timers TIM6 and TIM7
These timers are mainly used for DAC trigger generation. They can also be used as a 
generic 16-bit time base.
Independent watchdog
The independent watchdog is based on a 12-bit downcounter and 8-bit prescaler. It is 
clocked from an independent 40 kHz internal RC and as it operates independently from the 
main clock, it can operate in Stop and Standby modes. It can be used either as a watchdog 
to reset the device when a problem occurs, or as a free running timer for application timeout 
management. It is hardware or software configurable through the option bytes. The counter 
can be frozen in debug mode.
Window watchdog
The window watchdog is based on a 7-bit downcounter that can be set as free running. It 
can be used as a watchdog to reset the device when a problem occurs. It is clocked from 
the main clock. It has an early warning interrupt capability and the counter can be frozen in 
debug mode.
SysTick timer
This timer is dedicated to real-time operating systems, but could also be used as a standard 
down counter. It features:
• A 24-bit down counter
• Autoreload capability
• Maskable system interrupt generation when the counter reaches 0.
• Programmable clock source 

### 2.3.19 I²C bus
Up to two I²C bus interfaces can operate in multimaster and slave modes. They can support 
standard and fast modes. 
They support 7/10-bit addressing mode and 7-bit dual addressing mode (as slave). A 
hardware CRC generation/verification is embedded.
They can be served by DMA and they support SMBus 2.0/PMBus.

### 2.3.20 Universal synchr onous/asynchronous receiver transmitters (USARTs)
The STM32F103xF and STM32F103xG performance line embeds three universal 
synchronous/asynchronous receiver transmitters (USART1, USART2 and USART3) and 
two universal asynchronous receiver transmitters (UART4 and UART5).
These five interfaces provide asynchronous communication, IrDA SIR ENDEC support, 
multiprocessor communication mode, single-wire half-duplex communication mode and 
have LIN Master/Slave capability.
The USART1 interface is able to communicate at speeds of up to 4.5 Mbit/s. The other 
available interfaces communicate at up to 2.25 Mbit/s.
USART1, USART2 and USART3 also provide hardware management of the CTS and RTS 
signals, Smart Card mode (ISO 7816 compliant) and SPI-like communication capability. All 
interfaces can be served by the DMA controller except for UART5.
Description STM32F103xF, STM32F103xG
22/136 DocID16554 Rev 4

### 2.3.21 Serial peripheral interface (SPI)
Up to three SPIs are able to communicate up to 18 Mbits/s in slave and master modes in 
full-duplex and simplex communication modes. The 3-bit prescaler gives 8 master mode 
frequencies and the frame is configurable to 8 bits or 16 bits. The hardware CRC 
generation/verification supports basic SD Card/MMC modes. 
All SPIs can be served by the DMA controller.

### 2.3.22 Inter-integrated sound (I 2S)
Two standard I2S interfaces (multiplexed with SPI2 and SPI3) are available, that can be 
operated in master or slave mode. These interfaces can be configured to operate with 16/32 
bit resolution, as input or output channels. Audio sampling frequencies from 8 kHz up to 
48 kHz are supported. When either or both of the I2S interfaces is/are configured in master 
mode, the master clock can be output to the external DAC/CODEC at 256 times the 
sampling frequency.

### 2.3.23 SDIO
An SD/SDIO/MMC host interface is available, that supports MultiMediaCard System 
Specification Version 4.2 in three different databus modes: 1-bit (default), 4-bit and 8-bit. 
The interface allows data transfer at up to 48 MHz in 8-bit mode, and is compliant with SD 
Memory Card Specifications Version 2.0. 
The SDIO Card Specification Version 2.0 is also supported with two different databus 
modes: 1-bit (default) and 4-bit.
The current version supports only one SD/SDIO/MMC4.2 card at any one time and a stack 
of MMC4.1 or previous.
In addition to SD/SDIO/MMC, this interface is also fully compliant with the CE-ATA digital 
protocol Rev1.1.

### 2.3.24 Controller area network (CAN)
The CAN is compliant with specifications 2.0A and B (active) with a bit rate up to 1 Mbit/s. It 
can receive and transmit standard frames with 11-bit identifiers as well as extended frames 
with 29-bit identifiers. It has three transmit mailboxes, two receive FIFOs with 3 stages and 
14 scalable filter banks.

### 2.3.25 Universal serial bus (USB)
The STM32F103xF and STM32F103xG performance line embed a USB device peripheral 
compatible with the USB full-speed 12 Mbs. The USB interface implements a full-speed (12 
Mbit/s) function interface. It has software-configurable endpoint setting and suspend/resume 
support. The dedicated 48 MHz clock is generated from the internal main PLL (the clock 
source must use a HSE crystal oscillator).

### 2.3.26 GPIOs (general- purpose inputs/outputs)
Each of the GPIO pins can be configured by software as output (push-pull or open-drain), as 
input (with or without pull-up or pull-down) or as peripheral alternate function. Most of the 
GPIO pins are shared with digital or analog alternate functions. All GPIOs are high current-
capable.
DocID16554 Rev 4 23/136
STM32F103xF, STM32F103xG Description
132
The I/Os alternate function configuration can be locked if needed following a specific 
sequence in order to avoid spurious writing to the I/Os registers.

### 2.3.27 ADC (analog to digital converter)
Three 12-bit analog-to-digital converters are embedded into STM32F103xF and 
STM32F103xG performance line devices and each ADC shares up to 21 external channels, 
performing conversions in single-shot or scan modes. In scan mode, automatic conversion 
is performed on a selected group of analog inputs.
Additional logic functions embedded in the ADC interface allow:
• Simultaneous sample and hold
• Interleaved sample and hold
• Single shunt
The ADC can be served by the DMA controller.
An analog watchdog feature allows very precise monitoring of the converted voltage of one, 
some or all selected channels. An interrupt is generated when the converted voltage is 
outside the programmed thresholds.
The events generated by the general-purpose timers (TIMx) and the advanced-control 
timers (TIM1 and TIM8) can be internally connected to the ADC start trigger and injection 
trigger, respectively, to allow the application to synchronize A/D conversion and timers.

### 2.3.28 DAC (digital-to-analog converter)
The two 12-bit buffered DAC channels can be used to convert two digital signals into two 
analog voltage signal outputs. The chosen design structure is composed of integrated 
resistor strings and an amplifier in inverting configuration.
This dual digital Interface supports the following features:
• two DAC converters: one for each output channel
• 8-bit or 12-bit monotonic output
• left or right data alignment in 12-bit mode
• synchronized update capability
• noise-wave generation
• triangular-wave generation
• dual DAC channel independent or simultaneous conversions
• DMA capability for each channel
• external triggers for conversion
• input voltage reference VREF+
Eight DAC trigger inputs are used in the STM32F103xF and STM32F103xG performance 
line family. The DAC channels are triggered through the timer update outputs that are also 
connected to different DMA channels.
Description STM32F103xF, STM32F103xG
24/136 DocID16554 Rev 4

### 2.3.29 Temperature sensor
The temperature sensor has to generate a voltage that varies linearly with temperature. The 
conversion range is between 2 V < VDDA < 3.6 V. The temperature sensor is internally 
connected to the ADC1_IN16 input channel which is used to convert the sensor output 
voltage into a digital value.

### 2.3.30 Serial wire JTAG debug port (SWJ-DP)
The ARM SWJ-DP Interface is embedded, and is a combined JTAG and serial wire debug 
port that enables either a serial wire debug or a JTAG probe to be connected to the target. 
The JTAG TMS and TCK pins are shared respectively with SWDIO and SWCLK and a 
specific sequence on the TMS pin is used to switch between JTAG-DP and SW-DP.

### 2.3.31 Embedded Trace Macrocell™
The ARM® Embedded Trace Macrocell provides a greater visibility of the instruction and 
data flow inside the CPU core by streaming compressed data at a very high rate from the 
STM32F10xxx through a small number of ETM pins to an external hardware trace port 
analyzer (TPA) device. The TPA is connected to a host computer using USB, Ethernet, or 
any other high-speed channel. Real-time instruction and data flow activity can be recorded 
and then formatted for display on the host computer running debugger software. TPA 
hardware is commercially available from common development tool vendors. It operates 
with third party debugger software tools.
DocID16554 Rev 4 25/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132

## 3 Pinouts and pin descriptions
Figure 3. STM32F103xF/G BGA144 ballout
1. The above figure shows the package top view. 
AI14798b
VDD_7
PC3PC2
PF6
VDD_6VSS_4PF8
H
VDD_1
D PG13
PG14
PE6PE5
C
PG10
PG11
VDD_5
PB8
NRST
B PG12PG15
PC15-
OSC32_OUT
PB9
A
87654321
VBAT
OSC_IN
OSC_OUT
VSS_5
G
F
E
PF7
PC0
PF0 PF1
PF2
VSS_10 PG9PF4PF3 VSS_3PF5
VDD_8VDD_3VDD_4
VSS_8
PE4 PB5
PB6
BOOT0 PB7
VSS_11
PF10
PC1
VDD_11 VDD_10
PF9
109
K
J
VSS_2
PD3
PD4
PD1
PC12
PC11PD5
PD2 PD0
VDD_9
VSS_9
VDD_2
PG1
PC5PA5 PE9
PB2/
BOOT1PC4PA4 PE10
PG0PF13VREF–
PE12VSSA
PA1 PE13
PA0-WKUP
PD9
PD10 PG4
PD13
1211
PG8
PA10
NC
PA9
PA11
PA12PC10
PC9 PA8
PC7
PC6
PC8
PD14
PG3 PG2
PD15
M
L PF15
PB1PA7 PE7
PF12PB0PA6 PE8
PF14PF11VDDA
PE14VREF+
PA3 PE15
PA2
PB10
PD8 PD12
PB11 PB12
PB14 PB15
PB13
PC13-
TAMPER-RTC PE3 PE2 PE1 PE0 PB4JTRST PB3JTDO PD6 PD7 PA15JTDI PA14JTCK PA13JTMS
PE11VSS_6 VSS_7 VSS_1 PG7PD11 PG5PG6
PC14-
OSC32_IN
Pinouts and pin descriptions STM32F103xF, STM32F103xG
26/136 DocID16554 Rev 4
Figure 4. STM32F103xF/G performance line LQFP144 pinout
1. The above figure shows the package top view. 
6$$?
633?
0%
0%
0"
0"
"//4
0"
0"
0"
0"
0"
0'
6$$?
633?
0'
0'
0'
0'
0'
0'
0$
0$
6$$?
633?
0$
0$
0$
0$
0$
0$
0#
0#
0#
0!  
0!  
0% 6$$?
0% 633?
0% .#
0% 0!  
0% 0!  
6"!4 0!  
0#
4 !-0%2
24# 0!  
0#
/3#?). 0! 
0#
/3#?/54 0! 
0& 0#
0& 0#
0& 0#
0& 0#
0& 6$$?
0& 633?
633? 0'
6$$? 0'
0& 0'
0& 0'
0& 0'
0& 0'
0& 0'
/3#?). 0$
/3#?/54 0$
.234 6$$?
0# 633?
0# 0$
0# 0$
0# 0$
633! 0$
62%&
 0$
62%& 0$
6$$! 0"
0!  
 7 + 5 0 0"
0!  0"
0!  0"
0! 
633?
6$$?
0! 
0! 
0! 
0! 
0#
0#
0"
0"
0"
0&
0&
633?
6$$?
0&
0&
0&
0'
0'
0%
0%
0%
633?
6$$?
0%
0%
0%
0%
0%
0%
0"
0"
633?
6$$?




































































































,1&0












































AI
DocID16554 Rev 4 27/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
Figure 5. STM32F103xF/G performance line LQFP100 pinout
1. The above figure shows the package top view. 
AI











































































6$$? 
633?  
.#  
0!      
0!      
0!      
0!      
0!     
0!     
0#  
0#  
0#  
0#  
0$  
0$  
0$  
0$  
0$  
0$  
0$  
0$  
0"  
0"  
0"  
0"  
0! 
633?
6$$?
0! 
0! 
0! 
0! 
0#
0#
0"
0"
0"
0%
0%
0%
0%
0%
0%
0%
0%
0%
0"
0"
633?
6$$?
6$$?  
633?  
0%  
0%  
0"  
0"  
"//4  
0"  
0"  
0"  
0"  
0"  
0$  
0$  
0$  
0$  
0$  
0$  
0$  
0$  
0#  
0#  
0#  
0 !  
0 ! 

























0%
0%
0%
0%
0%
6"! 4
0#
4 !-0%2
24#
0#
/3#?).
0#
/3#?/54
633?
6$$?
/3#?).
/3#?/54
.234
0#
0#
0#
0#
633!
62%&

62%&
6$$!
0!  
 7 + 5 0
0! 
0! 
,1&0
Pinouts and pin descriptions STM32F103xF, STM32F103xG
28/136 DocID16554 Rev 4
Figure 6. STM32F103xF/G performance line LQFP64 pinout
1. The above figure shows the package top view. 
ϲϰ ϲϯ ϲϮ ϲϭ ϲϬ ϱϵ ϱϴ ϱϳ ϱϲ ϱϱ ϱϰ ϱϯ ϱϮ ϱϭ ϱϬ ϰϵ
ϰϴ
ϰϳ
ϰϲ
ϰϱ
ϰϰ
ϰϯ
ϰϮ
ϰϭ
ϰϬ
ϯϵ
ϯϴ
ϯϳ
ϯϲ
ϯϱ
ϯϰ
ϯϯ
ϭϳ ϭϴ ϭϵ ϮϬ Ϯϭ ϮϮ Ϯϯ Ϯϰ Ϯϵ ϯϬ ϯϭ ϯϮϮϱ Ϯϲ Ϯϳ Ϯϴ
ϭ
Ϯ
ϯ
ϰ
ϱ
ϲ
ϳ
ϴ
ϵ
ϭϬ
ϭϭ
ϭϮ
ϭϯ
ϭϰ
ϭϱ
ϭϲ
sd
WϭϯͲdDWZͲZd
W ϭϰ ͲK ^ ϯϮ ͺ/E
W ϭϱ ͲK ^ ϯϮ ͺKh d
W  ϬͲK^ ͺ/E
W  ϭͲK^ ͺKhd
EZ^d
WϬ
Wϭ
WϮ
Wϯ
s^^
s
W Ϭ Ͳ t < h W
W ϭ
W Ϯ
sͺϯ
s^^ͺϯ
W ϵ
W ϴ
KK d Ϭ
W ϳ
W ϲ
W ϱ
W ϰ
W ϯ
WϮ
WϭϮ
Wϭϭ
WϭϬ
W ϭ ϱ
W ϭ ϰ
sͺϮ
s^^ͺϮ
W ϭ ϯ
W ϭ Ϯ
W ϭ ϭ
W ϭ Ϭ
W ϵ
W ϴ
Wϵ
Wϴ
Wϳ
Wϲ
W ϭϱ
W ϭϰ
W ϭϯ
W ϭϮ
W ϯ
s^^ͺϰ
sͺϰ
W ϰ
W ϱ
W ϲ
W ϳ
Wϰ
Wϱ
W Ϭ
W ϭ
W Ϯ
Wϭ Ϭ
Wϭ ϭ
s^^ͺϭ
sͺϭ
>Y&Wϲϰ
DL
DocID16554 Rev 4 29/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
          
Table 5. STM32F103xF and STM32F103xG pin definitions 
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
A3 - 1 1 PE2 I/O FT PE2 TRACECK / FSMC_A23 -
A2 - 2 2 PE3 I/O FT PE3 TRACED0 / FSMC_A19 -
B2 - 3 3 PE4 I/O FT PE4 TRACED1/ FSMC_A20 -
B3 - 4 4 PE5 I/O FT PE5 TRACED2/ FSMC_A21 TIM9_CH1
B4 - 5 5 PE6 I/O FT PE6 TRACED3 / FSMC_A22 TIM9_CH2
C2 1 6 6 V BAT SV BAT --
A1 2 7 7 PC13-TAMPER-RTC(5) I/O PC13 (6) TAMPER-RTC -
B1 3 8 8 PC14-OSC32_IN (5) I/O PC14 (6) OSC32_IN -
C1 4 9 9 PC15-OSC32_OUT(5) I/O PC15 (6) OSC32_OUT -
C3 - - 10 PF0 I/O FT PF0 FSMC_A0 -
C4 - - 11 PF1 I/O FT PF1 FSMC_A1 -
D4 - - 12 PF2 I/O FT PF2 FSMC_A2 -
E2 - - 13 PF3 I/O FT PF3 FSMC_A3 -
E3 - - 14 PF4 I/O FT PF4 FSMC_A4 -
E4 - - 15 PF5 I/O FT PF5 FSMC_A5 -
D2 - 10 16 V SS_5 SV SS_5 --
D3 - 11 17 V DD_5 SV DD_5 --
F3 - - 18 PF6 I/O PF6 ADC3_IN4 / FSMC_NIORD TIM10_CH1
F2 - - 19 PF7 I/O PF7 ADC3_IN5 / FSMC_NREG TIM11_CH1
G3 - - 20 PF8 I/O PF8 ADC3_IN6 / FSMC_NIOWR TIM13_CH1
G2 - - 21 PF9 I/O PF9 ADC3_IN7 / FSMC_CD TIM14_CH1
G1 - - 22 PF10 I/O PF10 ADC3_IN8 / FSMC_INTR -
D1 5 12 23 OSC_IN I OSC_IN - PD0 (7)
E1 6 13 24 OSC_OUT O OSC_OUT - PD1 (7)
F1 7 14 25 NRST I/O NRST - -
H1 8 15 26 PC0 I/O PC0 ADC123_IN10 -
H2 9 16 27 PC1 I/O PC1 ADC123_IN11 -
Pinouts and pin descriptions STM32F103xF, STM32F103xG
30/136 DocID16554 Rev 4
H3 10 17 28 PC2 I/O PC2 ADC123_IN12 -
H4 11 18 29 PC3 I/O PC3 ADC123_IN13 -
J1 12 19 30 V SSA SV SSA --
K1 - 20 31 V REF- SV REF- --
L1 - 21 32 V REF+ SV REF+ --
M1 13 22 33 V DDA SV DDA --
J2 14 23 34 PA0-WKUP I/O PA0
WKUP/USART2_CTS(8) / 
ADC123_IN0 / TIM2_CH1_ETR / 
TIM5_CH1 / TIM8_ETR
-
K2 15 24 35 PA1 I/O PA1 USART2_RTS(7) / ADC123_IN1 /TIM5_CH2 / TIM2_CH2(7) -
L2 16 25 36 PA2 I/O PA2
USART2_TX(7) / TIM5_CH3 / 
ADC123_IN2 / TIM9_CH1 / 
TIM2_CH3 (7)
-
M2 17 26 37 PA3 I/O PA3
USART2_RX(7) / TIM5_CH4 / 
ADC123_IN3 / TIM2_CH4(7)/ 
TIM9_CH2
-
G4 18 27 38 V SS_4 SV SS_4 --
F4 19 28 39 V DD_4 SV DD_4 --
J3 20 29 40 PA4 I/O PA4 SPI1_NSS(7) / USART2_CK(7) / DAC_OUT1 / ADC12_IN4 -
K3 21 30 41 PA5 I/O PA5 SPI1_SCK(7) / DAC_OUT2 / ADC12_IN5 -
L3 22 31 42 PA6 I/O PA6
SPI1_MISO(7) / TIM8_BKIN / 
ADC12_IN6 / TIM3_CH1(7)/ 
TIM13_CH1
TIM1_BKIN
M3 23 32 43 PA7 I/O PA7
SPI1_MOSI(7)/ TIM8_CH1N / 
ADC12_IN7 / TIM3_CH2(7) / 
TIM14_CH1
TIM1_CH1N
J4 24 33 44 PC4 I/O PC4 ADC12_IN14 -
K4 25 34 45 PC5 I/O PC5 ADC12_IN15 -
L4 26 35 46 PB0 I/O PB0 ADC12_IN8 / TIM3_CH3 / TIM8_CH2N TIM1_CH2N
Table 5. STM32F103xF and STM32F103xG pin definitions (continued)
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
DocID16554 Rev 4 31/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
M4 27 36 47 PB1 I/O PB1 ADC12_IN9 / TIM3_CH4(7) / TIM8_CH3N TIM1_CH3N
J5 28 37 48 PB2 I/O FT PB2/BOOT1 - -
M5 - - 49 PF11 I/O FT PF11 FSMC_NIOS16 -
L5 - - 50 PF12 I/O FT PF12 FSMC_A6 -
H5 - - 51 V SS_6 SV SS_6 --
G5 - - 52 V DD_6 SV DD_6 --
K5 - - 53 PF13 I/O FT PF13 FSMC_A7 -
M6 - - 54 PF14 I/O FT PF14 FSMC_A8 -
L6 - - 55 PF15 I/O FT PF15 FSMC_A9 -
K6 - - 56 PG0 I/O FT PG0 FSMC_A10 -
J6 - - 57 PG1 I/O FT PG1 FSMC_A11 -
M7 - 38 58 PE7 I/O FT PE7 FSMC_D4 TIM1_ETR
L7 - 39 59 PE8 I/O FT PE8 FSMC_D5 TIM1_CH1N
K7 - 40 60 PE9 I/O FT PE9 FSMC_D6 TIM1_CH1
H6 - - 61 V SS_7 SV SS_7 --
G6 - - 62 V DD_7 SV DD_7 --
J7 - 41 63 PE10 I/O FT PE10 FSMC_D7 TIM1_CH2N
H8 - 42 64 PE11 I/O FT PE11 FSMC_D8 TIM1_CH2
J8 - 43 65 PE12 I/O FT PE12 FSMC_D9 TIM1_CH3N
K8 - 44 66 PE13 I/O FT PE13 FSMC_D10 TIM1_CH3
L8 - 45 67 PE14 I/O FT PE14 FSMC_D11 TIM1_CH4
M8 - 46 68 PE15 I/O FT PE15 FSMC_D12 TIM1_BKIN
M9 29 47 69 PB10 I/O FT PB10 I2C2_SCL / USART3_TX (7) TIM2_CH3
M10 30 48 70 PB11 I/O FT PB11 I2C2_SDA / USART3_RX (7) TIM2_CH4
H7 31 49 71 V SS_1 SV SS_1 --
G7 32 50 72 V DD_1 SV DD_1 --
M11 33 51 73 PB12 I/O FT PB12
SPI2_NSS / I2S2_WS / 
I2C2_SMBA / USART3_CK(7) / 
TIM1_BKIN(7)
-
Table 5. STM32F103xF and STM32F103xG pin definitions (continued)
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
Pinouts and pin descriptions STM32F103xF, STM32F103xG
32/136 DocID16554 Rev 4
M12 34 52 74 PB13 I/O FT PB13 SPI2_SCK / I2S2_CK / USART3_CTS(7) / TIM1_CH1N -
L11 35 53 75 PB14 I/O FT PB14 SPI2_MISO / TIM1_CH2N / USART3_RTS(7)/ TIM12_CH1 -
L12 36 54 76 PB15 I/O FT PB15 SPI2_MOSI / I2S2_SD / TIM1_CH3N(7) / TIM12_CH2 -
L9 - 55 77 PD8 I/O FT PD8 FSMC_D13 USART3_TX
K9 - 56 78 PD9 I/O FT PD9 FSMC_D14 USART3_RX
J9 - 57 79 PD10 I/O FT PD10 FSMC_D15 USART3_CK
H9 - 58 80 PD11 I/O FT PD11 FSMC_A16 USART3_CTS
L10 - 59 81 PD12 I/O FT PD12 FSMC_A17 TIM4_CH1 / USART3_RTS
K10 - 60 82 PD13 I/O FT PD13 FSMC_A18 TIM4_CH2
G8 - - 83 V SS_8 SV SS_8 --
F8 - - 84 V DD_8 SV DD_8 --
K11 - 61 85 PD14 I/O FT PD14 FSMC_D0 TIM4_CH3
K12 - 62 86 PD15 I/O FT PD15 FSMC_D1 TIM4_CH4
J12 - - 87 PG2 I/O FT PG2 FSMC_A12 -
J11 - - 88 PG3 I/O FT PG3 FSMC_A13 -
J10 - - 89 PG4 I/O FT PG4 FSMC_A14 -
H12 - - 90 PG5 I/O FT PG5 FSMC_A15 -
H11 - - 91 PG6 I/O FT PG6 FSMC_INT2 -
H10 - - 92 PG7 I/O FT PG7 FSMC_INT3 -
G11 - - 93 PG8 I/O FT PG8 - -
G10 - - 94 V SS_9 SV SS_9 --
F10 - - 95 V DD_9 SV DD_9 --
G12 37 63 96 PC6 I/O FT PC6 I2S2_MCK / TIM8_CH1 / SDIO_D6 TIM3_CH1
F12 38 64 97 PC7 I/O FT PC7 I2S3_MCK / TIM8_CH2 / SDIO_D7 TIM3_CH2
F11 39 65 98 PC8 I/O FT PC8 TIM8_CH3 / SDIO_D0 TIM3_CH3
Table 5. STM32F103xF and STM32F103xG pin definitions (continued)
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
DocID16554 Rev 4 33/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
E11 40 66 99 PC9 I/O FT PC9 TIM8_CH4 / SDIO_D1 TIM3_CH4
E12 41 67 100 PA8 I/O FT PA8 USART1_CK / TIM1_CH1(7) / MCO -
D12 42 68 101 PA9 I/O FT PA9 USART1_TX (7) / TIM1_CH2(7) -
D11 43 69 102 PA10 I/O FT PA10 USART1_RX (7) / TIM1_CH3(7) -
C12 44 70 103 PA11 I/O FT PA11 USART1_CTS / USB_DM / CAN_RX(7) / TIM1_CH4(7) -
B12 45 71 104 PA12 I/O FT PA12 USART1_RTS / USB_DP / CAN_TX(7) / TIM1_ETR(7) -
A12 46 72 105 PA13 I/O FT JTMS-SWDIO -P A 1 3
C11 - 73 106 Not connected
G9 47 74 107 V SS_2 SV SS_2 --
F9 48 75 108 V DD_2 SV DD_2 --
A11 49 76 109 PA14 I/O FT JTCK-SWCLK -P A 1 4
A10 50 77 110 PA15 I/O FT JTDI SPI3_NSS / I2S3_WS TIM2_CH1_ETR PA15/ SPI1_NSS
B11 51 78 111 PC10 I/O FT PC10 UART4_TX / SDIO_D2 USART3_TX
B10 52 79 112 PC11 I/O FT PC11 UART4_RX / SDIO_D3 USART3_RX
C10 53 80 113 PC12 I/O FT PC12 UART5_TX / SDIO_CK USART3_CK
E10 - 81 114 PD0 I/O FT PD0 FSMC_D2 (9) CAN_RX
D10 - 82 115 PD1 I/O FT PD1 FSMC_D3 (9) CAN_TX
E9 54 83 116 PD2 I/O FT PD2 TIM3_ETR / UART5_RX / SDIO_CMD -
D9 - 84 117 PD3 I/O FT PD3 FSMC_CLK USART2_CTS
C9 - 85 118 PD4 I/O FT PD4 FSMC_NOE USART2_RTS
B9 - 86 119 PD5 I/O FT PD5 FSMC_NWE USART2_TX
E7 - - 120 V SS_10 SV SS_10 --
F7 - - 121 V DD_10 SV DD_10 --
A8 - 87 122 PD6 I/O FT PD6 FSMC_NWAIT USART2_RX
Table 5. STM32F103xF and STM32F103xG pin definitions (continued)
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
Pinouts and pin descriptions STM32F103xF, STM32F103xG
34/136 DocID16554 Rev 4
A9 - 88 123 PD7 I/O FT PD7 FSMC_NE1 / FSMC_NCE2 USART2_CK
E8 - - 124 PG9 I/O FT PG9 FSMC_NE2 / FSMC_NCE3 -
D8 - - 125 PG10 I/O FT PG10 FSMC_NCE4_1 / FSMC_NE3 -
C8 - - 126 PG11 I/O FT PG11 FSMC_NCE4_2 -
B8 - - 127 PG12 I/O FT PG12 FSMC_NE4 -
D7 - - 128 PG13 I/O FT PG13 FSMC_A24 -
C7 - - 129 PG14 I/O FT PG14 FSMC_A25 -
E6 - - 130 V SS_11 SV SS_11 --
F6 - - 131 V DD_11 SV DD_11 --
B7 - - 132 PG15 I/O FT PG15 - -
A7 55 89 133 PB3 I/O FT JTDO SPI3_SCK / I2S3_CK/
PB3/TRACESWO
TIM2_CH2 / 
SPI1_SCK
A6 56 90 134 PB4 I/O FT NJTRST SPI3_MISO PB4/ TIM3_CH1SPI1_MISO
B6 57 91 135 PB5 I/O PB5 I2C1_SMBA / SPI3_MOSI / I2S3_SD TIM3_CH2 / SPI1_MOSI
C6 58 92 136 PB6 I/O FT PB6 I2C1_SCL (8)/ TIM4_CH1(8) USART1_TX
D6 59 93 137 PB7 I/O FT PB7 I2C1_SDA(8) / FSMC_NADV / TIM4_CH2(8) USART1_RX
D5 60 94 138 BOOT0 I BOOT0 - -
C5 61 95 139 PB8 I/O FT PB8 TIM4_CH3(8) / SDIO_D4 / TIM10_CH1 I2C1_SCL/CAN_RX
B5 62 96 140 PB9 I/O FT PB9 TIM4_CH4(8) / SDIO_D5 / TIM11_CH1 I2C1_SDA / CAN_TX
A5 - 97 141 PE0 I/O FT PE0 TIM4_ETR / FSMC_NBL0 -
A4 - 98 142 PE1 I/O FT PE1 FSMC_NBL1 -
E5 63 99 143 V SS_3 SV SS_3 --
F5 64 100 144 V DD_3 SV DD_3 --
1. I = input, O = output, S = supply.
2. FT = 5 V tolerant.
3. Function availability depends on the chosen device.
Table 5. STM32F103xF and STM32F103xG pin definitions (continued)
Pins
Pin name
Type(1)
I / O level(2)
Main 
function(3) 
(after reset)
Alternate functions(4)
LFBGA144
LQFP64
LQFP100
LQFP144
Default Remap
DocID16554 Rev 4 35/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
4. If several peripherals share the same I/O pin, to avoid conf lict between these alternate functions only one peripheral should 
be enabled at a time through the peripheral clock enable bit (in the corresponding RCC peripheral clock enable register).
5. PC13, PC14 and PC15 are supplied through the power switch. Sinc e the switch only sinks a limited amount of current (3 
mA), the use of GPIOs PC13 to PC15 in output mode is limited: the speed should not exceed 2 MHz with a maximum load 
of 30 pF and these IOs must not be used as a current source (e.g. to drive an LED).
6. Main function after the first backup domain power-up. Later on, it depends on the contents of the Backup registers even 
after reset (because these registers are not reset by the main reset). For details on how to manage these IOs, refer to the 
Battery backup domain and BKP register description sections in the STM32F10xxx reference manual, available from the 
STMicroelectronics website: www.st.com.
7. For the LQFP64 package, the pins number 5 and 6 are conf igured as OSC_IN/OSC_OUT after reset, however the 
functionality of PD0 and PD1 can be remapped by software on these pins. For the LQFP100 and LQFP144/BGA144 
packages, PD0 and PD1 are available by default, so there is no need for remapping. For more details, refer to Alternate 
function I/O and debug configuration section in the STM32F10xxx reference manual.
8. This alternate function can be remapped by software to some  other port pins (if available on the used package). For more 
details, refer to the Alternate function I/O and debug configuration section in the STM32F10xxx reference manual, 
available from the STMicroelectronics website: www.st.com.
9. For devices delivered in LQFP64 packages , the FSMC function is not available.
Pinouts and pin descriptions STM32F103xF, STM32F103xG
36/136 DocID16554 Rev 4
          
Table 6. FSMC pin definition 
Pins
FSMC
LQFP100(1)
CF CF/IDE NOR/PSRAM/SRAM NOR/PSRAM Mux NAND 16 bit
PE2 - - A23 A23 - Yes
PE3 - - A19 A19 - Yes
PE4 - - A20 A20 - Yes
PE5 - - A21 A21 - Yes
PE6 - - A22 A22 - Yes
PF0 A0 A0 A0 - - -
PF1 A1 A1 A1 - - -
PF2 A2 A2 A2 - - -
PF3 A3 - A3 - - -
PF4 A4 - A4 - - -
PF5 A5 - A5 - - -
PF6 NIORD NIORD - - -
PF7 NREG NREG - - -
PF8 NIOWR NIOWR - - -
PF9 CD CD - - -
PF10 INTR INTR - - -
PF11 NIOS16 NIOS16 - - -
PF12 A6 - A6 - - -
PF13 A7 - A7 - - -
PF14 A8 - A8 - - -
PF15 A9 - A9 - - -
PG0 A10 - A10 - - -
PG1 - - A11 - - -
PE7 D4 D4 D4 DA4 D4 Yes
PE8 D5 D5 D5 DA5 D5 Yes
PE9 D6 D6 D6 DA6 D6 Yes
PE10 D7 D7 D7 DA7 D7 Yes
PE11 D8 D8 D8 DA8 D8 Yes
PE12 D9 D9 D9 DA9 D9 Yes
PE13 D10 D10 D10 DA10 D10 Yes
PE14 D11 D11 D11 DA11 D11 Yes
PE15 D12 D12 D12 DA12 D12 Yes
PD8 D13 D13 D13 DA13 D13 Yes
DocID16554 Rev 4 37/136
STM32F103xF, STM32F103xG Pinouts and pin descriptions
132
PD9 D14 D14 D14 DA14 D14 Yes
PD10 D15 D15 D15 DA15 D15 Yes
PD11 - - A16 A16 CLE Yes
PD12 - - A17 A17 ALE Yes
PD13 - - A18 A18 Yes
PD14 D0 D0 D0 DA0 D0 Yes
PD15 D1 D1 D1 DA1 D1 Yes
PG2 - - A12 - - -
PG3 - - A13 - - -
PG4 - - A14 - - -
PG5 - - A15 - - -
PG6 - - - - INT2 -
PG7 - - - - INT3 -
PD0 D2 D2 D2 DA2 D2 Yes
PD1 D3 D3 D3 DA3 D3 Yes
PD3 - - CLK CLK - Yes
PD4 NOE NOE NOE NOE NOE Yes
PD5 NWE NWE NWE NWE NWE Yes
PD6 NWAIT NWAIT NWAIT NWAIT NWAIT Yes
PD7 - - NE1 NE1 NCE2 Yes
PG9 - - NE2 NE2 NCE3 -
PG10 NCE4_1 NCE4_1 NE3 NE3 - -
PG11 NCE4_2 NCE4_2 - - - -
PG12 - - NE4 NE4 - -
PG13 - - A24 A24 - -
PG14 - - A25 A25 - -
PB7 - - NADV NADV - Yes
PE0 - - NBL0 NBL0 - Yes
PE1 - - NBL1 NBL1 - Yes
1. Ports F and G are not available in devices delivered in 100-pin packages.
Table 6. FSMC pin definition (continued)
Pins
FSMC
LQFP100(1)
CF CF/IDE NOR/PSRAM/SRAM NOR/PSRAM Mux NAND 16 bit
Memory mapping STM32F103xF, STM32F103xG
38/136 DocID16554 Rev 4

## 4 Memory mapping
The memory map is shown in Figure 7.
DocID16554 Rev 4 39/136
STM32F103xF, STM32F103xG Memory mapping
132
Figure 7. Memory map
AI

-BYTE
 BLOCK 
\#ORTEX
-gS
INTERNAL
PERIPHERALS

-BYTE
 BLOCK 
.OT USED

-BYTE
 BLOCK 
&3-# REGISTER

-BYTE
 BLOCK 
&3-# BANK 
 BANK

-BYTE
 BLOCK 
&3-# BANK
 BANK

-BYTE
 BLOCK 
0ERIPHERALS

-BYTE
 BLOCK 
32!-
X 
X&&& &&&&
X 
X&&& &&&&
X 
X&&& &&&&
X 
X&&& &&&&
X 
X&&& &&&&
X! 
X"&&& &&&&
X# 
X$&&& &&&&
X% 
X&&&& &&&&

-BYTE
 BLOCK 
\#ODE
&LASH MEMORY BANK 
 +"	
X 
X  
 X&&& $&&&
X&&& %
 X&&& &&&
X&&& & 
 X&&& &&
X 
X &&&&
X  
 X&& &&&&
X 
X& &&&&
3YSTEM MEMORY
2ESERVED
2ESERVED
!LIASED TO &LASH OR SYSTEM
MEMORY DEPENDING ON
"//4 PINS
32!-  +" ALIASED
BY BIT
BANDING	
2ESERVED
X 
X &&&
X 
X&&& &&&&
4)-
4)-
X  
 X &&
4)-
4)-
4)-
4)-
2ESERVED
X  
 X &&
X  
 X "&&
X # 
 X &&&
X  
 X &&
X  
 X &&
X  
 X "&&
24# X  
 X "&&
77$' X # 
 X &&&
)7$' X  
 X &&
2ESERVED X  
 X &&
30))3 X  
 X "&&
30))3 X # 
 X &&&
2ESERVED X  
 X &&
53!24 X  
 X &&
X  
 X "&&53!24
5!24 X # 
 X &&&
5!24 X  
 X &&
)# X  
 X &&
)# X  
 X "&&
2ESERVED X  
 X "&&
"+0 X # 
 X &&&
072 X  
 X &&
$!# X  
 X &&
2ESERVED X  
 X &&&&
!&)/ X  
 X &&
0ORT !
%84) X  
 X &&
X  
 X "&&
0ORT " X # 
 X &&&
0ORT # X  
 X &&
0ORT $ X  
 X &&
0ORT % X  
 X "&&
0ORT & X # 
 X &&&
0ORT ' X  
 X &&
!$# X  
 X &&
X  
 X "&&
30) X  
 X &&
X  
 X &&
53!24 X  
 X "&&
2ESERVED X  
 X &&&
$-! X  
 X &&
$-! X  
 X &&
2ESERVED X  
 X &&&
2## X  
 X &&
2ESERVED X  
 X &&&
&LASH INTERFACES    X  
 X &&
2ESERVED X  
 X &&&
\#2# X  
 X &&
2ESERVED X  
 X&&& &&&&
&3-# BANK ./2032!- X  
 X&& &&&&
&3-# BANK ./2032!- X  
 X&& &&&&
&3-# BANK ./2032!- X  
 X"&& &&&&
&3-# BANK ./2032!- X#  
 X&&& &&&&
&3-# BANK .!.$ .!.$	X  
 X&&& &&&&
&3-# BANK .!.$ .!.$	X  
 X&&& &&&&
&3-# BANK 0##!2$ X  
 X&&& &&&&
&3-# REGISTER X!  
 X! &&&
2ESERVED X!  
 X"&&& &&&&
/PTION BYTES
4)-
!$#
X  
 X &&
X  
 X &&&&
3$)/
2ESERVED
!$# X # 
 X &&&
4)- X # 
 X &&&
53" REGISTERS
3HARED 53"#!. 32!- 
BYTES
"X#!.
X # 
 X &&&
X  
 X &&
X  
 X &&
&LASH MEMORY BANK 
 +" OR  +"	
X& &&&&
4)-
4)-
4)-
X  
 X &&
X  
 X &&
X # 
 X &&&
X  
 X "&&
X # 
 X &&&
X  
 X &&
4)-
4)-
4)-
2ESERVED X  
 X &&
Electrical characteristics STM32F103xF, STM32F103xG
40/136 DocID16554 Rev 4

## 5 Electrical characteristics

## 5.1 Parameter conditions
Unless otherwise specified, all voltages are referenced to VSS.

### 5.1.1 Minimum and maximum values
Unless otherwise specified the minimum and maximum values are guaranteed in the worst 
conditions of ambient temperature, supply voltage and frequencies by tests in production on 
100% of the devices with an ambient temperature at TA = 25 °C and TA = TAmax (given by 
the selected temperature range).
Data based on characterization results, design simulation and/or technology characteristics 
are indicated in the table footnotes and are not tested in production. Based on 
characterization, the minimum and maximum values refer to sample tests and represent the 
mean value plus or minus three times the standard deviation (mean±3Σ).

### 5.1.2 Typical values
Unless otherwise specified, typical data are based on TA = 25 °C, VDD = 3.3 V (for the 
2 V £ VDD £ 3.6 V voltage range). They are given only as design guidelines and are not 
tested.
Typical ADC accuracy values are determined by characterization of a batch of samples from 
a standard diffusion lot over the full temperature range, where 95% of the devices have an 
error less than or equal to the value indicated (mean±2Σ).

### 5.1.3 Typical curves
Unless otherwise specified, all typical curves are given only as design guidelines and are 
not tested.

### 5.1.4 Loading capacitor
The loading conditions used for pin parameter measurement are shown in Figure 8.

### 5.1.5 Pin input voltage
The input voltage measurement on a pin of the device is described in Figure 9.
          
Figure 8. Pin loading conditions Figure 9. Pin input voltage
-36
\#    P&
-#5 PIN
-36
-#5 PIN
6).
DocID16554 Rev 4 41/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.1.6 Power supply scheme
Figure 10. Power supply scheme
Caution: In Figure 10, the 4.7 µF capacitor must be connected to VDD3.
DL
9''
$QDORJ
5&V3//

3RZHUVZLWFK
9%$7
*3,2V
287
,1 .HUQHOORJLF
&38
'LJLWDO
	0HPRULHV
%DFNXSFLUFXLWU\
26&.57&
%DFNXSUHJLVWHUV
:DNHXSORJLF
îQ)
î)
9
5HJXODWRU
966
9''$
95()
95()
966$
$'&
'$&
/HYHOVKLIWHU
,2
/RJLF
9''
Q)
)
95()
Q)
)
9''
Electrical characteristics STM32F103xF, STM32F103xG
42/136 DocID16554 Rev 4

### 5.1.7 Current consumption measurement
Figure 11. Current consumption measurement scheme
AI
6"!4
6$$
6$$!
)$$?6"! 4
)$$
DocID16554 Rev 4 43/136
STM32F103xF, STM32F103xG Electrical characteristics
132

## 5.2 Absolute maximum ratings
Stresses above the absolute maximum ratings listed in Table 7: Voltage characteristics, 
Table 8: Current characteristics, and Table 9: Thermal characteristics may cause permanent 
damage to the device. These are stress ratings only and functional operation of the device 
at these conditions is not implied. Exposure to maximum rating conditions for extended 
periods may affect device reliability.
           
           
Table 7. Voltage characteristics
Symbol Ratings Min Max Unit
VDD–VSS External main supply voltage (including VDDA and VDD)(1)
1. All main power (V DD, VDDA) and ground (VSS, VSSA) pins must always be connected to the external power supply, in the permitted range.
–0.3 4.0
V
VIN(2)
2. V IN maximum must always be respected. Refer to Table 8: Current characteristics for the maximum allowed injected current values. 
Input voltage on five volt tolerant pin V SS − 0.3 V DD + 4.0 
Input voltage on any other pin V SS − 0.3 4.0
|ΔVDDx| Variations between different V DD power pins - 50 mV
|VSSX − VSS| Variations between all the different ground pins - 50
VESD(HBM) Electrostatic discharge voltage (human body model) see Section 5.3.12: Absolute maximum ratings (electrical sensitivity)
Table 8. Current characteristics
Symbol Ratings  Max. Unit
IVDD Total current into VDD/VDDA power lines (source)(1)
1. All main power (V DD, VDDA) and ground (VSS, VSSA) pins must always be connected to the external power supply, in the permitted range.
150
mA
IVSS Total current out of VSS ground lines (sink)(1) 150
IIO
Output current sunk by any I/O and control pin 25
Output current source by any I/Os and control pin − 25
IINJ(PIN)(2)
2. Negative injection disturbs the analog per formance of the device. See note 3 below Table 65 on page 110.
Injected current on five volt tolerant pins(3)
3. Positive injection is not possible on thes e I/Os. A negative injection is induced by VIN<VSS. IINJ(PIN) must never be exceeded. Refer to Table 7: Voltage characteristics for the maximum allowed input voltage 
values.
-5/+0
Injected current on any other pin(4)
4.  A positive inject ion is induced by VIN>VDD while a negative injection is induced by VIN<VSS. IINJ(PIN) must never be exceeded. Refer to Table 7: Voltage characteristics for the maximum allowed input voltage 
values.
± 5
ΣIINJ(PIN) Total injected current (sum of all I/O and control pins)(5)
5. When several inputs are submitted to a current injection, the maximum ΣIINJ(PIN) is the absolute sum of the positive and negative injected currents (instantaneous values). 
± 25
Electrical characteristics STM32F103xF, STM32F103xG
44/136 DocID16554 Rev 4
          

## 5.3 Operating conditions

### 5.3.1 General operating conditions
          
Table 9. Thermal characteristics
Symbol Ratings  Value Unit
TSTG Storage temperature range –65 to +150 °C
TJ Maximum junction temperature 150 °C
Table 10. General operating conditions
Symbol Parameter  Co nditions Min Max Unit
fHCLK Internal AHB clock frequency - 0 72
MHzfPCLK1 Internal APB1 clock frequency - 0 36
fPCLK2 Internal APB2 clock frequency - 0 72
VDD Standard operating voltage - 2 3.6 V
VDDA(1)
1. When the ADC is used, refer to Table 62: ADC characteristics.
Analog operating voltage 
(ADC not used) Must be the same potential 
as VDD(2)
2. It is recommended to power V DD and VDDA from the same source. A maximum difference of 300 mV between VDD and VDDA can be tolerated during power-up and operation.
23 . 6
V
Analog operating voltage 
(ADC used) 2.4 3.6
VBAT Backup operating voltage - 1.8 3.6 V
PD
Power dissipation at TA = 
85 °C for suffix 6 or TA = 
105 °C for suffix 7(3)
3. If T A is lower, higher PD values are allowed as long as TJ does not exceed TJmax (see Table 6.5: Thermal characteristics on page 129).
LQFP144 - 666
mW
LQFP100 - 434
LQFP64 - 444
LFBGA144 - 500
TA 
Ambient temperature for 6 
suffix version
Maximum power dissipation –40 85
°C
Low-power dissipation(4)
4. In low-power dissipation state, T A can be extended to this range as long as TJ does not exceed TJmax (see Table 6.5: Thermal characteristics on page 129).
–40 105
Ambient temperature for 7 
suffix version
Maximum power dissipation –40 105
°C
Low-power dissipation(4) –40 125
TJ Junction temperature range
6 suffix version –40 105
°C
7 suffix version –40 125
DocID16554 Rev 4 45/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.2 Operating conditions at power-up / power-down
The parameters given in Table 11 are derived from tests performed under the ambient 
temperature condition summarized in Table 10.
Table 11. Operating conditions at power-up / power-down

### 5.3.3 Embedded reset and power control block characteristics
The parameters given in Table 12 are derived from tests performed under ambient 
temperature and VDD supply voltage conditions summarized in Table 10.
           
Symbol Parameter Conditions Min Max Unit
tVDD
VDD rise time rate - 0¥ µs/V
VDD fall time rate 20 ¥
Table 12. Embedded reset and power control block characteristics
Symbol Parameter Conditions Min Typ  Max Unit
VPVD Programmable voltage detector level selection
PLS[2:0]=000 (rising edge) 2.1 2.18 2.26 V
PLS[2:0]=000 (falling edge) 2 2.08 2.16 V
PLS[2:0]=001 (rising edge) 2.19 2.28 2.37 V
PLS[2:0]=001 (falling edge) 2.09 2.18 2.27 V
PLS[2:0]=010 (rising edge) 2.28 2.38 2.48 V
PLS[2:0]=010 (falling edge) 2.18 2.28 2.38 V
PLS[2:0]=011 (rising edge) 2.38 2.48 2.58 V
PLS[2:0]=011 (falling edge) 2.28 2.38 2.48 V
PLS[2:0]=100 (rising edge) 2.47 2.58 2.69 V
PLS[2:0]=100 (falling edge) 2.37 2.48 2.59 V
PLS[2:0]=101 (rising edge) 2.57 2.68 2.79 V
PLS[2:0]=101 (falling edge) 2.47 2.58 2.69 V
PLS[2:0]=110 (rising edge) 2.66 2.78 2.9 V
PLS[2:0]=110 (falling edge) 2.56 2.68 2.8 V
PLS[2:0]=111 (rising edge) 2.76 2.88 3 V
PLS[2:0]=111 (falling edge) 2.66 2.78 2.9 V
VPVDhyst(2) PVD hysteresis - - 100 - mV
VPOR/PDR Power on/power down reset threshold Falling edge 1.8 (1)
1. The product behavior is guaranteed by design down to the minimum V POR/PDR value.
1.88 1.96 V
Rising edge 1.84 1.92 2.0 V
VPDRhyst(2) PDR hysteresis - - 40 - mV
TRSTTEMPO(2)
2. Guaranteed by design, not tested in production.
Reset temporization - 1 2.5 4.5 mS
Electrical characteristics STM32F103xF, STM32F103xG
46/136 DocID16554 Rev 4

### 5.3.4 Embedded reference voltage
The parameters given in Table 13 are derived from tests performed under ambient 
temperature and VDD supply voltage conditions summarized in Table 10.
           

### 5.3.5 Supply current characteristics
The current consumption is a function of several parameters and factors such as the 
operating voltage, ambient temperature, I/O pin loading, device software configuration, 
operating frequencies, I/O pin switching rate, program location in memory and executed 
binary code. 
The current consumption is measured as described in Figure 11: Current consumption 
measurement scheme. 
All Run-mode current consumption measurements given in this section are performed with a 
reduced code that gives a consumption equivalent to Dhrystone 2.1 code.
Maximum current consumption
The MCU is placed under the following conditions:
• All I/O pins are in input mode with a static value at VDD or VSS (no load)
• All peripherals are disabled except when explicitly mentioned
• The Flash memory access time is adjusted to the fHCLK frequency (0 wait state from 0 
to 24 MHz, 1 wait state from 24 to 48 MHz and 2 wait states above)
• Prefetch in ON (reminder: this bit must be set before clock setting and bus prescaling)
• When the peripherals are enabled fPCLK1 = fHCLK/2, fPCLK2 = fHCLK
The parameters given in Table 14, Table 15 and Table 16 are derived from tests performed 
under ambient temperature and VDD supply voltage conditions summarized in Table 10.
Table 13. Embedded internal reference voltage
Symbol Parameter Conditions Min Typ  Max Unit
VREFINT Internal reference voltage
–40 °C < TA < +105 °C 1.16 1.20 1.26 V
–40 °C < TA < +85 °C 1.16 1.20 1.24 V
TS_vrefint(1)
1. Shortest sampling time can be determined in  the application by multiple iterations.
ADC sampling time when 
reading the internal reference 
voltage
-- 5 . 1 1 7 . 1 (2)
2. Guaranteed by design, not tested in production.
µs
VRERINT(2)
Internal reference voltage 
spread over the temperature 
range
VDD = 3 V ±10 mV - - 10 mV
TCoeff(2) Temperature coefficient - - - 100 ppm/°C
DocID16554 Rev 4 47/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
          CIAO
Table 14. Maximum current consumption in Run mode, code with data processing
running from Flash
Symbol Parameter Conditions f HCLK
Max(1)
1. Guaranteed by characterization results, not tested in production.
Unit
TA = 85 °C T A = 105 °C
IDD Supply current in Run mode
External clock(2), all 
peripherals enabled
2. External clock is 8 MHz and PLL is on when f HCLK > 8 MHz.
72 MHz 68 69
mA
48 MHz 51 51
36 MHz 41 41
24 MHz 29 30
16 MHz 22 22.5
8 MHz 12.5 14
External clock(2), all 
peripherals disabled
72 MHz 39 39
48 MHz 29.5 30
36 MHz 24 24.5
24 MHz 17.5 19
16 MHz 14 15
8 MHz 8.5 10.5
Table 15. Maximum current consumption in Run mode, code with data processing
running from RAM
Symbol Parameter Conditions f HCLK
Max(1)
1. Guaranteed by characterization results, not tested in production at V DD max, fHCLK max.
Unit
TA = 85 °C T A = 105 °C
IDD Supply current in Run mode
External clock(2), all 
peripherals enabled
2. External clock is 8 MHz and PLL is on when f HCLK > 8 MHz.
72 MHz 65 65.5
mA
48 MHz 46.5 47
36 MHz 37 37
24 MHz 26.5 27
16 MHz 19 20
8 MHz 11.5 13
External clock(2), all 
peripherals disabled
72 MHz 34.5 36
48 MHz 25 26
36 MHz 20.5 21
24 MHz 15 16
16 MHz 11 13
8 MHz 7.5 9
Electrical characteristics STM32F103xF, STM32F103xG
48/136 DocID16554 Rev 4
Figure 12. Typical current consumption in Run mode versus frequency (at 3.6 V) -
code with data processing running from RAM, peripherals enabled 
Figure 13. Typical current consumption in Run mode versus frequency (at 3.6 V)-
code with data processing running from RAM, peripherals disabled  
AI









    
\#ONSUMPTION M!	
4EMPERATURE  #	
-(Z
-(Z
-(Z
-(Z
-(Z
-(Z










    
\#ONSUMPTION M!	
4EMPERATURE  #	
-(Z
-(Z
-(Z
-(Z
-(Z
-(Z
AI
DocID16554 Rev 4 49/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
Table 16. Maximum current consumption in Sleep mode, code running from Flash or 
RAM
Symbol Parameter Conditions f HCLK
Max(1)
1. Guaranteed by characterization results, not tested in production at V DD max, fHCLK max with peripherals enabled.
Unit
TA = 85 °C T A = 105 °C
IDD Supply current in Sleep mode
External clock(2), all 
peripherals enabled
2. External clock is 8 MHz and PLL is on when f HCLK > 8 MHz.
72 MHz 47.5 48.5
mA
48 MHz 34 35
36 MHz 27.5 27.5
24 MHz 20 20.5
16 MHz 15 16
8 MHz 9 11
External clock(2), all 
peripherals disabled
72 MHz 9.5 11.2
48 MHz 7.7 9.5
36 MHz 6.9 8.5
24 MHz 5.9 7.8
16 MHz 5.4 7.2
8 MHz 4.7 6.4
Electrical characteristics STM32F103xF, STM32F103xG
50/136 DocID16554 Rev 4
          
Figure 14. Typical current consumption on VBAT with RTC on vs. temperature at 
different VBAT
values
Table 17. Typical and maximum current consumptions in Stop and Standby modes
Symbol Parameter Conditions
Typ(1) Max
UnitVDD/VBA
T = 2.0 V
VDD/VBA
T = 2.4 V
VDD/VBA
T = 3.3 V
TA = 
85 °C
TA = 
105 °C
IDD
Supply current in 
Stop mode
Regulator in run mode, low-speed 
and high-speed internal RC 
oscillators and high-speed oscillator 
OFF (no independent watchdog), 
fCK=8 MHz
44.8 45.3 46.4 810 1680
µA
Regulator in low-power mode, low-
speed and high-speed internal RC 
oscillators and high-speed oscillator 
OFF (no independent watchdog)
37.4 37.8 38.7 790 1660
Supply current in 
Standby mode
Low-speed internal RC oscillator 
and independent watchdog OFF, 
low-speed oscillator and RTC OFF
1.8 2.0 2.5 5 (2) 8(2)
IDD_VBA
T
Backup domain 
supply current Low-speed oscillator and RTC ON 1.05 1.1 1.4 2 (2) 2.3(2)
1. Typical values are measured at T A = 25 °C.
2. Guaranteed by characterization results, not tested in production..






±   
7HPSHUDWXUH&
&RQVXPSWLRQ$
9
9
9
9
9
DL
DocID16554 Rev 4 51/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 15. Typical current consumption in Stop mode with regulator in run mode
versus temperature at different VDD values   








# # # #
\#ONSUMPTION ȝ!	
4EMPERATURE  #	
6
6
6
6
6
AI
Electrical characteristics STM32F103xF, STM32F103xG
52/136 DocID16554 Rev 4
Figure 16. Typical current consumption in Stop mode with regulator in low-power
mode versus temperature at different VDD values
Figure 17. Typical current consumption in Standby mode versus temperature at
different VDD values 








# # # #
\#ONSUMPTION ȝ!	
4EMPERATURE  #	
6
6
6
6
6
AI











# # # #
\#ONSUMPTION ȝ!	
4EMPERATURE  #	
6
6
6
6
6
AI
DocID16554 Rev 4 53/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Typical current consumption
The MCU is placed under the following conditions:
• All I/O pins are in input mode with a static value at VDD or VSS (no load).
• All peripherals are disabled except if it is explicitly mentioned.
• The Flash access time is adjusted to fHCLK frequency (0 wait state from 0 to 24 MHz, 1 
wait state from 24 to 48 MHZ and 2 wait states above).
• Ambient temperature and VDD supply voltage conditions summarized in Table 10.
• Prefetch is ON (Reminder: this bit must be set before clock setting and bus prescaling)
When the peripherals are enabled fPCLK1 = fHCLK/4, fPCLK2 = fHCLK/2, fADCCLK = fPCLK2/4
          
Table 18. Typical current consumption in Run mode, code with data processing
running from Flash
Symbol Parameter Conditions f HCLK
Typ(1)
1. Typical values are measures at T A = 25 °C, VDD = 3.3 V.
UnitAll peripherals 
enabled(2)
2. Add an additional power consumption of 0.8 mA per ADC for the analog part. In applications, this 
consumption occurs only while the ADC is on (ADON bit is set in the ADC_CR2 register).
All peripherals 
disabled
IDD
Supply 
current in 
Run mode
External clock(3)
3. External clock is 8 MHz and PLL is on when f HCLK > 8 MHz.
72 MHz 52.5 33.5
mA
48 MHz 36.6 23.8
36 MHz 28.5 18.7
24 MHz 24.1 12.8
16 MHz 14 9.2
8 MHz 7.7 5.4
4 MHz 4.6 3.4
2 MHz 3 2.3
1 MHz 2.2 1.8
500 kHz 1.7 1.5
125 kHz 1.4 1.3
Running on high 
speed internal RC 
(HSI), AHB 
prescaler used to 
reduce the 
frequency
64 MHz 45.5 28.6
mA
48 MHz 35.1 22.4
36 MHz 27.5 17.5
24 MHz 18.9 11.6
16 MHz 12.2 8.2
8 MHz 7.2 4.8
4 MHz 4 2.7
2 MHz 2.3 1.7
1 MHz 1.5 1.2
500 kHz 1.1 0.9
125 kHz 0.75 0.7
Electrical characteristics STM32F103xF, STM32F103xG
54/136 DocID16554 Rev 4
          
          
Table 19. Typical current consumption in Sleep mode, code running from Flash or
RAM 
Symbol Parameter Conditions f HCLK
Typ(1)
1. Typical values are measures at T A = 25 °C, VDD = 3.3 V.
UnitAll peripherals 
enabled(2)
2. Add an additional power consumption of 0.8 mA per ADC for the analog part. In applications, this 
consumption occurs only while the ADC is on (ADON bit is set in the ADC_CR2 register).
All peripherals 
disabled
IDD
Supply 
current in 
Sleep mode
External clock(3)
3. External clock is 8 MHz and PLL is on when f HCLK > 8 MHz.
72 MHz 32.5 7
mA
48 MHz 23 5
36 MHz 17.7 4
24 MHz 12.2 3.1
16 MHz 8.4 2.3
8 MHz 4.6 1.5
4 MHz 3 1.3
2 MHz 2.15 1.25
1 MHz 1.7 1.2
500 kHz 1.5 1.15
125 kHz 1.35 1.15
Running on high 
speed internal RC 
(HSI), AHB prescaler 
used to reduce the 
frequency
64 MHz 28.7 5.7
48 MHz 22 4.4
36 MHz 17 3.35
24 MHz 11.6 2.3
16 MHz 7.7 1.6
8 MHz 3.9 0.8
4 MHz 2.3 0.7
2 MHz 1.5 0.6
1 MHz 1.1 0.5
500 kHz 0.9 0.5
125 kHz 0.7 0.5
DocID16554 Rev 4 55/136
STM32F103xF, STM32F103xG Electrical characteristics
132
On-chip peripheral current consumption
The current consumption of the on-chip peripherals is given in Table 20. The MCU is placed 
under the following conditions:
• all I/O pins are in input mode with a static value at VDD or VSS (no load)
• all peripherals are disabled unless otherwise mentioned
• the given value is calculated by measuring the current consumption
– with all peripherals clocked off
– with only one peripheral clocked on
• ambient operating temperature and VDD supply voltage conditions summarized in 
Table 7
          
Table 20. Peripheral current consumption(1) 
Peripheral Current consumption
AHB (up to 72 MHz)
DMA1 23,06
DMA2 18,47
FSMC 55,14
CRC 2,08
SDIO 32,22
BusMatrix(2) 11,67
Electrical characteristics STM32F103xF, STM32F103xG
56/136 DocID16554 Rev 4
APB1 (up to 36 MHz)
APB1-Bridge 8,61
TIM2 37,22
TIM3 36,39
TIM4 35,56
TIM5 33,61
TIM6 7,78
TIM7 7,78
TIM12 19,17
TIM13 12,22
TIM14 13,33
SPI2/I2S2(3) 8,33
SPI3/I2S3(3) 8,33
USART2 12,22
USART3 12,22
UART4 12,22
UART5 12,22
I2C1 10,28
I2C2 10,28
USB 18,89
CAN1 18,89
DAC(4) 9,17
WWDG 3,06
PWR 2,50
BKP 2,78
IWDG 4,44
Table 20. Peripheral current consumption(1) (continued)
Peripheral Current consumption
DocID16554 Rev 4 57/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.6 External clock source characteristics
High-speed external user clock generated from an external source
The characteristics given in Table 21 result from tests performed using an high-speed 
external clock source, and under ambient temperature and supply voltage conditions 
summarized in Table 10.
APB2 (up to 72 MHz)
APB2-Bridge 2,78
GPIOA 7,64
GPIOB 7,64
GPIOC 7,64
GPIOD 8,47
GPIOE 8,47
GPIOF 8,19
GPIOG 8,19
SPI1 5,14
USART1 16,67
TIM1 28,47
TIM8 24,31
TIM9 11,81
TIM10 8,47
TIM11 8,47
ADC1(5)(6) 17,68
ADC2(5)(6) 15,54
ADC3(5)(6) 16,43
1. f HCLK = 72 MHz, fAPB1 = fHCLK/2, fAPB2 = fHCLK, default prescaler value for each peripheral.
2. The BusMatrix is automatically active when at least one master peripheral is ON. 
3. When the I2S is enabled, a current c onsumption equal to 0.02 mA must be added.
4. When DAC_OU1 or DAC_OUT2 is enabled, a current consumption equal to 0.36 mA must be added.
5. Specific conditions for ADC: f HCLK = 56 MHz, fAPB1 = fHCLK/2, fAPB2 = fHCLK, fADCCLK = fAPB2/4/ When ADON bit in the ADC_CR2 register is set to 1, a current consumption equal to 0.59 mA must be added.
6. When the ADC is enabled, a current consumption equal to 0.1 mA must be added.
Table 20. Peripheral current consumption(1) (continued)
Peripheral Current consumption
Electrical characteristics STM32F103xF, STM32F103xG
58/136 DocID16554 Rev 4
          
Low-speed external user clock generated from an external source
The characteristics given in Table 22 result from tests performed using an low-speed 
external clock source, and under ambient temperature and supply voltage conditions 
summarized in Table 10.
          
Table 21. High-speed external user clock characteristics
Symbol Parameter Condi tions Min Typ Max Unit
fHSE_ext User external clock source frequency(1)
1. Guaranteed by design, not tested in production.
-
18 2 5 M H z
VHSEH OSC_IN input pin high level voltage 0.7V DD -V DD
V
VHSEL OSC_IN input pin low level voltage V SS -0 . 3 V DD
tw(HSE)
tw(HSE) OSC_IN high or low time(1) 5-- ns
tr(HSE)
tf(HSE) OSC_IN rise or fall time(1) -- 2 0
Cin(HSE) OSC_IN input capacitance(1) -- 5 - p F
DuCy(HSE) Duty cycle - 45 - 55 %
IL OSC_IN Input leakage current V SS ≤ VIN ≤ VDD -- ± 1 µ A
Table 22. Low-speed external user clock characteristics
Symbol Parameter Conditions Min Typ Max Unit
fLSE_ext User External clock source frequency(1)
1. Guaranteed by design, not tested in production.
-
- 32.768 1000 kHz
VLSEH OSC32_IN input pin high level voltage 0.7VDD -V DD
V
VLSEL OSC32_IN input pin low level voltage VSS -0 . 3 V DD
tw(LSE)
tw(LSE) OSC32_IN high or low time(1) 450 - - ns
tr(LSE)
tf(LSE) OSC32_IN rise or fall time(1) -- 5 0
Cin(LSE) OSC32_IN input capacitance(1) -- 5 - p F
DuCy(LSE) Duty cycle - 30 - 70 %
IL OSC32_IN Input leakage current VSS ≤ VIN ≤ VDD -- ± 1 µ A
DocID16554 Rev 4 59/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 18. High-speed external clock source AC timing diagram
Figure 19. Low-speed external clock source AC timing diagram
AI
/3 # ?) .
%XTERNAL
34-&
CLOCK SOURCE
6(3%(
TF(3%	 T7(3%	
),
 
 
4(3%
TTR(3%	 T7(3%	
F(3%?EXT
6(3%,
DL
26&B,1([WHUQDO
670)
FORFNVRXUFH
9/6(+
WI/6( W:/6(
,/


7/6(
WWU/6( W:/6(
I/6(BH[W
9/6(/
Electrical characteristics STM32F103xF, STM32F103xG
60/136 DocID16554 Rev 4
High-speed external clock generated from a crystal/ceramic resonator
The high-speed external (HSE) clock can be supplied with a 4 to 16 MHz crystal/ceramic 
resonator oscillator. All the information given in this paragraph are based on 
characterization results obtained with typical external components specified in Table 23. In 
the application, the resonator and the load capacitors have to be placed as close as 
possible to the oscillator pins in order to minimize output distortion and startup stabilization 
time. Refer to the crystal resonator manufacturer for more details on the resonator 
characteristics (frequency, package, accuracy).
          
For CL1 and CL2, it is recommended to use high-quality external ceramic capacitors in the 
5 pF to 25 pF range (typ.), designed for high-frequency applications, and selected to match 
the requirements of the crystal or resonator (see Figure 20). CL1 and CL2 are usually the 
same size. The crystal manufacturer typically specifies a load capacitance which is the 
series combination of CL1 and CL2. PCB and MCU pin capacitance must be included (10 pF 
can be used as a rough estimate of the combined pin and board capacitance) when sizing 
CL1 and CL2. Refer to the application note AN2867 “Oscillator design guide for ST 
microcontrollers” available from the ST website www.st.com.
Table 23. HSE 4-16 MHz oscillator characteristics(1)(2)
1. Resonator characteristics given by the crystal/ceramic resonator manufacturer.
2. Guaranteed by characterization re sults, not tested in production.
Symbol Parameter Conditions Min Typ Max Unit
fOSC_IN Oscillator frequency - 4 8 16 MHz
RF Feedback resistor - - 200 - k Ω 
C
Recommended load capacitance 
versus equivalent serial 
resistance of the crystal (RS)(3)
3. The relatively low value of the RF resistor offers a good protection against issues resulting from use in a 
humid environment, due to the induced leakage and the bias condition change. However, it is 
recommended to take this point into account if the MCU is used in tough humidity conditions.
RS = 30 Ω -3 0-p F
i2 HSE driving current VDD= 3.3 V, VIN = VSS with 30 pF load --1 m A
gm Oscillator transconductance Startup 25 - - mA/V
tSU(HSE)(4)
4. t SU(HSE) is the startup time measured from the moment it is enabled (by software) to a stabilized 8 MHz oscillation is reached. This value is measured for a standard crystal resonator and it can vary significantly 
with the crystal manufacturer
Startup time  V DD is stabilized - 2 - ms
DocID16554 Rev 4 61/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 20. Typical application with an 8 MHz crystal
1. R EXT value depends on the crystal characteristics.
DL
26&B287
26&B,1 I+6(
&/
5)
670)
0+]
UHVRQDWRU
5HVRQDWRUZLWK
LQWHJUDWHGFDSDFLWRUV
%LDV
FRQWUROOHG
JDLQ
5(;7&/
Electrical characteristics STM32F103xF, STM32F103xG
62/136 DocID16554 Rev 4
Low-speed external clock generated from a crystal/ceramic resonator
The low-speed external (LSE) clock can be supplied with a 32.768 kHz crystal/ceramic 
resonator oscillator. All the information given in this paragraph are based on 
characterization results obtained with typical external components specified in Table 24. In 
the application, the resonator and the load capacitors have to be placed as close as 
possible to the oscillator pins in order to minimize output distortion and startup stabilization 
time. Refer to the crystal resonator manufacturer for more details on the resonator 
characteristics (frequency, package, accuracy).
          
Note: For C L1 and CL2, it is recommended to use high-quality ceramic capacitors in the 5 pF to 
15 pF range selected to match the requirements of the crystal or resonator (see Figure 21). 
CL1 and CL2, are usually the same size. The crystal manufacturer typically specifies a load 
capacitance which is the series combination of CL1 and CL2. 
Load capacitance CL has the following formula: CL = CL1 x CL2 / (CL1 + CL2) + Cstray where 
Cstray is the pin capacitance and board or trace PCB-related capacitance. Typically, it is 
between 2 pF and 7 pF.
Caution: To avoid exceeding the maximum value of CL1 and CL2 (15 pF) it is strongly recommended 
to use a resonator with a load capacitance CL ≤  7 pF. Never use a resonator with a load 
capacitance of 12.5 pF. 
Example: if you choose a resonator with a load capacitance of CL = 6 pF, and Cstray = 2 pF, 
then CL1 = CL2 = 8 pF.
Table 24. LSE oscillator characteristics (fLSE = 32.768 kHz)(1)(2)
Symbol Parameter Conditions Min Typ Max Unit
RF Feedback resistor - - 5 - M Ω 
C(2)
Recommended load capacitance 
versus equivalent serial 
resistance of the crystal (RS)
RS = 30 kΩ -- 1 5 p F
I2 LSE driving current V DD = 3.3 V, VIN = VSS -- 1 . 4 µ A
gm Oscillator transconductance - 5 - - µA/V
tSU(LSE)(3) Startup time  VDD is stabilized
TA = 50 °C - 1.5 -
s
TA = 25 °C - 2.5 -
TA = 10 °C - 4 -
TA = 0 °C - 6 -
TA = -10 °C - 10 -
TA = -20 °C - 17 -
TA = -30 °C - 32 -
TA = -40 °C - 60 -
1. Guaranteed by characterization results, not tested in production.
2. Refer to the note and caution paragraphs below the table,  and to the application note AN2867 “Oscillator design guide for 
ST microcontrollers”.
3.  t SU(LSE) is the startup time measured from the moment it is enabled (by software) until a stabilized 32.768 kHz oscillation is reached. This value is measured for a standard crystal and it can vary significantly with the crystal manufacturer, PCB 
layout and humidity.
DocID16554 Rev 4 63/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 21. Typical application with a 32.768 kHz crystal

### 5.3.7 Internal clock source characteristics
The parameters given in Table 25 are derived from tests performed under ambient 
temperature and VDD supply voltage conditions summarized in Table 10.
High-speed internal (HSI) RC oscillator
          
DL
26&B287
26&B,1 I/6(
&/
5)
670)
N+]
UHVRQDWRU
5HVRQDWRUZLWK
LQWHJUDWHGFDSDFLWRUV
%LDV
FRQWUROOHG
JDLQ
&/
Table 25. HSI oscillator characteristics(1)
1. V DD = 3.3 V, TA = –40 to 105 °C unless otherwise specified.
Symbol Parameter Conditions Min Typ Max Unit
fHSI Frequency - - 8 MHz 
DuCy(HSI) Duty cycle - 45 - 55 % 
ACCHSI Accuracy of the HSI oscillator
User-trimmed with the RCC_CR 
register(2)
2. Refer to application note AN2868 “STM32F10xxx internal  RC oscillator (HSI) calibration” available from 
the ST website www.st.com.
-- 1 (3)
3. Guaranteed by design, not tested in production.
%
Factory-
calibrated(4)
4. Guaranteed by characterization re sults, not tested in production.
TA = –40 to 105 °C –2 - 2.5 %
TA = –10 to 85 °C –1.5 - 2.2 %
TA = 0 to 70 °C –1.3 - 2 %
TA = 25 °C –1.1 - 1.8 %
tsu(HSI)(4) HSI oscillator startup time -1 - 2 µ s
IDD(HSI)(4) HSI oscillator power consumption - - 80 100 µA
Electrical characteristics STM32F103xF, STM32F103xG
64/136 DocID16554 Rev 4
Low-speed internal (LSI) RC oscillator
          
Wakeup time from low-power mode
The wakeup times given in Table 27 is measured on a wakeup phase with a 8-MHz HSI RC 
oscillator. The clock source used to wake up the device depends from the current operating 
mode:
• Stop or Standby mode: the clock source is the RC oscillator
• Sleep mode: the clock source is the clock that was set before entering Sleep mode.
All timings are derived from tests performed under ambient temperature and VDD supply 
voltage conditions summarized in Table 10. 
          
Table 26. LSI oscillator characteristics (1)
1. V DD = 3 V, TA = –40 to 105 °C unless otherwise specified.
Symbol Parameter Min Typ Max Unit
fLSI(2)
2. Guaranteed by characterization results, not tested in production.
Frequency 30 40 60 kHz 
tsu(LSI)(3)
3. Guaranteed by design, not tested in production.
LSI oscillator startup time - - 85 µs
IDD(LSI)(3) LSI oscillator power consumption - 0.65 1.2 µA
Table 27. Low-power mode wakeup timings
Symbol Parameter Typ Unit
tWUSLEEP(1)
1. The wakeup times are measured from the wakeup event to the point in which the user application code 
reads the first instruction.
Wakeup from Sleep mode 1.8 µs
tWUSTOP(1) Wakeup from Stop mode (regulator in run mode) 3.6 µsWakeup from Stop mode (regulator in low-power mode) 5.4
tWUSTDBY(1) Wakeup from Standby mode 50 µs
DocID16554 Rev 4 65/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.8 PLL characteristics
The parameters given in Table 28 are derived from tests performed under ambient 
temperature and VDD supply voltage conditions summarized in Table 10.
          

### 5.3.9 Memory characteristics
Flash memory
The characteristics are given at TA = –40 to 105 °C unless otherwise specified.
          
Table 28. PLL characteristics 
Symbol Parameter
Value
Unit
Min Typ Max (1)
1. Guaranteed by characterization results, not tested in production.
fPLL_IN
PLL input clock(2)
2. Take care of using the appropriate multiplier factors so as to have PLL input clock values compatible with 
the range defined by fPLL_OUT.
18 . 0 2 5 M H z
PLL input clock duty cycle 40 - 60 %
fPLL_OUT PLL multiplier output clock 16 - 72 MHz
tLOCK PLL lock time - - 200 µs
Jitter Cycle-to-cycle jitter - - 300 ps
Table 29. Flash memory characteristics
Symbol Parameter  Conditions Min Typ Max (1)
1. Guaranteed by design, not tested in production.
Unit
tprog 16-bit programming time T A = –40 to +105 °C 40 52.5 70 µs
tERASE Page (2 KB) erase time T A = –40 to +105 °C 20 - 40 ms
tME Mass erase time T A = –40 to +105 °C 20 - 40 ms
IDD Supply current 
Read mode 
fHCLK = 72 MHz with 2 wait 
states, VDD = 3.3 V
-- 2 8 m A
Write mode  
fHCLK = 72 MHz, VDD = 3.3 V --7 m A
Erase mode  
fHCLK = 72 MHz, VDD = 3.3 V --5 m A
Power-down mode / Halt, 
VDD = 3.0 to 3.6 V -- 5 0 µ A
Vprog Programming voltage - 2 - 3.6 V
Electrical characteristics STM32F103xF, STM32F103xG
66/136 DocID16554 Rev 4
          
Table 30. Flash memory endurance and data retention
Symbol Parameter  Conditions
Value
Unit
Min(1)
1. Guaranteed by characterization results, not tested in production.
NEND Endurance TA = –40 to +85 °C (6 suffix versions)TA = –40 to +105 °C (7 suffix versions) 10 kcycles
tRET Data retention
1 kcycle(2) at TA = 85 °C
2. Cycling performed over the whole temperature range.
30
Years1 kcycle(2) at TA = 105 °C 10
10 kcycles(2) at TA = 55 °C 20
DocID16554 Rev 4 67/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.10 FSMC characteristics
Asynchronous waveforms and timings
Figure 22 through Figure 25 represent asynchronous waveforms and Table 31 through 
Table 35 provide the corresponding timings. The results shown in these tables are obtained 
with the following FSMC configuration:
• AddressSetupTime = 0
• AddressHoldTime = 1
• DataSetupTime = 1
Note: On all tables, the t HCLK is the HCLK clock period.
Figure 22. Asynchronous non-multiplexed SRAM/PSRAM/NOR read waveforms
1. Mode 2/B, C and D only. In Mode 1, FSMC_NADV is not used.
Note: FSMC_BusTurnAroundDuration = 0.
'DWD
)60&B1(
)60&B1%/>@
)60&B'>@
WY%/B1(
WK'DWDB1(
)60&B12(
$GGUHVV)60&B$>@
WY$B1(
)60&B1:(
WVX'DWDB1(
WZ1(
069
Z12(W
WY12(B1(
WK1(B12(
WK'DWDB12(
WK$B12(
WK%/B12(
WVX'DWDB12(
)60&B1$'9
WY1$'9B1(
WZ1$'9
Electrical characteristics STM32F103xF, STM32F103xG
68/136 DocID16554 Rev 4
          
Figure 23. Asynchronous non-multiplexed SRAM/PSRAM/NOR write waveforms
1. Mode 2/B, C and D only. In Mode 1, FSMC_NADV is not used.
Table 31. Asynchronous non-multiplexed SRAM/PSRAM/NOR read timings(1)  
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(NE) FSMC_NE low time 5t HCLK + 0.5 5t HCLK + 2 ns
tv(NOE_NE) FSMC_NEx low to FSMC_NOE low 0.5 1.5 ns
tw(NOE) FSMC_NOE low time 5t HCLK – 1 5t HCLK + 1 ns
th(NE_NOE) FSMC_NOE high to FSMC_NE high hold time 0 - ns
tv(A_NE) FSMC_NEx low to FSMC_A valid - 3 ns
th(A_NOE) Address hold time after FSMC_NOE high 0 - ns
tv(BL_NE) FSMC_NEx low to FSMC_BL valid - 0 ns
th(BL_NOE) FSMC_BL hold time after FSMC_NOE high 0.5 - ns
tsu(Data_NE) Data to FSMC_NEx high setup time 2t HCLK - 1 - ns
tsu(Data_NOE) Data to FSMC_NOEx high setup time 2t HCLK - 1 - ns
th(Data_NOE) Data hold time after FSMC_NOE high 0 - ns
th(Data_NE) Data hold time after FSMC_NEx high 0 - ns
tv(NADV_NE) FSMC_NEx low to FSMC_NADV low - 0 ns
tw(NADV) FSMC_NADV low time - t HCLK + 2 ns
1%/
'DWD
)60&B1([
)60&B1%/>@
)60&B'>@
WY%/B1(
WK'DWDB1:(
)60&B12(
$GGUHVV)60&B$>@
WY$B1(
WZ1:(
)60&B1:(
WY1:(B1( WK1(B1:(
WK$B1:(
WK%/B1:(
WY'DWDB1(
WZ1(
DL
)60&B1$'9
WY1$'9B1(
WZ1$'9
DocID16554 Rev 4 69/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
          
Table 32. Asynchronous non-multiplexed SRAM/PSRAM/NOR write timings(1)
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(NE) FSMC_NE low time 3t HCLK + 0.5 3t HCLK + 1.5 ns
tv(NWE_NE) FSMC_NEx low to FSMC_NWE low t HCLK + 0.5 t HCLK + 1.5 ns
tw(NWE) FSMC_NWE low time t HCLK – 0.5 t HCLK + 1 ns
th(NE_NWE) FSMC_NWE high to FSMC_NE high hold time t HCLK – 0.5 - ns
tv(A_NE) FSMC_NEx low to FSMC_A valid - 0 ns
th(A_NWE) Address hold time after FSMC_NWE high t HCLK -n s
tv(BL_NE) FSMC_NEx low to FSMC_BL valid - 1.5 ns
th(BL_NWE) FSMC_BL hold time after FSMC_NWE high t HCLK – 1.5 - ns
tv(Data_NE) FSMC_NEx low to Data valid - t HCLK ns
th(Data_NWE) Data hold time after FSMC_NWE high t HCLK -n s
tv(NADV_NE) FSMC_NEx low to FSMC_NADV low - 0 ns
tw(NADV) FSMC_NADV low time - t HCLK + 1.5 ns
Table 33. Asynchronous multiplexed read timings
Symbol Parameter Min Max Unit
tw(NE) FSMC_NE low time 7t HCLK + 0.5 7t HCLK + 2
ns
tv(NOE_NE) FSMC_NEx low to FSMC_NOE low 3t HCLK + 0.5 3t HCLK + 1.5
tw(NOE) FSMC_NOE low time 4t HCLK – 1 4t HCLK + 1
th(NE_NOE) FSMC_NOE high to FSMC_NE high hold time 0.5 -
tv(A_NE) FSMC_NEx low to FSMC_A valid - 0
tv(NADV_NE) FSMC_NEx low to FSMC_NADV low 0 1
tw(NADV) FSMC_NADV low time t HCLK + 0.5 t HCLK + 2
th(AD_NADV) FSMC_AD (address) valid hold time after FSMC NADV high tHCLK -
th(A_NOE) Address hold time after FSMC_NOE high t HCLK – 2 -
th(BL_NOE) FSMC_BL time after FSMC_NOE high 0.5 -
tv(BL_NE) FSMC_NEx low to FSMC_BL valid - 0
tsu(Data_NE) Data to FSMC_NEx high setup time 4t HCLK – 0.5 -
tsu(Data_NOE) Data to FSMC_NOE high setup time 4t HCLK – 1 -
th(Data_NE) Data hold time after FSMC_NEx high 0 -
th(Data_NOE) Data hold time after FSMC_NOE high 0 -
Electrical characteristics STM32F103xF, STM32F103xG
70/136 DocID16554 Rev 4
Figure 24. Asynchronous multiplexed PSRAM/NOR read waveforms
          
Table 34. Asynchronous multiplexed PSRAM/NOR read timings(1) 
Symbol Parameter Min Max Unit
tw(NE) FSMC_NE low time 7t HCLK + 0.5 7t HCLK + 2  ns
tv(NOE_NE) FSMC_NEx low to FSMC_NOE low 3t HCLK + 0.5 3t HCLK + 1.5  ns
tw(NOE) FSMC_NOE low time 4t HCLK – 1 4t HCLK + 1  ns
th(NE_NOE) FSMC_NOE high to FSMC_NE high hold time 0.5 -  ns
tv(A_NE) FSMC_NEx low to FSMC_A valid - 0  ns
tv(NADV_NE) FSMC_NEx low to FSMC_NADV low 0 1  ns
tw(NADV) FSMC_NADV low time t HCLK + 0.5 t HCLK + 2  ns
th(AD_NADV) FSMC_AD (address) valid hold time after FSMC_NADV high tHCLK - n s
th(A_NOE) Address hold time after FSMC_NOE high t HCLK -2 -  ns
th(BL_NOE) FSMC_BL hold time after FSMC_NOE high 0.5 -  ns
tv(BL_NE) FSMC_NEx low to FSMC_BL valid - 0  ns
tsu(Data_NE) Data to FSMC_NEx high setup time 4t HCLK - 0.5 -  ns
tsu(Data_NOE) Data to FSMC_NOE high setup time 4t HCLK - 1 -  ns
.",
$ATA
&3-#?.",;=
&3-#?!$;=
TV",?.%	
TH$ATA?.%	
!DDRESS&3-#?!;=
TV!?.%	
&3-#?.7%
T V!?.%	
AIB
!DDRESS
&3-#?.!$6
T V.!$6?.%	
TW.!$6	
TSU$ATA?.%	
TH!$?.!$6	
&3-#?.%
&3-#?./%
TW.%	
T W./%	
TV./%?.%	 T H.%?./%	
TH!?./%	
TH",?./%	
TSU$ATA?./%	 TH$ATA?./%	
DocID16554 Rev 4 71/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 25. Asynchronous multiplexed PSRAM/NOR write waveforms
          
th(Data_NE) Data hold time after FSMC_NEx high 0 -  ns
th(Data_NOE) Data hold time after FSMC_NOE high 0 -  ns
1. C L = 15 pF.
Table 35. Asynchronous multiplexed PSRAM/NOR write timings(1)
Symbol Parameter Min Max Unit
tw(NE) FSMC_NE low time 5t HCLK + 0.5 5t HCLK + 2 ns
tv(NWE_NE) FSMC_NEx low to FSMC_NWE low t HCLK + 1 t HCLK + 1.5 ns
tw(NWE) FSMC_NWE low time 3t HCLK + 0.5 3t HCLK + 1 ns
th(NE_NWE) FSMC_NWE high to FSMC_NE high hold time t HCLK – 0.5 - ns
tv(A_NE) FSMC_NEx low to FSMC_A valid - 3.5 ns
tv(NADV_NE) FSMC_NEx low to FSMC_NADV low 0 1 ns
tw(NADV) FSMC_NADV low time t HCLK + 0.5 t HCLK + 1.5 ns
th(AD_NADV) FSMC_AD (address) valid hold time after FSMC_NADV high tHCLK – 0.5 - ns
Table 34. Asynchronous multiplexed PSRAM/NOR read timings(1) (continued)
Symbol Parameter Min Max Unit
1%/
'DWD
)60&B1([
)60&B1%/>@
)60&B$'>@
WY%/B1(
WK'DWDB1:(
)60&B12(
$GGUHVV)60&B$>@
WY$B1(
WZ1:(
)60&B1:(
WY1:(B1( WK1(B1:(
WK$B1:(
WK%/B1:(
WY$B1(
WZ1(
DL%
$GGUHVV
)60&B1$'9
WY1$'9B1(
WZ1$'9
WY'DWDB1$'9
WK$'B1$'9
Electrical characteristics STM32F103xF, STM32F103xG
72/136 DocID16554 Rev 4
Synchronous waveforms and timings
Figure 26 through Figure 29 represent synchronous waveforms and Table 37 through 
Table 39 provide the corresponding timings. The results shown in these tables are obtained 
with the following FSMC configuration:
• BurstAccessMode = FSMC_BurstAccessMode_Enable;
• MemoryType = FSMC_MemoryType_CRAM;
• WriteBurst = FSMC_WriteBurst_Enable;
• CLKDivision = 1; (0 is not supported, see the STM32F10xxx reference manual)
• DataLatency = 1 for NOR Flash; DataLatency = 0 for PSRAM
th(A_NWE) Address hold time after FSMC_NWE high 4t HCLK – 2 - ns
tv(BL_NE) FSMC_NEx low to FSMC_BL valid - 0.5 ns
th(BL_NWE) FSMC_BL hold time after FSMC_NWE high t HCLK – 1.5 - ns
tv(Data_NADV) FSMC_NADV high to Data valid - t HCLK + 6 ns
th(Data_NWE) Data hold time after FSMC_NWE high t HCLK – 0.5 - ns
1. C L = 15 pF.
Table 35. Asynchronous multiplexed PSRAM/NOR write timings(1)
Symbol Parameter Min Max Unit
DocID16554 Rev 4 73/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 26. Synchronous multiplexed NOR/PSRAM read timings
&3-#?#,+
&3-#?.%X
&3-#?.!$6
&3-#?!;=
&3-#?./%
&3-#?!$;= !$;= $ $
&3-#?.7!)4
7!)4#&'  B 7!)40/,  B	
&3-#?.7!)4
7!)4#&'  B 7!)40/,  B	
TW#,+	 TW#,+	
$ATA LATENCY  
"53452.  
TD#,+,
.%X,	 TD#,+,
.%X(	
TD#,+,
.!$6,	
TD#,+,
!6	
TD#,+,
.!$6(	
TD#,+,
!)6	
TD#,+(
./%,	 TD#,+,
./%(	
TD#,+,
!$6	
TD#,+,
!$)6	
TSU!$6
\#,+(	
TH#,+(
!$6	
TSU!$6
\#,+(	 TH#,+(
!$6	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
AII
$
Electrical characteristics STM32F103xF, STM32F103xG
74/136 DocID16554 Rev 4
          
Table 36. Synchronous multiplexed NOR/PSRAM read timings(1) 
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(CLK) FSMC_CLK period 27.6 -  ns
td(CLKL-NExL) FSMC_CLK low to FSMC_NEx low (x = 0...2) - 0.5  ns
td(CLKL-NExH) FSMC_CLK low to FSMC_NEx high (x = 0...2) 1 -  ns
td(CLKL-NADVL) FSMC_CLK low to FSMC_NADV low - 1  ns
td(CLKL-NADVH) FSMC_CLK low to FSMC_NADV high 0.5 -  ns
td(CLKL-AV) FSMC_CLK low to FSMC_Ax valid (x = 16...25) - 0  ns
td(CLKL-AIV) FSMC_CLK low to FSMC_Ax invalid (x = 16...25) 1.5 -  ns
td(CLKL-NOEL) FSMC_CLK low to FSMC_NOE low - 14  ns
td(CLKL-NOEH) FSMC_CLK low to FSMC_NOE high  1 -  ns
td(CLKL-ADV) FSMC_CLK low to FSMC_AD[15:0] valid - 11  ns
td(CLKL-ADIV) FSMC_CLK low to FSMC_AD[15:0] invalid 0.5 -  ns
tsu(ADV-CLKH) FSMC_A/D[15:0] valid data before FSMC_CLK high 2-  n s
th(CLKH-ADV) FSMC_A/D[15:0] valid data after FSMC_CLK high 0 -  ns
tsu(NWAITV-CLKH) FSMC_NWAIT valid before FSMC_CLK high 8 -  ns
th(CLKH-NWAITV) FSMC_NWAIT valid after FSMC_CLK high 2 -  ns
DocID16554 Rev 4 75/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 27. Synchronous multiplexed PSRAM write timings
&3-#?#,+
&3-#?.%X
&3-#?.!$6
&3-#?!;=
&3-#?.7%
&3-#?!$;= !$;= $ $
&3-#?.7!)4
7!)4#&'  B 7!)40/,  B	
TW#,+	 TW#,+	
$ATA LATENCY  
"53452.  
TD#,+,
.%X,	 TD#,+,
.%X(	
TD#,+,
.!$6,	
TD#,+,
!6	
TD#,+,
.!$6(	
TD#,+,
!)6	
TD#,+,
.7%(	TD#,+,
.7%,	
TD#,+,
.",(	
TD#,+,
!$6	
TD#,+,
!$)6	 TD#,+,
$ATA	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
AIG
TD#,+,
$ATA	
&3-#?.",
Electrical characteristics STM32F103xF, STM32F103xG
76/136 DocID16554 Rev 4
          
Table 37. Synchronous multiplexed PSRAM write timings(1)
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(CLK) FSMC_CLK period 27.5 -  ns
td(CLKL-NExL) FSMC_CLK low to FSMC_Nex low (x = 0...2) - 0  ns
td(CLKL-NExH) FSMC_CLK low to FSMC_NEx high (x = 0...2) 1 -  ns
td(CLKL-NADVL) FSMC_CLK low to FSMC_NADV low - 1  ns
td(CLKL-NADVH) FSMC_CLK low to FSMC_NADV high 1 -  ns
td(CLKL-AV) FSMC_CLK low to FSMC_Ax valid (x = 16...25) - 0  ns
td(CLKL-AIV) FSMC_CLK low to FSMC_Ax invalid (x = 16...25) 1 -  ns
td(CLKL-NWEL) FSMC_CLK low to FSMC_NWE low - 1  ns
td(CLKL-NWEH) FSMC_CLK low to FSMC_NWE high 1.5 -  ns
td(CLKL-ADV) FSMC_CLK low to FSMC_AD[15:0] valid - 10  ns
td(CLKL-ADIV) FSMC_CLK low to FSMC_AD[15:0] invalid 1 -  ns
td(CLKL-Data) FSMC_A/D[15:0] valid after FSMC_CLK low - 6  ns
td(CLKL-NBLH) FSMC_CLK low to FSMC_NBL high 1 -  ns
tsu(NWAITV-CLKH) FSMC_NWAIT valid before FSMC_CLK high 7 -  ns
th(CLKH-NWAITV) FSMC_NWAIT valid after FSMC_CLK high 2 -  ns
DocID16554 Rev 4 77/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 28. Synchronous non-multiplexed NOR/PSRAM read timings
          
Table 38. Synchronous non-multiplexed NOR/PSRAM read timings(1) 
Symbol Parameter Min Max Unit
tw(CLK) FSMC_CLK period 27.6 -  ns
td(CLKL-NExL) FSMC_CLK low to FSMC_NEx low (x = 0...2) - 1.5  ns
td(CLKL-NExH) FSMC_CLK low to FSMC_NEx high (x = 0...2) 2 -  ns
td(CLKL-NADVL) FSMC_CLK low to FSMC_NADV low - 0.5  ns
td(CLKL-NADVH) FSMC_CLK low to FSMC_NADV high 1 -  ns
td(CLKL-AV) FSMC_CLK low to FSMC_Ax valid (x = 0...25) - 0  ns
td(CLKL-AIV) FSMC_CLK low to FSMC_Ax invalid (x = 0...25) 2 -  ns
td(CLKL-NOEL) FSMC_CLK low to FSMC_NOE low - t HCLK + 1  ns
td(CLKL-NOEH) FSMC_CLK low to FSMC_NOE high 1.5 -  ns
tsu(DV-CLKH) FSMC_D[15:0] valid data before FSMC_CLK high 3.5 -  ns
th(CLKH-DV) FSMC_D[15:0] valid data after FSMC_CLK high 0 -  ns
tsu(NWAITV-CLKH) FSMC_NWAIT valid before FSMC_SMCLK high 7 -  ns
th(CLKH-NWAITV) FSMC_NWAIT valid after FSMC_CLK high 2 -  ns
&3-#?#,+
&3-#?.%X
&3-#?!;=
&3-#?./%
&3-#?$;= $ $
&3-#?.7!)4
7!)4#&'  B 7!)40/,  B	
&3-#?.7!)4
7!)4#&'  B 7!)40/,  B	
TW#,+	 TW#,+	
$ATA LATENCY  
"53452.  
TD#,+,
.%X,	 TD#,+,
.%X(	
TD#,+,
!6	 TD#,+,
!)6	
TD#,+(
./%,	 TD#,+,
./%(	
TSU$6
\#,+(	 TH#,+(
$6	
TSU$6
\#,+(	 TH#,+(
$6	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
TSU.7!)46
\#,+(	 T H#,+(
.7!)46	
TSU.7!)46
\#,+(	 TH#,+(
.7!)46	
AIH
&3-#?.!$6
TD#,+,
.!$6,	 TD#,+,
.!$6(	
$
Electrical characteristics STM32F103xF, STM32F103xG
78/136 DocID16554 Rev 4
Figure 29. Synchronous non-multiplexed PSRAM write timings
          
1. C L = 15 pF.
Table 39. Synchronous non-multiplexed PSRAM write timings(1) 
Symbol Parameter Min Max Unit
tw(CLK)  FSMC_CLK period 27.6 -  ns
td(CLKL-NExL)  FSMC_CLK low to FSMC_NEx low (x = 0...2) - 0.5  ns
td(CLKL-NExH)  FSMC_CLK low to FSMC_NEx high (x = 0...2) 1.5 -  ns
td(CLKL-NADVL)  FSMC_CLK low to FSMC_NADV low - 1  ns
td(CLKL-NADVH)  FSMC_CLK low to FSMC_NADV high 0.5 -  ns
td(CLKL-AV)  FSMC_CLK low to FSMC_Ax valid (x = 16...25) - 0  ns
td(CLKL-AIV)  FSMC_CLK low to FSMC_Ax invalid (x = 16...25) 1.5 -  ns
td(CLKL-NWEL)  FSMC_CLK low to FSMC_NWE low - 1  ns
td(CLKL-NWEH)  FSMC_CLK low to FSMC_NWE high 1.5 -  ns
td(CLKL-Data)  FSMC_D[15:0] valid data after FSMC_CLK low - 2.5  ns
td(CLKL-NBLH)  FSMC_CLK low to FSMC_NBL high 0.5 -  ns
tsu(NWAITV-CLKH)  FSMC_NWAIT valid before FSMC_CLK high 7 -  ns
th(CLKH-NWAITV)  FSMC_NWAIT valid after FSMC_CLK high 2 -  ns
)60&B&/.
)60&B1([
)60&B1$'9
)60&B$>@
)60&B12(
)60&B$'>@ $'>@ ' '
)60&B1:$,7
:$,7&)* E:$,732/E
)60&B1:$,7
:$,7&)* E:$,732/E
WZ&/. WZ&/.
'DWDODWHQF\ 
%867851 
WG&/./1([/ WG&/./1([+
WG&/./1$'9/
WG&/./$9
WG&/./1$'9+
WG&/./$,9
WG&/.+12(/ WG&/./12(+
WG&/./$'9
WG&/./$',9
WVX$'9&/.+
WK&/.+$'9
WVX$'9&/.+ WK&/.+$'9
WVX1:$,79&/.+ WK&/.+1:$,79
WVX1:$,79&/.+ WK&/.+1:$,79
WVX1:$,79&/.+ WK&/.+1:$,79
DLK
DocID16554 Rev 4 79/136
STM32F103xF, STM32F103xG Electrical characteristics
132
PC Card/CompactFlash controller waveforms and timings
Figure 30 through Figure 35 represent synchronous waveforms and Table 42 provides the 
corresponding timings. The results shown in this table are obtained with the following FSMC 
configuration:
• COM.FSMC_SetupTime = 0x04;
• COM.FSMC_WaitSetupTime = 0x07;
• COM.FSMC_HoldSetupTime = 0x04;
• COM.FSMC_HiZSetupTime = 0x00;
• ATT.FSMC_SetupTime = 0x04;
• ATT.FSMC_WaitSetupTime = 0x07;
• ATT.FSMC_HoldSetupTime = 0x04;
• ATT.FSMC_HiZSetupTime = 0x00;
• IO.FSMC_SetupTime = 0x04;
• IO.FSMC_WaitSetupTime = 0x07;
• IO.FSMC_HoldSetupTime = 0x04;
• IO.FSMC_HiZSetupTime = 0x00;
• TCLRSetupTime = 0;
• TARSetupTime = 0;
Figure 30. PC Card/CompactFlash controller waveforms for common memory read 
access
1. FSMC_NCE4_2 remains high (inac tive during 8-bit access.
1. C L = 15 pF.
)60&B1:(
WZ12(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
WG1&(B12(
WVX'12( WK12('
WY1&([$
WG15(*1&([
WG1,25'1&([
WK1&([$,
WK1&([15(*
WK1&([1,25'
WK1&([1,2:5
DLE
Electrical characteristics STM32F103xF, STM32F103xG
80/136 DocID16554 Rev 4
Figure 31. PC Card/CompactFlash controller waveforms for common memory write 
access
WG1&(B1:( WZ1:(
WK1:('
WY1&(B$
WG15(*1&(B
WG1,25'1&(B
WK1&(B$,
0(0[+,= 
WY1:('
WK1&(B15(*
WK1&(B1,25'
WK1&(B1,2:5
DLE
)60&B1:(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
WG1:(1&(B
WG'1:(
)60&B1&(B +LJK
DocID16554 Rev 4 81/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 32. PC Card/CompactFlash controller waveforms for attribute memory read
access
1. Only data bits 0...7 are read (bits 8...15 are disregarded).
WG1&(B12( WZ12(
WVX'12( WK12('
WY1&(B$ WK1&(B$,
WG15(*1&(B WK1&(B15(*
DLE
)60&B1:(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
WG12(1&(B
+LJK
Electrical characteristics STM32F103xF, STM32F103xG
82/136 DocID16554 Rev 4
Figure 33. PC Card/CompactFlash controller waveforms for attribute memory write
access
1. Only data bits 0...7 are dr iven (bits 8...15 remains HiZ).
Figure 34. PC Card/CompactFlash controller waveforms for I/O space read access
WZ1:(
WY1&(B$
WG15(*1&(B
WK1&(B$,
WK1&(B15(*
WY1:('
DLE
)60&B1:(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
WG1:(1&(B
+LJK
WG1&(B1:(
WG1,25'1&(B WZ1,25'
WVX'1,25' WG1,25''
WY1&([$ WK1&(B$,
DL%
)60&B1:(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
DocID16554 Rev 4 83/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 35. PC Card/CompactFlash controller waveforms for I/O space write access
          
          
WG1&(B1,2:5 WZ1,2:5
WY1&([$ WK1&(B$,
WK1,2:5'
$77[+,= 
WY1,2:5'
DLF
)60&B1:(
)60&B12(
)60&B'>@
)60&B$>@
)60&B1&(B
)60&B1&(B
)60&B15(*
)60&B1,2:5
)60&B1,25'
Table 40. Switching characteristics for PC Card/CF read and write cycles in
attribute/common space
Symbol Parameter Min Max Unit
tv(NCEx-A) FSMC_NCEx low to FSMC_Ay valid - 0
 ns
th(NCEx-AI) FSMC_NCEx high to FSMC_Ax invalid 0 -
td(NREG-NCEx) FSMC_NCEx low to FSMC_NREG valid - 2
th(NCEx-NREG) FSMC_NCEx high to FSMC_NREG invalid t HCLK + 4 -
td(NCEx_NWE) FSMC_NCEx low to FSMC_NWE low - 5t HCLK + 1
td(NCEx_NOE) FSMC_NCEx low to FSMC_NOE low - 5t HCLK + 1
tw(NOE) FSMC_NOE low width 8t HCLK - 0.5 8t HCLK + 1
td(NOE-NCEx FSMC_NOE high to FSMC_NCEx high 5t HCLK - 0.5 -
tsu(D-NOE) FSMC_D[15:0] valid data before FSMC_NOE high 32 -
th(NOE-D) FSMC_NOE high to FSMC_D[15:0] invalid t HCLK -
tw(NWE) FSMC_NWE low width 8t HCLK – 1 8t HCLK + 4
td(NWE_NCEx) FSMC_NWE high to FSMC_NCEx high 5t HCLK + 1.5 -
td(NCEx-NWE) FSMC_NCEx low to FSMC_NWE low - 5t HCLK + 1
tv(NWE-D) FSMC_NWE low to FSMC_D[15:0] valid - 0
th(NWE-D) FSMC_NWE high to FSMC_D[15:0] invalid 11t HCLK -
td(D-NWE) FSMC_D[15:0] valid before FSMC_NWE high 13t HCLK + 2.5 -
Electrical characteristics STM32F103xF, STM32F103xG
84/136 DocID16554 Rev 4
          
NAND controller waveforms and timings
Figure 36 through Figure 39 represent synchronous waveforms and Table 43 provides the 
corresponding timings. The results shown in this table are obtained with the following FSMC 
configuration:
• COM.FSMC_SetupTime = 0x00;
• COM.FSMC_WaitSetupTime = 0x02;
• COM.FSMC_HoldSetupTime = 0x01;
• COM.FSMC_HiZSetupTime = 0x00;
• ATT.FSMC_SetupTime = 0x00;
• ATT.FSMC_WaitSetupTime = 0x02;
• ATT.FSMC_HoldSetupTime = 0x01;
• ATT.FSMC_HiZSetupTime = 0x00;
• Bank = FSMC_Bank_NAND;
• MemoryDataWidth = FSMC_MemoryDataWidth_16b;
• ECC = FSMC_ECC_Enable;
• ECCPageSize = FSMC_ECCPageSize_512Bytes;
• TCLRSetupTime = 0;
• TARSetupTime = 0;
Table 41. Switching characteristics for PC Card/CF read and write cycles in I/O space
Symbol Parameter Min Max Unit
tw(NIOWR) FSMC_NIOWR low width 8 THCLK  - ns
tv(NIOWR-D) FSMC_NIOWR low to FSMC_D[15:0] valid  - 5 THCLK - 4 ns
th(NIOWR-D) FSMC_NIOWR high to FSMC_D[15:0] invalid 11THCLK - 7 -n s
td(NCE4_1-NIOWR) FSMC_NCE4_1 low to FSMC_NIOWR valid  - 5THCLK + 1 ns
th(NCEx-NIOWR) FSMC_NCEx high to FSMC_NIOWR invalid  5THCLK -2.5  -n s
td(NIORD-NCEx) FSMC_NCEx low to FSMC_NIORD valid  - 5THCLK -0.5 ns
th(NCEx-NIORD) FSMC_NCEx high to FSMC_NIORD) valid 5 THCLK - 0.5  -n s
tw(NIORD) FSMC_NIORD low width  8THCLK  - ns
tsu(D-NIORD) FSMC_D[15:0] valid before FSMC_NIORD high 28 - ns
td(NIORD-D) FSMC_D[15:0] valid after FSMC_NIORD high 3 - ns
DocID16554 Rev 4 85/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 36. NAND controller waveforms for read access
Figure 37. NAND controller waveforms for write access
)60&B1:(
)60&B12(15(
)60&B'>@
WVX'12( WK12('
DLE
$/()60&B$
&/()60&B$
)60&B1&([ /RZ
WG$/(12( WK12($/(
AIC
WK1:('WY1:('
)60&B1:(
)60&B12(15(
)60&B'>@
$/()60&B$
&/()60&B$
)60&B1&([
WG$/(1:( WK1:($/(
Electrical characteristics STM32F103xF, STM32F103xG
86/136 DocID16554 Rev 4
Figure 38. NAND controller waveforms for common memory read access
Figure 39. NAND controller waveforms for common memory write access
          
Table 42. Switching characteristics for NAND Flash read cycles(1)
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(NOE) FSMC_NOE low width 3t HCLK – 1 3t HCLK + 1  ns
tsu(D-NOE) FSMC_D[15:0] valid data before FSMC_NOE high 13 -  ns
th(NOE-D) FSMC_D[15:0] valid data after FSMC_NOE high 0 -  ns
td(ALE-NOE) FSMC_ALE valid before FSMC_NOE low - 2t HCLK  ns
th(NOE-ALE) FSMC_NWE high to FSMC_ALE invalid 2t HCLK - n s
)60&B1:(
)60&B12(
)60&B'>@
WZ12(
WVX'12( WK12('
DLE
$/()60&B$
&/()60&B$
)60&B1&([ /RZ
WG$/(12( WK12($/(
WZ1:(
WK1:('WY1:('
DLE
)60&B1:(
)60&B12(
)60&B'>@
WG'1:(
$/()60&B$
&/()60&B$
)60&B1&([ /RZ
WG$/(1:( WK1:($/(
DocID16554 Rev 4 87/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
Table 43. Switching characteristics for NAND Flash write cycles(1)
1. C L = 15 pF.
Symbol Parameter Min Max Unit
tw(NWE) FSMC_NWE low width 3t HCLK 3tHCLK  ns
tv(NWE-D) FSMC_NWE low to FSMC_D[15:0] valid - 0  ns
th(NWE-D) FSMC_NWE high to FSMC_D[15:0] invalid 2t HCLK + 2 -  ns
td(ALE-NWE) FSMC_ALE valid before FSMC_NWE low - 3t HCLK + 1.5  ns
th(NWE-ALE) FSMC_NWE high to FSMC_ALE invalid 3t HCLK + 8 -  ns
td(ALE-NOE) FSMC_ALE valid before FSMC_NOE low - 2t HCLK  ns
th(NOE-ALE) FSMC_NWE high to FSMC_ALE invalid 2t HCLK - n s
Electrical characteristics STM32F103xF, STM32F103xG
88/136 DocID16554 Rev 4

### 5.3.11 EMC characteristics
Susceptibility tests are performed on a sample basis during device characterization.
Functional EMS (electromagnetic susceptibility)
While a simple application is executed on the device (toggling 2 LEDs through I/O ports). 
the device is stressed by two electromagnetic events until a failure occurs. The failure is 
indicated by the LEDs:
• Electrostatic discharge (ESD) (positive and negative) is applied to all device pins until 
a functional disturbance occurs. This test is compliant with the IEC 61000-4-2 standard.
• FTB: A Burst of Fast Transient voltage (positive and negative) is applied to VDD and 
VSS through a 100 pF capacitor, until a functional disturbance occurs. This test is 
compliant with the IEC 61000-4-4 standard.
A device reset allows normal operations to be resumed. 
The test results are given in Table 44. They are based on the EMS levels and classes 
defined in application note AN1709.
          
Designing hardened software to avoid noise problems
EMC characterization and optimization are performed at component level with a typical 
application environment and simplified MCU software. It should be noted that good EMC 
performance is highly dependent on the user application and the software in particular.
Therefore it is recommended that the user applies EMC software optimization and 
prequalification tests in relation with the EMC level requested for his application.
Software recommendations
The software flowchart must include the management of runaway conditions such as:
• Corrupted program counter
• Unexpected reset
• Critical Data corruption (control registers...)
Prequalification trials
Most of the common failures (unexpected reset and program counter corruption) can be 
reproduced by manually forcing a low state on the NRST pin or the Oscillator pins for 1 
second.
Table 44. EMS characteristics
Symbol Parameter Conditions Level/Class
VFESD Voltage limits to be applied on any I/O pin to induce a functional disturbance VDD = 3.3 V, LQFP144, TA = +25 °C,  fHCLK = 72 MHz conforms to IEC 61000-4-2 2B
VEFTB
Fast transient voltage burst limits to be 
applied through 100 pF on VDD and VSS 
pins to induce a functional disturbance
VDD = 3.3 V, LQFP144, TA = +25 °C,  
fHCLK = 72 MHz 
conforms to IEC 61000-4-4
4A
DocID16554 Rev 4 89/136
STM32F103xF, STM32F103xG Electrical characteristics
132
To complete these trials, ESD stress can be applied directly on the device, over the range of 
specification values. When unexpected behavior is detected, the software can be hardened 
to prevent unrecoverable errors occurring (see application note AN1015).
Electromagnetic Interference (EMI)
The electromagnetic field emitted by the device are monitored while a simple application is 
executed (toggling 2 LEDs through the I/O ports). This emission test is compliant with 
IEC 61967-2 standard which specifies the test board and the pin loading.
          

### 5.3.12 Absolute maximum ratings (electrical sensitivity)
Based on three different tests (ESD, LU) using specific measurement methods, the device is 
stressed in order to determine its performance in terms of electrical sensitivity.
Electrostatic discharge (ESD)
Electrostatic discharges (a positive then a negative pulse separated by 1 second) are 
applied to the pins of each sample according to each pin combination. The sample size 
depends on the number of supply pins in the device (3 parts × (n+1) supply pins). This test 
conforms to the JESD22-A114/C101 standard.
           
Static latch-up
Two complementary static tests are required on six parts to assess the latch-up 
performance: 
• A supply overvoltage is applied to each power supply pin
• A current injection is applied to each input, output and configurable I/O pin
These tests are compliant with EIA/JESD 78A IC latch-up standard.
Table 45. EMI characteristics
Symbol Parameter Conditions Monitoredfrequency band Max vs. [fHSE/fHCLK] Unit8/48 MHz 8/72 MHz
SEMI Peak level
VDD = 3.3 V, TA = 25 °C, 
LQFP144 package 
compliant with IEC 
61967-2
0.1 to 30 MHz 8 12
dBµV30 to 130 MHz 31 21
130 MHz to 1GHz 28 33
SAE EMI Level 4 4 -
Table 46. ESD absolute maximum ratings
Symbol Ratings Conditions Class Maximum value(1)
1. Guaranteed by characterization results, not tested in production.
Unit
VESD(HBM) Electrostatic discharge voltage (human body model) TA = +25 °C, conforming to JESD22-A114 22 0 0 0
V
VESD(CDM)
Electrostatic discharge 
voltage (charge device 
model)
TA = +25 °C, conforming 
to JESD22-C101 III 500
Electrical characteristics STM32F103xF, STM32F103xG
90/136 DocID16554 Rev 4
          

### 5.3.13 I/O current in jection characteristics
As a general rule, current injection to the I/O pins, due to external voltage below VSS or 
above VDD (for standard, 3 V-capable I/O pins) should be avoided during normal product 
operation. However, in order to give an indication of the robustness of the microcontroller in 
cases when abnormal injection accidentally happens, susceptibility tests are performed on a 
sample basis during device characterization.
Functional susceptibilty to I/O current injection 
While a simple application is executed on the device,  the device is stressed by injecting 
current into the I/O pins programmed in floating input mode. While current is injected into 
the I/O pin, one at a time, the device is checked for functional failures. 
The failure is indicated by an out of range parameter: ADC error above a certain limit (>5 
LSB TUE), out of spec current injection on adjacent pins or other functional failure (for 
example reset, oscillator frequency deviation). 
The test results are given in Table 48
          
Table 47. Electrical sensitivities
Symbol Parameter Conditions Class
LU Static latch-up class T A = +105 °C conforming to JESD78A II level A
Table 48. I/O current injection susceptibility 
Symbol Description
Functional susceptibility 
UnitNegative 
injection
Positive 
injection
IINJ
Injected current on OSC_IN32, 
OSC_OUT32, PA4, PA5, PC13 -0 +0
mAInjected current on all FT pins -5 +0
Injected current on any other pin -5 +5
DocID16554 Rev 4 91/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.14 I/O port characteristics
General input/output characteristics
Unless otherwise specified, the parameters given in Table 49 are derived from tests 
performed under the conditions summarized in Table 10. All I/Os are CMOS and TTL 
compliant.
          
All I/Os are CMOS and TTL compliant (no software configuration required). Their 
characteristics cover more than the strict CMOS-technology or TTL parameters. The 
coverage of these requirements is shown in Figure 40 and Figure 41 for standard I/Os, and 
in Figure 42 and Figure 43 for 5 V tolerant I/Os. 
Table 49. I/O static characteristics
Symbol Parameter C onditions Min Typ  Max Unit
VIL
Standard IO input low 
level voltage
-
–0.3 - 0.28*(VDD-2 V)+0.8 V V
IO FT(1) input low level 
voltage –0.3 - 0.32*(VDD-2 V)+0.75 V V
VIH
Standard IO input high 
level voltage - 0.41*(VDD-2 V)+1.3 V -V DD+0.3 V
IO FT(1) input high level 
voltage
VDD > 2 V 0.42*(VDD-2 
V)+1 V -
5.5 
V
VDD ≤ 2 V 5.2
Vhys
Standard IO Schmitt 
trigger voltage 
hysteresis(2) -
200 - - mV
IO FT Schmitt trigger 
voltage hysteresis(2) 5% VDD(3) -- m V
Ilkg Input leakage current (4)
VSS ≤ VIN ≤ VDD
Standard I/Os -- ±1 µA
VIN= 5 V, I/O FT - - 3
RPU Weak pull-up equivalent resistor(5) VIN = VSS 30 40 50 k Ω
RPD Weak pull-down equivalent resistor(5) VIN = VDD 30 40 50 k Ω
CIO I/O pin capacitance - - 5 - pF
1. FT = Five-volt tolerant. In order to sustain a voltage higher than V DD+0.3 the internal pull-up/pull-down resistors must be disabled.
2. Hysteresis voltage between Schmitt trigger switching levels . Guaranteed by characterization results, not tested in 
production.
3. With a minimum of 100 mV.
4. Leakage could be higher than max. if negativ e current is injected on adjacent pins.
5. Pull-up and pull-down resistors are designed with a true resi stance in series with a switchable PMOS/NMOS. This 
MOS/NMOS contribution to the series resistance is minimum (~10% order).
Electrical characteristics STM32F103xF, STM32F103xG
92/136 DocID16554 Rev 4
Figure 40. Standard I/O input characteristics - CMOS port
Figure 41. Standard I/O input characteristics - TTL port
Figure 42. 5 V tolerant I/O input characteristics - CMOS port
AIB
6$$ 6	


 
)NPUT RANGE 
NOT GUARANTEED



6)(6$$
	


\#-/3 STANDARD REQUIREMENT 6
)(6$$ 

6)(6), 6	
\#-/3 STANDARD REQUIREMENT 6
),6$$




  
7),MAX
7)(MIN
6 $$
	6),
AI
 
)NPUT RANGE 
NOT GUARANTEED
6)(6), 6	






44, REQUIREMENTS  6 )( 6
6)(6$$
	
6),6$$
	
44, REQUIREMENTS  6 ),6
6$$ 6	
7),MAX
7)(MIN
6$$

 
\#-/3 STANDARD REQUIREMENTS 6
)(6$$
 
\#-/3 STANDARD REQUIRMENT 6
),6$$




  








6)(6), 6	
6$$ 6	
)NPUT RANGE 
NOT GUARANTEED
AIB
6)(6$$
	
6),6$$
	
DocID16554 Rev 4 93/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 43. 5 V tolerant I/O input characteristics - TTL port
Output driving current
The GPIOs (general purpose input/outputs) can sink or source up to ±8 mA, and sink or 
source up to ± 20 mA (with a relaxed VOL/VOH) except PC13, PC14 and PC15 which can 
sink or source up to ±3 mA. When using the GPIOs PC13 to PC15 in output mode, the 
speed should not exceed 2 MHz with a maximum load of 30 pF.
In the user application, the number of I/O pins which can drive current must be limited to 
respect the absolute maximum rating specified in Section 5.2:
• The sum of the currents sourced by all the I/Os on VDD, plus the maximum Run 
consumption of the MCU sourced on VDD, cannot exceed the absolute maximum rating 
IVDD (see Table 8). 
• The sum of the currents sunk by all the I/Os on VSS plus the maximum Run 
consumption of the MCU sunk on VSS cannot exceed the absolute maximum rating 
IVSS (see Table 8). 
Output voltage levels
Unless otherwise specified, the parameters given in Table 50 are derived from tests 
performed under ambient temperature and VDD supply voltage conditions summarized in 
Table 10. All I/Os are CMOS and TTL compliant.
          


 
NOT GUARANTEED 
)NPUT RANGE



44, REQUIREMENT  6)(6
6)(
6$$
	
6),
6$$
	
44, REQUIREMENTS 6),6 
6)(6), 6	
6$$ 6	
7),MAX
7)(MIN
AI
Table 50. Output voltage characteristics 
Symbol Parameter Conditions Min Max Unit
VOL(1) Output low level voltage for an I/O pin when 8 pins are sunk at same time TTL port(3)
IIO = +8 mA
2.7 V < VDD < 3.6 V
-0 . 4
V
VOH(2) Output high level voltage for an I/O pin when 8 pins are sourced at same time VDD–0.4 -
VOL (1) Output low level voltage for an I/O pin when 8 pins are sunk at same time CMOS port(3)
IIO =+ 8mA
2.7 V < VDD < 3.6 V
-0 . 4
V
VOH (2) Output high level voltage for an I/O pin when 8 pins are sourced at same time 2.4 -
Electrical characteristics STM32F103xF, STM32F103xG
94/136 DocID16554 Rev 4
VOL(1)(4) Output low level voltage for an I/O pin when 8 pins are sunk at same time IIO = +20 mA
2.7 V < VDD < 3.6 V
-1 . 3
V
VOH(2)(4) Output high level voltage for an I/O pin when 8 pins are sourced at same time VDD–1.3 -
VOL(1)(4) Output low level voltage for an I/O pin when 8 pins are sunk at same time IIO = +6 mA
2 V < VDD < 2.7 V
-0 . 4
V
VOH(2)(4) Output high level voltage for an I/O pin when 8 pins are sourced at same time VDD–0.4 -
1. The I IO current sunk by the device must always respect the absolute maximum rating specified in Table 8 and the sum of IIO (I/O ports and control pins) must not exceed IVSS.
2. The I IO current sourced by the device must always respect the absolute maximum rating specified in Table 8 and the sum of IIO (I/O ports and control pins) must not exceed IVDD.
3. TTL and CMOS outputs are compatible with JEDEC standards JESD36 and JESD52.
4. Guaranteed by characterization results, not tested in production.
Table 50. Output voltage characteristics (continued)
Symbol Parameter Conditions Min Max Unit
DocID16554 Rev 4 95/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Input/output AC characteristics
The definition and values of input/output AC characteristics are given in Figure 44 and 
Table 51, respectively.
Unless otherwise specified, the parameters given in Table 51 are derived from tests 
performed under ambient temperature and VDD supply voltage conditions summarized in 
Table 10. 
          
Table 51. I/O AC characteristics(1)  
1. The I/O speed is configured using the MODEx[1:0] bits. Refer to the STM32F10xxx reference manual for a 
description of GPIO Port configuration register.
MODEx[1:0] 
bit value(1) Symbol Parameter Conditions Min Max Unit
10
fmax(IO)out Maximum frequency(2)
2. The maximum frequency is defined in Figure 44.
CL = 50 pF, VDD = 2 V to 3.6 V - 2 MHz
tf(IO)out Output high to low level fall time
CL = 50 pF, VDD = 2 V to 3.6 V
-1 2 5 (3)
3. Guaranteed by design, not tested in production.
ns
tr(IO)out Output low to high level rise time -1 2 5 (3)
01
fmax(IO)out Maximum frequency(2) CL = 50 pF, VDD = 2 V to 3.6 V - 10 MHz
tf(IO)out Output high to low level fall time
CL = 50 pF, VDD = 2 V to 3.6 V
-2 5 (3)
ns
tr(IO)out Output low to high level rise time -2 5 (3)
11
Fmax(IO)out Maximum frequency(2)
CL = 30 pF, VDD = 2.7 V to 3.6 V - 50 MHz
CL = 50 pF, VDD = 2.7 V to 3.6 V - 30 MHz
CL = 50 pF, VDD = 2 V to 2.7 V - 20 MHz
tf(IO)out Output high to low level fall time
CL = 30 pF, VDD = 2.7 V to 3.6 V - 5 (3)
ns
CL = 50 pF, VDD = 2.7 V to 3.6 V - 8 (3)
CL = 50 pF, VDD = 2 V to 2.7 V - 12 (3)
tr(IO)out Output low to high level rise time
CL = 30 pF, VDD = 2.7 V to 3.6 V - 5 (3)
CL = 50 pF, VDD = 2.7 V to 3.6 V - 8 (3)
CL = 50 pF, VDD = 2 V to 2.7 V - 12 (3)
-t EXTIpw
Pulse width of external 
signals detected by 
the EXTI controller
-1 0 - n s
Electrical characteristics STM32F103xF, STM32F103xG
96/136 DocID16554 Rev 4
Figure 44. I/O AC characteristics definition 

### 5.3.15 NRST pin characteristics
The NRST pin input driver uses CMOS technology. It is connected to a permanent pull-up 
resistor, RPU (see Table 49).
Unless otherwise specified, the parameters given in Table 52 are derived from tests 
performed under ambient temperature and VDD supply voltage conditions summarized in 
Table 10. 
          
DLG



WU,2RXW
287387
(;7(51$/
21&/
0D[LPXPIUHTXHQF\LVDFKLHYHGLIWUWI7DQGLIWKHGXW\F\FOHLV
ZKHQORDGHGE\&/VSHFLILHGLQWKHWDEOH³,2$&FKDUDFWHULVWLFV´




7
WI,2RXW
Table 52. NRST pin characteristics  
Symbol Parameter Condi tions Min Typ Max Unit
VIL(NRST)(1)
1. Guaranteed by design, not tested in production.
NRST Input low level voltage - –0.5 - 0.8
V
VIH(NRST)(1) NRST Input high level voltage - 2 - V DD+0.5
Vhys(NRST) NRST Schmitt trigger voltage hysteresis - - 200 - mV
RPU Weak pull-up equivalent resistor(2)
2. The pull-up is designed with a true resistance in seri es with a switchable PMOS. This PMOS contribution 
to the series resistance must be minimum (~10% order).
VIN = VSS 30 40 50 k Ω
VF(NRST)(1) NRST Input filtered pulse - - - 100 ns
VNF(NRST)(1) NRST Input not filtered pulse - 300 - - ns
DocID16554 Rev 4 97/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 45. Recommended NRST pin protection 
1. The reset network protects t he device against parasitic resets.
2. The user must ensure that the level on the NRST pin can go below the V IL(NRST) max level specified in Table 52. Otherwise the reset will not be taken into account by the device.

### 5.3.16 TIM time r characteristics
The parameters given in Table 53 are guaranteed by design.
Refer to Section 5.3.14: I/O port characteristics for details on the input/output alternate 
function characteristics (output compare, input capture, external clock, PWM output).
           
DLF
670)
5381567
9''
)LOWHU
,QWHUQDO5HVHW
)
([WHUQDO
UHVHWFLUFXLW
Table 53. TIMx(1) characteristics 
1. TIMx is used as a general term to refer to the TIM1, TIM2, TIM3 and TIM4 timers.
Symbol Parameter Conditions Min Max Unit
tres(TIM) Timer resolution time
-1 - t TIMxCLK
 fTIMxCLK = 72 MHz 13.9 - ns
fEXT Timer external clock frequency on CH1 to CH4  -0 f TIMxCLK/2 MHzfTIMxCLK = 72 MHz 0 36 MHz
ResTIM Timer resolution - - 16 bit
tCOUNTER
16-bit counter clock period 
when internal clock is 
selected
- 1 65536 t TIMxCLK
 fTIMxCLK = 72 MHz 0.0139 910 µs
tMAX_COUNT Maximum possible count
- - 65536 × 65536 t TIMxCLK
 fTIMxCLK = 72 MHz - 59.6 s
Electrical characteristics STM32F103xF, STM32F103xG
98/136 DocID16554 Rev 4

### 5.3.17 Communications interfaces
I2C interface characteristics
The STM32F103xF, STM32F103xD and STM32F103xGSTM32F103xF and STM32F103xG 
performance line I2C interface meets the requirements of the standard I2C communication 
protocol with the following restrictions: the I/O pins SDA and SCL are mapped to are not 
“true” open-drain. When configured as open-drain, the PMOS connected between the I/O 
pin and VDD is disabled, but is still present.
The I2C characteristics are described in Table 54. Refer also to Section 5.3.14: I/O port 
characteristics for more details on the input/output alternate function characteristics (SDA 
and SCL).
          
Table 54. I2C characteristics  
Symbol Parameter
Standard mode 
I2C(1)(2)
1. Guaranteed by design, not tested in production.
Fast mode I2C(1)(2)
2. f PCLK1 must be at least 2 MHz to achieve standard mode I2C frequencies. It must be at least 4 MHz to achieve the fast mode I2C frequencies and it must be a multiple of 10 MHz in order to reach the I2C fast 
mode maximum clock speed of 400 kHz.
Unit
Min Max Min Max
tw(SCLL) SCL clock low time 4.7 - 1.3 - µs
tw(SCLH) SCL clock high time 4.0 - 0.6 -
tsu(SDA) SDA setup time 250 - 100 -
ns
th(SDA) SDA data hold time - 3450 (3) -9 0 0 (3)
3. The device must internally provide a hold time of at least 300ns for the SDA signal in order to bridge the 
undefined region on the falling edge of SCL.
tr(SDA)
tr(SCL) SDA and SCL rise time - 1000 - 300
tf(SDA)
tf(SCL) SDA and SCL fall time - 300 - 300 
th(STA) Start condition hold time 4.0 - 0.6 -
µs
tsu(STA) Repeated Start condition setup time 4.7 - 0.6 -
tsu(STO) Stop condition setup time 4.0 - 0.6 - μs
tw(STO:STA) Stop to Start condition time (bus free) 4.7 - 1.3 - μs
Cb Capacitive load for each bus line - 400 - 400 pF
tSP
Pulse width of the spikes 
that are suppressed by the 
analog filter for standard and 
fast mode
05 0 (4)
4. The minimum width of the spikes fi ltered by the analog filter is above tSP(max).
05 0 (4) μs
DocID16554 Rev 4 99/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 46. I2C bus AC waveforms and measurement circuit
1. Measurement points are done at CMOS levels: 0.3VDD and 0.7VDD.
2. Rs: Series protection resistors.
3. Rp: Pull-up resistors.
4. VDD_I2C : I2C bus supply 
          
Table 55. SCL frequency (fPCLK1= 36 MHz.,VDD_I2C = 3.3 V)(1)(2)
1. R P = External pull-up resistance, fSCL = I2C speed.
2. For speeds around 200 kHz, the tolerance on the achieved speed is of ±5%. For other speed ranges, the 
tolerance on the achieved speed ±2%. These variations depend on the accuracy of the external 
components used to design the application.
fSCL (kHz)
I2C_CCR value
RP = 4.7 kΩ
400 0x801E
300 0x8028
200 0x803C
100 0x00B4
50 0x0168
20 0x0384
ĂŝϭϰϵϳϵĚ
^d  Zd
^
ZW
/ϸďƵƐ
sͺ/Ϯ
^dDϯϮ
^
^>
ƚĨ;^Ϳ ƚƌ;^Ϳ
^>
ƚŚ;^dͿ
ƚǁ;^>,Ϳ
ƚǁ;^>>Ϳ
ƚƐƵ;^Ϳ
ƚƌ;^>Ϳ ƚĨ;^>Ϳ
ƚŚ;^Ϳ
^ d Z dZWd
^d  ZdƚƐƵ;^dͿ
ƚƐƵ;^dKͿ
^d K W ƚǁ;^dK͗^dͿ
sͺ/Ϯ
ZW
Z^
Z^
Electrical characteristics STM32F103xF, STM32F103xG
100/136 DocID16554 Rev 4
I2S - SPI characteristics
Unless otherwise specified, the parameters given in Table 56 for SPI or in Table 57 for I2S 
are derived from tests performed under ambient temperature, fPCLKx frequency and VDD 
supply voltage conditions summarized in Table 10.
Refer to Section 5.3.14: I/O port characteristics for more details on the input/output alternate 
function characteristics (NSS, SCK, MOSI, MISO for SPI and WS, CK, SD for I2S).
          
Table 56. SPI characteristics
Symbol Parameter Conditions Min Max Unit
fSCK
1/tc(SCK) SPI clock frequency
Master mode - 18
MHz
Slave mode -  18
tr(SCK)
tf(SCK)
SPI clock rise and fall 
time Capacitive load: C = 30 pF -  8 ns
DuCy(SCK) SPI slave input clock duty cycle Slave mode 30 70 %
tsu(NSS)(1)
1. Guaranteed by characterization results, not tested in production.
NSS setup time Slave mode 4t PCLK -
ns
th(NSS)(1) NSS hold time Slave mode 2t PCLK -
tw(SCKH)(1)
tw(SCKL)(1) SCK high and low time Master mode, fPCLK = 36 MHz, presc = 4  50 60
tsu(MI) (1)
tsu(SI)(1) Data input setup time
Master mode 5 -
Slave mode 5 -
th(MI) (1)
Data input hold time
Master mode 5 -
th(SI)(1) Slave mode 4 -
ta(SO)(1)(2)
2. Min time is for the minimum time to drive the output and the max time is for the maximum time to validate 
the data.
Data output access time Slave mode, f PCLK = 20 MHz  0 3t PCLK
tdis(SO)(1)(3)
3. Min time is for the minimum time to invalidate the output and the max time is for the maximum time to put 
the data in Hi-Z
Data output disable time Slave mode 2 10
tv(SO) (1) Data output valid time Slave mode (after enable edge) - 25
tv(MO)(1) Data output valid time Master mode (after enable edge) - 5
th(SO)(1)
Data output hold time
Slave mode (after enable edge) 15 -
th(MO)(1) Master mode (after enable edge) 2 -
DocID16554 Rev 4 101/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 47. SPI timing diagram - slave mode and CPHA = 0
Figure 48. SPI timing diagram - slave mode and CPHA = 1(1)
1. Measurement points are done at CMOS levels: 0.3V DD and 0.7VDD.
DLF
^</ŶƉƵƚ
W,с Ϭ
DK^/
/ EWhd
D/^K
KhdW hd
W,с Ϭ
D^  K hd
D^  / E
/ dϲ Khd
>^ /E
>^ Khd
WK>сϬ
WK>сϭ
/ dϭ /E
E^^ŝŶƉƵƚ
ƚ^h;E^^Ϳ
ƚĐ;^<Ϳ
ƚŚ;E^^Ϳ
ƚĂ;^KͿ
ƚǁ;^<,Ϳ
ƚǁ;^<>Ϳ
ƚǀ;^KͿ ƚŚ;^KͿ ƚƌ;^<Ϳ
ƚĨ;^<Ϳ
ƚĚŝƐ;^KͿ
ƚƐƵ;^/Ϳ
ƚŚ;^/Ϳ
DL
6&.,QSXW
&3+$ 
026,
,1387
0,62
287387
&3+$ 
06% 287
06% ,1
%,7 287
/6% ,1
/6% 287
&32/ 
&32/ 
%,7 ,1
W68166 WF6&. WK166
WD62
WZ6&.+
WZ6&./
WY62 WK62 WU6&.WI6&. WGLV62
WVX6, WK6,
166LQSXW
Electrical characteristics STM32F103xF, STM32F103xG
102/136 DocID16554 Rev 4
Figure 49. SPI timing diagram - master mode(1)
1. Measurement points are done at CMOS levels: 0.3V DD and 0.7VDD.
AI6
3#+ /UTPUT
\#0(! 
-/3)
/54054
-)3/
).0 54
\#0(! 
-3 ").
- 3" /54
") 4 ).
,3" /54
,3" ).
\#0/,
\#0/,
" ) 4 /54
.3 3 INPUT
TC3#+	
TW3#+(	
TW3#+,	
TR3#+	
TF3#+	
TH-)	
(IGH
3#+ /UTPUT
\#0(!
\#0(!
\#0/,
\#0/,
TSU-)	
TV-/	 TH-/	
DocID16554 Rev 4 103/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
Table 57. I2S characteristics 
Symbol Parameter Conditions Min Max Unit
DuCy(SCK) I2S slave input clock duty cycle Slave mode 30 70 %
fCK 
1/tc(CK) I2S clock frequency
Master mode (data: 16 bits, 
Audio frequency = 48 kHz)  1.522  1.525 MHz
Slave mode 0  6.5
tr(CK) 
tf(CK) I2S clock rise and fall time Capacitive load C L = 50 pF -  8
ns
tv(WS) (1) WS valid time Master mode 3 -
th(WS) (1) WS hold time Master mode I2S2 2 -I2S3 0 -
tsu(WS) (1) WS setup time Slave mode 4 -
th(WS) (1) WS hold time Slave mode 0 -
tw(CKH) (1)
CK high and low time Master fPCLK= 16 MHz, audio frequency = 48 kHz  312.5 -tw(CKL) (1)  345 -
tsu(SD_MR) (1) Data input setup time Master receiver I2S2  2 -I2S3 6.5 -
tsu(SD_SR) (1) Data input setup time Slave receiver 1.5 -
th(SD_MR)(1)(2)
Data input hold time
Master receiver  0 -
th(SD_SR) (1)(2) Slave receiver 0.5 -
tv(SD_ST) (1)(2) Data output valid time Slave transmitter (after enable edge) - 1 8
th(SD_ST) (1) Data output hold time Slave transmitter (after enable edge)  11 -
tv(SD_MT) (1)(2) Data output valid time Master transmitter (after enable edge) - 3
th(SD_MT) (1) Data output hold time Master transmitter (after enable edge)  0-
1. Guaranteed by design and/or characteri zation results, not tested in production.
2. Depends on f PCLK. For example, if fPCLK=8 MHz, then TPCLK = 1/fPLCLK =125 ns.
Electrical characteristics STM32F103xF, STM32F103xG
104/136 DocID16554 Rev 4
Figure 50. I2S slave timing diagram (Philips protocol)(1) 
1. Measurement points are done at CMOS levels: 0.3 × V DD and 0.7 × VDD.
2. LSB transmit/receive of the previ ously transmitted byte. No LSB transmit/receive is sent before the first 
byte.
Figure 51. I2S master timing diagram (Philips protocol)(1)
1. Guaranteed by characterization results, not tested in production.
2. LSB transmit/receive of the previ ously transmitted byte. No LSB transmit/receive is sent before the first 
byte. &.,QSXW
&32/ 
&32/ 
WF&.
:6LQSXW
6'WUDQVPLW
6'UHFHLYH
WZ&.+ WZ&./
WVX:6 WY6'B67 WK6'B67
WK:6
WVX6'B65 WK6'B65
06%UHFHLYH %LWQUHFHLYH /6%UHFHLYH
06%WUDQVPLW %LWQWUDQVPLW /6%WUDQVPLW
DLE
/6%UHFHLYH
/6%WUDQVPLW
\#+ OUTPUT
\#0/,  
\#0/,  
TC#+	
73 OUTPUT
3$RECEIVE
3$TRANSMIT
TW#+(	
TW#+,	
TSU3$?-2	
TV3$?-4	 TH3$?-4	
TH73	
TH3$?-2	
-3" RECEIVE "ITN RECEIVE ,3" RECEIVE
-3" TRANSMIT "ITN TRANSMIT ,3" TRANSMIT
AIB
TF#+	 TR#+	
TV73	
,3" RECEIVE	
,3" TRANSMIT	
DocID16554 Rev 4 105/136
STM32F103xF, STM32F103xG Electrical characteristics
132
SD/SDIO MMC card host interface (SDIO) characteristics
Unless otherwise specified, the parameters given in Table 58 are derived from tests 
performed under ambient temperature, fPCLKx frequency and VDD supply voltage conditions 
summarized in Table 10.
Refer to Section 5.3.14: I/O port characteristics for more details on the input/output alternate 
function characteristics (D[7:0], CMD, CK).
Figure 52. SDIO high-speed mode
Figure 53. SD default mode
          
Table 58. SD / MMC characteristics
Symbol Parameter Conditions Min Max Unit
fPP Clock frequency in data transfer mode CL ≤  30 pF 0 48 MHz
tW(CKL) Clock low time, f PP = 16 MHz C L ≤  30 pF 32 -
ns
tW(CKH) Clock high time, f PP = 16 MHz C L ≤  30 pF 30 -
tr Clock rise time C L ≤  30 pF - 4
tf Clock fall time C L ≤  30 pF - 5
T7#+(	
\#+
$ #-$
OUTPUT	
$ #-$
INPUT	
T#
T7#+,	
T/6 T/(
T)35 T)(
TF TR
AI
AI
\#+
$ #-$
OUTPUT	
T/6$ T/($
Electrical characteristics STM32F103xF, STM32F103xG
106/136 DocID16554 Rev 4
USB characteristics
The USB interface is USB-IF certified (Full Speed).
          
CMD, D inputs (referenced to CK)
tISU Input setup time C L ≤  30 pF 2 - ns
tIH Input hold time C L ≤  30 pF 0 -
CMD, D outputs (referenced to CK) in MMC and SD HS mode
tOV Output valid time C L ≤  30 pF - 6 ns
tOH Output hold time C L ≤  30 pF 0 -
CMD, D outputs (referenced to CK) in SD default mode(1)
tOVD Output valid default time C L ≤  30 pF - 7 ns
tOHD Output hold default time C L ≤  30 pF 0.5 -
1. Refer to SDIO_CLKCR, the SDI clock control register to control the CK output.
Table 59. USB startup time
Symbol Parameter  Max  Unit
tSTARTUP(1)
1. Guaranteed by design, not tested in production.
USB transceiver startup time 1 µs
Table 58. SD / MMC characteristics
Symbol Parameter Conditions Min Max Unit
DocID16554 Rev 4 107/136
STM32F103xF, STM32F103xG Electrical characteristics
132
          
Figure 54. USB timings: definition of data signal rise and fall time
          
Table 60. USB DC electrical characteristics 
Symbol Parameter C onditions Min. (1)
1. All the voltages are measured from the local ground potential.
Max.(1) Unit
Input levels
VDD USB operating voltage(2)
2. To be compliant with the USB 2.0 full-speed electrical  specification, the USB_DP (D+) pin should be pulled 
up with a 1.5 kΩ resistor to a 3.0-to-3.6 V voltage range.
-3 . 0 (3)
3. The STM32F103xF/G USB functionality is ensured dow n to 2.7 V but not the full USB electrical 
characteristics which are degraded in the 2.7-to-3.0 V VDD voltage range.
3.6 V
VDI(4)
4. Guaranteed by characterization results, not tested in production.
Differential input sensitivity I(USB_DP, USB_DM) 0.2 -
VVCM(4) Differential common mode range Includes V DI range 0.8 2.5
VSE(4) Single ended receiver threshold 1.3 2.0
Output levels
VOL Static output level low R L of 1.5 kΩ to 3.6 V(5)
5. RL is the load connected on the USB drivers
-0 . 3
V
VOH Static output level high R L of 15 kΩ to VSS(5) 2.8 3.6
Table 61. USB: full-speed electrical characteristics 
Driver characteristics(1)
1. Guaranteed by design, not tested in production.
Symbol Parameter Conditions Min Max Unit
tr Rise time(2)
2. Measured from 10% to 90% of the data signal. For more detailed informations, please refer to USB 
Specification - Chapter 7 (version 2.0).
CL = 50 pF 42 0 n s
tf Fall Time(2) CL = 50 pF 4 20 ns
trfm Rise/ fall time matching t r/tf 90 110 %
VCRS Output signal crossover voltage - 1.3 2.0 V
DL
WI
66
WU
9
&569
'LIIHUHQWLDO
GDWDOLQHV
&URVVRYHU
SRLQWV
Electrical characteristics STM32F103xF, STM32F103xG
108/136 DocID16554 Rev 4

### 5.3.18 CAN (controller ar ea network) interface
Refer to Section 5.3.14: I/O port characteristics for more details on the input/output alternate 
function characteristics (CAN_TX and CAN_RX).

### 5.3.19 12-bit ADC characteristics
Unless otherwise specified, the parameters given in Table 62 are preliminary values derived 
from tests performed under ambient temperature, fPCLK2 frequency and VDDA supply 
voltage conditions summarized in Table 10.
Note: It is recommended to perform a calibration after each power-up.
          
Table 62. ADC characteristics 
Symbol Parameter  Conditions Min Typ  Max Unit
VDDA Power supply - 2.4 - 3.6 V
VREF+ Positive reference voltage - 2.4 - V DDA V
IVREF Current on the VREF input pin -- 1 6 0 2 2 0 (1) µA
fADC ADC clock frequency - 0.6 - 14 MHz
fS(2) Sampling rate - 0.05 - 1 MHz
fTRIG(2) External trigger frequency fADC = 14 MHz - - 823 kHz-- - 1 7 1 / f ADC
VAIN Conversion voltage range(3) - 0 (VSSA or VREF- tied to ground) -V REF+ V
RAIN(2) External input impedance See Equation 1 and Table 63 for details -- 5 0 κΩ
RADC(2) Sampling switch resistance - - - 1 κΩ
CADC(2) Internal sample and hold capacitor -- - 8 p F
tCAL(2) Calibration time fADC = 14 MHz 5.9 µs-8 3 1 / f ADC
tlat(2) Injection trigger conversion latency fADC = 14 MHz - - 0.214 µs-- - 3 (4) 1/fADC
tlatr(2) Regular trigger conversion latency fADC = 14 MHz - - 0.143 µs-- - 2 (4) 1/fADC
tS(2) Sampling time fADC = 14 MHz 0.107 - 17.1 µs- 1.5 - 239.5 1/f ADC
tSTAB(2) Power-up time - 0 0 1 µs
tCONV(2) Total conversion time (including sampling time)
fADC = 14 MHz 1 18 µs
- 14 to 252 (tS for sampling +12.5 for successive approximation) 1/fADC
1. Guaranteed by characterization results, not tested in production.
DocID16554 Rev 4 109/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Equation 1: RAIN max formula
The formula above (Equation 1) is used to determine the maximum external impedance 
allowed for an error below 1/4 of LSB. Here N = 12 (from 12-bit resolution).
          
          
2. Guaranteed by design, not tested in production.
3. V REF+ can be internally connected to VDDA and VREF- can be internally connected to VSSA, depending on the package. Refer to Section 3: Pinouts and pin descriptions for further details.
4. For external triggers, a delay of 1/f PCLK2 must be added to the latency specified in Table 62.
Table 63. RAIN max for fADC = 14 MHz(1) 
1. Guaranteed by design, not tested in production.
Ts (cycles) t S (µs) R AIN max (kΩ)
1.5 0.11 0.4
7.5 0.54 5.9
13.5 0.96 11.4
28.5 2.04 25.2
41.5 2.96 37.2
55.5 3.96 50
71.5 5.11 NA
239.5 17.1 NA
Table 64. ADC accuracy - limited test conditions(1)(2)
1. ADC DC accuracy values are measured after internal calibration.
2. ADC Accuracy vs. Negative Injection Current: Inje cting negative current on any analog input pins should 
be avoided as this significantly reduces the accuracy of the conversion being performed on another analog 
input. It is recommended to add a Schottky diode (pin to ground) to analog pins which may potentially 
inject negative current.  
Any positive injection current within the limits specified for IINJ(PIN) and ΣIINJ(PIN) in Section 5.3.14 does not affect the ADC accuracy.
Symbol Parameter Test conditions Typ Max (3)
3. Guaranteed by characterization results, not tested in production.
Unit
ET Total unadjusted error f PCLK2 = 56 MHz, 
fADC = 14 MHz, RAIN < 10 kΩ,
VDDA = 3 V to 3.6 V
TA = 25 °C
Measurements made after 
ADC calibration 
VREF+ = VDDA
±1.3 ±2
LSB
EO Offset error ±1 ±1.5
EG Gain error ±0.5 ±1.5
ED Differential linearity error ±0.7 ±1
EL Integral linearity error ±0.8 ±1.5
RAIN
TS
fADC CADC 2
N2+
()ln××
-------------------------------------------------------------- RADC–<
Electrical characteristics STM32F103xF, STM32F103xG
110/136 DocID16554 Rev 4
          
Figure 55. ADC accuracy characteristics
1. Example of an actual transfer curve.
2. Ideal transfer curve.
3. End point correlation line.
4. E T = Total Unadjusted Error: maximum deviation between the actual and the ideal transfer curves. 
EO = Offset Error: deviation between the first actual transition and the first ideal one. 
EG = Gain Error: deviation between the last ideal transition and the last actual one. 
ED = Differential Linearity Error: maximum deviation between actual steps and the ideal one. 
EL = Integral Linearity Error: maximum deviation between any actual transition and the end point 
correlation line.
Table 65. ADC accuracy(1) (2)(3)
1. ADC DC accuracy values are measured after internal calibration.
2. Better performance could be achieved in restricted V DD, frequency, VREF and temperature ranges.
3. ADC Accuracy vs. Negative Injection Current: Inje cting negative current on any analog input pins should 
be avoided as this significantly reduces the accuracy of the conversion being performed on another analog 
input. It is recommended to add a Schottky diode (pin to ground) to analog pins which may potentially 
inject negative current.  
Any positive injection current within the limits specified for IINJ(PIN) and ΣIINJ(PIN) in Section 5.3.14 does not affect the ADC accuracy.
Symbol Parameter Test conditions Typ Max (4)
4. Preliminary values.
Unit
ET Total unadjusted error
fPCLK2 = 56 MHz, 
fADC = 14 MHz, RAIN < 10 kΩ,
VDDA = 2.4 V to 3.6 V
Measurements made after 
ADC calibration
±2 ±5
LSB
EO Offset error ±1.5 ±2.5
EG Gain error ±1.5 ±3
ED Differential linearity error ±1 ±2
EL Integral linearity error ±1.5 ±3
AIC
%/
%'
, 3" )$ % ! ,











        
	
	
%4
%$
%,
	
6$$ !633 !
6 2%&

OR              DEPENDING ON PACKAGE	=
6 $$!

;,3" )$%!,   
DocID16554 Rev 4 111/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 56. Typical connection diagram using the ADC
1. Refer to Table 62 for the values of RAIN, RADC and CADC.
2. C parasitic represents the capacitance of the PCB (dependent on soldering and PCB layout quality) plus the pad capacitance (roughly 7 pF). A high Cparasitic value will downgrade conversion accuracy. To remedy this, fADC should be reduced.
General PCB design guidelines
Power supply decoupling should be performed as shown in Figure 57 or Figure 58, 
depending on whether VREF+ is connected to VDDA or not. The 10 nF capacitors should be 
ceramic (good quality). They should be placed them as close as possible to the chip.
Figure 57. Power supply and reference decoupling (VREF+ not connected to VDDA)
1. V REF+ and VREF– inputs are available only on 100-pin packages. 
DL
670)9''
$,1[
,/$
9
97
5$,1
&SDUDVLWLF
9$,1
9
97
5$'&
&$'&
ELW
FRQYHUWHU
6DPSOHDQGKROG$'&
FRQYHUWHU
95()
670)
9''$
966$95()
)Q)
)Q)
DL
6HHQRWH
6HHQRWH
Electrical characteristics STM32F103xF, STM32F103xG
112/136 DocID16554 Rev 4
Figure 58. Power supply and reference decoupling (VREF+ connected to VDDA)
1. V REF+ and VREF– inputs are available only on 100-pin packages. 
95()9''$
670)
)Q)
95()±966$
DL
6HHQRWH
6HHQRWH
DocID16554 Rev 4 113/136
STM32F103xF, STM32F103xG Electrical characteristics
132

### 5.3.20 DAC electri cal specifications
          
Table 66. DAC characteristics 
Symbol Parameter Min Typ Max Unit Comments
VDDA Analog supply voltage 2.4 - 3.6 V
VREF+ Reference supply voltage 2.4 - 3.6 V V REF+ must always be below VDDA
VSSA Ground 0 - 0 V
RLOAD(1)
Resistive load vs. VSSA with 
buffer ON 5- - k Ω
Resistive load vs. VDDA with 
buffer ON 15 - - k Ω
RO(1) Impedance output with buffer OFF -- 1 5 k Ω
When the buffer is OFF, the Minimum 
resistive load between DAC_OUT 
and VSS to have a 1% accuracy is 
1.5 MΩ
CLOAD(1) Capacitive load - - 50 pF
Maximum capacitive load at 
DAC_OUT pin (when the buffer is 
ON).
DAC_OUT 
min(1)
Lower DAC_OUT voltage 
with buffer ON 0.2 - - V
It gives the maximum output 
excursion of the DAC.
It corresponds to 12-bit input code 
(0x0E0) to (0xF1C) at VREF+ = 3.6 V 
and (0x155) and (0xEAB) at VREF+ = 
2.4 V
DAC_OUT 
max(1)
Higher DAC_OUT voltage 
with buffer ON -- V DDA – 0.2 V
DAC_OUT 
min(1)
Lower DAC_OUT voltage 
with buffer OFF -0 . 5 m V It gives the maximum output 
excursion of the DAC.DAC_(1)OU
T max(1)
Higher DAC_OUT voltage 
with buffer OFF - VREF+ –10 mV V
IDDVREF+
DAC DC current 
consumption in quiescent 
mode (Standby mode)
- 380 µA
With no load, worst code (0x0E4) at 
VREF+ = 3.6 V in terms of DC 
consumption on the inputs
IDDA
DAC DC current 
consumption in quiescent 
mode(2)
- 380 µA With no load, middle code (0x800) on the inputs
- 480 µA
With no load, worst code (0xF1C) at 
VREF+ = 3.6 V in terms of DC 
consumption on the inputs
DNL(3)
Differential non linearity 
Difference between two 
consecutive code-1LSB)
- ±0.5 LSB Given for the DAC in 10-bit configuration
- ±3 LSB Given for the DAC in 12-bit configuration 
Electrical characteristics STM32F103xF, STM32F103xG
114/136 DocID16554 Rev 4
INL(2)
Integral non linearity 
(difference between 
measured value at Code i 
and the value at Code i on a 
line drawn between Code 0 
and last Code 1023)
-- ± 1 L S B Given for the DAC in 10-bit configuration 
-- ± 4 L S B Given for the DAC in 12-bit configuration
Offset(2)
Offset error
(difference between 
measured value at Code 
(0x800) and the ideal value = 
VREF+/2)
-- ± 1 0 m V
-- ± 3 L S B Given for the DAC in 10-bit at VREF+ = 3.6 V
-- ± 1 2 L S B Given for the DAC in 12-bit at VREF+ = 3.6 V
Gain 
error(2) Gain error - - ±0.5 % Given for the DAC in 12bit configuration
tSETTLING(2)
Settling time (full scale: for a 
10-bit input code transition 
between the lowest and the 
highest input codes when 
DAC_OUT reaches final 
value ±1LSB
-3 4 µ s C LOAD ≤  50 pF, RLOAD ≥ 5 kΩ
Update 
rate(2)
Max frequency for a correct 
DAC_OUT change when 
small variation in the input 
code (from code i to i+1LSB)
-- 1M S / s C LOAD ≤  50 pF, RLOAD ≥ 5 kΩ
tWAKEUP(2)
Wakeup time from off state 
(Setting the ENx bit in the 
DAC Control register)
- 6.5 10 µs
CLOAD ≤  50 pF, RLOAD ≥ 5 kΩ
input code between lowest and 
highest possible ones.
PSRR+ (1)
Power supply rejection ratio 
(to VDDA) (static DC 
measurement
- –67 –40 dB No R LOAD, CLOAD = 50 pF
1. Guaranteed by design, not tested in production.
2. The quiescent mode corresponds to a state where the DAC maintains a stable output level to ensure that no dynamic 
consumption occurs.
3. Preliminary values.
Table 66. DAC characteristics (continued)
Symbol Parameter Min Typ Max Unit Comments
DocID16554 Rev 4 115/136
STM32F103xF, STM32F103xG Electrical characteristics
132
Figure 59. 12-bit buffered /non-buffered DAC
1. The DAC integrates an output buffer that can be used to reduce the output impedance and to drive external 
loads directly without the use of an external operational amplifier. The buffer can be bypassed by 
configuring the BOFFx bit in the DAC_CR register.

### 5.3.21 Temperature sensor characteristics
          
5 /
& /
%XIIHUHG1RQEXIIHUHG'$&
'$&B287[
%XIIHU
ELW
GLJLWDOWR
DQDORJ
FRQYHUWHU
AI6
Table 67. TS characteristics
Symbol Parameter Min Typ Max Unit
TL(1)
1. Guaranteed on characterization results, not tested in production.
VSENSE linearity with temperature - ±1 ±2° C
Avg_Slope(1) Average slope 4.0 4.3 4.6 mV/°C
V25(1) Voltage at 25 °C 1.34 1.43 1.52 V
tSTART(2)
2. Guaranteed by design, not tested in production.
Startup time 4 - 10 µs
TS_temp(3)(2)
3. Shortest sampling time can be determined in the application by multiple iterations.
ADC sampling time when reading the 
temperature - - 17.1 µs
Package information STM32F103xF, STM32F103xG
116/136 DocID16554 Rev 4

## 6 Package information
In order to meet environmental requirements, ST offers these devices in different grades of 
ECOPACK® packages, depending on their level of environmental compliance. ECOPACK® 
specifications, grade definitions and product status are available at: www.st.com. 
ECOPACK® is an ST trademark.
DocID16554 Rev 4 117/136
STM32F103xF, STM32F103xG Package information
132

## 6.1 LFBGA144 package information
Figure 60. LFBGA144 – 144-ball low profile fine pitch ball grid array, 10 x 10 mm,
0.8 mm pitch, package outline
1. Drawing is not to scale.
          
Table 68. LFBGA144 – 144-ball low profile fine pitch ball grid array, 10 x 10 mm,
0.8 mm pitch, package mechanical data 
Symbol
millimeters inches (1)
Min Typ Max Typ Min Max
A(2) - - 1.700 0.0669
A1 0.210 - - 0.0083
A2 - 1.060 - 0.0417
A3 0.026 0.0010
A4 - 0.800 - - 0.0315 -
b 0.350 0.400 0.450 0. 0138 0.0157 0.0177
D 9.850 10.000 10.150 0.3878 0.3937 0.3996
D1 - 8.800 - - 0.3465 -
E 9.850 10.000 10.150 0.3878 0.3937 0.3996
E1 - 8.800 - - 0.3465 -
e - 0.800 - - 0.0315 -
F - 0.600 - - 0.0236 -
ddd - - 0.100 - - 0.0039
;B0(B9
6HDWLQJSODQH
$
H )
)
'
0
EEDOOV
$
(
7239,(:%277209,(:

H
$$
<
;
=
GGG =
'
(
HHH = < ;
III


0
0 =
$$
$EDOO
LGHQWLILHU
$EDOO
LQGH[DUHD
Package information STM32F103xF, STM32F103xG
118/136 DocID16554 Rev 4
Device marking for LFBGA144 package
The following figure gives an example of topside marking orientation versus ball A1 identifier 
location. 
Figure 61. LFBGA144 marking example (package top view)
1. Parts marked as “ES”, “E” or accompanied by an Engineering Sample notification letter, are not yet 
qualified and therefore not yet ready to be used in production and any consequences deriving from such 
usage will not be at ST charge. In no event, ST will be liable for any customer usage of these engineering 
samples in production. ST Quality has to be contacted prior to any decision to use these Engineering 
samples to run qualification activity.
eee - - 0.150 - - 0.0059
fff - - 0.080 - - 0.0031
1. Values in inches are converted from mm and rounded to 4 decimal digits.
2. STATSChipPAC package dimensions.
Table 68. LFBGA144 – 144-ball low profile fine pitch ball grid array, 10 x 10 mm,
0.8 mm pitch, package mechanical data (continued)
Symbol
millimeters inches (1)
Min Typ Max Typ Min Max
06Y9
%DOO
$LGHQWLILHU
5
670)
3URGXFWLGHQWLILFDWLRQ
=)+
'DWHFRGH
<: :
DocID16554 Rev 4 119/136
STM32F103xF, STM32F103xG Package information
132

## 6.2 LQFP144 package information
Figure 62. LQFP144 - 144-pin, 20 x 20 mm low-profile quad flat package outline
1. Drawing is not to scale. 
H
,'(17,),&$7,21
3,1
*$8*(3/$1(
PP
6($7,1*
3/$1(
'
'
'
(
(
(
.
FFF &
&
 



 

$B0(B9
$
$
$
/
/
F
E
$
Package information STM32F103xF, STM32F103xG
120/136 DocID16554 Rev 4
          
Table 69. LQFP144 - 144-pin, 20 x 20 mm low-profile quad flat package 
mechanical data 
Symbol
millimeters inches (1)
1. Values in inches are converted from mm and rounded to 4 decimal digits.
Min Typ Max Min Typ Max
A - - 1.600 - - 0.0630
A1 0.050 - 0.150 0.0020 - 0.0059
A2 1.350 1.400 1.450 0.0531 0.0551 0.0571
b 0.170 0.220 0.270 0.0067 0.0087 0.0106
c 0.090 - 0.200 0.0035 - 0.0079
D 21.800 22.000 22.200 0.8583 0.8661 0.8740
D1 19.800 20.000 20.200 0.7795 0.7874 0.7953
D3 - 17.500 - - 0.6890 -
E 21.800 22.000 22.200 0.8583 0.8661 0.8740
E1 19.800 20.000 20.200 0.7795 0.7874 0.7953
E3 - 17.500 - - 0.6890 -
e - 0.500 - - 0.0197 -
L 0.450 0.600 0.750 0.0177 0.0236 0.0295
L1 - 1.000 - - 0.0394 -
k 0 °3 . 5 °7 ° 0 °3 . 5 °7 °
ccc - - 0.080 - - 0.0031
DocID16554 Rev 4 121/136
STM32F103xF, STM32F103xG Package information
132
Figure 63. LQFP144 - 144-pin,20 x 20 mm low-profile quad flat package 
recommended footprint
1. Dimensions are expr essed in millimeters.


 




DLH
 





Package information STM32F103xF, STM32F103xG
122/136 DocID16554 Rev 4
Device marking for LQFP144 package
The following figure gives an example of topside marking orientation versus pin 1 identifier 
location. 
Figure 64. LQFP144 marking example (package top view)
1. Parts marked as “ES”, “E” or accompanied by an Engineering Sample notification letter, are not yet 
qualified and therefore not yet ready to be used in production and any consequences deriving from such 
usage will not be at ST charge. In no event, ST will be liable for any customer usage of these engineering 
samples in production. ST Quality has to be contacted prior to any decision to use these Engineering 
samples to run qualification activity.
06Y9
'DWHFRGH
3LQ
LGHQWLILHU
670)=)7
53URGXFWLGHQWLILFDWLRQ
5HYLVLRQFRGH
<: :

DocID16554 Rev 4 123/136
STM32F103xF, STM32F103xG Package information
132

## 6.3 LQFP100 package information
Figure 65. LFP100 – 14 x 14 mm 100 pin low-profile quad flat package outline
1. Drawing is not to scale.
          
E)$%.4)&)#! 4)/.
0). 
'!5'% 0,!.%
 MM
3%! 4).' 0,!.%
$
$
$
%
%
%
+
CCC #
\#
 


 

,?-%?6
!
!
!
,
,
C
B
!
Table 70. LQPF100 – 14 x 14 mm 100-pin low-profile quad flat package 
mechanical data 
Symbol
millimeters inches (1)
Min Typ Max Min Typ Max
A - - 1.600 - - 0.0630
A1 0.050 - 0.150 0.0020 - 0.0059
A2 1.350 1.400 1.450 0.0531 0.0551 0.0571
b 0.170 0.220 0.270 0.0067 0.0087 0.0106
c 0.090 - 0.200 0.0035 - 0.0079
D 15.800 16.000 16.200 0.6220 0.6299 0.6378
D1 13.800 14.000 14.200 0.5433 0.5512 0.5591
D3 - 12.000 - - 0.4724 -
E 15.800 16.000 16.200 0.6220 0.6299 0.6378
E1 13.800 14.000 14.200 0.5433 0.5512 0.5591
E3 - 12.000 - - 0.4724 -
Package information STM32F103xF, STM32F103xG
124/136 DocID16554 Rev 4
Figure 66. LQFP100 recommended footprint
1. Dimensions are in millimeters.
e - 0.500 - - 0.0197 -
L 0.450 0.600 0.750 0.0177 0.0236 0.0295
L1 - 1.000 - - 0.0394 -
k 0 °3 . 5 °7 ° 0 °3 . 5 °7 °
ccc - - 0.08 - - 0.0031
1. Values in inches are converted from mm and rounded to 4 decimal digits.
Table 70. LQPF100 – 14 x 14 mm 100-pin low-profile quad flat package 
mechanical data (continued)
Symbol
millimeters inches (1)
Min Typ Max Min Typ Max
 
 

 
 





AIC
DocID16554 Rev 4 125/136
STM32F103xF, STM32F103xG Package information
132
Device marking for LQFP100 package
The following figure gives an example of topside marking orientation versus pin 1 identifier 
location. 
Figure 67. LQFP100 marking example (package top view)
1. Parts marked as “ES”, “E” or accompanied by an Engineering Sample notification letter, are not yet 
qualified and therefore not yet ready to be used in production and any consequences deriving from such 
usage will not be at ST charge. In no event, ST will be liable for any customer usage of these engineering 
samples in production. ST Quality has to be contacted prior to any decision to use these Engineering 
samples to run qualification activity.
06Y9
670)
9*75 5HYLVLRQFRGH
3URGXFWLGHQWLILFDWLRQ
'DWHFRGH
3LQ
LQGHQWLILHU
< ::

Package information STM32F103xF, STM32F103xG
126/136 DocID16554 Rev 4

## 6.4 LQFP64 package information
Figure 68. LFP64 – 10 x 10 mm 64 pin low-profile quad flat package outline
1. Drawing is not in scale.
          
:B0(B9
$
$
$
6($7,1*3/$1(
FFF &
E
&
F
$
/
/
.
,'(17,),&$7,21
3,1
'
'
'
H
 





(
(
(
*$8*(3/$1(
PP
Table 71. LQFP64 – 10 x 10 mm 64 pin low-profile quad flat package mechanical data 
Symbol
millimeters inches (1)
Min Typ Max Min Typ Max
A  - - 1.600 - - 0.0630
A1 0.050 - 0.150 0.0020 - 0.0059
A2 1.350 1.400 1.450 0.0531 0.0551 0.0571
b 0.170 0.220 0.270 0.0067 0.0087 0.0106
c 0.090 - 0.200 0.0035 - 0.0079
D - 12.000 - - 0.4724 -
D1 - 10.000 - - 0.3937 -
D3 - 7.500 - - 0.2953 -
E - 12.000 - - 0.4724 -
E1 - 10.000 - - 0.3937 -
DocID16554 Rev 4 127/136
STM32F103xF, STM32F103xG Package information
132
Figure 69. LQFP64 - 64-pin, 10 x 10 mm low-profile quad flat recommended footprint
1. Dimensions are in millimeters.
E3 - 7.500 - - 0.2953 -
e - 0.500 - - 0.0197 -
θ 0° 3.5° 7° 0° 3.5° 7°
L 0.450 0.600 0.750 0.0177 0.0236 0.0295
L1 - 1.000 - - 0.0394 -
ccc - - 0.080 - - 0.0031
1. Values in inches are converted from mm and rounded to 4 decimal digits.
Table 71. LQFP64 – 10 x 10 mm 64 pin low-profile quad flat package mechanical data (continued)
Symbol
millimeters inches (1)
Min Typ Max Min Typ Max


 
 









AIC
Package information STM32F103xF, STM32F103xG
128/136 DocID16554 Rev 4
Device marking for LQFP64 package
The following figure gives an example of topside marking orientation versus pin 1 identifier 
location. 
Figure 70. LQFP64 marking example (package top view)
1. Parts marked as “ES”, “E” or accompanied by an Engineering Sample notification letter, are not yet 
qualified and therefore not yet ready to be used in production and any consequences deriving from such 
usage will not be at ST charge. In no event, ST will be liable for any customer usage of these engineering 
samples in production. ST Quality has to be contacted prior to any decision to use these Engineering 
samples to run qualification activity.
          
06Y9
3LQLGHQWLILHU
5)7
< ::
5HYLVLRQFRGH
3URGXFWLGHQWLILFDWLRQ
'DWHFRGH
670)
5
DocID16554 Rev 4 129/136
STM32F103xF, STM32F103xG Package information
132

## 6.5 Thermal characteristics
The maximum chip junction temperature (TJmax) must never exceed the values given in 
Table 10: General operating conditions on page 44.
The maximum chip-junction temperature, TJ max, in degrees Celsius, may be calculated 
using the following equation:
TJ max = TA max + (PD max x ΘJA)
Where:
• TA max is the maximum ambient temperature in °C,
•Θ JA is the package junction-to-ambient thermal resistance, in °C/W,
• PD max is the sum of PINT max and PI/O max (PD max = PINT max + PI/Omax),
• PINT max is the product of IDD and VDD, expressed in Watts. This is the maximum chip 
internal power.
PI/O max represents the maximum power dissipation on output pins where:
PI/O max = Σ (VOL × IOL) + Σ((VDD – VOH) × IOH),
taking into account the actual VOL / IOL and VOH / IOH of the I/Os at low and high level in the 
application.
          

### 6.5.1 Reference document
JESD51-2 Integrated Circuits Thermal Test Method Environment Conditions - Natural 
Convection (Still Air). Available from www.jedec.org
Table 72. Package thermal characteristics
Symbol Parameter Value Unit
ΘJA
Thermal resistance junction-ambient 
LFBGA144 - 10 × 10 mm / 0.8 mm pitch 40
°C/W
Thermal resistance junction-ambient 
LQFP144 - 20 × 20 mm / 0.5 mm pitch 30
Thermal resistance junction-ambient 
LQFP100 - 14 × 14 mm / 0.5 mm pitch 46
Thermal resistance junction-ambient 
LQFP64 - 10 × 10 mm / 0.5 mm pitch 45
Package information STM32F103xF, STM32F103xG
130/136 DocID16554 Rev 4

### 6.5.2 Selecting the product temperature range
When ordering the microcontroller, the temperature range is specified in the ordering 
information scheme shown in Table 73: STM32F103xF and STM32F103xG ordering 
information scheme.
Each temperature range suffix corresponds to a specific guaranteed ambient temperature at 
maximum dissipation and, to a specific maximum junction temperature.
As applications do not commonly use the STM32F103xF and STM32F103xG at maximum 
dissipation, it is useful to calculate the exact power consumption and junction temperature 
to determine which temperature range will be best suited to the application.
The following examples show how to calculate the temperature range needed for a given 
application.
Example 1: High-performance application
Assuming the following application conditions:
Maximum ambient temperature TAmax = 82 °C (measured according to JESD51-2), 
IDDmax = 50 mA, VDD = 3.5 V, maximum 20 I/Os used at the same time in output at low 
level with IOL = 8 mA, VOL= 0.4 V and maximum 8 I/Os used at the same time in output 
at low level with IOL = 20 mA, VOL= 1.3 V
PINTmax = 50 mA × 3.5 V= 175 mW
PIOmax = 20 × 8 mA × 0.4 V + 8 × 20 mA × 1.3 V = 272 mW
This gives: PINTmax = 175 mW and PIOmax = 272 mW:
PDmax = 175 + 272 = 447 mW
Thus: PDmax = 447 mW
Using the values obtained in Table 72 TJmax is calculated as follows:
– For LQFP100, 46 °C/W 
TJmax = 82 °C + (46 °C/W × 447 mW) = 82 °C + 20.6 °C = 102.6 °C
This is within the range of the suffix 6 version parts (–40 < TJ < 105 °C).
In this case, parts must be ordered at least with the temperature range suffix 6 (see 
Table 73: STM32F103xF and STM32F103xG ordering information scheme).
Example 2: High-temperature application
Using the same rules, it is possible to address applications that run at high ambient 
temperatures with a low dissipation, as long as junction temperature TJ remains within the 
specified range.
Assuming the following application conditions:
Maximum ambient temperature TAmax = 115 °C (measured according to JESD51-2), 
IDDmax = 20 mA, VDD = 3.5 V, maximum 20 I/Os used at the same time in output at low 
level with IOL = 8 mA, VOL= 0.4 V
PINTmax = 20 mA × 3.5 V= 70 mW
PIOmax = 20 × 8 mA × 0.4 V = 64 mW
This gives: PINTmax = 70 mW and PIOmax = 64 mW:
PDmax = 70 + 64 = 134 mW
Thus: PDmax = 134 mW
DocID16554 Rev 4 131/136
STM32F103xF, STM32F103xG Package information
132
Using the values obtained in Table 72 TJmax is calculated as follows:
– For LQFP100, 46 °C/W 
TJmax = 115 °C + (46 °C/W × 134 mW) = 115 °C + 6.2 °C = 121.2 °C
This is within the range of the suffix 7 version parts (–40 < TJ < 125 °C).
In this case, parts must be ordered at least with the temperature range suffix 7 (see 
Section 7: Part numbering).
Figure 71. LQFP100 PD max vs. TA
0
100
200
300
400
500
600
700
65 75 85 95 105 115 125 135
TA (°C)
PD (mW)
Suffix 6
Suffix 7
Part numbering STM32F103xF, STM32F103xG
132/136 DocID16554 Rev 4

## 7 Part numbering
          
For a list of available options (speed, package, etc.) or for further information on any aspect 
of this device, please contact your nearest ST sales office.
Table 73. STM32F103xF and STM32F103xG ordering information scheme
 
Example: STM32 F 103 R F T 6 xxx
Device family
STM32 = ARM-based 32-bit microcontroller
Product type
F = general-purpose
Device subfamily
103 = performance line
Pin count
R = 64 pins
V = 100 pins
Z = 144 pins
Flash memory size
F = 768 Kbytes of Flash memory
G = 1 Mbyte of Flash memory
Package
H = BGA
T = LQFP
Temperature range
6 = Industrial temperature range, –40 to 85 °C.
7 = Industrial temperature range, –40 to 105 °C.
Options
xxx = programmed parts
TR = tape and real
DocID16554 Rev 4 133/136
STM32F103xF, STM32F103xG Revision history
135

## 8 Revision history
          
Table 74. Document revision history
Date Revision Changes
27-Oct-2009 1 Initial release.
15-Nov-2010 2
LQFP64 package mechanical data updated: see Figure 66: LQFP64 – 
10 x 10 mm 64 pin low-profile quad flat package outline and Table 71: 
LQFP64 – 10 x 10 mm 64 pin low-profile quad flat package mechanical 
data.
Internal code removed from Table 73: STM32F103xF and 
STM32F103xG ordering information scheme.
Updated note 2 below Table 54: I2C characteristics
Updated Figure 46: I2C bus AC waveforms and measurement circuit
Updated Figure 45: Recommended NRST pin protection
Updated note 1 below Table 49: I/O static characteristics 
Updated Table 20: Peripheral current consumption
Updated Table 14: Maximum current consumption in Run mode, code 
with data processing  running from Flash
Updated Table 15: Maximum current consumption in Run mode, code 
with data processing  running from RAM
Updated Table 16: Maximum current consumption in Sleep mode, code 
running from Flash or RAM
Updated Table 17: Typical and maximum current consumptions in Stop 
and Standby modes
Updated Table 18: Typical current consumption in Run mode, code with 
data processing  running from Flash
Updated Table 19: Typical current consumption in Sleep mode, code 
running from Flash or  RAM
Updated Table 24: LSE oscillator characteristics (fLSE = 32.768 kHz)
Updated Figure 22: Asynchronous non-multiplexed 
SRAM/PSRAM/NOR read waveforms on page 63
Added Section 5.3.13: I/O current injection characteristics on page 84
18-Jan-2012 3
Section 2.3.26: GPIOs (general-purpose inputs/outputs): modified text 
of last sentence.
Table 5: STM32F103xF and STM32F103xG pin definitions: updated 
pins PD0, PD1, OSC_IN, OSC_OUT, PB8, PB9, and PF8.
Table 7: Voltage characteristics: Removed the previous footnotes 2 and 
3 and added current footnote 2.
Table 8: Current characteristics: updated footnotes 3, 4, and 5.
Table 21: High-speed external user clock characteristics: replaced the 
tw(HSE) min value by 5 (instead of 16).
Table 24: LSE oscillator characteristics (fLSE = 32.768 kHz): updated 
symbols and footnotes.
Revision history STM32F103xF, STM32F103xG
134/136 DocID16554 Rev 4
18-Jan-2012 3
Asynchronous waveforms and timings: added notes about tHCLK clock 
period and FSMC_BusTurnAroundDuration; updated conditions, 
modified Table 31: Asynchronous non-multiplexed 
SRAM/PSRAM/NOR read timings, Table 32: Asynchronous non-
multiplexed SRAM/PSRAM/NOR write timings, Table 34: 
Asynchronous multiplexed PSRAM/NOR read timings, and Table 35: 
Asynchronous multiplexed PSRAM/NOR write timings; added Table 33: 
Asynchronous multiplexed read timings.
Synchronous waveforms and timings: updated Figure 27: Synchronous 
multiplexed PSRAM write timings; updated Table 36: Synchronous 
multiplexed NOR/PSRAM read timings, Table 37: Synchronous 
multiplexed PSRAM write timings, Table 38: Synchronous non-
multiplexed NOR/PSRAM read timings, and Table 39: Synchronous 
non-multiplexed PSRAM write timings.
PC Card/CompactFlash controller waveforms and timings: updated 
Figure 35: PC Card/CompactFlash controller waveforms for I/O space 
write access; split switching characteristics into Table 40: Switching 
characteristics for PC Card/CF read and write cycles in  
attribute/common space and Table 41: Switching characteristics for PC 
Card/CF read and write cycles in I/O space, modified values, and 
removed footnote concerning preliminary values.
NAND controller waveforms and timings: updated conditions, split 
switching characteristics into Table 42: Switching characteristics for 
NAND Flash read cycles and Table 43: Switching characteristics for 
NAND Flash write cycles, and values modified.
Section 5.3.14: I/O port characteristics: updated footnote1 of Table 49: 
I/O static characteristics; updated Output driving current.
Table 50: Output voltage characteristics: swapped “TTL and “CMOS” 
ports in the conditions column.
Table 54: I2C characteristics: updated footnote 2.
Updated Table 58: SD / MMC characteristics.
Table 62: ADC characteristics: updated footnote 1.
Table 64: ADC accuracy - limited test conditions: updated footnote 3.
Table 67: TS characteristics: updated footnote 1.
Table 74. Document revision history
Date Revision Changes
DocID16554 Rev 4 135/136
STM32F103xF, STM32F103xG Revision history
135
          
15-May-2015 4
Added document status on first page.
Replace DAC1_OUT/DAC2_OUT by DAC_OUT1/DAC_OUT2, and 
updated TIM5 in Figure 1: STM32F103xF and STM32F103xG 
performance line block diagram on page 12. 
Replaced USBDP/USBDM by USB_DP/USB_DM in the whole 
document.
Updated notes related to electrical values guaranteed by 
characterization results. 
Updated Table 20: Peripheral current consumption.
Updated Table 36: Synchronous multiplexed NOR/PSRAM read 
timings to Table 39: Synchronous non-multiplexed PSRAM write 
timings(added FSMC_NWAIT timings). Updated Figure 26: 
Synchronous multiplexed NOR/PSRAM read timings on page 73 and 
Figure 28: Synchronous non-multiplexed NOR/PSRAM read timings on 
page 77 and Figure 35: PC Card/CompactFlash controller waveforms 
for I/O space write access on page 83.
Updated CDM class in Table 46: ESD absolute maximum ratings.
Updated Figure 44: I/O AC characteristics definition on page 96 and 
Figure 45: Recommended NRST pin protection on page 97.
Updated Figure 49: SPI timing diagram - master mode(1) on page 96.
Modified note 3 in Table 56: SPI characteristics.
Section : I2C interface characteristics: Updated introduction, updated 
Table 54: I2C characteristics and Figure 46: I2C bus AC waveforms and 
measurement circuit on page 99.
Modified note 2 in Table 64: ADC accuracy - limited test conditions, 
Figure 55: ADC accuracy characteristics on page 110 and Figure 56: 
Typical connection diagram using the ADC on page 111. Updated 
Figure 57: Power supply and reference decoupling (VREF+ not 
connected to VDDA) on page 111 and Figure 58: Power supply and 
reference decoupling (VREF+ connected to VDDA) on page 112.
Updated IDDA description and Offset comment in Table 66: DAC 
characteristics.
Updated Section 6.1: LFBGA144 package information and added 
Section : Device marking for LFBGA144 package.
Updated Section 6.2: LQFP144 package information and added 
Section : Device marking for LQFP144 package.
Updated Section 6.3: LQFP100 package information and added 
Section : Device marking for LQFP100 package.
Updated Section 6.4: LQFP64 package information and added 
Section : Device marking for LQFP64 package.
Table 74. Document revision history
Date Revision Changes
STM32F103xF, STM32F103xG
136/136 DocID16554 Rev 4
          
IMPORTANT NOTICE – PLEASE READ CAREFULLY
STMicroelectronics NV and its subsidiaries (“ST”) reserve the right to make changes, corrections, enhancements, modifications, and 
improvements to ST products and/or to this document at any time without notice. Purchasers should obtain the latest relevant information on 
ST products before placing orders. ST products are sold pursuant to ST’s terms and conditions of sale in place at the time of order 
acknowledgement.
Purchasers are solely responsible for the choice, selection, and use of ST products and ST assumes no liability for application assistance or 
the design of Purchasers’ products.
No license, express or implied, to any intellectual property right is granted by ST herein.
Resale of ST products with provisions different from the information set forth herein shall void any warranty granted by ST for such product.
ST and the ST logo are trademarks of ST. All other product or service names are the property of their respective owners.
Information in this document supersedes and replaces information previously supplied in any prior versions of this document.
© 2015 STMicroelectronics – All rights reserved
Mouser Electronics
  
Authorized Distributor
 
  
Click to View Pricing, Inventory, Delivery & Lifecycle Information:
 
 
 
 STMicroelectronics:   
  STM32F103RFT6  STM32F103ZGH6  STM32F103ZFH6  STM32F103VGT7  STM32F103RGT6  STM32F103VFT6 
STM32F103VGT6  STM32F103ZFT6  STM32F103ZGT6  STM32F103RGT7  STM32F103VFT6TR 
STM32F103ZFH6TR  STM32F103VFT7  STM32F103RFT6TR  STM32F103ZGT6TR  STM32F103RGT6TR 
STM32F103ZGH7  STM32F103ZGH6TR  STM32F103VGT6TR  STM32F103VGT7TR
