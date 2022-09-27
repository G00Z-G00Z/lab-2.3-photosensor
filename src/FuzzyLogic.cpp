#include <FuzzyLogic.h>
#include <Arduino.h>

using namespace FuzzyLogic;

AmbientLightClass::AmbientLightClass(String name, float minValue, float maxValue)
    : name(name), minValue(minValue), maxValue(maxValue)
{
}

String AmbientLightClass::getName() { return name; }

bool AmbientLightClass::isRangeInClass(float value) { return minValue <= value && value < maxValue; }

AmbientLightClassifier::AmbientLightClassifier() : ambientLightClasses(nullptr), size(0)
{
}

AmbientLightClassifier::AmbientLightClassifier(AmbientLightClass *arr, unsigned int size) : ambientLightClasses(arr), size(size)
{
}

String AmbientLightClassifier::getAmbientClassName(float value)
{

    for (size_t i = 0; i < size; i++)
    {
        if (ambientLightClasses[i].isRangeInClass(value))
        {
            return ambientLightClasses[i].getName();
        }
    }

    return "Error for value: " + String(value, 2);
}
