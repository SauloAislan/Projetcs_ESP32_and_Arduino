/**
 * @file DeepSleep_Botao.ino
 * @author Saulo Aislan
 * @brief Deep Sleep com acordar por botão (RST) no ESP8266.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/
 *
 * Conecte um push button entre GND e o pino RST para acordar manualmente.
 */

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);
  while (!Serial) {}
  Serial.println("Acordado!");
  Serial.println("Entrando em Deep-Sleep indefinido (acorde pelo botão RST)");
  ESP.deepSleep(0);  // Dorme indefinidamente até reset externo
}

void loop() {}
