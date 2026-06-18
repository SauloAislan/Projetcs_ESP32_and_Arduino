# Acoustic Levitation with Arduino

> **Arduino · AVR Timer ISR · Ultrasonic Transducer · Standing Waves · H-Bridge · Physics**

[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![AVR](https://img.shields.io/badge/AVR-Timer1%20ISR-orange?style=flat)]()
[![Physics](https://img.shields.io/badge/Physics-Acoustic%20Levitation-purple?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/levitacao-ultrassonica-com-arduino/) · Author: **Saulo Aislan**

---

## Overview

Acoustic levitation using an Arduino Nano to generate **40 kHz ultrasonic standing waves**. Small lightweight objects (foam, salt particles, paper balls) get trapped at pressure nodes between a transducer and reflector — levitating in mid-air without any mechanical contact.

Uses AVR hardware Timer1 in CTC mode with an ISR to toggle PORTC at 80 kHz (40 kHz full wave), driving a disassembled HC-SR04 transducer through an H-Bridge module.

## Physics

Standing waves form between the emitter and reflector. Objects are trapped at pressure nodes (points of minimum acoustic pressure) where the net radiation force is zero — creating stable levitation zones.

## Key Features

- ✅ AVR Timer1 ISR — precise 80 kHz square wave (no delay() blocking)
- ✅ Zero CPU overhead in loop() — pure hardware interrupt driven
- ✅ Configurable frequency via `OCR1A` register
- ✅ H-Bridge amplifies signal for stronger acoustic force

## Hardware

| Component | Qty |
|---|---|
| Arduino Nano V3.0 | 1 |
| HC-SR04 ultrasonic sensor (disassembled) | 1 |
| H-Bridge module with L293 IC | 1 |
| 3D-printed emitter/reflector mounts (or alligator clips) | — |
| Jumper wires | — |

## Frequency Calculation

```
f_square = 16 MHz / OCR1A = 16,000,000 / 200 = 80,000 Hz
f_wave   = 80,000 / 2 = 40,000 Hz (40 kHz)
```

## Wiring

| Arduino Nano | Component |
|---|---|
| A0–A7 (PORTC) | H-Bridge inputs |
| H-Bridge outputs | Transducer emitter and reflector |

## Assembly Tips

1. Disassemble HC-SR04: separate emitter (TX) and receiver (RX) cylinders
2. Mount them face-to-face, max 4 cm apart, precisely aligned
3. Avoid air currents during operation
4. Test with light objects: foam particles, styrofoam, salt

## Project Structure

```
ultrasonic-levitation-arduino/
└── Levitador_ultrasonico/
    └── Levitador_ultrasonico.ino
```

---

## Português — Levitação Ultrassônica com Arduino

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/levitacao-ultrassonica-com-arduino/)

Levitação acústica com Arduino Nano gerando ondas estacionárias de 40 kHz. O Timer1 AVR em modo CTC com ISR gera onda quadrada de 80 kHz (sem `delay()`) acionando o H-Bridge que alimenta os transdutores do HC-SR04 desmontado.

### Frequência
```
f = 16 MHz / OCR1A = 16.000.000 / 200 = 80 kHz → 40 kHz (onda completa)
```

### Dicas de Montagem
- Desmonte o HC-SR04, separando emissor e receptor
- Alinhe face a face com no máximo 4 cm de distância
- Evite correntes de ar
- Teste com isopor, sal ou bolinhas de papel
