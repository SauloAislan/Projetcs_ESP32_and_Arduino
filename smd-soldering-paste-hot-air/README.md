# SMD Soldering with Solder Paste and Hot Air Station — Practical Guide

> **SMD Soldering · Solder Paste · Hot Air Station · ESP32 · PCB Assembly · Electronics Repair**

[![PCB](https://img.shields.io/badge/PCB-SMD%20Assembly-blue?style=flat)]()
[![Guide](https://img.shields.io/badge/Type-Practical%20Guide-orange?style=flat)]()
[![Skill](https://img.shields.io/badge/Skill-Intermediate-yellow?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/aprenda-a-usar-a-solda-em-pasta-e-soprador-termico-soldando-um-esp32/) · Author: **Saulo Aislan**

---

## Overview

Hands-on guide to **SMD soldering** using **solder paste** (Sn63Pb37) and a **hot air rework station**. Demonstrated by soldering an **ESP32-WROOM-32** module onto a custom PCB. This technique is essential for repairing PCBs, soldering BGA/QFN packages, and building compact custom boards.

## Equipment Required

| Tool | Specification |
|---|---|
| Hot air rework station | 858D or similar (100–500°C, adjustable airflow) |
| Solder paste | Sn63Pb37 (leaded) or SAC305 (lead-free), 63/37 recommended for beginners |
| Stainless steel tweezers | Curved and straight |
| Flux pen | IPA-based or rosin flux |
| PCB holder / helping hands | Optional but highly recommended |
| Isopropyl alcohol (IPA 99%) | For cleaning after soldering |
| Cotton swabs / flux brush | For cleaning |

## Hot Air Station Settings

| Component | Temperature | Airflow |
|---|---|---|
| Small passives (0402, 0603) | 320–350°C | 3–4 |
| SOT-23, SOD-323 | 330–360°C | 3–4 |
| SOIC-8, QFP | 340–370°C | 4–5 |
| ESP32-WROOM-32 (LGA) | 380–400°C | 4–5 |
| BGA | 200–220°C (preheater) + 250°C top | 2–3 |

> Lead-free solder requires 20–30°C higher temperatures.

## Step-by-Step Process

### 1. PCB Preparation
- Clean PCB pads with IPA
- Apply flux to all pads (helps paste flow and improves wetting)

### 2. Solder Paste Application
- Apply paste with syringe or stencil to each pad
- Amount: small dot, roughly the size of the pad
- Avoid bridging adjacent pads

### 3. Component Placement
- Place component with tweezers — paste holds it in position
- Verify alignment under magnification before heating

### 4. Reflow with Hot Air
- Hold nozzle 2–3 cm above component
- Move in circular pattern
- Watch for solder to melt and components to self-align ("tombstoning" = too fast)
- Remove heat immediately when all solder joints appear shiny

### 5. Inspection and Cleaning
- Check for bridges with magnifier or USB microscope
- Clean flux residue with IPA + cotton swab
- Use solder wick + flux to remove bridges if needed

## Project Structure

```
smd-soldering-paste-hot-air/
└── README.md    ← This guide (technique tutorial, no firmware)
```

## Common Mistakes

| Mistake | Result | Fix |
|---|---|---|
| Too much paste | Bridges | Use less paste, clean and redo |
| Airflow too high | Blows component off pad | Reduce airflow |
| Moving too fast | Cold joints (grainy) | Move slower, reheat |
| Moving too slow | PCB delamination, lifted pads | Keep gun moving |

---

## Português — Solda em Pasta e Soprador Térmico: Guia Prático

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/aprenda-a-usar-a-solda-em-pasta-e-soprador-termico-soldando-um-esp32/)

Guia prático de **soldagem SMD** com **pasta de solda** (Sn63Pb37) e **soprador térmico**, demonstrado soldando um **ESP32-WROOM-32** numa PCB personalizada. Técnica essencial para reparar placas, soldar encapsulamentos BGA/QFN e montar placas compactas.

### Temperaturas do Soprador
| Componente | Temperatura | Fluxo |
|---|---|---|
| Passivos 0402/0603 | 320–350°C | 3–4 |
| SOT-23, SOD-323 | 330–360°C | 3–4 |
| ESP32-WROOM-32 (LGA) | 380–400°C | 4–5 |

### Erros Comuns
| Erro | Resultado | Solução |
|---|---|---|
| Pasta em excesso | Pontes de solda | Use menos pasta |
| Fluxo de ar alto | Componente sai do lugar | Reduza o fluxo |
| Movimento rápido | Solda fria (opaca) | Mova mais devagar |
