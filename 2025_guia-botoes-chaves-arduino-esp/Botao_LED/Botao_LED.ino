/**
 * @file Botao_LED.ino
 * @author Saulo Aislan
 * @brief Exemplo básico: botão com resistor pull-down controla um LED.
 *        Compatível com Arduino e ESP32/ESP8266.
 * @version 0.1
 * @date 2025
 * @copyright Copyright (c) 2025
 *
 * Artigo: https://blog.eletrogate.com/guia-completo-sobre-botoes-e-chaves-para-arduino-e-esp/
 *
 * Componentes:
 *   - Arduino Uno / ESP32 / ESP8266
 *   - 1× Push Button
 *   - 1× LED
 *   - Resistor pull-down (ligado entre pino do botão e GND)
 *
 * Ligação:
 *   Botão: um terminal → 5V/3.3V, outro terminal → pino 2 + resistor pull-down para GND
 *   LED: ânodo → pino 13 (com resistor limitador), cátodo → GND
 *
 * Tipos de botões abordados no artigo:
 *   - Push button momentâneo (2 e 4 pinos)
 *   - Mini rocker switch (KCD11-101)
 *   - Micro switch SS12D00G4
 *   - DIP switch
 *   - Chave fim de curso (limit switch)
 *   - Botão com trava (latching, PBS-16A)
 */

const int botao = 2;
const int led   = 13;

void setup() {
  pinMode(botao, INPUT);   // Resistor pull-down externo
  pinMode(led, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(botao);

  if (estadoBotao == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
