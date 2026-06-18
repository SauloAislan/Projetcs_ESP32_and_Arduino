/**
 * @file Controle_de_abastecimento.ino
 * @author Saulo Aislan
 * @brief Controle inteligente de abastecimento de caixa d'água com Arduino Nano,
 *        sensor de fluxo YF-S201, display LCD I2C e relé.
 * @version 0.1
 * @date 2025-02-10
 * @copyright Copyright (c) 2025
 *
 * Artigo: https://blog.eletrogate.com/controle-inteligente-para-abastecimento-de-caixa-dagua-com-arduino-nano/
 *
 * Componentes:
 *   - Arduino Nano V3.0
 *   - Sensor de fluxo YF-S201 (1/2") → pino D3 (interrupção)
 *   - Display LCD 16x2 com módulo I2C (SDA=A4, SCL=A5)
 *   - Módulo relé 5V 1 canal → pino D5
 *   - Botões: Diminuir=D2, Aumentar=D6, Iniciar=D9
 *   - Resistores pull-up 10kΩ nos botões
 *
 * Bibliotecas necessárias:
 *   - LiquidCrystal I2C (Library Manager)
 *   - Wire (built-in)
 */

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const float SENSOR_FLUXO_PIN     = 3;
const float RELE_BOMBA_PIN       = 5;
const float BOTAO_AUMENTAR_PIN   = 6;
const float BOTAO_DIMINUIR_PIN   = 2;
const float BOTAO_INICIAR_PIN    = 9;

const float LIMITE_MAXIMO_LITROS   = 1000;
const float LIMITE_MINIMO_LITROS   = 10;
const float INCREMENTO_LITROS      = 10;
const float FATOR_MULTIPLICADOR_BOTAO = 10;
const float FATOR_CALIBRACAO       = 4.5;

volatile int pulsos = 0;
float litros_desejados = 0;
int incremento_litros  = INCREMENTO_LITROS;
float vazao      = 0;
float volume     = 0;
float volume_total = 0;
unsigned long tempo_antes       = 0;
unsigned long debounce_delay    = 200;
unsigned long ultimo_tempo_botao = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void iniciarAbastecimento(void);

void contadorPulsos(void) {
  pulsos++;
}

void setup() {
  pinMode(SENSOR_FLUXO_PIN,   INPUT);
  pinMode(RELE_BOMBA_PIN,     OUTPUT);
  pinMode(BOTAO_AUMENTAR_PIN, INPUT_PULLUP);
  pinMode(BOTAO_DIMINUIR_PIN, INPUT_PULLUP);
  pinMode(BOTAO_INICIAR_PIN,  INPUT_PULLUP);

  digitalWrite(RELE_BOMBA_PIN, LOW);
  attachInterrupt(digitalPinToInterrupt(SENSOR_FLUXO_PIN), contadorPulsos, FALLING);

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Controle de");
  lcd.setCursor(0, 1);
  lcd.print("Abastecimento!");
  Serial.println("Controle de abastecimento de Caixa d'Água");
}

void loop() {
  if (digitalRead(BOTAO_AUMENTAR_PIN) == LOW &&
      millis() - ultimo_tempo_botao > debounce_delay) {
    litros_desejados += incremento_litros;
    litros_desejados = constrain(litros_desejados, LIMITE_MINIMO_LITROS, LIMITE_MAXIMO_LITROS);
    ultimo_tempo_botao = millis();
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Litros desejados:");
    lcd.setCursor(2, 1); lcd.print(litros_desejados);
    Serial.print("Litros desejados: "); Serial.println(litros_desejados);
  }

  if (digitalRead(BOTAO_DIMINUIR_PIN) == LOW &&
      millis() - ultimo_tempo_botao > debounce_delay) {
    litros_desejados -= incremento_litros;
    litros_desejados = constrain(litros_desejados, LIMITE_MINIMO_LITROS, LIMITE_MAXIMO_LITROS);
    ultimo_tempo_botao = millis();
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Litros desejados:");
    lcd.setCursor(2, 1); lcd.print(litros_desejados);
    Serial.print("Litros desejados: "); Serial.println(litros_desejados);
  }

  if (digitalRead(BOTAO_INICIAR_PIN) == LOW && litros_desejados > 0) {
    iniciarAbastecimento();
  }
}

void iniciarAbastecimento() {
  pulsos       = 0;
  volume_total = 0;

  digitalWrite(RELE_BOMBA_PIN, HIGH);
  Serial.println("Iniciando Abastecimento...");

  while (volume_total < litros_desejados) {
    if (pulsos == 0) continue;

    if ((millis() - tempo_antes) > 1000) {
      vazao = ((1000.0 / (millis() - tempo_antes)) * pulsos) / FATOR_CALIBRACAO;
      Serial.print("Vazão: "); Serial.print(vazao); Serial.println(" L/min");

      volume       = vazao / 60;
      volume_total += FATOR_MULTIPLICADOR_BOTAO * volume;
      Serial.print("Volume Total: "); Serial.print(volume_total); Serial.println(" L");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Vazao: "); lcd.print(vazao, 1); lcd.print(" L/min");
      lcd.setCursor(0, 1);
      lcd.print("Vol: "); lcd.print(volume_total, 1); lcd.print(" L");

      pulsos      = 0;
      tempo_antes = millis();
    }

    if (volume_total >= litros_desejados) break;
  }

  digitalWrite(RELE_BOMBA_PIN, LOW);
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Abastecimento");
  lcd.setCursor(0, 1); lcd.print("Concluido!");
  Serial.println("Abastecimento concluído!");
}
