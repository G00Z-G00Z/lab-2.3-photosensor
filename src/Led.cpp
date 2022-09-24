#include <Led.h>
#include <Arduino.h>

using namespace Leds;

Led::Led() : pin(0) {}

Led::Led(int pin) : pin(pin) { pinMode(pin, OUTPUT); }

void Led::on() { digitalWrite(pin, HIGH); }
void Led::off() { digitalWrite(pin, LOW); }

LedPWM::LedPWM() : Led() {}

LedPWM::LedPWM(int pwmPin) : Led(pwmPin) {}

void LedPWM::on() { analogWrite(pin, 255); }
void LedPWM::off() { analogWrite(pin, 0); }

void LedPWM::setDutyCicle(Leds::dutyCycle_t duty) { analogWrite(pin, duty); }
