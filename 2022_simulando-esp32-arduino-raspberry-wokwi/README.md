# Simulando ESP32, Arduino e Raspberry Pi com o Wokwi

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/simulando-esp32-arduino-e-raspberry-pi-com-o-wokwi/)

## Descrição

Tutorial sobre o **Wokwi** — simulador online gratuito para Arduino, ESP32 e Raspberry Pi Pico — com três projetos práticos demonstrados:

1. **Mini Piano** com Arduino UNO (8 notas musicais)
2. **Contador de 0 a F** com display 7 segmentos no Raspberry Pi Pico (MicroPython)
3. **Monitor MQTT** com ESP32 e DHT22 (temperatura/umidade para broker MQTT)

## Projetos

### 1. Mini Piano (Arduino UNO)
```
mini_piano_arduino/
└── mini_piano_arduino.ino
```
8 botões geram notas de Dó a Dó (C4–C5) em um buzzer.

### 2. Contador 7 Segmentos (Raspberry Pi Pico)
```
contador_7seg_raspberry_pico/
└── contador_7seg_raspberry_pico.py
```
Chave toggle determina contagem crescente ou decrescente (hex 0–F).

### 3. MQTT com ESP32 + DHT22
```
mqtt_esp32_dht22/
└── mqtt_esp32_dht22.ino
```
Lê temperatura/umidade e publica via MQTT no broker `test.mosquitto.org`.

## Estrutura do Projeto

```
2022_simulando-esp32-arduino-raspberry-wokwi/
├── mini_piano_arduino/
│   └── mini_piano_arduino.ino
├── contador_7seg_raspberry_pico/
│   └── contador_7seg_raspberry_pico.py
└── mqtt_esp32_dht22/
    └── mqtt_esp32_dht22.ino
```

## Como Simular no Wokwi

1. Acesse [wokwi.com](https://wokwi.com)
2. Clique em **"New Project"** e selecione a plataforma
3. Cole o código do projeto desejado
4. Monte o circuito arrastando os componentes
5. Clique em **Play** para simular

## Bibliotecas (Mini Piano)

Inclua o arquivo `pitches.h` disponível em:
Arduino IDE → Exemplos → 02.Digital → toneMelody

## Bibliotecas (MQTT ESP32)

- **EspMQTTClient** — Library Manager
- **DHT sensor library for ESPx** — Library Manager

## Tópicos MQTT (Projeto 3)

| Direção | Tópico |
|---|---|
| Publish temperatura | `topicowokwi/Temp` |
| Publish umidade | `topicowokwi/Humidade` |
| Subscribe mensagens | `topicowokwi/msgRecebida/#` |

> O Wokwi fornece WiFi virtual "Wokwi-GUEST" sem senha para simulação.
