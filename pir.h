#ifndef PIR_H
#define PIR_H
#include "pico/stdlib.h"

#define PIR_PIN 4

void pir_sensor_init(void);
bool pir_sensor_motion_detected(uint pir);

#endif