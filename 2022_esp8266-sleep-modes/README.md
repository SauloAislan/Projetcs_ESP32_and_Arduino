# Economizando Energia – Sleep Modes no ESP8266

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/)

## Descrição

Tutorial completo sobre como reduzir o consumo de energia em projetos IoT com **ESP8266 NodeMCU**. O exemplo prático lê a temperatura do sensor TMP36, publica os dados via **MQTT** e coloca o ESP8266 em **Deep Sleep** por 30 segundos antes de repetir o ciclo — reduzindo o consumo de ~80mA em modo ativo para ~20µA em sleep.

## Modos de Sleep

| Modo | Consumo | WiFi | Clock |
|---|---|---|---|
| Modem-Sleep | ~15 mA | OFF | ON |
| Light-Sleep | ~0,4 mA | OFF | OFF |
| Deep-Sleep | ~20 µA | OFF | Apenas RTC |

## Componentes

| Componente | Qtd |
|---|---|
| ESP8266 NodeMCU V3 (Lolin) | 1 |
| Sensor de temperatura TMP36 | 1 |
| Push Button | 1 |
| Resistor 10kΩ | 1 |
| Protoboard 400 pontos | 1 |

## Estrutura do Projeto

```
2022_esp8266-sleep-modes/
├── DeepSleep_Tempo/
│   └── DeepSleep_Tempo.ino    ← Deep Sleep por 30s com wake por timer
├── DeepSleep_Botao/
│   └── DeepSleep_Botao.ino    ← Deep Sleep com wake por botão (RST)
└── DeepSleep_MQTT/
    └── DeepSleep_MQTT.ino     ← Lê TMP36 → publica MQTT → dorme 30s
```

## Bibliotecas Necessárias (DeepSleep_MQTT)

- **ESP8266WiFi** — inclusa no ESP8266 Arduino Core
- **PubSubClient** — Library Manager

## Pinagem

| Componente | ESP8266 NodeMCU |
|---|---|
| TMP36 (saída analógica) | A0 |
| GPIO16 (D0) → RST | RST (apenas para wake por timer) |
| Botão RST wake | RST |

> **ATENÇÃO:** Conecte `GPIO16 (D0)` ao `RST` **somente após o upload do código** para evitar problemas de programação.

## Como Usar

### Deep Sleep por Timer
1. Abra `DeepSleep_Tempo/DeepSleep_Tempo.ino`
2. Faça o upload
3. Conecte D0 ao RST
4. O ESP8266 dormirá por 30 segundos e acordará automaticamente

### Deep Sleep com Botão
1. Abra `DeepSleep_Botao/DeepSleep_Botao.ino`
2. Faça o upload
3. Conecte um botão entre GND e RST para acordar manualmente

### Deep Sleep com MQTT
1. Abra `DeepSleep_MQTT/DeepSleep_MQTT.ino`
2. Edite `WIFI_SSID` e `WIFI_PASS` com suas credenciais
3. Faça o upload
4. Conecte D0 ao RST
5. O ciclo será: conecta WiFi → lê sensor → publica MQTT → dorme 30s → repete

## Fluxo (DeepSleep_MQTT)

```
[Acorda] → [WiFi] → [Lê TMP36] → [MQTT Publish] → [Deep Sleep 30s] → [Repete]
```
