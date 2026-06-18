/**
 * @file Motor_Passo_DRV8825.ino
 * @author Saulo Aislan
 * @brief Controla motor de passo NEMA 17 com driver DRV8825 e Arduino Uno.
 *        Gira no sentido horário (lento) e anti-horário (rápido).
 * @version 0.1
 * @date 2026
 * @copyright Copyright (c) 2026
 *
 * Artigo: https://blog.eletrogate.com/driver-drv8825-guia-completo-para-projetos-com-arduino-e-motor-de-passo/
 *
 * Componentes:
 *   - Arduino Uno R3
 *   - Driver DRV8825
 *   - Motor de passo NEMA 17 (4,2 kgf.cm / 1,7A)
 *   - Capacitor eletrolítico 100µF/25V (próximo à alimentação do driver)
 *   - Fonte 12V 1A
 *
 * Pinagem DRV8825 → Arduino:
 *   RST → 5V | SLP → 5V | GND → GND
 *   STEP → pino 3 | DIR → pino 2
 *   Motor: A1, A2, B1, B2 → bobinas do NEMA 17
 *
 * Microstepping (pinos M0, M1, M2):
 *   LOW/LOW/LOW   = Full step
 *   HIGH/LOW/LOW  = 1/2 step
 *   LOW/HIGH/LOW  = 1/4 step
 *   HIGH/HIGH/LOW = 1/8 step
 *   LOW/LOW/HIGH  = 1/16 step
 *   HIGH/HIGH/HIGH = 1/32 step
 */

const int dirPin  = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;  // Full step, NEMA 17 = 1.8°/step

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin,  OUTPUT);
}

void loop() {
  // Gira no sentido horário – lento
  digitalWrite(dirPin, HIGH);
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);

  // Gira no sentido anti-horário – rápido
  digitalWrite(dirPin, LOW);
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
