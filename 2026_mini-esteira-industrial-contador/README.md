# Mini Esteira Industrial com Contador de Objetos e Display LCD

Publicado em: **2026** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/mini-esteira-industrial-com-contador-de-objetos-e-display-lcd/)

## Descrição

Esteira industrial em miniatura que simula uma linha de produção real. Peças metálicas são transportadas por uma esteira de tecido TNT acionada por motor DC, detectadas por sensor indutivo NPN e contadas em tempo real no display LCD 16×2. O projeto demonstra conceitos fundamentais de automação industrial: mecânica, impressão 3D, eletrônica e programação com Arduino.

## Componentes

### Eletrônicos

| Componente | Qtd |
|---|---|
| Arduino Uno R3 + cabo USB | 1 |
| Motor DC 3-6V com caixa de redução e eixo duplo | 1 |
| Sensor indutivo NPN LJ12A3-4-Z/BX | 1 |
| Display LCD 16×2 com módulo I2C | 1 |
| Mini chave gangorra KCD11-101 | 1 |
| Protoboard 830 pontos | 1 |
| Conector jack de alimentação | 1 |
| Fonte 12V 1A | 1 |

### Mecânicos

| Componente | Qtd |
|---|---|
| Perfis de alumínio 20×20mm (45cm) | 2 |
| Parafusos M3 (8–10mm) | 10 |
| T-nuts M3 | 10 |
| Rolamentos radiais 6804 (20×32×7mm) | 4 |
| Tecido TNT (105cm × 8cm) | 1 |

### Peças 3D Impressas (PLA/ABS/PETG)

- Suporte do motor
- Suporte de rolamentos + cantoneiras
- Rolos (motorizado e livre)
- Suporte do sensor
- Pés

## Estrutura do Projeto

```
2026_mini-esteira-industrial-contador/
└── Contador_esteira/
    └── Contador_esteira.ino
```

## Biblioteca Necessária

- **LiquidCrystal I2C** — Library Manager

## Pinagem

| Componente | Arduino Uno |
|---|---|
| Sensor indutivo (sinal) | Pino 2 (INT0) |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Motor (via chave gangorra) | Alimentação externa 12V |

## Montagem (Passo a Passo)

### Fase 1 – Estrutura Mecânica
1. Posicione os dois perfis de alumínio paralelos como base
2. Insira os T-nuts nos rasgos antes de fechar
3. Instale as barras de conexão e cantoneiras com parafusos M3
4. Monte os rolamentos nas peças de canto

### Fase 2 – Motor e Rolos
1. Fixe o motor no suporte 3D com cola quente + fita dupla-face
2. Instale o rolo motorizado no eixo do motor
3. Instale o rolo livre com rolamentos

### Fase 3 – Esteira (Tecido TNT)
1. Posicione a estrutura dentro do tecido TNT
2. Insira os rolos dentro da esteira
3. Una as pontas do TNT com costura ou cola de tecido
4. Ajuste a tensão afastando os rolos

### Fase 4 – Eletrônica
1. Conecte o sensor indutivo ao pino 2 (com `INPUT_PULLUP`)
2. Posicione o sensor a no máximo **1 cm** da esteira
3. Faça upload de `Contador_esteira.ino`
4. Instale a chave gangorra para ligar/desligar o motor

## Como Funciona

```
[Motor liga] → [Esteira move peças metálicas] 
→ [Sensor indutivo detecta peça] → [Interrupção Arduino] 
→ [Contador incrementa] → [LCD atualiza]
```

O **debounce** de 150ms na interrupção garante que cada peça seja contada apenas uma vez.

## Aplicações Educacionais e Profissionais

- Demonstração de conceitos de automação industrial
- Prototipagem de sistemas de contagem de produção
- Projetos de TCC e trabalhos acadêmicos
- Simulação de linha de montagem para treinamento
