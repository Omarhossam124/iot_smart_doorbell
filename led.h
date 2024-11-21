#ifndef LED_H
#define LED_H

#include "pico/stdlib.h"

#define LED_PIN 6

void led_init(void);
void led_on(uint led_pin);
void led_off(uint led_pin);

#endif