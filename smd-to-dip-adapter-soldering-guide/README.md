# SMD to DIP Adapter Soldering Guide — Prototyping with SMD Components

> **SMD · DIP Adapter · Breakout Board · Prototyping · Soldering · Electronics · SOIC · QFN**

[![Guide](https://img.shields.io/badge/Type-Soldering%20Guide-blue?style=flat)]()
[![PCB](https://img.shields.io/badge/PCB-Adapter%20Boards-orange?style=flat)]()
[![Skill](https://img.shields.io/badge/Skill-Beginner--Intermediate-green?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/dicas-para-usar-adaptadores-smd-para-dip-em-seus-projetos/) · Author: **Saulo Aislan**

---

## Overview

Practical guide to using **SMD-to-DIP adapter boards** — small breakout PCBs that convert SMD packages (SOIC, SOT-23, QFN, TSSOP) to 2.54mm through-hole pitch for use on breadboards and perfboards. Covers soldering techniques, adapter types, and tips for working with fine-pitch SMD ICs before committing to a custom PCB.

## Why Use Adapters?

- SMD components are cheaper and often only available in SMD packages
- Enables breadboard prototyping with SMD-only ICs
- Ideal for testing before ordering a PCB
- Essential for working with QFN, LGA, BGA packages on prototypes

## Common SMD Package Types

| Package | Pitch | Adapter Size | Difficulty |
|---|---|---|---|
| SOIC-8 | 1.27mm | Small | Beginner |
| SOT-23-5 | 0.95mm | Very small | Beginner |
| TSSOP-16 | 0.65mm | Medium | Intermediate |
| QFP-32 | 0.8mm | Medium | Intermediate |
| QFN-20 | 0.5mm | Requires paste | Advanced |

## Required Tools

| Tool | Notes |
|---|---|
| Soldering iron | Fine tip (0.5–1mm), 300–350°C |
| Solder wire | Sn63Pb37 0.5mm or 0.3mm |
| Tweezers | Curved, anti-static |
| Flux pen | Essential for fine pitch |
| Magnifier or loupe | 10× minimum |
| IPA 99% + swabs | For cleaning |
| Solder wick | For fixing bridges |

## Soldering Technique — SOIC/TSSOP

1. **Tin one pad** on adapter board
2. **Tack component** — place IC, align all pins, solder one pin to hold position
3. **Check alignment** under magnifier
4. **Solder all pins** — drag soldering or tack each pin
5. **Apply flux** → wipe iron across all pins in one motion (drag method)
6. **Remove bridges** with wick + flux
7. **Clean** with IPA

## Drag Soldering (For SOIC and QFP)

```
1. Apply flux generously to all pads
2. Load iron tip with fresh solder
3. Drag iron at 45° angle across all pins in one smooth stroke
4. Flux flows solder onto each pin, surface tension prevents bridges
5. Check with magnifier — fix any bridges with wick
```

## Project Structure

```
smd-to-dip-adapter-soldering-guide/
└── README.md    ← This guide (technique tutorial, no firmware)
```

## Tips

- Flux is everything — re-apply between passes
- Good illumination is non-negotiable — use a ring light or desk lamp
- Practice on a sacrificial component first
- Use hot air at low flow for QFN — solder paste only option for bottom-pad packages

---

## Português — Adaptadores SMD para DIP: Guia de Soldagem

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/dicas-para-usar-adaptadores-smd-para-dip-em-seus-projetos/)

Guia prático para usar **placas adaptadoras SMD para DIP** — PCBs de breakout que convertem encapsulamentos SMD (SOIC, SOT-23, QFN, TSSOP) para passo 2,54mm, compatível com protoboard e perfboard. Cobre técnicas de soldagem, tipos de adaptadores e dicas para prototipar com CIs SMD antes de encomendar uma PCB.

### Técnica de Drag Soldering (SOIC/QFP)
```
1. Aplique flux generosamente em todos os pinos
2. Carregue a ponteira com solda fresca
3. Arraste a ponteira em 45° sobre todos os pinos
4. O flux direciona a solda, tensão superficial evita pontes
5. Verifique com lupa — remova pontes com malha dessoldante
```

### Dicas Essenciais
- Flux é fundamental — reaplicar entre cada passagem
- Boa iluminação é obrigatória
- Pratique em componente descartável primeiro
