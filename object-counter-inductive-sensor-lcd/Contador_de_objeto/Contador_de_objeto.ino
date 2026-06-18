/**
 * @file Contador_de_objeto.ino
 * @author Saulo Aislan
 * @brief Contador de objetos metálicos com sensor indutivo PNP e display LCD I2C.
 * @version 0.1
 * @date 2024-09-21
 * @copyright Copyright (c) 2024
 *
 * Artigo: https://blog.eletrogate.com/contador-de-objetos-com-arduino-sensor-indutivo-e-display-lcd/
 *
 * Componentes:
 *   - ESP32 DevKitC (30 pinos)
 *   - Sensor indutivo PNP LJ12A3-4-Z/BY (12V via regulador LM2596)
 *   - Display LCD 16x2 com módulo I2C (SDA=GPIO21, SCL=GPIO22)
 *   - Módulo Step-Down LM2596 (12V → saída para sensor)
 *   - Resistor pull-down 1kΩ no pino do sensor
 *
 * Pinagem:
 *   Sensor (fio marrom → VCC regulador, azul → GND, preto → GPIO12)
 *   LCD SDA → GPIO21 | LCD SCL → GPIO22
 *
 * Bibliotecas necessárias:
 *   - LiquidCrystal I2C (Library Manager: "LiquidCrystal I2C by Arduino")
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int sensorPin = 12;
volatile int count = 0;
int lastState = LOW;

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Altere para 0x27 se necessário

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Contador de");
  lcd.setCursor(0, 1);
  lcd.print("objetos");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Aguardando");
  lcd.setCursor(0, 1);
  lcd.print("Objetos!");
}

void loop() {
  int currentState = digitalRead(sensorPin);

  if (currentState == HIGH && lastState == LOW) {
    count++;
    Serial.println("Objeto detectado! Contagem: " + String(count));

    lcd.setCursor(0, 0);
    lcd.print("Total de objetos");
    lcd.setCursor(0, 1);
    lcd.print("contados: ");
    lcd.print(count);
  }

  lastState = currentState;
  delay(50);
}
