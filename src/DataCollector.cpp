#include <DataCollector.h>
#include <Arduino.h>

static const float reference_voltage = 5.0f;

using namespace DataCollector;

float DataCollector::rawAnalog2voltage(int rawValue)
{

    float percent = (float)rawValue / 1023.000f;

    return percent * reference_voltage;
}

void DataCollector::printLabels()
{
    Serial.println("distance,voltage");
}

void DataCollector::printSerialData(int distance_cm, RBD::LightSensor &sensor)
{

    float rawValue = sensor.getRawValue();

    float voltage = DataCollector::rawAnalog2voltage(rawValue);

    Serial.println(String(distance_cm) + "," + String(voltage, 5));
}

void DataCollector::getSamples(RBD::LightSensor &sensor, Buttons::Button &btn, LiquidCrystal &lcd, int min_cm, int max_cm, int step = 1, bool printLabels = false)
{
    using namespace DataCollector;

    if (printLabels)
        DataCollector::printLabels();

    for (size_t current_cm = min_cm; current_cm < max_cm; current_cm++)
    {
        lcd.clear();
        lcd.home();
        lcd.print("Tomar para: " + String(current_cm) + "cm");

        while (!btn.wasPressed())
        {
            lcd.setCursor(0, 1);
            int rawValue = sensor.getRawValue();
            lcd.print("Raw: " + String(rawValue) + "  ");
            delay(100);
        }
    }
}
