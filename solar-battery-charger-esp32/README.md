# Solar Battery Charger for ESP32 / Arduino — Off-Grid IoT

> **ESP32 · TP4056 · Li-Ion · Solar Panel · Off-Grid · IoT Power · Energy Harvesting**

[![Platform](https://img.shields.io/badge/Platform-ESP32-red?style=flat)](https://www.espressif.com/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Power](https://img.shields.io/badge/Power-Solar%20%2B%20Li--Ion-yellow?style=flat)]()

Published on [Blog Eletrogate](https://blog.eletrogate.com/carregador-de-bateria-solar-para-projetos-com-esp32-ou-arduino/) · Author: **Saulo Aislan**

---

## Overview

Complete guide to building an **off-grid power system** for ESP32/Arduino using a solar panel, **TP4056** Li-Ion charger module, and 18650 battery. Enables truly autonomous IoT field devices (weather stations, remote sensors, animal monitoring) with no wired power required.

Covers component selection, charging circuit, protection, and how to combine with **Deep Sleep** for multi-month battery life.

## Power Chain

```
Solar Panel (5V–6V) → TP4056 Charger → 18650 Li-Ion Battery → Boost Converter (5V) → ESP32
```

## Key Features

- ✅ TP4056 provides CC/CV charging with battery protection (overcharge, over-discharge, short-circuit)
- ✅ Works with 6V/1W solar panels (commonly available)
- ✅ LED status indicators: CHARGING (red) / FULL (blue)
- ✅ Combine with ESP32 Deep Sleep for months of autonomy
- ✅ No grid power required — true remote deployment

## Hardware

| Component | Qty |
|---|---|
| 6V/1W monocrystalline solar panel | 1 |
| TP4056 charger module with protection (DW01A) | 1 |
| 18650 Li-Ion battery 3.7V (~2600mAh) | 1 |
| 18650 battery holder | 1 |
| MT3608 boost converter module (3.7V → 5V) | 1 |
| ESP32 DevKit or Arduino | 1 |

## Autonomy Calculation

```
Capacity (mAh) ÷ Average current (mA) = Hours of runtime

Example:
ESP32 Deep Sleep: ~0.01 mA (sleep) + 80 mA (active, 1 sec/min)
Average ≈ 1.3 mA
2600 mAh ÷ 1.3 mA ≈ 2000 hours ≈ 83 days
```

## Solar Panel Sizing

| Panel Power | Charge Time (2600mAh) | Suitable For |
|---|---|---|
| 0.5W (6V/83mA) | ~31h full sun | Very low duty cycle |
| 1W (6V/167mA) | ~15h full sun | Standard IoT sensor |
| 2W (6V/333mA) | ~8h full sun | High-frequency wake |

## Project Structure

```
solar-battery-charger-esp32/
└── Carregador_Solar/
    └── Carregador_Solar.ino    ← ESP32 blink demo on GPIO4
```

## Deep Sleep Integration

Combine this power circuit with Deep Sleep for maximum autonomy:

```cpp
esp_sleep_enable_timer_wakeup(30 * 60 * 1000000ULL);  // Wake every 30 min
esp_deep_sleep_start();
```

---

## Português — Carregador Solar para ESP32 e Arduino

**Artigo completo:** [blog.eletrogate.com](https://blog.eletrogate.com/carregador-de-bateria-solar-para-projetos-com-esp32-ou-arduino/)

Guia completo para sistema de energia off-grid com painel solar, **TP4056**, bateria 18650 e ESP32. Permite dispositivos IoT remotos sem energia da rede (estações climáticas, sensores de campo, monitoramento de animais).

### Cadeia de Energia
```
Painel Solar (6V) → TP4056 → Bateria 18650 → Boost 5V → ESP32
```

### Cálculo de Autonomia
```
ESP32 Deep Sleep: ~0,01 mA (sleep) + 80 mA (ativo, 1s/min)
Média ≈ 1,3 mA → 2600 mAh ÷ 1,3 mA ≈ 83 dias
```
