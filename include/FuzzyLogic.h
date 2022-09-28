#pragma once
#include <Arduino.h>

namespace FuzzyLogic
{

    class AmbientLightClassifier;

    class AmbientLightClass
    {

    private:
        String name;
        float minValue;
        float maxValue;
        friend AmbientLightClassifier;

    public:
        AmbientLightClass(String name, float minValue, float maxValue);

        bool isRangeInClass(float value);

        String getName();
    };

    class AmbientLightClassifier
    {

    private:
        AmbientLightClass *ambientLightClasses;
        unsigned int size;

    public:
        AmbientLightClassifier(AmbientLightClass *arr, unsigned int size);
        AmbientLightClassifier();
        String getAmbientClassName(int value);
    };

};
