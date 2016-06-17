#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

class Button
{
    public:
        Button(uint8_t pin);
        void update();
        void set_onPush(void (*onPush)());
        void set_onRelease(void (*onRelease)());
        void set_pushed(void (*pushed)());
        void set_released(void (*released)());
        uint8_t read();
    private:
        uint8_t _pin;
        uint8_t last_state;
        void (*p_onPush)();
        void (*p_onRelease)();
        void (*p_pushed)();
        void (*p_released)();
};

#endif /* BUTTONS_H */
