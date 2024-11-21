#ifndef SERVO_H
#define SERVO_H

#include "pico/stdlib.h"

#define SERVO_PIN 9

void servo_init(void);
void servo_set_position(uint servo_pin,uint angle);

#endif