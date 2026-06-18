/**
 * @file Arduino_Uno.ino
 * @author Saulo Aislan
 * @brief Comunicação Half-Duplex RS-485 – lado Arduino Uno
 *        Potenciômetro local controla LED no Arduino Mega e vice-versa.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/comunicacao-half-duplex-com-rs-485/
 *
 * Pinagem:
 *   - RO  → pino 2 (SoftwareSerial RX)
 *   - DI  → pino 3 (SoftwareSerial TX)
 *   - DE/RE → pino 4
 *   - Potenciômetro → A0
 *   - LED → pino 10 (PWM)
 */

#include <SoftwareSerial.h>

#define ANALOG_PIN 0
#define ENB_PIN    4   // HIGH = Transmitindo | LOW = Recebendo
#define LED_PIN    10

SoftwareSerial serialRS(2, 3);  // RO, DI

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
