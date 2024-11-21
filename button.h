#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"

#define BUTTON_PIN 5

void buttonInit(void);
bool buttonPressed(uint butt_pin);

#endif