# Radar/Sonar Ultrassônico com Arduino e Processing

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/radar-sonar-ultrassonico-para-seus-projetos/)

## Descrição

Sistema de radar ultrassônico que combina **Arduino + HC-SR04 + Servo Motor** com uma interface gráfica em **Processing (Java)**. O servo gira o sensor de 15° a 165°, medindo a distância a cada grau e enviando os dados pela serial. O Processing renderiza um display estilo radar em tempo real, mostrando a posição e distância dos objetos detectados.

## Componentes

| Componente | Qtd |
|---|---|
| Arduino Nano V3.0 | 1 |
| Sensor HC-SR04 | 1 |
| MicroServo TowerPro MG90S (metal, 180°) | 1 |
| Mini Protoboard 170 pontos | 1 |
| Jumpers macho-macho (20cm) | 20 |
| Jumpers macho-fêmea (20cm) | 20 |

## Estrutura do Projeto

```
2022_radar-sonar-ultrasonico/
├── Radar_ultrasonico/
│   └── Radar_ultrasonico.ino    ← Código Arduino (servo + HC-SR04)
└── Radar_Processing/
    └── Radar_Processing.pde     ← Visualização gráfica (Processing IDE)
```

## Pinagem

| Componente | Arduino Nano |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | Pino 11 |
| HC-SR04 ECHO | Pino 10 |
| Servo VCC | 5V (ou fonte externa) |
| Servo GND | GND |
| Servo Signal | Pino 12 |

> Se o servo não funcionar adequadamente, use fonte externa de 5V para o circuito completo.

## Como Usar

### Arduino
1. Abra `Radar_ultrasonico/Radar_ultrasonico.ino` no Arduino IDE.
2. Instale a biblioteca **Servo** (geralmente já inclusa).
3. Faça o upload para o Arduino Nano.

### Processing
1. Baixe o Processing em [processing.org](https://processing.org/download).
2. Abra `Radar_Processing/Radar_Processing.pde`.
3. **Altere `"COM5"`** na linha `myPort = new Serial(this, "COM5", 9600)` para a porta do seu Arduino.
4. **Feche o Serial Monitor** do Arduino IDE.
5. Clique em **PLAY** no Processing.

## Protocolo Serial

O Arduino envia dados no formato:
```
ANGULO,DISTANCIA.
```
Exemplo: `45,23.` = 45 graus, 23 cm de distância.

## Alcance de Detecção

O radar exibe objetos até **40 cm**. Objetos além disso são marcados como "Fora do alcance".
