# Comunicação com Conversor USB-RS485

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/comunicacao-com-conversor-usb-rs485/)

## Descrição

Sistema de comunicação entre **computador e Arduino** via **RS-485**, simulando um cenário industrial onde o computador funciona como sistema de controle (ERP) e o Arduino como CLP. O computador envia comandos de texto ("LED ON"/"LED OFF") via terminal serial, e o Arduino exibe a mensagem no LCD e aciona o LED correspondente.

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Uno R3 | 1 |
| Módulo conversor TTL para RS485 | 1 |
| Conversor Mini USB para RS485 | 1 |
| Display LCD 16×2 com módulo I2C | 1 |
| Resistor 1kΩ | 1 |
| LED vermelho 5mm | 1 |
| Protoboard 830 pontos | 2 |

## Estrutura do Projeto

```
2022_comunicacao-usb-rs485/
└── PC_Arduino_RS485/
    └── PC_Arduino_RS485.ino
```

## Bibliotecas Necessárias

- **LiquidCrystal_I2C** — Library Manager
- **Wire** — built-in
- **SoftwareSerial** — built-in

## Pinagem

| Componente | Arduino Uno |
|---|---|
| RS485 RO (RX) | Pino 2 (SoftwareSerial) |
| RS485 DI (TX) | Pino 3 (SoftwareSerial) |
| RS485 DE/RE | Pino 4 (LOW = recepção) |
| LED | Pino 13 (+ resistor 1kΩ) |
| LCD SDA | A4 |
| LCD SCL | A5 |

> Certifique-se de conectar A com A e B com B entre o módulo RS485 e o conversor USB-RS485.

## Como Usar

1. Instale a biblioteca **LiquidCrystal_I2C**.
2. Faça o upload de `PC_Arduino_RS485.ino`.
3. Conecte o conversor USB-RS485 ao computador.
4. Conecte os terminais A e B do conversor USB-RS485 aos terminais A e B do módulo TTL-RS485.
5. Abra um terminal serial (ex.: **Termite**) na porta COM do conversor USB-RS485 a 9600 baud.
6. Envie os comandos abaixo e observe o LCD e o LED:

| Comando enviado | Resultado |
|---|---|
| `LED ON` | LED acende, LCD mostra "LED Aceso!" |
| `LED OFF` | LED apaga, LCD mostra "LED Apagado!" |
| Qualquer texto | LCD exibe o texto recebido |

## Endereço I2C do LCD

Se o LCD não funcionar, use um scanner I2C para descobrir o endereço correto (pode ser `0x27` em vez de `0x3F`):
```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```
