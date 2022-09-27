#include <Display.h>

using namespace Display;

void LightLevelsDisplay::clearAndResetCursor()
{
    this->clear();
    this->home();
}

void LightLevelsDisplay::printDistance(float distance_cm)
{
    this->clearAndResetCursor();
    this->print(String(distance_cm, 2) + "cm");
    this->setCursor(0, 1);
    this->print(this->classifier->getAmbientClassName(distance_cm));
}
