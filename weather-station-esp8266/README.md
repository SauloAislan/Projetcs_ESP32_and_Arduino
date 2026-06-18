# Residential Weather Station with ESP8266

> **ESP8266 · DHT11 · BMP280 · Rain Sensor · OLED 128x64 · IoT · Multi-sensor**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/Platform-ESP8266-blue?style=flat)](https://www.espressif.com/)
[![I2C](https://img.shields.io/badge/Protocol-I2C-orange?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/estacao-meteorologica-residencial-com-esp8266/) · Author: **Saulo Aislan**

---

## Overview

Local weather station that displays real-time environmental data on a **128×64 OLED display** — cycling through five screens every 3 seconds. Uses four sensors simultaneously for accurate local measurements instead of relying on city-level weather apps.

**Metrics displayed:** Temperature · Humidity · Atmospheric Pressure · Altitude · Rain detection

## Key Features

- ✅ 5 rotating display screens with icons (sun/cloud animation)
- ✅ Dual temperature reading averaged from DHT11 + BMP280
- ✅ Rain detection via analog sensor with voltage divider
- ✅ Altitude calculated from barometric pressure (BMP280)
- ✅ I2C bus shared between OLED and BMP280

## Hardware

| Component | Qty |
|---|---|
| ESP8266 12F (USB module) | 1 |
| OLED display 128×64 0.96" I2C (blue/yellow) | 1 |
| DHT11 temperature/humidity sensor | 1 |
| BMP280 pressure + temperature sensor | 1 |
| Rain sensor module (analog) | 1 |
| 4.7kΩ resistors | 2 |
| 5V power supply + Micro USB | 1 |

## Wiring

| Component | ESP8266 Pin |
|---|---|
| OLED SDA | D4 (GPIO2) |
| OLED SCL | D5 (GPIO14) |
| BMP280 SDA | D4 (GPIO2) — shared I2C bus |
| BMP280 SCL | D5 (GPIO14) — shared I2C bus |
| DHT11 DATA | D1 (GPIO5) |
| Rain sensor (analog) | A0 — with 4.7kΩ voltage divider |

## Project Structure

```
weather-station-esp8266/
└── Estacao_metereologica/
    ├── Estacao_metereologica.ino
    └── images.h    ← bitmap icons (sun & cloud) — download from article
```

## Libraries Required

| Library | Source |
|---|---|
| BMP280 (mahfuz195) | GitHub |
| DHTesp (beegee-tokyo) | Library Manager |
| SSD1306 (ThingPulse) | Library Manager |

## Display Rotation

```
[Rain] → [Temperature] → [Pressure] → [Altitude] → [Humidity] → repeat (3s each)
```

---

## Português — Estação Meteorológica Residencial com ESP8266

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/estacao-meteorologica-residencial-com-esp8266/)

Estação meteorológica local com **ESP8266**, **DHT11**, **BMP280**, sensor de chuva e display OLED 128×64. Exibe temperatura, umidade, pressão, altitude e indicação de chuva em 5 telas que alternam a cada 3 segundos com ícones gráficos.

### Pinagem
| Componente | ESP8266 |
|---|---|
| OLED/BMP280 SDA | D4 (GPIO2) |
| OLED/BMP280 SCL | D5 (GPIO14) |
| DHT11 DATA | D1 (GPIO5) |
| Sensor chuva | A0 + divisor 2×4k7Ω |

### Como Usar
1. Baixe o arquivo `images.h` do artigo e coloque na mesma pasta do `.ino`
2. Instale as bibliotecas (BMP280, DHTesp, SSD1306)
3. Faça upload pelo Arduino IDE
4. Abra o Serial Monitor a 115200 baud para ver os dados brutos
