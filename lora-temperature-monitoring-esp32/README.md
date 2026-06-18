# LoRa Temperature Monitoring with Heltec ESP32

> **ESP32 · LoRa 915MHz · DHT11 · OLED Display · Peer-to-Peer Wireless · IoT**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![LoRa](https://img.shields.io/badge/LoRa-915MHz-green?style=flat)](https://lora-alliance.org/)
[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)

Published on [Blog Eletrogate](https://blog.eletrogate.com/monitoramento-remoto-de-temperatura-utilizando-a-heltec-esp32-lora/) · Author: **Saulo Aislan**

---

## Overview

Long-range wireless temperature monitoring system built with two **Heltec ESP32 LoRa** boards and a **DHT11** sensor. The transmitter reads temperature and sends it over LoRa radio (915 MHz); the receiver displays the data on the built-in OLED — no Wi-Fi, no internet, no infrastructure needed.

**Real-world use case:** Remote agricultural sensors, outdoor monitoring stations, battery/solar-powered sensor nodes.

## Key Features

- ✅ Peer-to-peer LoRa at 915 MHz (Anatel-approved for Brazil)
- ✅ Kilometers of range in open field — no router needed
- ✅ OLED feedback on both transmitter and receiver
- ✅ Packet-based protocol — only transmits on temperature change

## Hardware

| Component | Qty |
|---|---|
| Heltec LoRa WiFi 915MHz SX1276 ESP32 (0.96" OLED + antenna) | 2 |
| DHT11 temperature/humidity sensor | 1 |
| 400-point breadboard | 1 |
| Jumper wires | — |

## Wiring — Transmitter

| DHT11 | Heltec ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 17 |

Receiver: no external connections needed.

## Project Structure

```
lora-temperature-monitoring-esp32/
├── transmissor/
│   └── transmissor.ino    ← reads DHT11, sends LoRa packet
└── receptor/
    └── receptor.ino       ← receives packet, shows on OLED
```

## Libraries Required

1. **Heltec ESP32** board package — Preferences → Additional URLs:
   ```
   https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/releases/download/0.0.5/package_heltec_esp32_index.json
   ```
2. **Heltec ESP32** library — Library Manager
3. **DHTesp** — Library Manager (transmitter only)

## How It Works

```
[DHT11] ──► [Heltec TX] ──LoRa 915MHz──► [Heltec RX] ──► [OLED: Temp XX.X °C]
```

---

## Português — Monitoramento Remoto de Temperatura com Heltec ESP32 LoRa

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/monitoramento-remoto-de-temperatura-utilizando-a-heltec-esp32-lora/)

Sistema de monitoramento de temperatura de longo alcance com dois módulos **Heltec ESP32 LoRa** e sensor **DHT11**. O transmissor lê a temperatura e envia via rádio LoRa 915 MHz; o receptor exibe no display OLED integrado — sem Wi-Fi, sem internet, sem infraestrutura.

**Aplicação:** Sensores agrícolas em áreas remotas, estações outdoor com bateria/solar.

### Componentes
- 2× Heltec LoRa WiFi 915MHz SX1276 ESP32 (OLED 0,96" + antena)
- 1× Sensor DHT11 · Protoboard 400 pontos · Jumpers

### Pinagem — Transmissor
| DHT11 | Heltec ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 17 |

### Como Usar
1. Adicione a URL do Board Manager nas preferências do Arduino IDE
2. Instale as bibliotecas **Heltec ESP32** e **DHTesp**
3. Upload de `transmissor.ino` na primeira placa
4. Upload de `receptor.ino` na segunda placa
5. Ligue ambas — temperatura aparece no OLED do receptor
