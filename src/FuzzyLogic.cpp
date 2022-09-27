#include <FuzzyLogic.h>
#include <Arduino.h>

using namespace FuzzyLogic;

AmbientLightClass::AmbientLightClass(String name, float minValue, float maxValue)
    : name(name), minValue(minValue), maxValue(maxValue)
{
}

String AmbientLightClass::getName() { return name; }

bool AmbientLightClass::isRangeInClass(float value) { return minValue <= value && value < maxValue; }

template <unsigned int ambientLightClassesNo>
AmbientLightClassifier<ambientLightClassesNo>::AmbientLightClassifier(AmbientLightClass *arr)
{
    ambientLightClasses = arr;
}

template <unsigned int ambientLightClassesNo>
String AmbientLightClassifier<ambientLightClassesNo>::getAmbientClassName(float value)
{

    for (size_t i = 0; i < ambientLightClassesNo; i++)
    {
        if (ambientLightClasses[i].isRangeInClass(value))
        {
            return ambientLightClasses[i].getName();
        }
    }

    return "Error for value: " + String(value, 2);
}
