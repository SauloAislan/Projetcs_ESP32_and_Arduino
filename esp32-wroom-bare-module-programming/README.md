# Programming ESP32-WROOM-32 Bare Module with Custom PCB Adapter

> **ESP32-WROOM-32 · PCB Design · EasyEDA · SMD Soldering · Custom Adapter · Breadboard**

[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![PCB](https://img.shields.io/badge/PCB-EasyEDA-blue?style=flat)](https://easyeda.com/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)

Published on [Blog Eletrogate](https://blog.eletrogate.com/esp-wroom-32-como-programar-o-modulo-esp32/) · Author: **Saulo Aislan**

---

## Overview

How to work with the **ESP32-WROOM-32** module as a standalone component (without a DevKit board). Covers designing a custom DIP-pitch adapter PCB in **EasyEDA**, ordering from JLCPCB, soldering the SMD module, and flashing firmware via CH340 USB-Serial adapter.

This is the approach used in commercial products — you buy just the module, not a full dev board, and integrate it directly onto your own PCB.

## Key Features

- ✅ ESP32-WROOM-32 module programming without DevKit board
- ✅ Custom breadboard-compatible adapter PCB (2.54mm pitch)
- ✅ Boot/Enable circuit with auto-reset via DTR/RTS
- ✅ EasyEDA schematic → Gerber → JLCPCB workflow
- ✅ SMD hand-soldering (paste + hot air or iron)

## Hardware

| Component | Qty |
|---|---|
| ESP32-WROOM-32 module | 1 |
| Custom adapter PCB | 1 |
| CH340 USB-Serial adapter (3.3V logic) | 1 |
| 10µF electrolytic capacitor | 2 |
| 10kΩ resistor | 2 |
| Tactile push button (BOOT + EN) | 2 |
| 2.54mm pin headers | — |

## ESP32-WROOM-32 Boot Modes

| IO0 | EN | Mode |
|---|---|---|
| LOW (BOOT button held) | HIGH | Download / Flash mode |
| HIGH (floating) | HIGH | Normal run mode |
| Any | LOW → HIGH | Reset |

## Auto-Reset Circuit

The DTR/RTS signals from the USB-Serial adapter automatically control IO0 and EN — no need to hold buttons manually when uploading via Arduino IDE.

## Arduino IDE Setup

```
Board: "ESP32 Dev Module"
Upload Speed: 921600
CPU Frequency: 240MHz
Flash Size: 4MB (32Mb)
Partition Scheme: Default 4MB with spiffs
```

## Project Structure

```
esp32-wroom-bare-module-programming/
└── Blink_ESP32/
    └── Blink_ESP32.ino    ← LED blink on GPIO4, every 5s
```

## Flashing Steps

1. Connect CH340 TX→ESP32 RX, RX→TX, GND→GND, 3V3→3V3
2. Hold BOOT button → press EN → release EN → release BOOT
3. Click **Upload** in Arduino IDE
4. After upload, press EN to reset and run

---

## Português — ESP-WROOM-32 com Adaptador PCB Personalizado

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/esp-wroom-32-como-programar-o-modulo-esp32/)

Como trabalhar com o módulo **ESP32-WROOM-32** standalone, sem um kit de desenvolvimento. Cobre o design de um adaptador PCB no **EasyEDA**, envio para fabricação na JLCPCB, soldagem SMD e programação via adaptador USB-Serial CH340.

### Modos de Boot
| IO0 | EN | Modo |
|---|---|---|
| LOW (botão BOOT pressionado) | HIGH | Download/Flash |
| HIGH (solto) | HIGH | Execução normal |
| Qualquer | LOW→HIGH | Reset |

### Passos para Gravar
1. Conecte CH340: TX→RX, RX→TX, GND→GND, 3V3→3V3
2. Segure BOOT → pressione EN → solte EN → solte BOOT
3. Clique **Upload** no Arduino IDE
4. Pressione EN para executar após upload
