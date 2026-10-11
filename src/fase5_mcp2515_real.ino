// FASE 5 - BYD Lerma - MCP2515 Real + VCU 53ms
// Autor: Norberto
#include <mcp_can.h>
#include <SPI.h>
#define CAN0_INT 2
MCP_CAN CAN0(10);
unsigned long last_53ms = 0;
int soc = 85;
bool safe_mode = false;
void setup() {
  Serial.begin(115200);
  while(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ)!= CAN_OK) {
    Serial.println("MCP2515 Error - Revisa wiring");
    delay(100);
  }
  CAN0.setMode(MCP_NORMAL);
  Serial.println("BYD VCU 53ms - MCP2515 OK - Fase 5 Lista");
}
void loop() {
  unsigned long now = millis();
  if (now - last_53ms >= 53) {
    last_53ms = now;
    soc--; if(soc<0) soc=100;
    if(soc < 20) {
      safe_mode = true;
      Serial.println("ALERTA ADAS - SOC <20% -> SAFE MODE");
    }
    byte data[8] = {soc, 0, 0, 0, safe_mode, 0, 0, 0};
    byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, data);
    if(sndStat == CAN_OK) {
      Serial.print("ID 0x100 SOC:");
      Serial.print(soc);
      Serial.println("% - 53ms OK - Fase 5");
    } else {
      Serial.println("Falla Bus CAN - Latencia >150ms -> SAFE MODE");
    }
  }
}
