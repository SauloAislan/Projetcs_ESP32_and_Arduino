/**
 * @file transmissor.ino
 * @author Saulo Aislan
 * @brief Transmissor LoRa – lê temperatura do DHT11 e envia via LoRa 915 MHz
 * @version 0.1
 * @date 2021
 * @copyright Copyright (c) 2021
 *
 * Artigo: https://blog.eletrogate.com/monitoramento-remoto-de-temperatura-utilizando-a-heltec-esp32-lora/
 *
 * Bibliotecas necessárias:
 *   - Heltec ESP32 (Board Manager)
 *   - DHTesp (Library Manager)
 */

#include "heltec.h"
#include "DHTesp.h"

#define BAND 915E6  // Frequência LoRa – 915 MHz (Anatel/Brasil)

DHTesp dht;
String packet;
float currentTemp;
float currentHumidity;

void getTemp() {
  float temperature = dht.getTemperature();
  if (temperature != currentTemp) {
    currentTemp = temperature;
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
  delay(1000);
}

void sendPacket() {
  LoRa.beginPacket();
  LoRa.print("Temperatura: ");
  LoRa.print(currentTemp);
  LoRa.endPacket();
}

void setup() {
  pinMode(LED, OUTPUT);
  Heltec.begin(true, true, true, true, BAND);
  Heltec.display->init();
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->clear();
  Heltec.display->drawString(33, 5, "Iniciado");
  Heltec.display->drawString(10, 30, "com Sucesso!");
  Heltec.display->display();
  delay(1000);
  dht.setup(17, DHTesp::DHT11);  // DHT11 no pino 17
  currentTemp = dht.getTemperature();
}

void loop() {
  getTemp();
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(30, 5, "Enviando");
  Heltec.display->drawString(33, 30, (String)currentTemp);
  Heltec.display->drawString(78, 30, "°C");
  Heltec.display->display();
  sendPacket();
}
