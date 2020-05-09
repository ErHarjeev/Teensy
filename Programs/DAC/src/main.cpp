// Digital To Analog Converter
#include <Arduino.h>
#define DAC_Pin A14
#define ADC_Pin A0
void setup() {
  analogWriteResolution(8);
  analogReadResolution(8);
  Serial.begin(115200);
}
void loop() {
  static uint32_t previousMillis = 0;  
  static int32_t counter = 0;
  
  uint32_t DAC_Input = 0;
  
  DAC_Input = sin((double)counter/100) * 127 + 127;
  
  analogWrite(DAC_Pin, DAC_Input);  //8bit DAC 0...2^8-1 0...255 0..3.3V
  uint32_t ADC_RAW_Value =  analogRead(ADC_Pin); //8bit DAC 0...2^8-1 0...255 0..3.3V
  
  float ADC_Value_Volt = (double)map(ADC_RAW_Value,0,255,0,3300) / 1000;
  
  Serial.print(ADC_RAW_Value);
  Serial.print(",");
  Serial.println(ADC_Value_Volt);
  Serial.flush();

  while((micros() - previousMillis) <= 10000 ){
      //do nothing
  }
  
  previousMillis = micros();
  counter++;
}




/*#include <Arduino.h>

#define DAC_Pin A14
#define ADC_Pin A0

void setup() {
  analogWriteResolution(8);
  analogReadResolution(8);
  Serial.begin(115200);
 
}

void loop() {

  static uint8_t counter = 0;
  analogWrite(DAC_Pin, counter);
  uint8_t ADC_Raw_Value = analogRead(ADC_Pin);
  Serial.write(ADC_Raw_Value);
  //Serial.print("\n");
  Serial.flush();
  delay(1);
  counter++;
}   */