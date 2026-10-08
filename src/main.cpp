#include <Arduino.h>

unsigned long lastLoop = 0;
const int LOOP_MS = 53;
bool systemOK = true;

void setup() {
  Serial.begin(115200);
  Serial.println("MyAutoOS VCU ADAS L2/L3 | 53ms Loop | Iniciado");
  pinMode(2, OUTPUT); // LED estado
}

void loop() {
  unsigned long now = millis();
  if (now - lastLoop >= LOOP_MS) {
    lastLoop = now;
    
    // Simulacion lectura NTC / sensor en pin 34
    int ntc = analogRead(34); // 0 = desconectado
    
    if (ntc < 100) {
      systemOK = false;
      Serial.println("Latencia: 53 ms | ERROR NTC -> ROJO");
      digitalWrite(2, LOW);
    } else {
      systemOK = true;
      Serial.print("Latencia: ");
      Serial.print(LOOP_MS);
      Serial.println(" ms | OK");
      digitalWrite(2, HIGH);
    }
  }
}
