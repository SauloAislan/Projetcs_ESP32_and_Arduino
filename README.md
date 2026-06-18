# IoT & Embedded Systems Portfolio — Saulo Aislan

> **Firmware Engineer | IoT Developer | Embedded Systems | Arduino | ESP32 | LoRa | MQTT | RS-485 | PCB Design**

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![ESP32](https://img.shields.io/badge/ESP32-red?style=flat)](https://www.espressif.com/)
[![ESP8266](https://img.shields.io/badge/ESP8266-blue?style=flat)](https://www.espressif.com/)
[![MQTT](https://img.shields.io/badge/MQTT-Protocol-purple?style=flat)](https://mqtt.org/)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-orange?style=flat&logo=platformio)](https://platformio.org/)

---

## About

Embedded systems developer and technical writer with **5+ years** building and documenting IoT projects. All projects were published as full tutorials on [Blog Eletrogate](https://blog.eletrogate.com), Brazil's largest electronics community — covering hardware design, firmware development, industrial communication protocols, and PCB manufacturing.

**Core Skills:**
- Microcontrollers: Arduino (Uno, Nano, Mega), ESP8266, ESP32, Raspberry Pi Pico
- Wireless: LoRa 915MHz, Wi-Fi, MQTT broker integration
- Industrial protocols: RS-485 (half-duplex, full-duplex), RS-232/TTL
- Sensors: DHT11/22, BMP280, HC-SR04, inductive PNP/NPN, pH sensor, flow sensor, rain sensor
- Actuators: stepper motors (DRV8825, A4988), DC motors, servo motors, relays
- PCB Design: EasyEDA, Gerber generation, SMD soldering (paste + hot air)
- Platforms: Arduino IDE, PlatformIO (VS Code), Processing, Wokwi Simulator

---

## Projects

### 🔗 Wireless & IoT

| Repository | Description | Stack |
|---|---|---|
| [lora-temperature-monitoring-esp32](./lora-temperature-monitoring-esp32/) | Long-range P2P temperature monitoring over LoRa 915MHz | ESP32, LoRa, DHT11, OLED |
| [esp32-cam-remote-access-ngrok](./esp32-cam-remote-access-ngrok/) | Live MJPEG video stream accessible globally via Ngrok tunnel | ESP32-CAM, OV2640, Ngrok |
| [cat-fountain-esp8266-wifi](./cat-fountain-esp8266-wifi/) | Wi-Fi controlled water pump with async web interface | ESP8266, AsyncWebServer, Relay |
| [weather-station-esp8266](./weather-station-esp8266/) | Multi-sensor local weather station with OLED display | ESP8266, DHT11, BMP280, OLED |
| [esp8266-deep-sleep-mqtt](./esp8266-deep-sleep-mqtt/) | Ultra-low-power IoT node: reads sensor → publishes MQTT → deep sleeps | ESP8266, MQTT, TMP36 |
| [wokwi-simulator-esp32-arduino-rpi-pico](./wokwi-simulator-esp32-arduino-rpi-pico/) | Three simulated projects: Piano (Arduino), 7-seg counter (Pico), MQTT (ESP32) | Arduino, MicroPython, MQTT |

### 📡 Industrial Communication

| Repository | Description | Stack |
|---|---|---|
| [rs485-half-duplex-arduino](./rs485-half-duplex-arduino/) | Bidirectional RS-485 between Arduino Uno and Mega; pot controls remote LED | RS-485, MAX485, SoftwareSerial |
| [rs485-usb-pc-to-arduino](./rs485-usb-pc-to-arduino/) | PC sends commands via USB-RS485; Arduino controls LCD + LED | RS-485, LCD I2C, USB-RS485 |

### 🤖 Robotics & Motion

| Repository | Description | Stack |
|---|---|---|
| [otto-robot-arduino-nano](./otto-robot-arduino-nano/) | Open-source biped robot with ultrasonic obstacle avoidance | Arduino Nano, SG90 Servo, HC-SR04 |
| [ultrasonic-radar-arduino-processing](./ultrasonic-radar-arduino-processing/) | Rotating ultrasonic radar with real-time Processing visualization | Arduino, HC-SR04, Servo, Processing |
| [ultrasonic-levitation-arduino](./ultrasonic-levitation-arduino/) | Acoustic levitation using 40kHz standing waves (AVR timer ISR) | Arduino Nano, HC-SR04, H-Bridge |
| [drv8825-stepper-motor-driver-arduino](./drv8825-stepper-motor-driver-arduino/) | Full guide: DRV8825 with NEMA 17, microstepping 1/32 | Arduino, DRV8825, NEMA 17 |
| [mini-conveyor-belt-object-counter](./mini-conveyor-belt-object-counter/) | Industrial mini conveyor with inductive sensor and LCD counter | Arduino, Inductive Sensor, DC Motor, 3D Print |

### 🌱 Sensing & Measurement

| Repository | Description | Stack |
|---|---|---|
| [ph-monitor-esp32-ads1115](./ph-monitor-esp32-ads1115/) | High-precision pH monitor with 16-bit ADC for hydroponics | ESP32, ADS1115, PH-4502C, PlatformIO |
| [object-counter-inductive-sensor-lcd](./object-counter-inductive-sensor-lcd/) | Metal object counter with PNP inductive sensor on production line | ESP32, Inductive PNP, LCD I2C |
| [smart-water-tank-controller-arduino](./smart-water-tank-controller-arduino/) | Automated water tank filling with flow sensor and relay control | Arduino Nano, YF-S201, Relay, LCD |

### ☀️ Energy & Hardware

| Repository | Description | Stack |
|---|---|---|
| [solar-battery-charger-esp32](./solar-battery-charger-esp32/) | Standalone solar power system: panel → TP4056 → Li-Ion → ESP32 | ESP32, TP4056, Solar Panel |
| [esp32-wroom-bare-module-programming](./esp32-wroom-bare-module-programming/) | Programming bare ESP32-WROOM-32D without dev board (CP2102) | ESP32, CP2102, SMD Soldering |

### 🛠 Guides & Tutorials

| Repository | Description | Stack |
|---|---|---|
| [easyeda-pcb-design-guide](./easyeda-pcb-design-guide/) | Complete PCB design workflow: schematic → routing → Gerber → JLCPCB | EasyEDA, PCB, Gerber, JLCPCB |
| [smd-soldering-paste-hot-air](./smd-soldering-paste-hot-air/) | SMD soldering with paste and hot air station — step-by-step | Solder Paste, Hot Air, ESP32 SMD |
| [smd-to-dip-adapter-soldering-guide](./smd-to-dip-adapter-soldering-guide/) | Using SMD-to-DIP adapters for breadboard prototyping | SMD, LM393, Soldering |
| [buttons-switches-guide-arduino-esp](./buttons-switches-guide-arduino-esp/) | Complete guide: push buttons, rockers, limit switches, DIP switches | Arduino, ESP32, Pull-up/Pull-down |
| [rgb-led-christmas-tree](./rgb-led-christmas-tree/) | No-microcontroller LED tree using RC timing circuits and transistors | RC Circuit, NPN Transistor, RGB LED |

---

## Tech Stack

```
Languages   : C/C++ (Arduino), Python (MicroPython), Java (Processing)
MCU         : Arduino Uno/Nano/Mega, ESP8266, ESP32, Raspberry Pi Pico
Wireless    : LoRa 915MHz, Wi-Fi, MQTT
Protocols   : RS-485, I2C, SPI, UART, SoftwareSerial
Tools       : Arduino IDE, PlatformIO, EasyEDA, Wokwi, ngrok, Processing
Hardware    : PCB Design, SMD Soldering, 3D Printing, Aluminum Profiles
```

---

## Contact

- **Technical Blog:** [blog.eletrogate.com](https://blog.eletrogate.com) — 23 published tutorials
- **Email:** sauloaislan17@gmail.com

---

# Portfólio de Sistemas Embarcados e IoT — Saulo Aislan

Desenvolvedor de sistemas embarcados e redator técnico com **mais de 5 anos** construindo e documentando projetos IoT. Todos os projetos foram publicados como tutoriais completos no [Blog Eletrogate](https://blog.eletrogate.com).

**Habilidades principais:** Arduino, ESP8266, ESP32, LoRa, MQTT, RS-485, I2C, SPI, PlatformIO, EasyEDA, soldagem SMD, impressão 3D.

Veja a tabela de projetos acima — todos com código-fonte completo e README detalhado em inglês e português.
