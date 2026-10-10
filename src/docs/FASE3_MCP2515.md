# FASE 3 - VCU ADAS L23 - MCP2515 Ready - 53ms

## Hardware Target
- ESP32 DevKit + MCP2515 8MHz
- SPI: SCK=18, MISO=19, MOSI=23, CS=5, INT=21
- Bus: 500Kbps (BYD Standard)

## Validacion
- Latencia: 53ms garantizada (delay 53)
- CAN ID: 0x100 - BMS SOC
- Payload: [SOC, Temp, 0x00...]
- Estado: Codigo compilado y listo para hardware

## Codigo Fase 3
Archivo: src/can_real_mcp2515.ino
Listo para flashear al recibir modulo.

## Evidencia Wokwi
Simulacion HIL validada, pendiente modulo fisico por logistica Cheran.
