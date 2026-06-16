# Monitor de pH de Líquidos com ESP32 e Sensor PH-4502C

Publicado em: **2024** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/monitorando-o-ph-de-liquidos-com-esp32-e-sensor-ph-4502c/)

## Descrição

Monitor de pH com **ESP32**, módulo **ADS1115** (ADC externo de 16 bits) e sensor **PH-4502C**. O ADS1115 melhora significativamente a precisão da leitura analógica comparado ao ADC interno do ESP32. Projeto ideal para sistemas hidropônicos, aquicultura, tratamento de água e controle de processos.

O pH ideal para hidroponia fica entre **5,5 e 6,5**.

## Componentes

| Componente | Qtd |
|---|---|
| ESP32 DevKitC S1 | 1 |
| Módulo ADS1115 (ADC 16 bits I2C) | 1 |
| Sensor pH-4502C com eletrodo | 1 |
| Protoboard 400 pontos | 2 |
| Soluções tampão pH 4, 7 e 10 (calibração) | — |

## Estrutura do Projeto (PlatformIO)

```
2024_monitor-ph-esp32/
├── platformio.ini
└── src/
    └── main.cpp
```

> Também pode ser usado no Arduino IDE renomeando `main.cpp` para `main.ino`.

## Bibliotecas Necessárias

- **Adafruit ADS1X15** — PlatformIO / Library Manager

## Pinagem

| Componente | ESP32 |
|---|---|
| ADS1115 SDA | GPIO 21 |
| ADS1115 SCL | GPIO 22 |
| ADS1115 VDD | 3.3V |
| ADS1115 GND | GND |
| PH-4502C Po | ADS1115 A0 |
| PH-4502C V+ | 5V |
| PH-4502C GND | GND |

## Calibração (Passo a Passo)

### Passo 1 – Calibração do Offset
1. Curto-circuite o conector BNC (pinos externo e central)
2. Conecte o sensor ao ESP32
3. Use o código de offset simples:
   ```cpp
   float voltage = analogRead(35) * (3.3 / 4095.0);
   ```
4. Ajuste o potenciômetro **"calibration reading"** até Serial mostrar ~2,5V

### Passo 2 – Calibração com Solução Tampão pH 7
1. Mergulhe o eletrodo na solução tampão pH 7
2. Faça upload de `main.cpp`
3. Ajuste `calibration_value` (linha 21) até o Serial mostrar pH 7,0
4. Salve o novo valor e re-faça upload

### Passo 3 – Prevenção de Contaminação Cruzada
- Lave o eletrodo com água destilada entre medições
- Use soluções tampão em ordem crescente (4 → 7 → 10)

## Fórmula de Conversão

```
pH = -5.70 × Tensão + calibration_value
```

## Como Usar

1. Clone ou copie o projeto.
2. Abra com **PlatformIO** (VS Code) ou renomeie para `.ino` e abra no Arduino IDE.
3. Execute a calibração conforme descrito.
4. Abra o Serial Monitor a 115200 baud.
5. Insira o eletrodo no líquido e leia o pH.
