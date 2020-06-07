#include <Arduino.h>
#define digPin 16
#define DACPin A14
//Function Prototypes
void PrintInfo(uint16_t DAC_value, boolean digValue);
int16_t count = 1023; // 2^10 -1  (see DAC resolution)
void setup() {
    // Init Serial
    Serial.begin(115200);
    // Configure OutputPin
    pinMode(digPin, INPUT);
    // Configure DAC resolution
    analogWriteRes(10);
}
void loop() {
    //Output DAC values triangle
    //UP
    for (uint16_t i = 0; i < count; i++)
    {
        analogWrite(DACPin,i);
        PrintInfo(i,digitalRead(digPin));
        delay(10);
    }
    //DOWN
    for (uint16_t i = count; i > 0; i--)
    {
        analogWrite(DACPin,i);
        PrintInfo(i,digitalRead(digPin));
        delay(10);
    }
}
void PrintInfo(uint16_t DAC_value, boolean digValue){
        DAC_value = map(DAC_value, 0, 1023, 0, 3300); //map mv
        Serial.print((float)DAC_value);
        Serial.print(",");
        Serial.println(digValue * 3300);
        Serial.flush();
}






/* Check Digital Input for different levels of voltages By Harjeev
#include <Arduino.h>
#define DAC_Pin A14
#define input_Pin A0
uint8_t DAC_Input = 0; 

void setup() {
  analogWriteResolution(8);
  Serial.begin(115200);
  pinMode(input_Pin,INPUT_PULLUP);
}

void loop() {
   
  static bool Ramp = 0;       // 0 for upward 1 for downward
  uint8_t voltage_level = 0;    // flag to read the digital input level
  analogWrite(DAC_Pin, DAC_Input);  
  Serial.print(DAC_Input);
  Serial.print(",");
  
  if(digitalRead(input_Pin))
  {
    voltage_level = 255;
  }
  else
  {
    voltage_level = 0;
  }
  
  Serial.println(voltage_level);
  Serial.flush();
  delay(10);


  if (Ramp)
  {
    DAC_Input--; 
    if(DAC_Input == 0)
    {
      Ramp = 0 ;
    }
  }
  else
  {
    DAC_Input++;
    if(DAC_Input == 255)
    {
      Ramp = 1 ;
    }
  }
}


*/





