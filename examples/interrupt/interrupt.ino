#include "APDS9200.h"
#include "Wire.h"

APDS9200 lightSensor;
const int interruptPin = 6;
const int LED = 5;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(interruptPin, INPUT);
  pinMode(LED, OUTPUT);

  //For both and upper and lower threshold:
  lightSensor.setInterruptThresh(500, 1000);

  //Just the upper lightSensor threshold:
  //lightSensor.setInterruptThreshUpper(1000);

  //Just the lower lightSensor threshold:
  //lightSensor.setInterruptThreshLower(500);

  
  lightSensor.enableLightInterrupt();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lightSensor.enableLight();
  
  delay(150);

  if(digitalRead(interruptPin) == HIGH)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
    
}
