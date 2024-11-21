#include "led.h"
#include "pico/stdlib.h"

void led_init(void) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN,GPIO_OUT);
    led_off(LED_PIN);
}

void led_on(uint led_pin){
    gpio_put(LED_PIN,true);
}

void led_off(uint led_pin){
        gpio_put(LED_PIN,false);
}