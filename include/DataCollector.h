#pragma once
#include <RBD_LightSensor.h>

namespace DataCollector
{

    void print_labels();

    void print_serial_data(int distance_cm, RBD::LightSensor &sensor);

};
