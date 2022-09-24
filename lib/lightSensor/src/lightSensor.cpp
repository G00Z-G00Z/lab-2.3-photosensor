/*This is where you write the code you want to run*/
#include "Arduino.h"
#include <lightSensor.h>

using namespace LightSensor;

// Read transducer data
int readLDRData(int analogPort)
{
  int sensorReading = analogRead(analogPort);
  return sensorReading;
}
// Provide a brightness value from current LDR data and circuit's ADC range
int setBrightness(int transducerValue, int minADC, int maxADC)
{
  // map current LDR data ADC range to the 255-0 scale Arduino can use to
  // output analog volage
  int brightness = map(transducerValue, minADC, maxADC, 255, 0);
  return brightness;
}