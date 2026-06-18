# RGB LED Christmas Tree — Electronics Holiday Decoration

> **RGB LED · Christmas Tree · DIY Electronics · LED Art · Soldering · Holiday Project**

[![DIY](https://img.shields.io/badge/Type-DIY%20Electronics-green?style=flat)]()
[![Skill](https://img.shields.io/badge/Skill-Beginner-blue?style=flat)]()
[![Holiday](https://img.shields.io/badge/Holiday-Christmas%20Project-red?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/arvore-de-natal-com-leds-rgb/) · Author: **Saulo Aislan**

---

## Overview

Decorative **Christmas tree with RGB LEDs** — a fun holiday electronics project that combines a laser-cut or 3D-printed tree structure with colorful LEDs wired in a creative pattern. An excellent beginner project for learning basic soldering, LED polarity, resistor sizing, and wire management.

No microcontroller required — this is a pure analog/passive electronics build.

## Key Features

- ✅ No microcontroller needed — beginner-friendly
- ✅ RGB LEDs for multicolor decoration
- ✅ Teaches: LED polarity, resistor calculation, breadboard-to-solder transition
- ✅ Runs on 5V USB or 4×AA batteries

## Hardware

| Component | Qty |
|---|---|
| RGB LED (common cathode or anode) | 10–20 |
| 100Ω resistors (for each color channel at 5V) | varies |
| 5V USB power supply or 4×AA battery holder | 1 |
| Perfboard or custom PCB | 1 |
| Decorative tree base (laser-cut acrylic or 3D print) | 1 |
| Jumper wires or enameled copper wire | — |

## LED Resistor Calculation

For each color channel at 5V supply:

```
R = (Vcc - Vf) / If

Red:   R = (5V - 2.0V) / 0.020A = 150Ω → use 150Ω
Green: R = (5V - 3.2V) / 0.020A = 90Ω  → use 100Ω
Blue:  R = (5V - 3.2V) / 0.020A = 90Ω  → use 100Ω
```

## Wiring Pattern (Common Cathode)

```
5V → Resistor → LED Anode (R/G/B individually)
All LED Cathodes → GND
```

## Color Combinations

By wiring color channels together, you can create:

| R | G | B | Result |
|---|---|---|---|
| ON | OFF | OFF | Red |
| OFF | ON | OFF | Green |
| OFF | OFF | ON | Blue |
| ON | ON | OFF | Yellow |
| OFF | ON | ON | Cyan |
| ON | OFF | ON | Magenta |
| ON | ON | ON | White |

## Project Structure

```
rgb-led-christmas-tree/
└── README.md    ← This guide (no firmware — passive electronics project)
```

## Assembly Tips

1. Sort LEDs — test each one before soldering
2. Mark cathode (shorter leg) with a marker before clipping leads
3. Use enameled copper wire for a clean, artistic look
4. Consider adding a 555 timer circuit for automatic blinking
5. Glue LEDs to tree structure with hot glue

---

## Português — Árvore de Natal com LEDs RGB

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/arvore-de-natal-com-leds-rgb/)

Árvore de Natal decorativa com **LEDs RGB** — projeto eletrônico natalino que combina estrutura em acrílico/impressão 3D com LEDs coloridos. Ótimo para iniciantes aprenderem soldagem básica, polaridade de LED e dimensionamento de resistores.

Não requer microcontrolador — projeto passivo/analógico.

### Cálculo do Resistor (5V)
```
R = (Vcc - Vf) / If
Vermelho: (5V - 2,0V) / 20mA = 150Ω
Verde:    (5V - 3,2V) / 20mA = 90Ω → use 100Ω
Azul:     (5V - 3,2V) / 20mA = 90Ω → use 100Ω
```

### Dicas de Montagem
- Teste cada LED antes de soldar
- Marque o catodo (perna menor) antes de cortar
- Use fio de cobre esmaltado para visual limpo e artístico
