#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"

#define BUZZER_PIN 7

void buzzer_init(void);

void buzzer_play_tone(uint buzz);

void buzzer_stop(uint buzz);

#endif