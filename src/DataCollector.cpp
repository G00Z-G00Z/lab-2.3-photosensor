#include <DataCollector.h>
#include <Arduino.h>

static const float reference_voltage = 5.0f;

using namespace DataCollector;

void DataCollector::print_labels()
{
    Serial.println("distance, voltage");
}

void DataCollector::print_serial_data(int distance_cm, RBD::LightSensor &sensor)
{

    float raw_valuee = sensor.getRawValue();

    float percent = raw_valuee / 1023.000f;

    float voltage = percent * reference_voltage;

    Serial.println(String(distance_cm) + "," + String(voltage, 5));
}
