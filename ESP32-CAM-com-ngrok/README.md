# ESP32-CAM Acessado Remotamente com Ngrok

Publicado em: **2022** | Autor: **Saulo Aislan**
Artigo original: [blog.eletrogate.com](https://blog.eletrogate.com/esp32-cam-acessado-remotamente-com-ngrok/)

## Descrição

Câmera de segurança com **ESP32-CAM** acessível de qualquer lugar do mundo via **ngrok** — uma ferramenta que cria um túnel seguro entre o servidor local e a internet. O sistema transmite vídeo em tempo real no formato MJPEG com proteção por autenticação básica.

## Componentes

| Componente | Qtd |
|---|---|
| ESP32-CAM (AI Thinker) com câmera OV2640 2MP | 1 |
| Conversor USB para RS232 TTL FTDI FT232RL | 1 |
| Protoboard 400 pontos | 1 |
| Jumpers macho-macho (20cm) | 20 |
| Fonte 5V 1A (recomendado) | 1 |

## Estrutura do Projeto

```
2022_esp32-cam-ngrok/
└── esp32Cam/
    ├── esp32Cam.ino      ← Firmware principal
    ├── camera_pins.h     ← Definição de pinos por modelo
    └── src/
        ├── OV2640.cpp    ← Baixe do GitHub: Picaio/espcam
        └── OV2640.h
```

## Bibliotecas Externas

Baixe os arquivos `OV2640.cpp` e `OV2640.h` do repositório:
[github.com/Picaio/espcam](https://github.com/Picaio/espcam)

Coloque-os na pasta `esp32Cam/src/`.

## Configuração

1. Edite `esp32Cam.ino` e substitua:
   ```cpp
   #define SSID1 "SEU_SSID"
   #define PWD1  "SUA_SENHA"
   ```

2. No Arduino IDE:
   - **Board:** AI Thinker ESP32-CAM
   - **PSRAM:** Enabled

## Programação (via FTDI)

| ESP32-CAM | FTDI |
|---|---|
| GND | GND |
| 5V | VCC |
| U0R (RX) | TX |
| U0T (TX) | RX |
| IO0 | GND (modo flash) |

> Conecte IO0 ao GND apenas durante o upload. Desconecte após programar.

## Configuração Ngrok

1. Crie conta em [ngrok.com](https://ngrok.com) e obtenha o token.
2. Configure:
   ```
   ngrok config add-authtoken SEU_TOKEN
   ```
3. Exponha o servidor com autenticação:
   ```
   ngrok http --basic-auth="usuario:senha" IP_ESP32:8880
   ```
4. Use a URL gerada pelo ngrok para acessar remotamente.

## Acesso ao Stream

- **Local:** `http://IP_DO_ESP32:8880/`
- **Remoto:** URL fornecida pelo ngrok

> Se houver erro de header HTTP, aumente `CONFIG_HTTPD_MAX_REQ_HDR_LEN` para 1024 no sdkconfig.

## Nota de Energia

O ESP32-CAM consome corrente alta durante streaming. Use **fonte 5V 1A** dedicada para evitar instabilidades causadas pela limitação de corrente USB.
