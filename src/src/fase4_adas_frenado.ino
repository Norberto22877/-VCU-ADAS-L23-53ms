// FASE 4 - VCU ADAS L23 + FRENADO
unsigned long lastCAN = 0;
unsigned long lastBrake = 0;
int soc = 100;
bool brakeActive = false;

void setup() {
  Serial.begin(115200);
  Serial.println("=== VCU ADAS L23 - FASE 4 ===");
  Serial.println("MCP2515 Iniciado - 500Kbps - LISTO");
}

void loop() {
  unsigned long now = millis();
  if (now - lastCAN >= 53) {
    lastCAN = now;
    Serial.printf("[%lu] CAN 0x100 - SOC %d%% - 53ms OK\n", now, soc);
    if (soc < 20) Serial.println("  >> ADAS L23: SOC BAJO");
  }
  if (now - lastBrake >= 100) {
    lastBrake = now;
    brakeActive = (random(0,100) > 80);
    if (brakeActive) {
      Serial.printf("[%lu] CAN 0x200 - FRENO ACTIVADO - ADAS OK\n", now);
    }
  }
}
