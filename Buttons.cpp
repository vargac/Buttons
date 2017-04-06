#include "Buttons.h"

Button::Button(uint8_t pin, bool inverse)
{
    _pin = pin;
    pinMode(_pin, INPUT);
    last_state = digitalRead(_pin);
    inv = inverse;

    p_onPush = NULL;
    p_onRelease = NULL;
    p_pushed = NULL;
    p_released = NULL;
}

void Button::update()
{
    uint8_t actual_state = inv ? !digitalRead(_pin) : digitalRead(_pin);
    if (actual_state) {
        if (!last_state) {
            if (p_onPush != NULL) (*p_onPush)();
        }
        if (p_pushed != NULL) (*p_pushed)();
    } else {
        if (last_state) {
            if (p_onRelease != NULL) (*p_onRelease)();
        }
        if (p_released != NULL) (*p_released)();
    }
    last_state = actual_state;
}

uint8_t Button::read()
{
    return inv ? !digitalRead(_pin) : digitalRead(_pin);
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
