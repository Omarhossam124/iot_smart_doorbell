#include "button.h"
#include "pico/stdlib.h"

void buttonInit(){
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN,GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

bool buttonPressed(uint butt_pin){
    return !gpio_get(butt_pin);
}