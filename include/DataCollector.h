#pragma once
#include <RBD_LightSensor.h>
#include <LiquidCrystal.h>
#include <Button.h>

namespace DataCollector
{

    void printLabels();

    void printSerialData(int distance_cm, RBD::LightSensor &sensor);

    void getSamples(RBD::LightSensor &sensor,
                    Buttons::Button &btn,
                    LiquidCrystal &lcd,
                    int min_cm,
                    int max_cm,
                    int step = 1,
                    bool printLabels = false);

    float rawAnalog2voltage(int rawValue);

};
