/**
 * @file PC_Arduino_RS485.ino
 * @author Saulo Aislan
 * @brief Firmware para receber dados via RS485 enviados pelo computador,
 *        exibir no LCD 16x2 e acender ou apagar um LED.
 * @version 1.0
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/comunicacao-com-conversor-usb-rs485/
 *
 * Componentes:
 *   - Arduino Uno R3
 *   - Módulo conversor TTL para RS485
 *   - Conversor Mini USB para RS485
 *   - Display LCD 16x2 com módulo I2C (endereço 0x3F)
 *   - LED vermelho com resistor 1kΩ
 *
 * Pinagem RS485:
 *   - RO  → pino 2 (SoftwareSerial RX)
 *   - DI  → pino 3 (SoftwareSerial TX)
 *   - DE/RE → pino 4 (LOW = modo recepção)
 *   - LED → pino 13
 *
 * Bibliotecas necessárias:
 *   - LiquidCrystal_I2C (Library Manager)
 *   - Wire (built-in)
 *   - SoftwareSerial (built-in)
 *
 * Envie "LED ON" ou "LED OFF" pelo terminal (ex.: Termite) via USB-RS485.
 */

#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define ENB_PIN  4
#define PinLED  13

LiquidCrystal_I2C lcd(0x3F, 16, 2);
SoftwareSerial serialRS(2, 3);  // RO, DI

char ledStatus;
const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];
String strTemp = "";

void setup() {
  Serial.begin(9600);
  serialRS.begin(9600);
  lcd.init();
  pinMode(PinLED, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  digitalWrite(ENB_PIN, LOW);  // Modo recepção

  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("  Comunicacao  ");
  lcd.setCursor(0, 1);
  lcd.print("     RS485   ");
  delay(1500);
}

void loop() {
  if (serialRS.available() > 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recebendo:");
    lcd.setCursor(0, 1);

    int rlen = serialRS.readBytesUntil('\n', buf, BUFFER_SIZE);
    for (int i = 0; i < rlen - 1; i++) {
      strTemp += buf[i];
    }

    lcd.print(strTemp);
    ledFunc(strTemp);
  }
  strTemp = "";
}

/**
 * @brief Acende ou apaga o LED conforme mensagem recebida
 */
void ledFunc(String ledNewStatus) {
  if (ledNewStatus == "LED ON" || ledNewStatus == "LED On") {
    digitalWrite(PinLED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LED Aceso!");
  } else if (ledNewStatus == "LED OFF" || ledNewStatus == "LED Off") {
    digitalWrite(PinLED, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LED Apagado!");
  }
}
