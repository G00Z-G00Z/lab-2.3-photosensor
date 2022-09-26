#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello world");
}

void loop()
{
  static int i = 0;

  Serial.println(String(i++) + ": Hola");
  delay(1000);
}