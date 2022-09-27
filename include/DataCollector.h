#pragma once
#include <RBD_LightSensor.h>
#include <LiquidCrystal.h>
#include <Button.h>

namespace DataCollector
{

    void print_labels();

    void print_serial_data(int distance_cm, RBD::LightSensor &sensor);

    void get_all_data(RBD::LightSensor &sensor, Buttons::Button &btn, LiquidCrystal &lcd, int min_cm, int max_cm, int step = 1, bool printLabels = false);

};
