# Otto DIY Robot with Arduino Nano

> **Arduino Nano · Servo Motor · HC-SR04 · Robotics · STEM · 3D Printing · Otto DIY**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![3D Print](https://img.shields.io/badge/3D-Printed-orange?style=flat)]()
[![Robotics](https://img.shields.io/badge/Robotics-Biped-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/montando-seu-robo-otto-com-arduino-nano/) · Author: **Saulo Aislan**

---

## Overview

Assembly and programming of the **Otto DIY** open-source biped robot (11×7×12 cm). Otto walks, dances, makes sounds, and autonomously avoids obstacles detected by an ultrasonic sensor. Excellent STEM educational tool — minimal soldering, beginner-friendly code.

## Key Features

- ✅ 4-servo bipedal walking with gait control
- ✅ Ultrasonic obstacle avoidance (< 15 cm → stop, sing, reverse, turn)
- ✅ Buzzer sound effects (surprise, happy, sad, etc.)
- ✅ Programmable via Arduino IDE or **Otto Blockly** (no-code)
- ✅ Step-down regulator for stable 5V servo supply from 9V battery
- ✅ Fully 3D printable body (PLA/PETG)

## Hardware

| Component | Qty |
|---|---|
| Arduino Nano V3.0 + USB cable | 1 |
| Arduino Nano expansion shield | 1 |
| HC-SR04 ultrasonic sensor | 1 |
| TowerPro SG90 9g servo | 4 |
| Active buzzer 3V | 1 |
| 9V battery | 1 |
| Mini 360 DC-DC step-down regulator | 1 |
| F-F jumper wires (40 units) | 1 set |
| 3D printed parts (head, body, 2 legs, 2 feet) | 1 set |

## Pin Mapping

| Component | Arduino Nano |
|---|---|
| Left leg servo | Pin 2 |
| Right leg servo | Pin 3 |
| Left foot servo | Pin 4 |
| Right foot servo | Pin 5 |
| Buzzer | Pin 13 |
| HC-SR04 TRIG | Pin 8 |
| HC-SR04 ECHO | Pin 9 |

## Library Required

- **Otto DIY** — Library Manager (search "Otto")

## Obstacle Avoidance Logic

```cpp
if (distance <= 15 cm):
    sing(surprise) → walk backward → turn right
else:
    walk forward
```

## Project Structure

```
otto-robot-arduino-nano/
└── Meu_Robo_Otto/
    └── Meu_Robo_Otto.ino
```

## Assembly Steps

1. Servo installation (legs & feet) — align at exactly 90°
2. Head assembly — mount HC-SR04 and buzzer
3. Shield + Arduino attach to head
4. Power calibration — adjust step-down trimpot to exactly 5V
5. Connect all servos, sensor, buzzer to shield
6. Upload firmware → Otto starts walking!

---

## Português — Robô Otto com Arduino Nano

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/montando-seu-robo-otto-com-arduino-nano/)

Montagem e programação do **Robô Otto DIY** — robô bípede open-source de 11×7×12 cm. Caminha, dança, emite sons e evita obstáculos com sensor ultrassônico. Ferramenta educacional STEM excelente.

### Lógica de Desvio
```
Se distância ≤ 15 cm → Canta + Recua + Vira
Caso contrário → Avança
```

### Como Usar
1. Instale a biblioteca **Otto DIY** no Library Manager
2. Imprima as peças 3D (PLA/PETG)
3. Monte os servos com alinhamento de 90°
4. Calibre o step-down para 5V exatos
5. Upload de `Meu_Robo_Otto.ino`
