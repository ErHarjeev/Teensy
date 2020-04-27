#include<Arduino.h>
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
const uint8_t led =  LED_BUILTIN;
uint32_t previous_time_ms = 00 ;
uint32_t current_time_ms = 00 ;

uint32_t exe_previous_us   = 00;
uint32_t exe_current_us   = 00;

const  uint32_t led_interval = 1000;
boolean led_state = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led,led_state);
}

// the loop routine runs over and over again forever:
void loop() {
  static uint32_t previous_time_ms = 00 ; // it makes local variable to store the previous value and initilization is only once
  current_time_ms = millis();

  exe_previous_us = micros();
  if ( current_time_ms - previous_time_ms >= led_interval
  ){    uint32_t y = micros();
      led_state = !led_state;
      digitalWrite(led,led_state);
      Serial.print(" Previous value = ") ; Serial.print(previous_time_ms);
      Serial.print(" Previous value = ") ; Serial.println(previous_time_ms); 
      previous_time_ms = current_time_ms;
      Serial.println(micros()-y);

  }
  
}