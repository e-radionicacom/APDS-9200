#include "APDS9200.h"
#include "Wire.h"

APDS9200 lightSensor;

long light;
long UVlight;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Starting!");
}

void loop() {
  Serial.print("UV Light:\t");
  lightSensor.enableUV();
  delay(150); // 150ms needed for UV reading
  UVlight = lightSensor.getUV();
  Serial.print(UVlight);
  Serial.print("\t\t");

  Serial.print("Light:  ");
  lightSensor.enableLight();
  delay(100);
  light = lightSensor.getLight();
  Serial.println(light);

  delay(500); // make readings each 500ms
}
