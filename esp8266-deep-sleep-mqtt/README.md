# ESP8266 Deep Sleep + MQTT — Ultra-Low-Power IoT Node

> **ESP8266 · Deep Sleep · MQTT · TMP36 · Power Optimization · IoT · NodeMCU**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![MQTT](https://img.shields.io/badge/MQTT-Protocol-purple?style=flat)](https://mqtt.org/)
[![Platform](https://img.shields.io/badge/Platform-ESP8266-blue?style=flat)](https://www.espressif.com/)

Published on [Blog Eletrogate](https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/) · Author: **Saulo Aislan**

---

## Overview

Demonstrates how to reduce ESP8266 power consumption from ~80 mA (active Wi-Fi) down to **~20 µA** using Deep Sleep mode. The practical example reads temperature from a TMP36 sensor, publishes the reading to an MQTT broker, then sleeps for 30 seconds before repeating — ideal for battery-powered IoT sensor nodes.

## Sleep Modes Comparison

| Mode | Current | Wi-Fi | CPU Clock |
|---|---|---|---|
| Active | ~80 mA | ON | ON |
| Modem-Sleep | ~15 mA | OFF | ON |
| Light-Sleep | ~0.4 mA | OFF | OFF |
| **Deep-Sleep** | **~20 µA** | OFF | RTC only |

## Hardware

| Component | Qty |
|---|---|
| ESP8266 NodeMCU V3 (Lolin) | 1 |
| TMP36 temperature sensor | 1 |
| Push button (for manual wake) | 1 |
| 10kΩ resistor | 1 |
| 400-point breadboard | 1 |

## Project Structure

```
esp8266-deep-sleep-mqtt/
├── DeepSleep_Tempo/
│   └── DeepSleep_Tempo.ino    ← wakes by timer (30s cycle)
├── DeepSleep_Botao/
│   └── DeepSleep_Botao.ino    ← wakes by RST button
└── DeepSleep_MQTT/
    └── DeepSleep_MQTT.ino     ← reads TMP36 → MQTT → sleep 30s
```

## Wiring

| Component | ESP8266 NodeMCU |
|---|---|
| TMP36 analog output | A0 |
| GPIO16 (D0) → RST | RST pin (timer wake only — connect AFTER upload) |
| Wake button | RST pin to GND |

> ⚠️ **Important:** Connect D0 → RST **only after uploading** firmware to avoid programming issues.

## Libraries

- **ESP8266WiFi** — included in ESP8266 Arduino Core
- **PubSubClient** — Library Manager

## Power Cycle (MQTT variant)

```
[Boot] → [Connect WiFi] → [Read TMP36] → [Publish MQTT] → [Deep Sleep 30s] → [Repeat]
```

Total active time per cycle: ~2–3 seconds. Duty cycle ~10% → effective current << 10 mA.

---

## Português — ESP8266 Deep Sleep + MQTT

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/)

Demonstra como reduzir o consumo do ESP8266 de ~80 mA para **~20 µA** com Deep Sleep. O exemplo prático lê o sensor TMP36, publica via MQTT e dorme por 30 segundos — ideal para nós IoT alimentados por bateria.

### Estrutura
- `DeepSleep_Tempo/` — acorda por timer (30s)
- `DeepSleep_Botao/` — acorda por botão no RST
- `DeepSleep_MQTT/` — lê TMP36 → MQTT → dorme

### Como Usar (MQTT)
1. Edite `WIFI_SSID` e `WIFI_PASS` no arquivo `.ino`
2. Faça o upload
3. Conecte D0 ao RST (somente após upload)
4. O ciclo: WiFi → lê sensor → publica → dorme 30s → repete
