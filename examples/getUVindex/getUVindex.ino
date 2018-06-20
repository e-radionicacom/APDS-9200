#include "APDS9200.h"
#include "Wire.h"

APDS9200 lightSensor;

long UVindex;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Starting!");
}

void loop() {
  Serial.print("UV index:\t");
  lightSensor.enableUV();
  delay(150); // 150ms needed for UV reading
  UVindex = lightSensor.getUVIndex();
  Serial.println(UVindex);

  delay(500); // make readings each 500ms
}
