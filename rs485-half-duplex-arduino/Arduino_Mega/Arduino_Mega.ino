/**
 * @file Arduino_Mega.ino
 * @author Saulo Aislan
 * @brief Comunicação Half-Duplex RS-485 – lado Arduino Mega
 *        Potenciômetro local controla LED no Arduino Uno e vice-versa.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/comunicacao-half-duplex-com-rs-485/
 *
 * Pinagem:
 *   - RO  → pino 10 (SoftwareSerial RX)
 *   - DI  → pino 11 (SoftwareSerial TX)
 *   - DE/RE → pino 12
 *   - Potenciômetro → A0
 *   - LED → pino 13 (PWM)
 */

#include <SoftwareSerial.h>

#define ANALOG_PIN 0
#define ENB_PIN    12
#define LED_PIN    13

SoftwareSerial serialRS(10, 11);  // RO, DI

void setup()
{
  Serial.begin(9600);
  serialRS.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  digitalWrite(LED_PIN, 0);
  digitalWrite(ENB_PIN, HIGH);
  Serial.println("\nComunicação Iniciada!");
}

void loop()
{
  int analogValue = analogRead(ANALOG_PIN);
  int analogData  = map(analogValue, 0, 1023, 0, 200);

  // Transmissão
  serialRS.print('I');
  serialRS.print(analogData);
  serialRS.print('F');
  serialRS.flush();
  delay(5);

  // Recepção
  digitalWrite(ENB_PIN, LOW);
  if (serialRS.available() > 0) {
    if (serialRS.find('I')) {
      int LedValue = serialRS.parseInt();
      if (serialRS.read() == 'F') {
        ledFunc(LedValue);
      }
    }
  }
  digitalWrite(ENB_PIN, HIGH);
}

void ledFunc(int lValue) {
  if (lValue >= 10) {
    analogWrite(LED_PIN, lValue);
  } else {
    analogWrite(LED_PIN, 0);
  }
}
