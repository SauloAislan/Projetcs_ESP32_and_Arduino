# Comunicação Half-Duplex com RS-485

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/comunicacao-half-duplex-com-rs-485/)

## Descrição

Sistema de comunicação bidirecional entre **Arduino Uno e Arduino Mega** usando o padrão **RS-485**. Um potenciômetro conectado ao Arduino 1 controla o brilho do LED no Arduino 2, e vice-versa — demonstrando comunicação industrial half-duplex em tempo real.

O padrão RS-485 suporta múltiplos dispositivos em um único barramento, velocidade de até 10 Mb/s e distâncias de até 1.219 metros, com alta resistência a interferências.

## Half-Duplex

Dois dispositivos podem transmitir e receber, porém **não ao mesmo tempo**. A direção alterna via pino DE/RE:
- `HIGH` → modo transmissão
- `LOW` → modo recepção

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Uno R3 | 1 |
| Arduino Mega 2560 R3 | 1 |
| Módulo conversor TTL para RS485 (MAX485) | 2 |
| Potenciômetro linear 1kΩ | 2 |
| Resistor 1kΩ | 2 |
| LED azul 5mm | 1 |
| LED verde 5mm | 1 |
| Protoboard 830 pontos | 2 |
| Jumpers macho-fêmea (20cm) | 40 |

## Estrutura do Projeto

```
2022_comunicacao-half-duplex-rs485/
├── Arduino_Uno/
│   └── Arduino_Uno.ino
└── Arduino_Mega/
    └── Arduino_Mega.ino
```

## Pinagem

### Arduino Uno
| Componente | Pino |
|---|---|
| RS485 RO (RX) | 2 (SoftwareSerial) |
| RS485 DI (TX) | 3 (SoftwareSerial) |
| RS485 DE/RE | 4 |
| Potenciômetro | A0 |
| LED (PWM) | 10 |

### Arduino Mega
| Componente | Pino |
|---|---|
| RS485 RO (RX) | 10 (SoftwareSerial) |
| RS485 DI (TX) | 11 (SoftwareSerial) |
| RS485 DE/RE | 12 |
| Potenciômetro | A0 |
| LED (PWM) | 13 |

### Barramento RS-485
Conecte `A` com `A` e `B` com `B` entre os dois módulos.

## Como Usar

1. Faça upload de `Arduino_Uno.ino` no Arduino Uno.
2. Faça upload de `Arduino_Mega.ino` no Arduino Mega.
3. Conecte os barramentos A-A e B-B entre os módulos RS-485.
4. Gire o potenciômetro em um Arduino e observe o LED no outro variar.

## Protocolo de Dados

```
Formato: 'I' + VALOR + 'F'
Exemplo: I150F  (valor 150 de 0–200)
```
O receptor parseia `parseInt()` entre 'I' e 'F' e aplica via PWM no LED.
