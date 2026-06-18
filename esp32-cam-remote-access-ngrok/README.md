# ESP32-CAM Remote Access via Ngrok — Live Video Stream

> **ESP32-CAM · OV2640 · MJPEG Stream · Ngrok Tunnel · Security Camera · IoT**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![Ngrok](https://img.shields.io/badge/Tunnel-Ngrok-blue?style=flat)](https://ngrok.com/)

Published on [Blog Eletrogate](https://blog.eletrogate.com/esp32-cam-acessado-remotamente-com-ngrok/) · Author: **Saulo Aislan**

---

## Overview

DIY security camera using an **ESP32-CAM** that streams live MJPEG video accessible from **anywhere in the world** via an Ngrok tunnel. Includes basic authentication for access control. Free, fast to set up, no static IP or port forwarding needed.

## Key Features

- ✅ Live MJPEG video stream on port 8880
- ✅ Global remote access via Ngrok (no static IP needed)
- ✅ HTTP Basic Auth protection
- ✅ PSRAM detection → auto quality adjustment
- ✅ Supports AI Thinker and WROVER-KIT board variants
- ✅ Configurable: mirror, flip, JPEG quality, frame size

## Hardware

| Component | Qty |
|---|---|
| ESP32-CAM (AI Thinker) with OV2640 2MP camera | 1 |
| FTDI FT232RL USB-to-Serial converter | 1 |
| 400-point breadboard | 1 |
| Jumper wires (20 units) | 1 set |
| 5V 1A power supply (recommended) | 1 |

## Project Structure

```
esp32-cam-remote-access-ngrok/
└── esp32Cam/
    ├── esp32Cam.ino      ← main firmware (edit SSID/password here)
    ├── camera_pins.h     ← pin definitions per board model
    └── src/
        ├── OV2640.cpp    ← download from github.com/Picaio/espcam
        └── OV2640.h
```

> Download `OV2640.cpp` and `OV2640.h` from [github.com/Picaio/espcam](https://github.com/Picaio/espcam) and place in `src/`.

## Configuration

Edit `esp32Cam.ino`:
```cpp
#define SSID1 "YOUR_WIFI_SSID"
#define PWD1  "YOUR_WIFI_PASSWORD"
```

Arduino IDE settings:
- Board: **AI Thinker ESP32-CAM**
- PSRAM: **Enabled**

## Programming Wiring (FTDI → ESP32-CAM)

| ESP32-CAM | FTDI |
|---|---|
| GND | GND |
| 5V | VCC |
| U0R | TX |
| U0T | RX |
| IO0 | GND ← connect only during flash |

## Ngrok Setup

```bash
ngrok config add-authtoken YOUR_TOKEN
ngrok http --basic-auth="user:password" ESP32_IP:8880
```

Access the generated HTTPS URL from anywhere.

---

## Português — ESP32-CAM Acessado Remotamente com Ngrok

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/esp32-cam-acessado-remotamente-com-ngrok/)

Câmera de segurança com **ESP32-CAM** acessível de qualquer lugar do mundo via túnel **Ngrok**. Transmite vídeo MJPEG em tempo real com proteção por autenticação básica. Gratuito e sem necessidade de IP fixo.

### Componentes
- ESP32-CAM (AI Thinker) com câmera OV2640 2MP
- Conversor FTDI FT232RL · Jumpers · Fonte 5V 1A

### Configuração
1. Baixe `OV2640.cpp` e `.h` e coloque em `src/`
2. Edite SSID e senha em `esp32Cam.ino`
3. Ative PSRAM no Arduino IDE
4. Upload (IO0 ao GND durante programação)
5. Configure Ngrok com seu token e exponha a porta 8880
