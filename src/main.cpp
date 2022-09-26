#include <Arduino.h>
#include <Display.h>
#include <Button.h>
#include <Led.h>
#include <RBD_LightSensor.h>
#include <LiquidCrystal.h>

#define PIN_LED_PWM 10
#define BTN_PIN 10
#define PHOTORESISTOR_PIN 10

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

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello world");

  led.on();
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Hola");
}

void loop()
{
  static int i = 0;
  Serial.println("Hello x " + String(i++));
}