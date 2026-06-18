# PCB Design Guide with EasyEDA — From Schematic to JLCPCB

> **EasyEDA · PCB Design · Gerber · JLCPCB · KiCad · Schematic · Prototype · Hardware Design**

[![EasyEDA](https://img.shields.io/badge/Tool-EasyEDA-blue?style=flat)](https://easyeda.com/)
[![JLCPCB](https://img.shields.io/badge/Manufacturer-JLCPCB-green?style=flat)](https://jlcpcb.com/)
[![Guide](https://img.shields.io/badge/Type-Design%20Guide-orange?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/easyeda-guia-definitivo-para-projetar-pcbs/) · Author: **Saulo Aislan**

---

## Overview

Complete workflow for designing professional PCBs using **EasyEDA** (free, browser-based) and ordering from **JLCPCB** (5 PCBs from $2). Covers schematic capture, component library, PCB layout, design rule checks (DRC), Gerber export, and order placement. Ideal for transitioning from breadboard prototypes to permanent boards.

## Why EasyEDA?

| Feature | EasyEDA | KiCad | Altium |
|---|---|---|---|
| Price | Free | Free | $$$  |
| Learning curve | Low | Medium | High |
| Cloud-based | Yes | No | No |
| JLCPCB integration | Native | Via plugin | Manual |
| LCSC component library | Built-in | Manual | Manual |
| Best for | Beginners/Hobbyists | Open-source pros | Industry |

## PCB Design Workflow

1. **Schematic** — Place components, add power symbols, draw nets
2. **Footprint assignment** — Match schematic symbols to PCB footprints
3. **PCB layout** — Place components, define board outline, route traces
4. **DRC** — Run Design Rule Check, fix all errors
5. **Gerber export** — Generate manufacturing files (6-layer zip)
6. **Order** — Upload to JLCPCB, select specs, checkout

## PCB Design Rules (Minimum for JLCPCB)

| Parameter | Min Value |
|---|---|
| Trace width | 0.127mm (5mil) |
| Clearance | 0.127mm |
| Drill hole | 0.2mm |
| Board thickness | 0.4mm – 2.4mm |
| Copper layers | 1, 2, 4, 6... |

## Ordering from JLCPCB — Typical Cost

| Quantity | Size | Price |
|---|---|---|
| 5 | 100×100mm | ~$2 |
| 5 | 100×100mm (4-layer) | ~$6 |
| 10 | 100×100mm | ~$5 |

> Shipping adds $3–$15 depending on country and carrier.

## Project Structure

```
easyeda-pcb-design-guide/
└── README.md    ← This guide (design tutorial, no firmware)
```

## Tips for First PCB

- Add 0.5mm clearance around board edge for milling
- Use ground planes (copper pour) on bottom layer
- Label all connectors and test points on silkscreen
- Add fiducial marks for SMD assembly
- Order 5 PCBs — extras are nearly free and you'll need them

---

## Português — EasyEDA: Guia Definitivo para Projetar PCBs

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/easyeda-guia-definitivo-para-projetar-pcbs/)

Workflow completo para projetar PCBs profissionais com **EasyEDA** (gratuito, online) e fabricar na **JLCPCB** (5 PCBs a partir de R$10). Cobre esquemático, atribuição de footprints, layout, DRC, exportação Gerber e pedido de fabricação.

### Fluxo de Trabalho
1. **Esquemático** → 2. **Footprints** → 3. **Layout PCB** → 4. **DRC** → 5. **Gerber** → 6. **Pedido JLCPCB**

### Custo Típico JLCPCB
| Quantidade | Tamanho | Preço |
|---|---|---|
| 5 | 100×100mm | ~US$2 |
| 5 | 100×100mm (4 camadas) | ~US$6 |
