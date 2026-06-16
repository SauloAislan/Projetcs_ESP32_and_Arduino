# Carregador de Bateria Solar para Projetos com ESP32 ou Arduino

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/carregador-de-bateria-solar-para-seu-projetos-com-esp32-ou-arduino/)

## Descrição

Sistema de alimentação solar autônomo para projetos com **ESP32 ou Arduino**. O painel solar carrega uma bateria de lítio via módulo **TP4056** (com proteção integrada), que por sua vez alimenta o microcontrolador continuamente — mesmo sem sol, a bateria mantém o sistema operacional.

Perfeito para projetos IoT em locais sem acesso à rede elétrica, como sensores remotos, estações meteorológicas e automação rural.

## Componentes

| Componente | Qtd |
|---|---|
| ESP32 (30 pinos) | 1 |
| Bateria Li-Ion recarregável | 1 |
| Módulo TP4056 com proteção (USB-C) | 1 |
| Painel solar 5,5V 240mA | 1 |
| LED vermelho 5mm | 1 |
| Resistor 1kΩ | 1 |
| Diodo 1N4007 | 1 |
| Placa fenolite perfurada 7×5cm (opcional) | 1 |
| Bornes KRE 2 vias (opcional) | 2 |

## Estrutura do Projeto

```
2025_carregador-solar-esp32/
└── Carregador_Solar/
    └── Carregador_Solar.ino
```

## Diagrama de Ligação

```
[Painel Solar] → [Diodo 1N4007] → [TP4056 IN+/IN-]
                                    ↓
                              [Bateria Li-Ion]
                              [TP4056 BAT+/BAT-]
                                    ↓
                              [TP4056 OUT+/OUT-]
                                    ↓
                              [ESP32 VIN/GND]
                                    ↓
                           [LED → GPIO4 → Resistor 1kΩ → GND]
```

## Como Montar

1. **Painel solar → TP4056:** Conecte o positivo do painel em série com o diodo 1N4007 ao IN+ do TP4056. O diodo evita descarga reversa no painel à noite.
2. **Bateria → TP4056:** Conecte ao BAT+ e BAT-.
3. **TP4056 → ESP32:** Conecte OUT+ ao VIN e OUT- ao GND do ESP32.
4. **LED:** Ânodo → GPIO4, Cátodo → Resistor 1kΩ → GND.
5. **Upload:** Faça upload de `Carregador_Solar.ino`.

## Indicadores do TP4056

| LED TP4056 | Significado |
|---|---|
| Vermelho aceso | Carregando |
| Azul/Verde aceso | Carga completa |

## Upload do Código

Como o ESP32 é alimentado pelo TP4056, para programar use o cabo USB do próprio ESP32 (desconecte da saída do TP4056 se necessário) ou use um conversor FTDI externo.

## Aplicações

- Sensores remotos em campos agrícolas
- Estações meteorológicas sem rede elétrica
- Monitoramento de reservatórios em locais remotos
- Projetos IoT em áreas rurais
