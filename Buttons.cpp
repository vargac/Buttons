#include "Buttons.h"

Button::Button(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
    last_state = digitalRead(_pin);

    p_onPush = NULL;
    p_onRelease = NULL;
    p_pushed = NULL;
    p_released = NULL;
}

void Button::update()
{
    uint8_t actual_state = digitalRead(_pin);
    if (actual_state) {
        if (p_pushed != NULL) (*p_pushed)();
        if (!last_state) {
            if (p_onPush != NULL) (*p_onPush)();
        }
    } else {
        if (p_released != NULL) (*p_released)();
        if (last_state) {
            if (p_onRelease != NULL) (*p_onRelease)();
        }
    }
    last_state = actual_state;
}

uint8_t Button::read()
{
    return digitalRead(_pin);
}

void Button::set_onPush(void (*onPush)())
{
    p_onPush = onPush;
}

void Button::set_onRelease(void (*onRelease)())
{
    p_onRelease = onRelease;
}

void Button::set_pushed(void (*pushed)())
{
    p_pushed = pushed;
}

void Button::set_released(void (*released)())
{
    p_released = released;
}
