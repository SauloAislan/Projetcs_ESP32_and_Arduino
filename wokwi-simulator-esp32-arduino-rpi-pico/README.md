# Online Simulator for ESP32, Arduino & Raspberry Pi Pico — Wokwi Guide

> **Wokwi · ESP32 · Arduino · Raspberry Pi Pico · MicroPython · MQTT · Online Simulator**

[![Wokwi](https://img.shields.io/badge/Simulator-Wokwi-green?style=flat)](https://wokwi.com/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![MicroPython](https://img.shields.io/badge/MicroPython-Pico-yellow?style=flat)](https://micropython.org/)

Published on [Blog Eletrogate](https://blog.eletrogate.com/simulando-esp32-arduino-e-raspberry-pi-com-o-wokwi/) · Author: **Saulo Aislan**

---

## Overview

Complete guide to **Wokwi** — the free online simulator for ESP32, Arduino, and Raspberry Pi Pico. Prototype firmware without hardware using a browser-based environment with virtual LEDs, sensors, displays, motors, and more. Three example projects cover different platforms and use cases.

Wokwi supports **Arduino C++** and **MicroPython**, includes a built-in serial monitor, logic analyzer, and WiFi simulation with real MQTT broker connectivity.

## Key Features

- ✅ Zero hardware required — run in browser
- ✅ Supports ESP32, Arduino (Uno/Nano/Mega), Raspberry Pi Pico
- ✅ Real WiFi simulation → connect to actual MQTT brokers
- ✅ DHT22, LCD, buttons, 7-segment, servos, motors all simulated
- ✅ MicroPython REPL console for Pico
- ✅ Shareable project links

## Example Projects Included

### 1. Mini Piano — Arduino
8-button musical instrument using `pitches.h` tone library.

| Component | Arduino |
|---|---|
| Buttons (×8) | Pins 4–12 |
| Buzzer | Pin 8 |

### 2. ESP32 + DHT22 + MQTT
IoT sensor publishing temperature and humidity to `test.mosquitto.org` (public broker).

| Topic | Data |
|---|---|
| `topicowokwi/Temp` | Temperature (°C) |
| `topicowokwi/Humidade` | Humidity (%) |

### 3. 7-Segment Counter — Raspberry Pi Pico (MicroPython)
Toggle switch increments/decrements counter on common-anode 7-segment display.

```python
# Toggle switch on GPIO 11
# 7-segment segments on GPIO 2–9
```

## Project Structure

```
wokwi-simulator-esp32-arduino-rpi-pico/
├── mini_piano_arduino/
│   └── mini_piano_arduino.ino
├── mqtt_esp32_dht22/
│   └── mqtt_esp32_dht22.ino
└── contador_7seg_raspberry_pico/
    └── contador_7seg_raspberry_pico.py
```

## Libraries Required

- **EspMQTTClient** — ESP32 MQTT (Library Manager)
- **DHTesp** — DHT22 for ESP32 (Library Manager)

## How to Use

1. Go to [wokwi.com](https://wokwi.com) and create a new project
2. Select your board (ESP32 / Arduino / Pico)
3. Paste the code and add components from the toolbar
4. Click **Start** ▶ to simulate

---

## Português — Simulando ESP32, Arduino e Raspberry Pi com o Wokwi

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/simulando-esp32-arduino-e-raspberry-pi-com-o-wokwi/)

Guia completo do **Wokwi** — simulador online gratuito para ESP32, Arduino e Raspberry Pi Pico. Prototipe firmware sem hardware, direto no navegador. Três projetos de exemplo: piano com Arduino, MQTT com ESP32+DHT22, e contador 7 segmentos com Pico em MicroPython.

### Como Usar
1. Acesse [wokwi.com](https://wokwi.com) e crie um novo projeto
2. Selecione a placa (ESP32 / Arduino / Pico)
3. Cole o código e adicione componentes pela barra lateral
4. Clique em **Start** ▶ para simular
