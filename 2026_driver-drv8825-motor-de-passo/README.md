# Driver DRV8825 – Guia Completo para Projetos com Arduino e Motor de Passo

Publicado em: **2026** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/driver-drv8825-guia-completo-para-projetos-com-arduino-e-motor-de-passo/)

## Descrição

Guia completo sobre o **driver DRV8825** para controle de motores de passo. O DRV8825 supera o popular A4988 em robustez, precisão e versatilidade, suportando microstepping de até 1/32 e alimentação de 8,2V a 45V — ideal para aplicações que exigem alta resolução e operação estável.

## Especificações do DRV8825

| Parâmetro | Valor |
|---|---|
| Tensão de alimentação | 8,2V – 45V |
| Corrente máxima | ~2,2A (com dissipador) |
| Microstepping | 1, 1/2, 1/4, 1/8, 1/16, 1/32 |
| Interface | STEP/DIR |
| Proteção | Sobrecorrente + temperatura |

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Uno R3 + cabo USB | 1 |
| Driver DRV8825 | 1 |
| Motor de passo NEMA 17 (4,2 kgf.cm / 1,7A) | 1 |
| Capacitor eletrolítico 100µF/25V | 1 |
| Fonte 12V 1A | 1 |
| Protoboard 400 pontos | 1 |
| Jumpers | — |

## Estrutura do Projeto

```
2026_driver-drv8825-motor-de-passo/
└── Motor_Passo_DRV8825/
    └── Motor_Passo_DRV8825.ino
```

## Pinagem

| DRV8825 | Arduino Uno |
|---|---|
| RST | 5V |
| SLP | 5V |
| GND | GND |
| STEP | Pino 3 |
| DIR | Pino 2 |

| DRV8825 | Motor NEMA 17 |
|---|---|
| A1, A2 | Bobina A |
| B1, B2 | Bobina B |

> Coloque o capacitor de 100µF próximo aos terminais de alimentação VMOT e GND do driver para estabilizar a tensão.

## Configuração de Microstepping

| M0 | M1 | M2 | Resolução |
|---|---|---|---|
| LOW | LOW | LOW | Full step (200 passos/volta) |
| HIGH | LOW | LOW | 1/2 step (400 passos/volta) |
| LOW | HIGH | LOW | 1/4 step (800 passos/volta) |
| HIGH | HIGH | LOW | 1/8 step (1600 passos/volta) |
| LOW | LOW | HIGH | 1/16 step (3200 passos/volta) |
| HIGH | HIGH | HIGH | 1/32 step (6400 passos/volta) |

Pinos M0, M1, M2 flutuantes = Full step (resistores pull-down internos).

## Como Usar

1. Monte o circuito conforme a pinagem.
2. Instale o capacitor 100µF próximo à alimentação do driver.
3. Faça upload de `Motor_Passo_DRV8825.ino`.
4. O motor girará:
   - **Horário** lentamente por 1 volta
   - **Anti-horário** rapidamente por 1 volta
   - Repete indefinidamente

## Ajuste de Corrente

Ajuste o trimpot no driver com multímetro:
```
V_ref = I_max × 0,5
Exemplo para 1A: V_ref = 0,5V
```
Meça V_ref entre o pino central do trimpot e GND.

## Aplicações

- Impressoras 3D (eixos X, Y, Z)
- CNCs e plotters
- Câmeras com controle de foco motorizado
- Robótica e automação
