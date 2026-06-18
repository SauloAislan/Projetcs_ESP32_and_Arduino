# Wi-Fi Controlled Cat Water Fountain with ESP8266

> **ESP8266 · AsyncWebServer · Relay · Water Pump · IoT · Home Automation**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/Platform-ESP8266-blue?style=flat)](https://www.espressif.com/)
[![Web](https://img.shields.io/badge/Interface-Web%20UI-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/fonte-bebedouro-para-gatos-com-esp8266/) · Author: **Saulo Aislan**

---

## Overview

Automated water fountain for cats controlled via a **responsive web interface** over Wi-Fi. The ESP8266 creates its own access point — no router needed. Four operating modes let you run the pump continuously, on a timer, manually, or both.

Cats prefer moving water; this project ensures fresh, flowing water while preventing sediment buildup.

## Operating Modes

| Mode | Description |
|---|---|
| Continuous | Pump always ON |
| Time Interval | ON for 15s every 60 minutes |
| Manual | Web button (ON/OFF) |
| Time + Manual | Combines timer and manual control |

## Key Features

- ✅ Standalone Wi-Fi AP — no router required
- ✅ Responsive HTML web interface (mobile-friendly)
- ✅ Async HTTP server (non-blocking)
- ✅ NPN transistor driver for relay (protects ESP8266 GPIO)
- ✅ 4 pump control modes

## Hardware

| Component | Qty |
|---|---|
| Wemos D1 Mini Pro (ESP8266) | 1 |
| Mini submersible water pump (5V) | 1 |
| 5V relay module (1 channel) | 1 |
| NPN transistor 2N2222 | 1 |
| 1kΩ resistor | 1 |
| 47kΩ resistor | 1 |
| 5V 1A power supply | 1 |

## Wiring

| Component | Wemos D1 Mini Pro |
|---|---|
| Relay (via transistor driver) | D2 (GPIO4) |
| Power | VIN / GND |

**Transistor circuit:**
```
ESP8266 D2 ──[1kΩ]──► Base (2N2222)
                       Collector ──► Relay coil ──► 5V
                       Emitter ──► GND
GND ──[47kΩ]──► Base  (pull-down)
```

## Wi-Fi Access

- **SSID:** `Bebedouro`  |  **Password:** `123456789`
- **URL:** http://192.168.4.1

## Project Structure

```
cat-fountain-esp8266-wifi/
└── Bebedouro/
    └── Bebedouro.ino
```

## Libraries Required

- **ESPAsyncTCP** — Library Manager
- **ESPAsyncWebServer** — Library Manager

---

## Português — Fonte Bebedouro para Gatos com ESP8266

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/fonte-bebedouro-para-gatos-com-esp8266/)

Bebedouro automatizado para gatos controlado via **interface web Wi-Fi**. O ESP8266 cria seu próprio ponto de acesso — sem roteador. Quatro modos de operação: contínuo, por tempo, manual e híbrido.

> ⚠️ O sistema não possui sensor de nível — verifique periodicamente para evitar que a bomba queime.

### Acesso
- **SSID:** `Bebedouro` | **Senha:** `123456789` | **URL:** http://192.168.4.1

### Como Usar
1. Instale **ESPAsyncTCP** e **ESPAsyncWebServer**
2. Upload de `Bebedouro.ino` no Wemos D1 Mini Pro
3. Conecte ao Wi-Fi `Bebedouro`
4. Abra http://192.168.4.1 e selecione o modo
