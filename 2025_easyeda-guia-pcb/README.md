# EasyEDA: Guia Definitivo para Projetar PCBs

Publicado em: **2025** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/easyeda-o-guia-definitivo-para-projetar-pcbs/)

## Descrição

Guia completo para usar o **EasyEDA** — plataforma online gratuita para design de PCBs (Printed Circuit Boards). Do esquemático à fabricação, o tutorial cobre todo o fluxo de trabalho para criar placas de circuito impresso profissionais, desde iniciantes até projetos intermediários.

O EasyEDA permite criar PCBs sem instalar software, com integração direta à fabricante **JLCPCB** para pedidos com um clique.

## Acesso

- **EasyEDA:** [easyeda.com](https://easyeda.com)
- **JLCPCB:** [jlcpcb.com](https://jlcpcb.com)

## Fluxo de Trabalho

```
[Esquemático] → [Converter para PCB] → [Posicionar Componentes] 
→ [Rotear Trilhas] → [DRC] → [Gerar Gerber] → [Fabricar]
```

## Configurações Recomendadas

| Parâmetro | Valor |
|---|---|
| Espessura mínima de trilha | 0,254mm (10 mil) |
| Clearance mínimo | 0,2mm |
| Espessura da placa | 1,6mm |
| Via mínima | 0,6mm pad / 0,3mm drill |
| Trilha de sinal | 0,254mm |
| Trilha de alimentação | ≥ 0,5mm |

## Passo a Passo

### 1. Criar Projeto
1. Acesse [easyeda.com](https://easyeda.com) e crie uma conta
2. Selecione "Standard online"
3. Clique em "New Project"

### 2. Desenhar Esquemático
1. Insira componentes via biblioteca (LCSC ou Common Library)
2. Use a ferramenta "Wire" para conectar os pinos
3. Aplique símbolos VCC/GND para distribuição de energia
4. Rotule os componentes

### 3. Converter para PCB
1. Design → Convert to PCB
2. Configure número de camadas e dimensões da placa
3. Revise o "Ratsnest" (conexões lógicas)

### 4. Layout da PCB
1. Posicione componentes estrategicamente (agrupe por função)
2. Conectores nas bordas da placa
3. Selecione TopLayer ou BottomLayer para rotear
4. Use a ferramenta "Track" para desenhar trilhas de cobre
5. Ângulos de 45° em vez de 90°
6. "Via" para conexões entre camadas

### 5. Plano de Ground (Copper Pour)
1. Selecione a camada desejada
2. Ferramentas → Copper Area
3. Selecione GND como net
4. Isso reduz EMI e melhora dissipação térmica

### 6. Design Rule Check (DRC)
1. Design → Design Rule
2. Clique em "Check DRC"
3. Corrija todos os erros antes de gerar os arquivos

### 7. Gerar Arquivos Gerber
1. Fabrication → Generate PCB Fabrication File
2. Ou "One-click Order PCB/SMT" para pedido direto no JLCPCB

## Dicas

- **Componentes LCSC:** facilita integração com serviço de montagem SMT da JLCPCB
- **Visualização 3D:** View → 3D View para conferir aparência final
- **Roteamento híbrido:** route manualmente trilhas críticas, use Autorouter para o restante
- **Silk Screen:** posicione labels sem sobrepor pads ou vias
