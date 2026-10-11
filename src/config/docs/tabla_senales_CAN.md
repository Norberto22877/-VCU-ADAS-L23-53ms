# Tabla de Señales CAN - VCU BYD Lerma

| ID | Nombre | DLC | Señal | Bits | Rango | Unidad |
|---|---|---|---|---|---|---|
| 0x100 | VCU_Traction | 8 | SOC | 0-7 | 0-100 | % |
| 0x100 | VCU_Traction | 8 | Torque_Req | 8-15 | 0-255 | Nm |
| 0x100 | VCU_Traction | 8 | Safe_Mode | 32 | 0/1 | boolean |
| 0x200 | ADAS_Brake | 8 | Brake_Req | 0-7 | 0-100 | % |
| 0x200 | ADAS_Brake | 8 | AEB_Status | 8 | 0/1 | boolean |
