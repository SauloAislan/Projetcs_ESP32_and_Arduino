# Fonte Bebedouro para Gatos com ESP8266

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/fonte-bebedouro-para-gatos-com-esp8266/)

## Descrição

Bebedouro automático para gatos com controle via **interface web Wi-Fi**. O sistema aciona uma mini bomba submersível através de um relé, oferecendo quatro modos de operação configuráveis pelo smartphone ou computador conectado à rede criada pelo próprio dispositivo.

Gatos preferem água em movimento — este projeto resolve isso e ainda prevê o acúmulo de sedimentos e bactérias em vasilhas estagnadas.

> **Atenção:** O sistema não possui detecção de nível de água. Verifique periodicamente para evitar que a bomba queime por falta d'água.

## Componentes

| Componente | Qtd |
|---|---|
| Wemos D1 Mini Pro (ESP8266) | 1 |
| Mini bomba submersível 5V | 1 |
| Módulo relé 5V 1 canal | 1 |
| Transistor NPN 2N2222 | 1 |
| Resistor 1kΩ | 1 |
| Resistor 47kΩ | 1 |
| Placa fenolite perfurada 7×9cm | 1 |
| Conector jack DC-005 fêmea | 1 |
| Borne 2 posições | 1 |
| Fonte 5V 1A | 1 |

## Estrutura do Projeto

```
2022_fonte-bebedouro-gatos-esp8266/
└── Bebedouro/
    └── Bebedouro.ino
```

## Bibliotecas Necessárias

- **ESPAsyncTCP** — Library Manager
- **ESPAsyncWebServer** — Library Manager

## Rede Wi-Fi

O dispositivo cria uma rede própria:
- **SSID:** `Bebedouro`
- **Senha:** `123456789`
- **Acesso:** http://192.168.4.1

## Modos de Operação

| Modo | Descrição |
|---|---|
| **Contínuo** | Bomba sempre ligada |
| **Por Tempo** | Liga/desliga em intervalos de 60 min (15s ligado) |
| **Manual** | Botão Ligar/Desligar na página web |
| **Tempo e Manual** | Combina temporização com controle manual |

## Pinagem

| Componente | Wemos D1 Mini Pro |
|---|---|
| Relé (via transistor) | D2 (GPIO4) |
| Fonte 5V | VIN / GND |

## Como Usar

1. Instale as bibliotecas **ESPAsyncTCP** e **ESPAsyncWebServer**.
2. Faça o upload de `Bebedouro.ino` para o Wemos D1 Mini Pro.
3. Conecte seu smartphone/computador à rede `Bebedouro`.
4. Abra o navegador em `http://192.168.4.1`.
5. Selecione o modo de operação desejado.

## Circuito do Transistor (Driver do Relé)

```
ESP8266 D2 → [1kΩ] → Base (2N2222)
                     Coletor → Bobina do Relé → 5V
                     Emissor → GND
GND → [47kΩ] → Base (pull-down)
```
