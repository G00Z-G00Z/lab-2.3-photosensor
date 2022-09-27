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

void DataCollector::get_all_data(RBD::LightSensor &sensor, Buttons::Button &btn, LiquidCrystal &lcd, int min_cm, int max_cm, int step = 1, bool printLabels = false)
{
    using namespace DataCollector;

    if (printLabels)
        print_labels();

    for (size_t current_cm = min_cm; current_cm < max_cm; current_cm++)
    {
        lcd.clear();
        lcd.home();
        lcd.print("Tomar para: " + String(current_cm) + "cm");
        lcd.noCursor();

        while (!btn.wasPressed())
        {
        }
        print_serial_data(current_cm, sensor);
    }
}
