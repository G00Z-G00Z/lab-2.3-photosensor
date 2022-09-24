#pragma once

namespace Leds
{

    /**
     * @brief Led class for handling on and off state
     *
     */
    class Led
    {

    protected:
        int pin;

    public:
        Led();
        Led(int pin);
        virtual void on();
        virtual void off();
    };

    /**
     * @brief int that goes from 0 to 255
     *
     */
    using dutyCycle_t = unsigned char;

    /**
     * @brief Class that handles Led that has PWM
     *
     */
    class LedPWM : public Led
    {

    public:
        LedPWM();
        LedPWM(int pwmPin);
        void on() override;
        void off() override;

        void setDutyCicle(dutyCycle_t duty);
    };

};