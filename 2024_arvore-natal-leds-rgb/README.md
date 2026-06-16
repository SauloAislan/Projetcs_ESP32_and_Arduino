# Árvore de Natal com LEDs RGB

Publicado em: **2024** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/como-montar-uma-arvore-de-natal-com-leds-rgb/)

## Descrição

Árvore de Natal decorativa construída diretamente em **protoboard** com **LEDs RGB automáticos** que ciclam as cores independentemente — sem microcontrolador ou programação! O efeito de piscar aleatório é criado por circuitos **RC (resistor-capacitor)** com transistores NPN, onde diferentes valores de componentes criam intervalos únicos de temporização para cada LED.

Projeto excelente para iniciantes aprenderem sobre LEDs, transistores e circuitos RC.

## Componentes

| Componente | Qtd |
|---|---|
| LED RGB automático 5mm | 23 |
| Transistor NPN S9014 | 3 |
| Capacitor eletrolítico 47µF | 3 |
| Resistor 100Ω (1/4W) | 4 |
| Resistor 4,7kΩ (1/4W) | 3 |
| Protoboard 830 pontos | 2 |
| Protoboard 400 pontos | 1 |
| Kit de jumpers rígidos U (140 peças) | 1 |
| Suporte de pilhas 3×AA | 1 |
| Multímetro digital (opcional) | 1 |

## Funcionamento

O projeto **não usa código** — funciona por hardware puro:

1. **LEDs RGB automáticos** têm um CI interno que cicla as cores (vermelho → verde → azul → repete).
2. **Circuitos RC** com transistores criam temporização independente para cada grupo de LEDs.
3. O capacitor carrega/descarrega pelo resistor, alternando a condução do transistor.
4. Diferentes valores de C e R = diferentes velocidades de piscar.

## Alimentação

- **Tensão:** 3V (2× pilha AA) ou 5V
- Todos os ânodos dos LEDs vão para o positivo da alimentação
- Cada conjunto de LEDs é controlado por um transistor

## Montagem

### Etapa 1 – Estrutura da Árvore
- Arranje os LEDs em padrão triangular na protoboard simulando uma árvore
- Conecte todos os ânodos (+) ao barramento positivo

### Etapa 2 – Circuito RC (para cada grupo)
```
5V ──[4,7kΩ]──┬──[100Ω]──→ Base do S9014
               │
            [47µF]
               │
              GND

Coletor do S9014 → Resistor limitador → Cátodo dos LEDs
Emissor do S9014 → GND
```

### Etapa 3 – Alimentação
- Conecte o suporte de pilhas (3V–4,5V) ao barramento de alimentação
- Ligue e aprecie!

## Observação

Os LEDs RGB automáticos são diferentes dos LEDs RGB comuns — eles possuem apenas **2 terminais** (+ e –) e um CI interno para controle de cor, não requerendo pinos individuais de controle.
