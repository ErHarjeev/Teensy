#include <Arduino.h>

//float fVariable = 3.14; // single precision number 32 bit (IEEE754)
//double dVarible =  6.28; // double precision number 64 bit (IEEE754)

union fVariableTpye {
  float f;
  int i;
}fVariable ;      // varible of union


void setup() {
  Serial.begin(9600);
  fVariable.f =  3.14;
}

void loop() {
  // print actual fVariable value
  Serial.print(fVariable.f);
  Serial.print(" , ");
  Serial.println(fVariable.i, BIN);
  // and

  // print memory bit pattern of fVariable
}