# Object Counter with ESP32, Inductive Sensor, and LCD

> **ESP32 · Inductive Proximity Sensor · LCD I2C · Industrial Automation · Interrupt · Debounce**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![Sensor](https://img.shields.io/badge/Sensor-Inductive%20PNP-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/contador-de-objetos-com-arduino-sensor-indutivo-e-display-lcd/) · Author: **Saulo Aislan**

---

## Overview

Industrial-grade object counter using an **ESP32**, **inductive proximity sensor (PNP)**, and **16×2 LCD**. Unlike optical sensors, the inductive sensor detects only metallic objects — immune to ambient light, dust, and transparent materials. Count is displayed live on LCD and can be reset via button.

Applicable to production line monitoring, inventory management, and quality control.

## Key Features

- ✅ Non-contact inductive sensing (metallic objects only)
- ✅ 50ms software debounce prevents false counts
- ✅ Real-time display on 16×2 LCD via I2C (SDA/SCL)
- ✅ Reset button to zero the counter
- ✅ Immune to light interference

## Hardware

| Component | Qty |
|---|---|
| ESP32 DevKitC S1 | 1 |
| Inductive proximity sensor PNP LJ12A3-4-Z/BX | 1 |
| 16×2 LCD with I2C adapter module | 1 |
| Push button (reset) | 1 |
| 12V 1A power supply | 1 |
| 400-point breadboard | 1 |

## Wiring

| Component | ESP32 |
|---|---|
| Inductive sensor (signal) | GPIO 12 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| LCD VCC | 5V |
| LCD GND | GND |
| Sensor VCC | 12V (external) |
| Sensor GND | GND (shared) |

> **PNP sensor output:** signal goes LOW when metal object is detected.

## Project Structure

```
object-counter-inductive-sensor-lcd/
└── Contador_de_objeto/
    └── Contador_de_objeto.ino
```

## Library Required

- **LiquidCrystal_I2C** — Library Manager

## Sensor Positioning

- Detection range: 0–4 mm from sensor face
- Mount sensor perpendicular to moving objects
- Adjust distance to trigger on object approach, not recede

## Working Principle

```
Object enters sensor field → OUTPUT goes LOW → ESP32 GPIO 12 reads LOW
→ Debounce 50ms → Increment counter → Update LCD
```

---

## Português — Contador de Objetos com ESP32 e Sensor Indutivo

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/contador-de-objetos-com-arduino-sensor-indutivo-e-display-lcd/)

Contador industrial de objetos com **ESP32**, sensor **indutivo PNP** e **LCD I2C**. O sensor indutivo detecta apenas objetos metálicos — imune a luz ambiente, poeira e materiais transparentes.

### Lógica de Funcionamento
```
Objeto entra no campo → saída vai para LOW → ESP32 GPIO12 detecta LOW
→ Debounce 50ms → Incrementa contador → Atualiza LCD
```

### Posicionamento do Sensor
- Alcance de detecção: 0–4 mm da face do sensor
- Monte perpendicular ao objeto em movimento
- Ajuste para disparar na aproximação, não no afastamento
