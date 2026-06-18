/**
 * @file main.cpp
 * @author Saulo Aislan
 * @brief Monitor de pH com ESP32, módulo ADS1115 e sensor PH-4502C.
 *        Ideal para sistemas hidropônicos, aquicultura e controle de água.
 * @version 0.1
 * @date 2024-07-12
 * @copyright Copyright (c) 2024
 *
 * Artigo: https://blog.eletrogate.com/monitorando-o-ph-de-liquidos-com-esp32-e-sensor-ph-4502c/
 *
 * Componentes:
 *   - ESP32 DevKitC S1
 *   - Módulo ADS1115 (I2C: SDA=GPIO21, SCL=GPIO22)
 *   - Sensor PH-4502C
 *
 * Bibliotecas necessárias (PlatformIO / Library Manager):
 *   - Adafruit ADS1X15
 *   - SPI (built-in)
 *
 * Calibração:
 *   1. Curto-circuite o conector BNC (externo + centro) → saída 2,5V
 *   2. Ajuste o potenciômetro "calibration reading" até Serial mostrar ~2,5V
 *   3. Com solução tampão pH 7, ajuste `calibration_value` até ler pH 7
 */

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

int buffer_arr[10], temp;
unsigned long int avgval;
float ph_act;
float calibration_value = 20.5;  // Ajuste durante calibração

void setup(void)
{
    Serial.begin(115200);
    Serial.println("::::: Monitor de pH :::::");

    ads.setGain(GAIN_ONE);  // ±4.096V

    if (!ads.begin()) {
        Serial.println("Falha ao iniciar o ADS1115.");
        while (1);
    }
    Serial.println("ADS1115 inicializado com sucesso.");
}

void loop(void)
{
    int16_t adc0  = ads.readADC_SingleEnded(0);
    float   volts0 = ads.computeVolts(adc0);

    for (int i = 0; i < 10; i++) {
        buffer_arr[i] = (int)(volts0 * 1000);  // armazena em mV
        delay(30);
    }

    // Ordena buffer (bubble sort) para descartar extremos
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (buffer_arr[i] > buffer_arr[j]) {
                temp         = buffer_arr[i];
                buffer_arr[i] = buffer_arr[j];
                buffer_arr[j] = temp;
            }
        }
    }

    // Média dos 6 valores centrais
    avgval = 0;
    for (int i = 2; i < 8; i++) avgval += buffer_arr[i];
    float volt = (float)avgval / 6 / 1000.0;  // de volta para V

    ph_act = -5.70 * volts0 + calibration_value;

    Serial.print("Tensão: ");    Serial.print(volts0, 4); Serial.println(" V");
    Serial.print("Valor de pH: "); Serial.println(ph_act, 2);
    delay(1000);
}
