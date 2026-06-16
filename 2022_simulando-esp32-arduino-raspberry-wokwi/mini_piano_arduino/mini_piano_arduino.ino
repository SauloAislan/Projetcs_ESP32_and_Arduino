/**
 * @file mini_piano_arduino.ino
 * @author Saulo Aislan
 * @brief Mini Piano com Arduino UNO – 8 botões geram notas musicais no buzzer.
 *        Simulado no Wokwi: https://wokwi.com
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/simulando-esp32-arduino-e-raspberry-pi-com-o-wokwi/
 *
 * Componentes:
 *   - Arduino UNO R3
 *   - 8× Push Button (pinos 4, 5, 6, 7, 9, 10, 11, 12)
 *   - 1× Buzzer ativo (pino 8)
 *
 * Inclua o arquivo pitches.h (disponível nos exemplos do Arduino IDE:
 *   Arquivo > Exemplos > 02.Digital > toneMelody > pitches.h)
 */

#include "pitches.h"

#define BUZZER_PIN 8

const uint8_t buttonPins[] = {12, 11, 10, 9, 7, 6, 5, 4};
const int buttonTones[]    = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
                               NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup() {
  for (uint8_t i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int pitch = 0;
  for (uint8_t i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      pitch = buttonTones[i];
    }
  }
  if (pitch) {
    tone(BUZZER_PIN, pitch);
  } else {
    noTone(BUZZER_PIN);
  }
}
