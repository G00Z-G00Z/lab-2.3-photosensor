#pragma once
/* This files is what the .cpp file looks for when it runs*/
#include "Arduino.h"

namespace LightSensor
{
    // capture analog voltage at the analogPort
    int readLDRData(int analogPort);
    // gives a value between 0 and 255 to use in a digital port
    int setBrightness(int transducerValue, int minADC, int maxADC);

}