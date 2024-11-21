#include "pir.h"
#include "pico/stdlib.h"

void pir_sensor_init(void){
    gpio_init(PIR_PIN);
    gpio_set_dir(PIR_PIN, GPIO_IN);
}

bool pir_sensor_motion_detected(uint pir){
    return gpio_get(pir);
}