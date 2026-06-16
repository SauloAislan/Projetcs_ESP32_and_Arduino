# Aprenda a Usar a Solda em Pasta e Soprador Térmico Soldando um ESP32

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/aprenda-a-usar-a-solda-em-pasta-e-soprador-termico-soldando-um-esp32/)

## Descrição

Tutorial prático de **soldagem SMD** com pasta de solda e soprador térmico (hot air), demonstrado soldando um módulo **ESP32-WROOM-32D** em uma PCB. A técnica garante conexões precisas e confiáveis, especialmente em componentes compactos que seriam difíceis de soldar com ferro convencional.

Ideal para quem quer aprender soldagem de componentes SMD (Surface Mount Device) e construir projetos mais profissionais e compactos.

## Materiais Necessários

| Material | Especificação |
|---|---|
| ESP32-WROOM-32D | Módulo principal |
| PCB compatível | Placa de circuito impresso |
| Pasta de solda | Seringa aplicadora |
| Soprador térmico / Hot air station | Ou estação de retrabalho |
| Pinça antistática ESD-11 | Para posicionamento |
| Álcool isopropílico 99% | Limpeza |
| Pincel HK-212 Hikari | Limpeza de flux |
| Malha dessoldadora | Correção de pontes |
| Papel ou pano limpo | Secagem |

## Processo de Soldagem (Passo a Passo)

### Preparação
1. Limpe a PCB com álcool isopropílico e pincel
2. Aguarde secar completamente
3. Aplique pasta de solda em camada fina e uniforme sobre os pads com a seringa

### Posicionamento
4. Posicione o ESP32 com pinça antistática
5. Alinhe cuidadosamente todos os pinos com os pads da PCB
6. Verifique o alinhamento antes de aplicar calor

### Soldagem com Soprador
7. Configure o soprador: **250–350°C**, fluxo de ar médio (posição 4–7)
8. Aplique calor em movimentos circulares suaves ao redor do componente
9. Aguarde a pasta de solda fundir e fluir para os pads
10. Mantenha distância de **3–5 cm** do componente
11. Aguarde o resfriamento natural (não assopre)

### Verificação e Limpeza
12. Inspecione visualmente todas as conexões (use lupa se possível)
13. Use multímetro (continuidade) para confirmar conexões
14. Aplique álcool isopropílico e pincel para remover resíduo de flux
15. Seque com papel ou pano limpo

## Erros Comuns a Evitar

| Erro | Consequência | Como Evitar |
|---|---|---|
| Pasta em excesso | Curtos entre pinos | Aplicar camada fina |
| Temperatura muito alta | Dano ao componente | Nunca ultrapassar 380°C |
| Desalinhamento | Pinos fora dos pads | Verificar com lupa antes |
| Resfriamento forçado | Solda fria / microfissuras | Deixar resfriar naturalmente |

## Vantagens da Técnica

- Solda todos os pinos simultaneamente → mais rápido
- Reduz erros de soldagem em componentes pequenos
- Resultado mais profissional e próximo de linha de produção
- Pode ser aplicada a outros CIs SMD: reguladores, sensores, etc.

## Ferramentas Alternativas

Para soldagem com **ferro de solda** em SMD, veja o projeto:
[2024_adaptadores-smd-para-dip](../2024_adaptadores-smd-para-dip/README.md)
