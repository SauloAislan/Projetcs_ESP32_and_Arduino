# Complete Guide to Buttons and Switches for Arduino and ESP32

> **Arduino · ESP32 · Push Button · Toggle Switch · Pull-up · Pull-down · Debounce · INPUT_PULLUP**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![Guide](https://img.shields.io/badge/Type-Complete%20Guide-blue?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/guia-completo-sobre-botoes-e-chaves-para-arduino-e-esp/) · Author: **Saulo Aislan**

---

## Overview

Definitive reference for using **push buttons and toggle switches** with Arduino and ESP32. Covers all connection modes, floating input problem, pull-up vs pull-down resistors, internal INPUT_PULLUP, hardware and software debounce — a foundation topic every embedded developer must master.

## Why Buttons Behave Unexpectedly

Floating digital inputs (unconnected when button is open) pick up electromagnetic noise and read randomly. Pull resistors fix this:

| Configuration | Button Released | Button Pressed | Logic |
|---|---|---|---|
| Pull-down (10kΩ to GND) | LOW (0) | HIGH (1) | Active HIGH |
| Pull-up (10kΩ to VCC) | HIGH (1) | LOW (0) | Active LOW |
| INPUT_PULLUP (internal) | HIGH (1) | LOW (0) | Active LOW |

## External Pull-down Wiring

```
VCC ──── Button ──── GPIO pin
                        │
                     10kΩ
                        │
                       GND
```

## Internal Pull-up (Simplest)

```cpp
pinMode(2, INPUT_PULLUP);
// No external resistor needed
// Button between GPIO and GND
// Read LOW = pressed, HIGH = released
```

## Key Features

- ✅ External pull-down wiring diagram
- ✅ Internal INPUT_PULLUP (no resistor needed)
- ✅ Software debounce with `delay()` and `millis()`
- ✅ Hardware debounce with 100nF capacitor
- ✅ Toggle switch types (SPST, SPDT, DPDT) explained

## Debounce Strategies

### Software — delay()
```cpp
if (digitalRead(2) == HIGH) {
  delay(50);  // wait for contact to settle
  if (digitalRead(2) == HIGH) {
    // confirmed press
  }
}
```

### Software — millis() (non-blocking)
```cpp
if (millis() - lastDebounceTime > debounceDelay) {
  // check state
}
```

### Hardware
Place a **100nF capacitor** between the GPIO pin and GND. Works passively — no code required.

## Switch Types Covered

| Type | Poles | Description | Use Case |
|---|---|---|---|
| SPST | 1 | Single throw — simple ON/OFF | LED, relay |
| SPDT | 1 | 2 outputs — center common | Mode select |
| DPDT | 2 | 2 switches linked | Motor polarity reversal |

## Project Structure

```
buttons-switches-guide-arduino-esp/
└── Botao_LED/
    └── Botao_LED.ino    ← Button pin 2 (external pull-down) + LED pin 13
```

---

## Português — Guia Completo sobre Botões e Chaves para Arduino e ESP

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/guia-completo-sobre-botoes-e-chaves-para-arduino-e-esp/)

Referência completa para uso de **botões e chaves** com Arduino e ESP32. Cobre todos os modos de conexão, problema do pino flutuante, resistores pull-up e pull-down, INPUT_PULLUP interno, debounce por hardware e software — fundamento essencial para todo desenvolvedor embarcado.

### Pull-up Interno (Mais Simples)
```cpp
pinMode(2, INPUT_PULLUP);
// Sem resistor externo
// Botão entre GPIO e GND
// LOW = pressionado, HIGH = solto
```

### Tipos de Chaves
| Tipo | Polos | Uso |
|---|---|---|
| SPST | 1 | Liga/Desliga simples |
| SPDT | 1 | Seleção de modo |
| DPDT | 2 | Inversão de polaridade de motor |
