/**
 * @file Meu_Robo_Otto.ino
 * @author Saulo Aislan
 * @brief Robô Otto com Arduino Nano – evita obstáculos com sensor ultrassônico
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/montando-seu-robo-otto-com-arduino-nano/
 * Baseado em: https://www.ottodiy.com/
 *
 * Componentes:
 *   - Arduino Nano V3.0
 *   - Shield expansão Arduino Nano
 *   - 4× Micro Servo 9g SG90 TowerPro (pinos 2, 3, 4, 5)
 *   - Sensor HC-SR04 (TRIG=8, ECHO=9)
 *   - Buzzer ativo 3V (pino 13)
 *   - Bateria 9V + regulador Step-Down (saída 5V)
 *
 * Bibliotecas necessárias:
 *   - Otto (Library Manager: "Otto DIY")
 */

#include <Otto.h>
Otto Otto;

#define PernaEsq 2
#define PernaDir 3
#define PeEsq   4
#define PeDir   5
#define Buzzer  13
#define Trigger  8
#define Echo     9

long ultrasound()
{
  long duration, distance;
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration / 58;
  return distance;
}

void setup() {
  Otto.init(PernaEsq, PernaDir, PeEsq, PeDir, true, Buzzer);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  Otto.swing(2, 1000, 20);
  Otto.shakeLeg(1, 2000, -1);
}

void loop()
{
  if (ultrasound() <= 15)
  {
    Otto.sing(S_surprise);
    Otto.walk(2, 1000, -1);
    Otto.turn(4, 1000, 1);
  }
  Otto.walk(1, 1000, 1);
}
