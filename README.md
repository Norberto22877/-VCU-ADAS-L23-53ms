# MyAutoOS-Technologies | VCU ADAS L2/L3 53ms

Bucle de Control Determinista 53ms | Listo para Producción EV
FASE 1: VCU + BMS + Control Térmico validado

**Repo:** github.com/Norberto22877/-VCU-ADAS-L23-53ms
**Contacto:** engineering@myautoos.tech
**Ruta:** Michoacán -> BYD Lerma | 13 Oct 2026

### Validación
- Latencia <53ms garantizada (bucle determinista)
- Fail-safe NTC desconectado -> ROJO / LED OFF
- NTC OK -> Latencia 53ms OK / LED ON (GPIO2)
- Listo para PoC HIL en Lerma

### Estructura
- platformio.ini - Config ESP32 DevKit
- src/main.cpp - Loop 53ms validado

### Evidencia
Serial Monitor: Latencia: 53 ms | OK
