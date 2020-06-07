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



/*   Frank's Code 
#include <Arduino.h>
//float fVariable  = 3.14; //single precision number 32bit (IEEE754)
//double dVariable = 6.28; //double precision number 64bit (IEEE754)
double a = 0.3;
double b = 0.0125;
double sumAB = 0.3125;
//0.300000011920928955078125 + 0.012500000186264514923095703125 = 
//0.312500012107193470001220703125‬
void setup() {
  Serial.begin(9600);
}
void loop() {
    if(a+b == sumAB){
       Serial.print("a= "); Serial.print(a,15);
       Serial.print("b= ");Serial.print(b,15);
       Serial.print("sumAB= ");Serial.print(sumAB,15);
       Serial.print("a+b =");Serial.println(a+b,15);
       Serial.println("0.3 + 0.0125 = 0.3125"); 
    } 
    else
    {
        Serial.print("a= "); Serial.print(a,15);
        Serial.print("b= ");Serial.print(b,15);
        Serial.print("sumAB= ");Serial.print(sumAB,15);
        Serial.print("a+b =");Serial.println(a+b,15);
        Serial.println("0.3 + 0.0125 != 0.3125 "); 
    }
    delay(1000);
}  */



//NOTE
/*limitation of float number 
#include <Arduino.h>
//float fVariable  = 3.14; //single precision number 32bit (IEEE754)
//double dVariable = 6.28; //double precision number 64bit (IEEE754)
union fVariableType {
   float f;
   uint32_t i;
} Variable;  
void setup() {
  Serial.begin(9600);
}
void loop() {
  Variable.f = 10e30;
  Serial.print(Variable.i, BIN); Serial.print(", ");
  Variable.f = 10e30 + 1000000;
  Serial.println(Variable.i, BIN);
  Variable.f = 10e30;
  if (Variable.f == (Variable.f +10000000)){
      Serial.print("Sucess!");
      }
  //and
  //print memory bit pattern of fVariable
}*/