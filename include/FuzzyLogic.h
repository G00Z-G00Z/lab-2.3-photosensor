#pragma once
#include <Arduino.h>

namespace FuzzyLogic
{

    class AmbientLightClass
    {

    private:
        String name;
        float minValue;
        float maxValue;

    public:
        AmbientLightClass(String name, float minValue, float maxValue);

        bool isRangeInClass(float value);

        String getName();
    };

    template <unsigned int ambientLightClassesNo>
    class AmbientLightClassifier
    {

    private:
        AmbientLightClass ambientLightClasses[ambientLightClassesNo];

    public:
        AmbientLightClassifier(AmbientLightClass *arr);
        String getAmbientClassName(float value);
    };

};
