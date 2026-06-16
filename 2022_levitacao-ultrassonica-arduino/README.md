# Levitação Ultrassônica com Arduino

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/levitacao-ultrassonica-com-arduino/)

## Descrição

Projeto que demonstra **levitação acústica** usando Arduino Nano. Ondas ultrassônicas (acima de 20 kHz) criam **ondas estacionárias** entre um transdutor (emissor) e um refletor — as partículas leves ficam presas nos nós de pressão e literalmente levitam no ar.

O Arduino gera uma onda quadrada de 80 kHz usando o TIMER1 via interrupção de hardware, que alimenta um **módulo H-Bridge** para acionar os transdutores do HC-SR04 desmontado.

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Nano V3.0 | 1 |
| Sensor HC-SR04 (desmontado) | 1 |
| Módulo H-Bridge com CI L293 | 1 |
| Jumpers | — |
| Suportes 3D impressos (Thingiverse) | — |

## Estrutura do Projeto

```
2022_levitacao-ultrassonica-arduino/
└── Levitador_ultrasonico/
    └── Levitador_ultrasonico.ino
```

## Como Funciona

O TIMER1 do Arduino AVR é configurado em modo CTC com OCR1A = 200, gerando:

```
f = 16 MHz / 200 = 80 kHz (onda quadrada) → 40 kHz (onda completa)
```

O ISR inverte a saída de PORTC a cada ciclo, criando a oscilação nos transdutores.

## Montagem

1. **Desmonte** o HC-SR04 separando o emissor e o receptor.
2. Monte os transdutores **alinhados** com distância máxima de **4 cm** entre si.
3. Conecte os pinos analógicos (PORTC) ao H-Bridge.
4. Conecte o H-Bridge aos transdutores (observe a polaridade — círculo preto = negativo).
5. Faça o upload do código.
6. Evite correntes de ar durante os testes.

## Pinagem

| Arduino Nano | H-Bridge |
|---|---|
| A0–A7 (PORTC) | Entradas do H-Bridge |

## Dicas

- Objetos leves como isopor, partículas de sal ou bolinhas de papel funcionam melhor.
- O alinhamento preciso entre emissor e refletor é essencial.
- Correntes de ar interferem na levitação.
