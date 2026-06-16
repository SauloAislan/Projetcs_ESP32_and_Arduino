/**
 * @file Radar_ultrasonico.ino
 * @author Saulo Aislan
 * @brief Controla servo motor (15° a 165°) e calcula distância com HC-SR04,
 *        enviando dados via serial para visualização no Processing
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/radar-sonar-ultrassonico-para-seus-projetos/
 *
 * Componentes:
 *   - Arduino Nano V3.0
 *   - Sensor HC-SR04 (TRIG=11, ECHO=10)
 *   - MicroServo TowerPro MG90S (pino 12)
 *
 * Visualização:
 *   Abra o arquivo Radar_Processing.pde no Processing IDE.
 *   Altere a porta COM no código Processing para corresponder ao seu Arduino.
 */

#include <Servo.h>

int calcDistancia();

const int trigPin = 11;
const int echoPin = 10;

uint32_t tempo;
int distancia;

Servo servo;

void setup(void)
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servo.attach(12);
}

void loop(void)
{
  for (int i = 15; i <= 165; i++)
  {
    servo.write(i);
    delay(30);
    distancia = calcDistancia();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }

  for (int i = 165; i > 15; i--)
  {
    servo.write(i);
    delay(30);
    distancia = calcDistancia();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}

/**
 * @brief Emite sinal ultrassônico e calcula distância em centímetros
 * @return int distância em cm
 */
int calcDistancia()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  tempo = pulseIn(echoPin, HIGH);
  distancia = tempo * 0.034 / 2;
  return distancia;
}
