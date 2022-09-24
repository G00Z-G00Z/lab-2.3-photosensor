#pragma once
#include <LiquidCrystal.h>

namespace Display
{

    class CustomDisplay : public LiquidCrystal
    {

    public:
        CustomDisplay(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
            : LiquidCrystal(rs, en, d4, d5, d6, d7) {}
    };

};
