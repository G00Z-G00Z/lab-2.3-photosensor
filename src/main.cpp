#include <Arduino.h>
#include <Display.h>
#include <Button.h>
#include <Led.h>
#include <RBD_LightSensor.h>
#include <DataCollector.h>

#define PIN_LED_PWM 10
#define BTN_PIN 29
#define PHOTORESISTOR_PIN A0

Buttons::Button btn(BTN_PIN);

Leds::LedPWM led(PIN_LED_PWM);

RBD::LightSensor phoresistor(PHOTORESISTOR_PIN);

// Pins del lcd
const int rs = 30,
          en = 31,
          d4 = 32,
          d5 = 33,
          d6 = 34,
          d7 = 35;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void collectData()
{

  if (!btn.wasPressed())
    return;

  DataCollector::get_all_data(phoresistor, btn, lcd, 0, 31);
  lcd.clear();
  lcd.home();
  lcd.print("Terminado !!");
  delay(3000);
  lcd.clear();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello world");

  led.off();
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Hola");

  // phoresistor.setFloor(980);
  // phoresistor.setCeiling(1020);
  DataCollector::print_labels();
}

void loop()
{

  collectData();
}