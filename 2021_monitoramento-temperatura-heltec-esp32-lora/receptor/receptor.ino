/**
 * @file receptor.ino
 * @author Saulo Aislan
 * @brief Receptor LoRa – recebe temperatura e exibe no display OLED
 * @version 0.1
 * @date 2021
 * @copyright Copyright (c) 2021
 *
 * Artigo: https://blog.eletrogate.com/monitoramento-remoto-de-temperatura-utilizando-a-heltec-esp32-lora/
 *
 * Bibliotecas necessárias:
 *   - Heltec ESP32 (Board Manager)
 */

#include "heltec.h"

#define BAND 915E6  // Frequência LoRa – 915 MHz (Anatel/Brasil)

String packSize = "--";
String packet;

void LoRaDataPrint() {
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawString(0, 1, "Recebendo " + packSize + " bytes");
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(15, 16, "Temperatura");
  Heltec.display->drawString(33, 38, packet);
  Heltec.display->drawString(78, 38, "°C");
  Heltec.display->display();
}

void cbk(int packetSize) {
  packet = "";
  packSize = String(packetSize, DEC);
  for (int i = 0; i < packetSize; i++) {
    packet += (char)LoRa.read();
  }
  LoRaDataPrint();
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Heltec.begin(true, true, true, true, BAND);
  Heltec.display->init();
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->clear();
  Heltec.display->drawString(10, 5, "Iniciado com Sucesso!");
  Heltec.display->drawString(10, 30, "Aguardando os dados...");
  Heltec.display->display();
  Serial.println("Iniciado com Sucesso!");
  Serial.println("Aguardando os dados...");
  delay(1000);
  LoRa.receive();
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    cbk(packetSize);
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    Serial.print("Recebendo a temperatura: ");
    Serial.print(packet);
    Serial.println("°C");
  }
  delay(10);
}
