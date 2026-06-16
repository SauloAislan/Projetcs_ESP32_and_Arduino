# Robô Otto com Arduino Nano

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/montando-seu-robo-otto-com-arduino-nano/)

## Descrição

Montagem e programação do **Robô Otto** — um robô bípede open-source de 11×7×12 cm que caminha, dança, emite sons e evita obstáculos. Ferramenta educacional excelente para STEM, com montagem acessível (mínima soldagem) e programação via Arduino IDE ou Otto Blockly.

O código detecta obstáculos com sensor ultrassônico e desvia automaticamente, utilizando os 4 servos para andar e virar.

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Nano V3.0 + cabo USB | 1 |
| Shield expansão para Arduino Nano | 1 |
| HC-SR04 Sensor ultrassônico | 1 |
| Micro Servo 9g SG90 TowerPro | 4 |
| Buzzer ativo 3V | 1 |
| Push Button ou chave 3 terminais | 1 |
| Bateria 3,7V ou 9V | 1 |
| Regulador Step-Down DC-DC Mini 360 | 1 |
| Jumpers fêmea-fêmea (40 un, 20cm) | 1 |
| Peças 3D impressas (cabeça, corpo, 2 pernas, 2 pés) | 1 set |

## Estrutura do Projeto

```
2022_robo-otto-arduino-nano/
└── Meu_Robo_Otto/
    └── Meu_Robo_Otto.ino
```

## Biblioteca Necessária

- **Otto DIY** — Library Manager (busque por "Otto")

## Pinagem

| Componente | Arduino Nano |
|---|---|
| Servo Perna Esquerda | Pino 2 |
| Servo Perna Direita | Pino 3 |
| Servo Pé Esquerdo | Pino 4 |
| Servo Pé Direito | Pino 5 |
| Buzzer | Pino 13 |
| HC-SR04 TRIG | Pino 8 |
| HC-SR04 ECHO | Pino 9 |

## Montagem (Passo a Passo)

1. **Servos das pernas:** Parafuse nos encaixes do corpo com posição de 90°.
2. **Montagem das pernas:** Insira o servo na perna com alinhamento de 90°; fixe os pés.
3. **Cabeça:** Monte buzzer e HC-SR04 na peça de cabeça; encaixe o shield com Arduino.
4. **Calibração de tensão:** Faça upload de código de monitoramento no Arduino, ajuste o Step-Down para exatamente 5V via trimpot enquanto lê o Serial Monitor.
5. **Conexões finais:** Ligue todos os servos, buzzer e sensor ao shield.
6. **Upload:** Faça upload de `Meu_Robo_Otto.ino`.

## Lógica de Funcionamento

```
Se distância <= 15 cm → Emite som + recua + vira
Caso contrário       → Avança 1 passo
```

## Funções Disponíveis (Biblioteca Otto)

| Função | Descrição |
|---|---|
| `Otto.walk(n, t, dir)` | Caminha n passos |
| `Otto.turn(n, t, dir)` | Vira n passos |
| `Otto.swing(n, t, h)` | Balanço lateral |
| `Otto.shakeLeg(n, t, dir)` | Chacoalha perna |
| `Otto.sing(S_surprise)` | Emite som |
