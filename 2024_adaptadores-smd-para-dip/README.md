# Dicas para Usar Adaptadores SMD para DIP em seus Projetos

Publicado em: **2024** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/dicas-para-usar-os-adaptadores-smd-para-dip-em-seus-projetos/)

## Descrição

Guia prático para utilizar **adaptadores SMD para DIP**, permitindo que componentes em encapsulamento SMD (Surface Mount Device) sejam usados em protoboards e PCBs com furos passantes. O artigo demonstra o processo de soldagem e um circuito de exemplo com o CI **LM393** (comparador de tensão).

Componentes SMD são cada vez mais comuns em projetos modernos devido ao tamanho compacto e eficiência, mas nem sempre é prático soldá-los diretamente em protoboards.

## Componentes

| Componente | Qtd |
|---|---|
| Adaptador SMD para DIP (tamanho adequado ao CI) | 1 |
| CI LM393 SMD (comparador de tensão) | 1 |
| Resistor 1kΩ | 1 |
| LED vermelho 5mm | 1 |
| Potenciômetro linear 10kΩ | 2 |
| Header pino macho 180° (40 pinos) | 1 |
| Protoboard 400 pontos | 2 |
| Ferro de solda | 1 |
| Flux para soldagem | — |
| Multímetro (opcional) | 1 |
| Pinça antistática ESD-11 (opcional) | 1 |

## Técnica de Soldagem (Ferro de Solda)

1. Selecione o adaptador correto para o encapsulamento do CI
2. Aplique flux nos pads do adaptador
3. Posicione o CI com pinça (alinhe os pinos com precisão)
4. Solde dois pinos opostos para fixar
5. Para CIs multi-pino: use técnica de *drag soldering* com flux contínuo
6. Verifique continuidade com multímetro
7. Instale o header de pinos para uso em protoboard

## Técnica de Soldagem (Soprador Térmico)

1. Limpe a PCB com álcool isopropílico
2. Aplique estanho nos pads com ferro de solda
3. Posicione o CI com pinça antistática
4. Configure o soprador para 150–200°C
5. Mova o soprador lentamente ao redor do componente (3–5 cm de distância)
6. Aguarde o resfriamento natural
7. Inspecione com lupa

## Circuito de Exemplo (LM393)

O LM393 é um **comparador de tensão duplo**. O LED acende quando a tensão na entrada não-inversora (pino 3) supera a entrada inversora (pino 2):

```
Potenciômetro 1 → Pino 3 (não-inversor)
Potenciômetro 2 → Pino 2 (inversor)
LED → Saída (pino 1) com resistor 1kΩ
```

Ajuste os potenciômetros e observe o LED ligar/desligar conforme os níveis de tensão.

## Dicas Importantes

- **Escolha o adaptador certo:** verifique o número de pinos e o espaçamento (pitch) do encapsulamento
- **Use flux:** melhora muito a qualidade da solda em pads SMD
- **Confirme com multímetro:** teste continuidade entre pinos e ausência de curtos
- **Temperatura correta:** ferro muito quente danifica o componente; muito frio = solda fria
