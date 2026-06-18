/**
 * @file Carregador_Solar.ino
 * @author Saulo Aislan
 * @brief Demonstra sistema solar autônomo: painel → TP4056 → bateria Li → ESP32.
 *        LED pisca para indicar que o ESP32 está operando com energia solar.
 * @version 0.1
 * @date 2025
 * @copyright Copyright (c) 2025
 *
 * Artigo: https://blog.eletrogate.com/carregador-de-bateria-solar-para-seu-projetos-com-esp32-ou-arduino/
 *
 * Componentes:
 *   - ESP32 (30 pinos)
 *   - Módulo TP4056 com proteção (entrada USB-C)
 *   - Bateria Li-Ion recarregável
 *   - Painel solar 5,5V 240mA
 *   - LED vermelho + resistor 1kΩ
 *   - Diodo 1N4007 (proteção contra inversão no painel)
 *
 * Ligação:
 *   Painel solar → diodo 1N4007 → TP4056 IN+/IN-
 *   Bateria → TP4056 BAT+/BAT-
 *   TP4056 OUT+ → ESP32 VIN | OUT- → GND
 *   LED → GPIO4 (pino 4) com resistor 1kΩ em série
 */

#define LED_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
