/**
 * @file DeepSleep_Tempo.ino
 * @author Saulo Aislan
 * @brief Deep Sleep por tempo no ESP8266 – acorda após 30 segundos.
 *        Conecte GPIO16 (D0) ao RST somente APÓS o upload do código.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/
 */

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);
  while (!Serial) {}
  Serial.println("Acordado!");
  Serial.println("Entrando em Deep-Sleep por 30 segundos");
  ESP.deepSleep(30e6);  // 30 segundos em microssegundos
}

void loop() {}
