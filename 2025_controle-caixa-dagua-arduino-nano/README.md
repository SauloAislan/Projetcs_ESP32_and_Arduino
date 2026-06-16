# Controle Inteligente para Abastecimento de Caixa D'Água com Arduino Nano

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/controle-inteligente-para-abastecimento-de-caixa-dagua-com-arduino-nano/)

## Descrição

Sistema de automação residencial que monitora e controla o enchimento de caixas d'água. O sensor de fluxo **YF-S201** mede a quantidade de água em litros, o **Arduino Nano** processa os pulsos e aciona/desliga a bomba automaticamente via relé quando o volume desejado é atingido. Interface com botões para configurar o volume alvo e display LCD para monitoramento em tempo real.

Substitui sistemas de bóia mecânicos que podem falhar e causar transbordamento.

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Nano V3.0 + cabo USB | 1 |
| Sensor de fluxo YF-S201 (1/2") | 1 |
| Display LCD 16×2 com módulo I2C | 1 |
| Módulo relé 5V 1 canal | 1 |
| Resistor 10kΩ | 3 |
| Push Button (12×12×4,3mm) | 3 |
| Protoboard 830 pontos | 2 |
| Fonte 5V 1A | 1 |

## Estrutura do Projeto

```
2025_controle-caixa-dagua-arduino-nano/
└── Controle_de_abastecimento/
    └── Controle_de_abastecimento.ino
```

## Bibliotecas Necessárias

- **LiquidCrystal I2C** — Library Manager
- **Wire** — built-in

## Pinagem

| Componente | Arduino Nano |
|---|---|
| Sensor de fluxo (amarelo – sinal) | D3 (interrupção) |
| Sensor de fluxo (vermelho – VCC) | 5V |
| Sensor de fluxo (preto – GND) | GND |
| Módulo relé | D5 |
| Botão Aumentar | D6 |
| Botão Diminuir | D2 |
| Botão Iniciar | D9 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Como Usar

1. Instale a biblioteca **LiquidCrystal I2C**.
2. Faça o upload de `Controle_de_abastecimento.ino`.
3. Conecte o sensor de fluxo na tubulação de entrada da caixa.
4. Conecte a bomba d'água ao relé.
5. **Configure o volume:**
   - Pressione **Aumentar** ou **Diminuir** para ajustar em passos de 10 litros.
   - O LCD mostrará "Litros desejados: XX".
6. **Inicie:** pressione o botão **Iniciar** — a bomba liga e o LCD mostra vazão e volume em tempo real.
7. Ao atingir o volume configurado, a bomba **desliga automaticamente**.

## Sequência de Operação

```
[Configura volume] → [Pressiona Iniciar] → [Bomba liga] 
→ [Sensor conta litros] → [Volume atingido] → [Bomba desliga]
```

## Calibração do Sensor YF-S201

O fator padrão é `4,5` pulsos/segundo por litro/minuto. Ajuste `FATOR_CALIBRACAO` se necessário:
```cpp
const float FATOR_CALIBRACAO = 4.5;
```

## Limites de Volume

- **Mínimo:** 10 litros
- **Máximo:** 1000 litros
- **Incremento:** 10 litros por botão
