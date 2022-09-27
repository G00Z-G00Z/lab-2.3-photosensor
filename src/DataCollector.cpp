#include <DataCollector.h>
#include <Arduino.h>

static const float reference_voltage = 5.0f;

using namespace DataCollector;

void print_labels()
{
    Serial.println("distance, voltage");
}

void print_serial_data(int distance_cm, RBD::LightSensor &sensor)
{
    float voltage = ((float)sensor.getPercentValue() / 100.0f) * reference_voltage;
    Serial.println(String(distance_cm) + "," + String(voltage));
}
