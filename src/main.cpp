#include <Arduino.h>
#include <Display.h>
#include <Button.h>
#include <Led.h>

#define PIN_LED_PWM 10
#define BTN_PIN 10

Buttons::Button btn(BTN_PIN);

Leds::LedPWM led(PIN_LED_PWM);

// Pins del lcd
const int rs = 30,
          en = 31,
          d4 = 32,
          d5 = 33,
          d6 = 34,
          d7 = 35;

Display::CustomDisplay lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello world");
}

void loop()
{
}