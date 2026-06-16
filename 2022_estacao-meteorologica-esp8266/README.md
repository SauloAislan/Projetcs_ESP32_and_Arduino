# Estação Meteorológica Residencial com ESP8266

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/estacao-meteorologica-residencial-com-esp8266/)

## Descrição

Estação meteorológica local com **ESP8266**, que exibe em um display OLED 128×64 as seguintes informações ambientais em tempo real:

- Temperatura (média DHT11 + BMP280)
- Umidade relativa do ar (DHT11)
- Pressão atmosférica (BMP280)
- Altitude (calculada via pressão)
- Indicação de chuva (sensor analógico)

O display alterna automaticamente entre as telas a cada 3 segundos, com ícones gráficos (sol/nuvem).

## Componentes

| Componente | Qtd |
|---|---|
| ESP8266 12F IOT USB | 1 |
| Display OLED 128×64 0,96" I2C | 1 |
| Sensor DHT11 | 1 |
| Sensor BMP280 (pressão + temperatura) | 1 |
| Sensor de chuva (analógico) | 1 |
| Resistores 4k7Ω | 2 |
| Fonte 5V + cabo Micro USB | 1 |

## Estrutura do Projeto

```
2022_estacao-meteorologica-esp8266/
└── Estacao_metereologica/
    ├── Estacao_metereologica.ino
    └── images.h    ← Bitmaps dos ícones (sol e nuvem) – baixe do artigo
```

## Bibliotecas Necessárias

| Biblioteca | Onde instalar |
|---|---|
| BMP280 (mahfuz195) | GitHub |
| DHTesp (beegee-tokyo) | Library Manager |
| SSD1306 (ThingPulse) | Library Manager |

## Pinagem

| Componente | ESP8266 |
|---|---|
| OLED SDA | D4 (GPIO2) |
| OLED SCL | D5 (GPIO14) |
| BMP280 SDA | D4 (GPIO2) |
| BMP280 SCL | D5 (GPIO14) |
| DHT11 DATA | D1 (GPIO5) |
| Sensor de chuva (analógico) | A0 (com divisor 2×4k7Ω) |

> O divisor de tensão com 2×4k7Ω protege o pino A0 reduzindo a tensão para nível seguro.

## Como Usar

1. Baixe o arquivo `images.h` do artigo original e coloque na mesma pasta do `.ino`.
2. Instale as bibliotecas listadas.
3. Faça o upload pelo Arduino IDE (selecione o módulo ESP8266 correto em Tools → Board).
4. Abra o Serial Monitor (115200 baud) para ver os dados brutos.

## Lógica de Detecção de Chuva

```cpp
if (analogRead(A0) <= 900) → Chovendo
if (analogRead(A0) >  900) → Sem chuva
```

## Sequência de Telas

```
[Chuva] → [Temperatura] → [Pressão] → [Altitude] → [Umidade] → repete
```
Cada tela fica ativa por 3 segundos.
