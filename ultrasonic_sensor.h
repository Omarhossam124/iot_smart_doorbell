#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include "pico/stdlib.h"

#define TRIG_PIN 2
#define ECHO_PIN 3

void ultrasonic_init(void);
float ultrasonic_get_distance(void);

#endif