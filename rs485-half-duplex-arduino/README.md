# RS-485 Half-Duplex Communication — Arduino Uno ↔ Mega

> **RS-485 · MAX485 · Half-Duplex · Industrial Protocol · Arduino · SoftwareSerial**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![RS-485](https://img.shields.io/badge/Protocol-RS--485-orange?style=flat)]()
[![Industrial](https://img.shields.io/badge/Use-Industrial%20IoT-blue?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/comunicacao-half-duplex-com-rs-485/) · Author: **Saulo Aislan**

---

## Overview

Bidirectional RS-485 communication between an **Arduino Uno** and **Arduino Mega**. Rotating a potentiometer on one board controls the LED brightness on the other — simultaneously and independently. Demonstrates half-duplex turnaround logic, frame parsing, and the MAX485 driver module.

**RS-485 advantages:** Up to 1,200 m range · 10 Mb/s · Multi-drop bus (up to 32 nodes) · High noise immunity — ideal for industrial environments.

## Half-Duplex Principle

```
Direction control via DE/RE pin:
  HIGH → Transmit mode
  LOW  → Receive mode

Protocol frame: 'I' + VALUE (0–200) + 'F'
```

## Hardware

| Component | Qty |
|---|---|
| Arduino Uno R3 | 1 |
| Arduino Mega 2560 R3 | 1 |
| TTL-to-RS485 converter module (MAX485) | 2 |
| 1kΩ linear potentiometer | 2 |
| 1kΩ resistor | 2 |
| Blue LED 5mm | 1 |
| Green LED 5mm | 1 |
| 830-point breadboard | 2 |

## Wiring

### Arduino Uno
| Component | Pin |
|---|---|
| RS485 RO (RX) | 2 (SoftwareSerial) |
| RS485 DI (TX) | 3 (SoftwareSerial) |
| RS485 DE/RE | 4 |
| Potentiometer | A0 |
| LED (PWM) | 10 |

### Arduino Mega
| Component | Pin |
|---|---|
| RS485 RO (RX) | 10 (SoftwareSerial) |
| RS485 DI (TX) | 11 (SoftwareSerial) |
| RS485 DE/RE | 12 |
| Potentiometer | A0 |
| LED (PWM) | 13 |

> Connect A↔A and B↔B between the two RS-485 modules.

## Project Structure

```
rs485-half-duplex-arduino/
├── Arduino_Uno/
│   └── Arduino_Uno.ino
└── Arduino_Mega/
    └── Arduino_Mega.ino
```

---

## Português — Comunicação Half-Duplex com RS-485

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/comunicacao-half-duplex-com-rs-485/)

Comunicação bidirecional RS-485 entre **Arduino Uno e Mega**. O potenciômetro de um controla o LED do outro. Demonstra o protocolo industrial RS-485 com lógica de half-duplex via pino DE/RE.

**Vantagens do RS-485:** até 1.200 m · 10 Mb/s · multi-drop (32 nós) · alta imunidade a ruído.

### Como Usar
1. Upload de `Arduino_Uno.ino` no Uno
2. Upload de `Arduino_Mega.ino` no Mega
3. Conecte A↔A e B↔B entre os módulos RS-485
4. Gire o potenciômetro e veja o LED do outro Arduino variar
