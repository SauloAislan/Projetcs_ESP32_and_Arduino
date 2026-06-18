# Mini Industrial Conveyor Belt with Object Counter

> **Arduino · Inductive Sensor · DC Motor · LCD I2C · 3D Printing · Industrial Automation · ISR**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Industrial](https://img.shields.io/badge/Use-Industrial%20Automation-blue?style=flat)]()
[![3D Print](https://img.shields.io/badge/3D-Printed%20Parts-orange?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/mini-esteira-industrial-com-contador-de-objetos-e-display-lcd/) · Author: **Saulo Aislan**

---

## Overview

Fully functional **miniature industrial conveyor belt** that transports metal pieces on a TNT fabric belt, detects each piece via an **inductive proximity sensor (NPN)**, and displays the real-time count on a **16×2 LCD**. The Arduino uses a hardware interrupt (ISR) with debounce for accurate counting.

Covers mechanical assembly (aluminum profiles, 3D-printed parts, bearings), electrical integration, and firmware — an end-to-end industrial automation project.

## Key Features

- ✅ Hardware interrupt (ISR) for accurate object detection
- ✅ 150ms debounce prevents double-counting
- ✅ Non-contact inductive sensor (dust, humidity, and vibration resistant)
- ✅ Aluminum profile frame with 3D-printed structural parts
- ✅ Toggle switch for motor ON/OFF independent of counter

## Hardware

### Electronics

| Component | Qty |
|---|---|
| Arduino Uno R3 | 1 |
| DC motor 3–6V with gearbox (dual shaft) | 1 |
| Inductive sensor NPN LJ12A3-4-Z/BX | 1 |
| 16×2 LCD with I2C module | 1 |
| Mini toggle switch KCD11-101 | 1 |
| 12V 1A power supply | 1 |

### Mechanical

| Component | Qty |
|---|---|
| 20×20mm aluminum profiles, 45cm | 2 |
| M3 screws (8–10mm) | 10 |
| T-nuts M3 | 10 |
| Radial bearings 6804 (20×32×7mm) | 4 |
| TNT fabric belt (105cm × 8cm) | 1 |
| 3D printed parts (motor bracket, rollers, sensor mount, feet) | 1 set |

## Wiring

| Component | Arduino Uno |
|---|---|
| Inductive sensor (signal) | Pin 2 (INT0) |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Motor (via toggle switch) | External 12V supply |

## Project Structure

```
mini-conveyor-belt-object-counter/
└── Contador_esteira/
    └── Contador_esteira.ino
```

## Library Required

- **LiquidCrystal_I2C** — Library Manager

## How the ISR Works

```cpp
attachInterrupt(digitalPinToInterrupt(2), contarObjeto, FALLING);
// FALLING edge = sensor triggers when metal object enters field
// 150ms debounce prevents counting same object twice
```

## Assembly Steps

1. Mount aluminum profiles as base frame
2. Install bearings and corner pieces
3. Attach motor with 3D-printed bracket
4. Install motorized roller (shaft) and free roller (bearings)
5. Wrap TNT fabric belt around structure + rollers
6. Tension belt by sliding roller bracket
7. Mount sensor at max 1cm from belt surface
8. Wire electronics and upload firmware

---

## Português — Mini Esteira Industrial com Contador de Objetos

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/mini-esteira-industrial-com-contador-de-objetos-e-display-lcd/)

Mini esteira industrial funcional com motor DC, sensor indutivo NPN, Arduino e LCD I2C. Peças metálicas são transportadas pela esteira TNT, detectadas sem contato pelo sensor e contadas em tempo real via interrupção de hardware (ISR) com debounce.

### Lógica do ISR
```cpp
// Borda de descida = objeto entra no campo do sensor
// Debounce de 150ms evita contagem dupla
attachInterrupt(digitalPinToInterrupt(2), contarObjeto, FALLING);
```

### Posicionamento do Sensor
O sensor indutivo deve estar a no máximo **1 cm** da superfície da esteira para detecção confiável.
