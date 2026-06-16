# ESP-WROOM-32 com Adaptador ESP32

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/esp-wroom-32-com-adaptador-esp32/)

## Descrição

Tutorial de como montar, soldar e programar o módulo **ESP-WROOM-32** utilizando um **adaptador ESP32** em vez de uma placa de desenvolvimento completa. Esta abordagem cria um circuito mais compacto e barato para produtos finais, eliminando componentes desnecessários como USB e reguladores de tensão.

## Componentes

| Componente | Qtd |
|---|---|
| ESP32-WROOM-32D | 1 |
| Adaptador para ESP32 | 1 |
| Conversor USB para RS232 TTL (CP2102, 5 pinos) | 1 |
| LED vermelho 5mm | 1 |
| Resistor 10kΩ | 1 |
| Ferro de solda Hikari Power-40 | 1 |
| Estanho Hikari HS-63 1mm | — |
| Jumpers macho-fêmea e fêmea-fêmea | — |

## Estrutura do Projeto

```
2022_esp-wroom-32-adaptador/
└── Blink_ESP32/
    └── Blink_ESP32.ino
```

## Como Soldar o ESP32 no Adaptador

1. Limpe as superfícies com álcool isopropílico.
2. Use ferro de ponta fina e estanho fino (≤ 1mm).
3. Aplique flux para melhor fluidez do estanho.
4. Solde dois pinos opostos primeiro para fixar o componente.
5. Complete todos os pinos com movimentos suaves.
6. Verifique continuidade com multímetro.

## Pinagem CP2102 → Adaptador

| CP2102 | Adaptador |
|---|---|
| GND | GND |
| 3V3 | 3V3 |
| TXD | RXD |
| RXD | TXD |

## Modo de Programação

1. **Segure** o botão `IO0` (FLASH)
2. **Pressione e solte** o botão `RESET`
3. **Solte** o botão `IO0`
4. Faça o upload pelo Arduino IDE

## Configuração Arduino IDE

- **Board:** ESP32 Dev Module
- **Port:** COM da CP2102
- **Upload Speed:** 115200

## Como Usar

1. Solde o ESP32-WROOM-32D no adaptador.
2. Conecte o CP2102 conforme a tabela de pinagem.
3. Entre no modo de programação (ver acima).
4. Faça upload de `Blink_ESP32.ino`.
5. Pressione `RESET` para executar normalmente.
6. O LED no GPIO4 piscará a cada 5 segundos com mensagem no Serial Monitor.

## Modo de Operação Normal

Forneça 3,3V e GND com corrente mínima de 500mA e pressione RESET uma vez.
