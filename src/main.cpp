#include <Arduino.h>
#include <Display.h>
#include <Button.h>
#include <Led.h>
#include <RBD_LightSensor.h>
#include <DataCollector.h>
#include <FuzzyLogic.h>
#include <DistanceModel.h>

#define PIN_LED_PWM 10
#define BTN_PIN 29
#define PHOTORESISTOR_PIN A0

#define PHOTORESISTOR_FLOOR 960    // max light
#define PHOTORESISTOR_CEILING 1023 // total

Buttons::Button btn(BTN_PIN);

Leds::LedPWM led(PIN_LED_PWM);

RBD::LightSensor photoresitor(PHOTORESISTOR_PIN);

// Pins del lcd
const int rs = 30,
          en = 31,
          d4 = 32,
          d5 = 33,
          d6 = 34,
          d7 = 35;

FuzzyLogic::AmbientLightClass ambientLightIdentifiers[4] = {
    FuzzyLogic::AmbientLightClass("Dark", 0, 10),
    FuzzyLogic::AmbientLightClass("Dim", 11, 18),
    FuzzyLogic::AmbientLightClass("Bright", 19, 25),
    FuzzyLogic::AmbientLightClass("Blinding", 25, 30)};

FuzzyLogic::AmbientLightClassifier classifier(ambientLightIdentifiers, 4u);

Display::LightLevelsDisplay lcd(&classifier, rs, en, d4, d5, d6, d7);

static void collectData()
{

  if (!btn.wasPressed())
    return;

  led.off();
  DataCollector::getSamples(photoresitor, btn, lcd, 0, 31);
  lcd.clear();
  lcd.home();
  lcd.print("Terminado !!");
  delay(3000);
  lcd.clear();
}

void setup()
{
  Serial.begin(9600);
  led.off();
  lcd.begin(16, 2);
  photoresitor.setFloor(PHOTORESISTOR_FLOOR);
  photoresitor.setCeiling(PHOTORESISTOR_CEILING);
  DataCollector::printLabels();
}

void printDistance(long interval_ms, int rawValue)
{
  using namespace DistanceModel;

  static unsigned int interval = interval_ms;
  static long passedTime = millis();
  long currentTime = millis();

  if (currentTime - passedTime >= interval)
  {
    float distance = Linear::voltage2distance_cm(DataCollector::rawAnalog2voltage(rawValue));
    lcd.printDistance(distance < 0 ? 0 : distance);
    passedTime = currentTime;
  }
}

void loop()
{
  collectData();
  // Recieve phototransitordata
  int rawValue = photoresitor.getRawValue();
  int percentLight = photoresitor.getPercentValue();
  led.setDutyCicle(map(percentLight, 0, 100, 0, 255));
  printDistance(1000, rawValue);
}