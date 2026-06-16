/**
 * @file Levitador_ultrasonico.ino
 * @author Saulo Aislan
 * @brief Gera onda de 80kHz no sensor ultrassônico para levitação acústica
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/levitacao-ultrassonica-com-arduino/
 *
 * Componentes:
 *   - Arduino Nano V3.0
 *   - Sensor HC-SR04 (desmontado – emissor e receptor separados)
 *   - Módulo H-bridge com CI L293
 */

#if defined(__arm__)
#elif defined(__AVR__)
#else
  #error Placa não suportada. Selecione uma placa da família Arduino/AVR.
#endif

byte TP = 0b10101010;  // Alterna entre 0 e 1 para controle de porta

// Interrupção por comparação de igualdade no TIMER1
// Inverte o valor da porta a cada ciclo
ISR(TIMER1_COMPA_vect)
{
  PORTC = TP;  // Envia valor TP para PORTC
  TP = ~TP;    // Inverte TP para próxima execução
}

void setup()
{
  DDRC = 0b11111111;  // Define todos os pinos PC como OUTPUT

  noInterrupts();

  // Configuração do TIMER1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A  = 200;            // 16MHz / 200 = 80kHz (onda quadrada)

  TCCR1B |= (1 << WGM12);   // Modo CTC
  TCCR1B |= (1 << CS10);    // Prescaler 1 (sem divisão)
  TIMSK1 |= (1 << OCIE1A);  // Habilita interrupção por comparação

  interrupts();
}

void loop() {}
