# Smart Water Tank Controller with Arduino Nano

> **Arduino Nano · YF-S201 · Flow Sensor · Relay · LCD I2C · Water Automation · Interrupt**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Automation](https://img.shields.io/badge/Use-Water%20Automation-blue?style=flat)]()
[![Sensor](https://img.shields.io/badge/Sensor-YF--S201%20Flow-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/controle-inteligente-para-abastecimento-de-caixa-dagua-com-arduino-nano/) · Author: **Saulo Aislan**

---

## Overview

Automated water tank filling controller using an **Arduino Nano**, **YF-S201** water flow sensor, and a **relay** to control a pump. Measures water volume dispensed in real time using pulse interrupts, automatically stops the pump at a user-defined setpoint, and displays current volume on a **16×2 LCD**.

Perfect for irrigation systems, water treatment, and any application requiring precise volume dispensing.

## Key Features

- ✅ Pulse counting via external interrupt (INT1) for precise flow measurement
- ✅ Automatic pump cutoff at configurable setpoint
- ✅ Real-time volume display on LCD I2C
- ✅ 3 push buttons: SET VOLUME ↑, SET VOLUME ↓, START/STOP
- ✅ Calibration factor adjustable per sensor unit

## Hardware

| Component | Qty |
|---|---|
| Arduino Nano V3.0 | 1 |
| YF-S201 water flow sensor (G1/2") | 1 |
| 5V relay module | 1 |
| 16×2 LCD with I2C adapter | 1 |
| Push button | 3 |
| 12V submersible pump | 1 |
| Hose + fittings for YF-S201 | — |

## Wiring

| Component | Arduino Nano |
|---|---|
| YF-S201 signal (yellow) | D3 (INT1) |
| Relay signal | D5 |
| Button UP | D2 |
| Button DOWN | D6 |
| Button START | D9 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Calibration

The YF-S201 generates ~450 pulses per liter (nominal). Adjust `FATOR_CALIBRACAO` in code for your specific unit:

```cpp
float FATOR_CALIBRACAO = 4.5;  // pulses per second per liter/min
// Volume (L) = pulseCount / (FATOR_CALIBRACAO × 60)
```

To calibrate: measure 1 liter, count the pulses, and adjust accordingly.

## Project Structure

```
smart-water-tank-controller-arduino/
└── Controle_de_abastecimento/
    └── Controle_de_abastecimento.ino
```

## Library Required

- **LiquidCrystal_I2C** — Library Manager

## Operating Logic

1. Set desired volume with UP/DOWN buttons
2. Press START → relay energizes → pump runs
3. Interrupt counts YF-S201 pulses → calculates volume
4. At setpoint → relay de-energizes → pump stops

---

## Português — Controle Inteligente de Abastecimento com Arduino Nano

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/controle-inteligente-para-abastecimento-de-caixa-dagua-com-arduino-nano/)

Controlador de abastecimento de caixa d'água com **Arduino Nano**, sensor de fluxo **YF-S201** e relé. Mede volume em tempo real via interrupção de pulsos, corta a bomba automaticamente ao atingir o setpoint e exibe o volume no LCD I2C.

### Calibração
```cpp
float FATOR_CALIBRACAO = 4.5;
// Volume (L) = contagem / (FATOR_CALIBRACAO × 60)
```
Meça 1 litro real, conte os pulsos e ajuste o fator.

### Lógica de Operação
1. Ajuste o volume com os botões UP/DOWN
2. Pressione START → relé liga → bomba roda
3. Interrupção conta pulsos do YF-S201 → calcula volume
4. Ao atingir setpoint → relé desliga → bomba para
