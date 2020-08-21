#include <Arduino.h>
#include <QC3Control.h>
//             ATINY 
//            _______
//    Reset -|1     8|- VIN
//    A3  3 -|2     7|- 2 A1
//    A2  4 -|3     6|- 1 PWM
//      GND -|4_____5|- 0 PWM
//  

#define pinLED  1 
#define pinTestVoltage A1 
QC3Control quickCharge(3, 4);  // byte DpPin, byte DmPin


void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinTestVoltage, INPUT);
  //Optional
  //quickCharge.begin();
  //set voltage to 12V
  quickCharge.set12V();
  delay(1000);
}

void loop() {
  if (analogRead(pinTestVoltage) >= 450) {
    digitalWrite(pinLED, HIGH);
    delay(1000);
  } else {
    digitalWrite(pinLED, LOW);
    delay(1000);
    digitalWrite(pinLED, HIGH);
    delay(1000);
  }
}
