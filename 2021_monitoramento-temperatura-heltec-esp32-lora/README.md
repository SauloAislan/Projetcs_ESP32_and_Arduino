# Monitoramento Remoto de Temperatura com Heltec ESP32 LoRa

Publicado em: **2021** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/monitoramento-remoto-de-temperatura-utilizando-a-heltec-esp32-lora/)

## Descrição

Sistema de monitoramento remoto de temperatura utilizando tecnologia **LoRa** (Long Range), que oferece comunicação sem fio de longo alcance com baixo consumo de energia. O projeto cria uma rede ponto-a-ponto onde um dispositivo transmite leituras de temperatura do sensor DHT11 e o receptor exibe os dados em um display OLED — sem necessidade de Wi-Fi ou infraestrutura de internet.

Ideal para aplicações como sensores agrícolas em áreas remotas alimentados por bateria ou painel solar.

## Componentes

| Componente | Qtd |
|---|---|
| Heltec LoRa WiFi 915MHz SX1276 ESP32 (com display OLED 0,96") | 2 |
| Sensor de temperatura/umidade DHT11 | 1 |
| Protoboard 400 pontos | 1 |
| Jumpers | — |

## Estrutura do Projeto

```
2021_monitoramento-temperatura-heltec-esp32-lora/
├── transmissor/
│   └── transmissor.ino   ← Código do transmissor (com DHT11)
└── receptor/
    └── receptor.ino      ← Código do receptor (apenas LoRa)
```

## Bibliotecas Necessárias

1. **Heltec ESP32** (Board Manager)
   - Preferences → Additional URLs: `https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/releases/download/0.0.5/package_heltec_esp32_index.json`
   - Tools → Board Manager → "Heltec ESP32" → Instalar
2. **Heltec ESP32** (Library Manager)
   - Sketch → Include Library → Manage Libraries → "Heltec ESP32" → Instalar
3. **DHTesp** (Library Manager) — para o transmissor

## Pinagem

### Transmissor
| DHT11 | Heltec ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | Pino 17 |

### Receptor
Nenhuma conexão externa — usa apenas o módulo LoRa interno.

## Como Usar

1. Adicione a URL do Board Manager nas preferências do Arduino IDE.
2. Instale as bibliotecas listadas acima.
3. Faça o upload de `transmissor.ino` na primeira placa Heltec.
4. Faça o upload de `receptor.ino` na segunda placa Heltec.
5. Ligue ambas as placas — o receptor exibirá a temperatura no OLED.

## Frequência LoRa

**915 MHz** — homologada pela Anatel para uso no Brasil.

## Funcionamento

```
[DHT11] → [Heltec TX] --(LoRa 915MHz)--> [Heltec RX] → [Display OLED]
```

O transmissor lê a temperatura a cada segundo e envia um pacote LoRa somente quando o valor muda. O LED pisca para indicar envio. O receptor decodifica o pacote e exibe `Temperatura: XX.X °C` no display OLED.
