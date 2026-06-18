# DRV8825 Stepper Motor Driver — Complete Guide with Arduino

> **DRV8825 · NEMA 17 · Stepper Motor · Microstepping · Arduino · 3D Printer · CNC**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Motor](https://img.shields.io/badge/Motor-NEMA%2017-orange?style=flat)]()
[![Driver](https://img.shields.io/badge/Driver-DRV8825-blue?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/driver-drv8825-guia-completo-para-projetos-com-arduino-e-motor-de-passo/) · Author: **Saulo Aislan**

---

## Overview

Complete guide for controlling a **NEMA 17 stepper motor** using the **DRV8825** driver with Arduino. The DRV8825 outperforms the A4988 with higher voltage range (8.2V–45V), finer microstepping (up to 1/32), integrated over-current and thermal protection — ideal for 3D printers, CNC routers, and precision automation.

## DRV8825 Specifications

| Parameter | Value |
|---|---|
| Supply voltage | 8.2V – 45V |
| Max current | ~2.2A (with heatsink) |
| Microstepping | Full, 1/2, 1/4, 1/8, 1/16, **1/32** |
| Interface | STEP / DIR |
| Protection | Over-current + thermal shutdown |

## Hardware

| Component | Qty |
|---|---|
| Arduino Uno R3 | 1 |
| DRV8825 stepper driver module | 1 |
| NEMA 17 stepper motor (4.2 kgf.cm / 1.7A) | 1 |
| 100µF/25V electrolytic capacitor | 1 |
| 12V 1A power supply | 1 |
| 400-point breadboard | 1 |

## Wiring

| DRV8825 | Arduino |
|---|---|
| RST | 5V |
| SLP | 5V |
| GND | GND |
| STEP | Pin 3 |
| DIR | Pin 2 |

> Place the 100µF capacitor close to VMOT and GND pins to suppress voltage spikes.

## Microstepping Table

| M0 | M1 | M2 | Resolution | Steps/Revolution |
|---|---|---|---|---|
| LOW | LOW | LOW | Full step | 200 |
| HIGH | LOW | LOW | 1/2 step | 400 |
| LOW | HIGH | LOW | 1/4 step | 800 |
| HIGH | HIGH | LOW | 1/8 step | 1600 |
| LOW | LOW | HIGH | 1/16 step | 3200 |
| HIGH | HIGH | HIGH | 1/32 step | 6400 |

Float M0/M1/M2 = Full step (internal pull-down resistors).

## Current Limit Adjustment

```
V_ref = I_max × 0.5
Example for 1A: V_ref = 0.5V
```
Measure V_ref between trimpot center and GND while adjusting.

## Project Structure

```
drv8825-stepper-motor-driver-arduino/
└── Motor_Passo_DRV8825/
    └── Motor_Passo_DRV8825.ino
```

## Demo Behavior

1. Clockwise rotation — slow (2000 µs step delay)
2. 1-second pause
3. Counter-clockwise — fast (1000 µs step delay)
4. Repeat

## Applications

- 3D printer axes (X, Y, Z)
- CNC routers and plotters
- Camera sliders and motorized focus
- Robotics and precision automation

---

## Português — Driver DRV8825 com Arduino e Motor de Passo

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/driver-drv8825-guia-completo-para-projetos-com-arduino-e-motor-de-passo/)

Guia completo para controlar um **motor de passo NEMA 17** com o driver **DRV8825** e Arduino. O DRV8825 supera o A4988: tensão 8,2V–45V, microstepping até 1/32, proteção integrada de sobrecorrente e temperatura.

### Calibração de Corrente
```
V_ref = I_max × 0,5  →  Para 1A: V_ref = 0,5V
```
Meça entre o centro do trimpot e GND ao ajustar.

### Como Usar
1. Monte o circuito conforme a pinagem
2. Coloque o capacitor 100µF próximo à alimentação
3. Upload de `Motor_Passo_DRV8825.ino`
4. O motor gira horário (lento) e anti-horário (rápido)
