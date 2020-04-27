#include <Arduino.h>

#define buttonPin 14
#define LedPin 13
#define PRESS_UPDATE 500

boolean ButtonPressed = false ;
volatile boolean ledstate= false ;
volatile uint32_t pressCounter = 0;
volatile uint32_t errorPressCounter = 0;
const volatile uint8_t DEBOUNCE_DELAY_MS = 150;

void ISR_button();

void setup() {
    Serial.begin(115200);
    pinMode(LedPin, OUTPUT) ;
    attachInterrupt(buttonPin,ISR_button,FALLING) ;
}

void loop() {
  static uint32_t previousTime_ms = 0;
  uint32_t currentTime_ms = millis();
  digitalWrite(LedPin,ledstate);

  if ((currentTime_ms - previousTime_ms)> PRESS_UPDATE  )
  {
    Serial.print(pressCounter);
    Serial.print(", ");
    Serial.println(errorPressCounter );
    previousTime_ms = currentTime_ms;

  }
}

void ISR_button(){
  //
  static uint32_t previousTimeButtonPress_ms =0;
  uint32_t currentTimeButtonPress_ms=millis();
  if ((currentTimeButtonPress_ms - previousTimeButtonPress_ms)>= DEBOUNCE_DELAY_MS)
  {
    ledstate  = !ledstate;
    pressCounter++;
    previousTimeButtonPress_ms = currentTimeButtonPress_ms ; 
  }
  errorPressCounter++;
  //ButtonPressed = !ButtonPressed; 
  
}