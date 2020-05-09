#include <Arduino.h>

u_int8_t uINT_Variable_MIN = 0;
u_int8_t uINT_Variable_MAX = -0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  Serial.print("DEC: ");
  Serial.print(uINT_Variable_MIN, DEC);
  Serial.print(", BIN: ");
  Serial.println(uINT_Variable_MIN, BIN);
  delay(1000);

   Serial.print("DEC: ");
  Serial.print(uINT_Variable_MIN, DEC);
  Serial.print(", BIN: ");
  Serial.println(uINT_Variable_MIN, BIN);
  delay(1000);
  // put your main code here, to run repeatedly:
}