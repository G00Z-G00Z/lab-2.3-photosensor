#pragma once
#include <LiquidCrystal.h>
#include <FuzzyLogic.h>

namespace Display
{

    class LightLevelsDisplay : public LiquidCrystal
    {
        FuzzyLogic::AmbientLightClassifier *classifier = nullptr;

    public:
        LightLevelsDisplay(FuzzyLogic::AmbientLightClassifier *classifier, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
            : LiquidCrystal(rs, en, d4, d5, d6, d7), classifier(classifier) {}

        void printDistance(float distance_cm);

        void clearAndResetCursor();
    };

};
