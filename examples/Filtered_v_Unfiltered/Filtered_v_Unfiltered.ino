#include "APDS9200.h"
#include "Wire.h"

APDS9200 lightSensor;

long lightFiltered;
long lightUnfiltered;
long UVlightFiltered;
long UVlightUnfiltered;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {

  delay(500);
  Serial.print("UV lightSensor (Filter vs Unfilter:\t");
  lightSensor.enableUV();
  delay(150);
  UVlightFiltered = lightSensor.getUV();
  UVlightUnfiltered = lightSensor.getUVUnfiltered();
  Serial.print(UVlightFiltered);
  Serial.print("\t");
  Serial.println(UVlightUnfiltered);

  Serial.print("lightSensor (Filter vs Unfilter):  ");
  lightSensor.enableLight();
  delay(100);
  lightFiltered = lightSensor.getLight();
  lightUnfiltered = lightSensor.getLightUnfiltered();
  Serial.print(lightFiltered);
  Serial.print("\t");
  Serial.println(lightUnfiltered);
  Serial.println();

  delay(500); // make readings each 500ms
}
