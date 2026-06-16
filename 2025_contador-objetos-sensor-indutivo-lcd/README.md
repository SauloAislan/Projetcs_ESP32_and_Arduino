# Contador de Objetos com Arduino, Sensor Indutivo e Display LCD

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/contador-de-objetos-com-arduino-sensor-indutivo-e-display-lcd/)

## Descrição

Sistema de contagem automática de objetos metálicos usando **sensor indutivo PNP** e **ESP32**, com exibição em tempo real no display **LCD 16×2 via I2C**. O sensor detecta peças metálicas sem contato físico através de campo eletromagnético — ideal para linhas de produção, controle de inventário e monitoramento de fluxo de materiais.

Sensores indutivos são robustos e resistentes a poeira, umidade e vibração, tornando-os preferidos em ambientes industriais.

## Componentes

| Componente | Qtd |
|---|---|
| ESP32 DevKitC (30 pinos) | 1 |
| Sensor indutivo PNP LJ12A3-4-Z/BY | 1 |
| Display LCD 16×2 com módulo I2C | 1 |
| Módulo Step-Down LM2596 | 1 |
| Protoboard 830 pontos | 2 |
| Resistor pull-down 1kΩ | 1 |
| Fonte 12V 1A | 1 |
| Jumpers | — |

## Estrutura do Projeto

```
2025_contador-objetos-sensor-indutivo-lcd/
└── Contador_de_objeto/
    └── Contador_de_objeto.ino
```

## Biblioteca Necessária

- **LiquidCrystal I2C** — Library Manager (busque "LiquidCrystal I2C by Arduino")

## Pinagem

| Componente | ESP32 |
|---|---|
| Sensor (fio preto – sinal) | GPIO 12 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| Sensor (fio marrom – VCC) | Saída positiva do LM2596 |
| Sensor (fio azul – GND) | GND |

### Módulo LM2596 (Step-Down)
| LM2596 | Conexão |
|---|---|
| IN+ / IN- | Fonte 12V |
| OUT+ → Sensor marrom | VCC do sensor |
| OUT- → GND comum | GND |

> Ajuste o LM2596 para a tensão de operação do sensor (verificar datasheet — LJ12A3-4-Z/BY opera com 6–36V).

## Como Usar

1. Instale a biblioteca **LiquidCrystal I2C**.
2. Faça o upload de `Contador_de_objeto.ino`.
3. Se o LCD não acender, use um I2C Scanner para descobrir o endereço:
   - Tente `0x27` se `0x3F` não funcionar.
4. Posicione o sensor indutivo a no máximo **4mm** dos objetos metálicos.
5. Passe peças metálicas pela frente do sensor e observe a contagem no LCD.

## Lógica de Detecção

```
Estado HIGH → Estado LOW  =  borda de descida = objeto detectado → contador++
```

O `delay(50)` evita contagem dupla por vibração (debounce por software).

## Aplicações

- Linhas de produção industrial
- Controle de estoque automatizado
- Monitoramento de fluxo de peças
- Sistemas de controle de qualidade
