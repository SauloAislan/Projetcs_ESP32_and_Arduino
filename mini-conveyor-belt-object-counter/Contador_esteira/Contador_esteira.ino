/**
 * @file Contador_esteira.ino
 * @author Saulo Aislan
 * @brief Mini esteira industrial com contador de objetos metálicos,
 *        sensor indutivo NPN e display LCD I2C.
 * @version 0.1
 * @date 2026-03-02
 * @copyright Copyright (c) 2026
 *
 * Artigo: https://blog.eletrogate.com/mini-esteira-industrial-com-contador-de-objetos-e-display-lcd/
 *
 * Componentes eletrônicos:
 *   - Arduino Uno R3
 *   - Motor DC 3-6V com caixa de redução e eixo duplo
 *   - Sensor indutivo NPN LJ12A3-4-Z/BX → pino 2 (interrupção)
 *   - Display LCD 16x2 com módulo I2C (SDA=A4, SCL=A5)
 *   - Mini chave gangorra (liga/desliga motor)
 *   - Fonte 12V 1A
 *
 * Componentes mecânicos:
 *   - 2× Perfil de alumínio 20x20 (45cm)
 *   - 4× Rolamentos radiais 6804 (20×32×7mm)
 *   - Tecido TNT como esteira (105cm × 8cm)
 *   - Peças impressas em 3D (suportes, rolos, pés, suporte do sensor)
 *
 * Bibliotecas necessárias:
 *   - LiquidCrystal I2C (Library Manager)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define SENSOR_PIN 2  // Pino de interrupção (INT0 no UNO)

volatile unsigned long contador = 0;
volatile bool objetoDetectado   = false;

unsigned long ultimoPulso    = 0;
const int debounceTime       = 150;  // ms

void contarObjeto();

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); lcd.print("Contador de");
  lcd.setCursor(0, 1); lcd.print("objetos");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0); lcd.print("Aguardando");
  lcd.setCursor(0, 1); lcd.print("Objetos!");
  delay(1000);
  lcd.clear();

  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), contarObjeto, FALLING);
}

void loop() {
  if (objetoDetectado) {
    objetoDetectado = false;

    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Qtd Objetos:");
    lcd.setCursor(0, 1); lcd.print(contador);
  }
}

void contarObjeto() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - ultimoPulso > debounceTime) {
    contador++;
    objetoDetectado = true;
    ultimoPulso = tempoAtual;
  }
}
