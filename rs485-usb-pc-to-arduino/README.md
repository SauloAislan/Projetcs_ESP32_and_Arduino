# RS-485 Communication — PC to Arduino via USB Adapter

> **RS-485 · USB-RS485 · Industrial Automation · LCD I2C · Arduino · SCADA-like**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![RS-485](https://img.shields.io/badge/Protocol-RS--485-orange?style=flat)]()
[![Industrial](https://img.shields.io/badge/Use-Industrial%20IoT-blue?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/comunicacao-com-conversor-usb-rs485/) · Author: **Saulo Aislan**

---

## Overview

Simulates an **industrial automation scenario** where a PC acts as the control system (HMI/SCADA) and an Arduino functions as a PLC/RTU. The PC sends text commands via a USB-RS485 adapter; the Arduino displays the received message on an LCD and controls an LED accordingly.

Send `LED ON` or `LED OFF` from any serial terminal — the Arduino responds instantly.

## Key Features

- ✅ PC-to-microcontroller RS-485 link via USB adapter
- ✅ Receive-only firmware (EN pin held LOW)
- ✅ 16×2 LCD I2C display shows all received messages
- ✅ LED controlled by text commands
- ✅ Industrial wiring convention (A↔A, B↔B)

## Hardware

| Component | Qty |
|---|---|
| Arduino Uno R3 | 1 |
| TTL-to-RS485 converter module | 1 |
| Mini USB-to-RS485 serial adapter | 1 |
| 16×2 LCD with I2C module | 1 |
| 1kΩ resistor | 1 |
| Red LED 5mm | 1 |
| 830-point breadboard | 2 |

## Wiring

| Component | Arduino Uno |
|---|---|
| RS485 RO | Pin 2 (SoftwareSerial RX) |
| RS485 DI | Pin 3 (SoftwareSerial TX) |
| RS485 DE/RE | Pin 4 → GND (receive mode) |
| LED | Pin 13 + 1kΩ resistor |
| LCD SDA | A4 |
| LCD SCL | A5 |

> Connect A↔A and B↔B between TTL module and USB-RS485 adapter.

## Commands

| Command sent from PC | Arduino Response |
|---|---|
| `LED ON` | LED turns on, LCD: "LED Aceso!" |
| `LED OFF` | LED turns off, LCD: "LED Apagado!" |
| Any text | LCD shows the received text |

## Project Structure

```
rs485-usb-pc-to-arduino/
└── PC_Arduino_RS485/
    └── PC_Arduino_RS485.ino
```

## Library Required

- **LiquidCrystal_I2C** — Library Manager
  (try address `0x27` if `0x3F` doesn't work)

---

## Português — Comunicação USB-RS485 do PC para o Arduino

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/comunicacao-com-conversor-usb-rs485/)

Simulação de automação industrial: PC como sistema de controle e Arduino como CLP. O PC envia comandos via USB-RS485; o Arduino exibe no LCD e aciona o LED. Envie `LED ON` ou `LED OFF` por qualquer terminal serial (ex.: Termite).

### Como Usar
1. Instale **LiquidCrystal_I2C**
2. Upload de `PC_Arduino_RS485.ino`
3. Conecte o USB-RS485 ao PC e o módulo TTL-RS485 ao Arduino (A↔A, B↔B)
4. Abra terminal serial a 9600 baud e envie comandos
