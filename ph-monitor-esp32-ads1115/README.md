# pH Monitor with ESP32 and ADS1115 — Hydroponics & Water Quality

> **ESP32 · ADS1115 · PH-4502C · Hydroponics · Water Quality · PlatformIO · ADC 16-bit**

[![PlatformIO](https://img.shields.io/badge/PlatformIO-orange?style=flat&logo=platformio)](https://platformio.org/)
[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![Sensor](https://img.shields.io/badge/Sensor-PH--4502C-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/monitorando-o-ph-de-liquidos-com-esp32-e-sensor-ph-4502c/) · Author: **Saulo Aislan**

---

## Overview

High-precision pH monitoring system using an **ESP32**, external **ADS1115** 16-bit ADC, and **PH-4502C** electrode sensor. The ADS1115 dramatically improves accuracy over the ESP32's built-in ADC. Essential for **hydroponics**, aquaculture, water treatment, and lab applications where precise pH control is critical.

Optimal pH for hydroponic plants: **5.5 – 6.5**

## Key Features

- ✅ 16-bit ADC via ADS1115 (vs 12-bit internal ESP32 ADC)
- ✅ 10-sample median filter removes noise outliers
- ✅ Two-step calibration: offset + buffer solution
- ✅ PlatformIO project (also works in Arduino IDE)
- ✅ Serial output: voltage + calculated pH

## Hardware

| Component | Qty |
|---|---|
| ESP32 DevKitC S1 | 1 |
| ADS1115 ADC module (I2C, 16-bit) | 1 |
| PH-4502C pH sensor with BNC electrode | 1 |
| pH buffer solutions (4, 7, 10) for calibration | — |
| 400-point breadboard × 2 | 2 |

## Wiring

| Component | ESP32 |
|---|---|
| ADS1115 SDA | GPIO 21 |
| ADS1115 SCL | GPIO 22 |
| ADS1115 VDD | 3.3V |
| ADS1115 GND | GND |
| PH-4502C Po (output) | ADS1115 A0 |
| PH-4502C V+ | 5V |
| PH-4502C GND | GND |

## Project Structure

```
ph-monitor-esp32-ads1115/
├── platformio.ini
└── src/
    └── main.cpp    ← rename to .ino for Arduino IDE
```

## Library Required

- **Adafruit ADS1X15** — PlatformIO / Library Manager

## Calibration (Step-by-Step)

### Step 1 — Offset Calibration
1. Short-circuit BNC connector (outer ring to center pin)
2. Upload and read serial output
3. Adjust "calibration reading" potentiometer until voltage ≈ **2.5V**

### Step 2 — pH 7 Calibration
1. Dip electrode in pH 7 buffer solution
2. Adjust `calibration_value` in code until reading = **7.00**
3. Re-upload

### Cross-contamination Prevention
Always rinse electrode with distilled water between measurements.

## pH Formula

```
pH = -5.70 × Voltage + calibration_value
```

---

## Português — Monitor de pH com ESP32 e ADS1115

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/monitorando-o-ph-de-liquidos-com-esp32-e-sensor-ph-4502c/)

Monitor de pH de alta precisão com **ESP32**, **ADS1115** (ADC 16 bits I2C) e sensor **PH-4502C**. Ideal para hidroponias, aquicultura e controle de qualidade da água. O ADS1115 oferece resolução muito superior ao ADC interno do ESP32.

**pH ideal para hidroponia: 5,5 – 6,5**

### Calibração
1. **Offset:** curto no BNC → ajuste trimpot até ~2,5V
2. **pH 7:** solução tampão → ajuste `calibration_value` até ler 7,0

### Fórmula
```
pH = -5,70 × Tensão + calibration_value
```
