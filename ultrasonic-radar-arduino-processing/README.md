# Ultrasonic Radar with Arduino + Processing GUI

> **Arduino · HC-SR04 · Servo Motor · Processing · Real-time Visualization · Sonar**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Processing](https://img.shields.io/badge/GUI-Processing-blue?style=flat)](https://processing.org/)
[![Sensor](https://img.shields.io/badge/Sensor-HC--SR04-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/radar-sonar-ultrassonico-para-seus-projetos/) · Author: **Saulo Aislan**

---

## Overview

Rotating ultrasonic radar that sweeps a **HC-SR04 sensor** from 15° to 165° using a servo motor, then renders a **real-time radar display** in Processing (Java). Objects within 40 cm are highlighted in red on the Plan Position Indicator (PPI) screen.

Combines embedded firmware (Arduino) with desktop visualization (Processing) over serial communication.

## Key Features

- ✅ 150° sweep range (15°–165°) with continuous back-and-forth scan
- ✅ Real-time radar PPI display with distance rings at 10/20/30/40 cm
- ✅ Object detection up to 40 cm
- ✅ Serial data protocol: `ANGLE,DISTANCE.`
- ✅ Green radar line animation mimics real radar systems

## Hardware

| Component | Qty |
|---|---|
| Arduino Nano V3.0 | 1 |
| HC-SR04 ultrasonic sensor | 1 |
| TowerPro MG90S servo (metal gear, 180°) | 1 |
| 170-point breadboard | 1 |
| Jumper wires (M-M and M-F, 20cm) | 40 |

## Wiring

| Component | Arduino Nano |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | Pin 11 |
| HC-SR04 ECHO | Pin 10 |
| Servo signal | Pin 12 |
| Servo VCC | 5V (or external if servo stutters) |

## Project Structure

```
ultrasonic-radar-arduino-processing/
├── Radar_ultrasonico/
│   └── Radar_ultrasonico.ino    ← Arduino: servo sweep + distance
└── Radar_Processing/
    └── Radar_Processing.pde     ← Processing: radar GUI
```

## How to Run

**Arduino:**
1. Upload `Radar_ultrasonico.ino`

**Processing:**
1. Install [Processing](https://processing.org/download)
2. Open `Radar_Processing.pde`
3. Change `"COM5"` to your Arduino's COM port
4. Close Arduino Serial Monitor
5. Click **Play** ▶

## Serial Protocol

```
Arduino → PC:   "ANGLE,DISTANCE."
Example:        "90,23."  = 90°, 23 cm
```

---

## Português — Radar Ultrassônico com Arduino e Processing

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/radar-sonar-ultrassonico-para-seus-projetos/)

Radar rotativo com Arduino Nano, sensor HC-SR04 e servo MG90S. Visualização em tempo real no Processing (Java) com display estilo PPI. Detecta objetos até 40 cm em um arco de 150°.

### Como Usar
1. Upload de `Radar_ultrasonico.ino` no Arduino
2. Abra `Radar_Processing.pde` no Processing
3. Altere `"COM5"` para a porta do seu Arduino
4. Feche o Serial Monitor e clique em **Play**
