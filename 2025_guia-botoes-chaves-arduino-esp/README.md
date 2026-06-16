# Guia Completo sobre Botões e Chaves para Arduino e ESP

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/guia-completo-sobre-botoes-e-chaves-para-arduino-e-esp/)

## Descrição

Guia completo sobre os tipos de **botões e chaves** mais utilizados em projetos com Arduino e ESP32/ESP8266, com exemplos práticos de circuito e código. Componentes fundamentais para qualquer projeto interativo — desde acionar um LED até controlar menus e estados de dispositivos.

## Tipos de Componentes Abordados

| Componente | Tipo | Características |
|---|---|---|
| Push Button 4 pinos (12×12mm) | Momentâneo | Ativa apenas quando pressionado |
| Push Button 2 pinos | Momentâneo | Versão compacta |
| Mini Rocker Switch KCD11-101 | Mantido | Liga/desliga com trava |
| Micro Switch SS12D00G4 | Deslizante | 3 terminais, haste longa |
| DIP Switch (1 ou 4 canais) | Mantido | Múltiplas chaves em linha |
| Chave fim de curso (Limit Switch) | Momentâneo | Detecta posição mecânica |
| Botão com trava PBS-16A | Mantido | Trava ao pressionar, solta ao pressionar novamente |

## Estrutura do Projeto

```
2025_guia-botoes-chaves-arduino-esp/
└── Botao_LED/
    └── Botao_LED.ino
```

## Componentes do Exemplo

| Componente | Qtd |
|---|---|
| Arduino Uno / ESP32 / ESP8266 | 1 |
| Push Button | 1 |
| LED | 1 |
| Resistor pull-down (10kΩ) | 1 |

## Resistores Pull-Down e Pull-Up

### Pull-Down (usado neste projeto)
```
5V ──[Botão]──┬── Pino Arduino
              │
           [10kΩ]
              │
             GND
```
Sem pressionar: pino = LOW | Com pressionar: pino = HIGH

### Pull-Up (alternativa com INPUT_PULLUP)
```cpp
pinMode(botao, INPUT_PULLUP);
// Sem pressionar: pino = HIGH | Com pressionar: pino = LOW
```

## Pinagem do Exemplo

| Componente | Arduino |
|---|---|
| Botão (com pull-down externo) | Pino 2 |
| LED | Pino 13 |

## Como Usar

1. Monte o circuito com o botão e resistor pull-down.
2. Faça o upload de `Botao_LED.ino`.
3. Pressione o botão — o LED acende.
4. Solte o botão — o LED apaga.

## Dicas por Tipo de Botão

### Push Button 4 Pinos
Os 4 pinos são 2 pares. Pinos do mesmo lado estão conectados internamente — use pinos de lados opostos.

### Chave Fim de Curso
Use para detectar posição em impressoras 3D, CNCs e robôs. Conecte o pino COM e NO (Normally Open).

### DIP Switch
Excelente para configurações de endereço em projetos com múltiplos módulos (ex.: I2C address selection).

### Botão com Trava
Implementar debounce e leitura de estado é essencial — o botão mantém o estado pressionado mesmo após soltar.
