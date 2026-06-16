/**
 * @file Blink_ESP32.ino
 * @author Saulo Aislan
 * @brief Blink com ESP-WROOM-32 usando adaptador + conversor CP2102.
 *        Demonstra upload de firmware no módulo sem placa de desenvolvimento.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/esp-wroom-32-com-adaptador-esp32/
 *
 * Componentes:
 *   - ESP32-WROOM-32D
 *   - Adaptador ESP32
 *   - Conversor USB para RS232 TTL (CP2102, 5 pinos)
 *   - LED vermelho + resistor 10kΩ
 *
 * Modo de programação:
 *   1. Segure o botão IO0 (FLASH)
 *   2. Pressione e solte o botão RESET
 *   3. Solte o botão IO0
 *   4. Faça o upload pelo Arduino IDE
 *
 * Pinagem CP2102 → Adaptador:
 *   GND → GND | 3V3 → 3V3 | TXD → RXD | RXD → TXD
 */

#define LEDPIN 4

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  Serial.println("Acende o LED!");
  digitalWrite(LEDPIN, HIGH);
  delay(5000);
  Serial.println("Apaga o LED!");
  digitalWrite(LEDPIN, LOW);
  delay(5000);
}
