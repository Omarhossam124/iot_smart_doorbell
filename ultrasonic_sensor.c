#include "ultrasonic_sensor.h"
#include "pico/stdlib.h"

void ultrasonic_init(){
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);

    gpio_set_dir(TRIG_PIN,GPIO_IN);
    gpio_set_dir(ECHO_PIN,GPIO_OUT);
}

float ultrasonic_get_distance(void){
    gpio_put(TRIG_PIN, true);   // Set TRIG_PIN high
    sleep_us(10);              // Wait for 10 microseconds
    gpio_put(TRIG_PIN, false); // Set TRIG_PIN low

    // Wait for the echo signal on ECHO_PIN
    uint64_t start_time = time_us_32();  // Start time
    while (gpio_get(ECHO_PIN) == 0 && (time_us_32() - start_time) < 20000); // Wait for echo to go high

    if (time_us_32() - start_time >= 20000) { // Timeout check
        return -1; // Return an error if no echo received
    }

    uint64_t echo_start_time = time_us_32();  // Record echo start time
    while (gpio_get(ECHO_PIN) == 1 && (time_us_32() - echo_start_time) < 20000); // Wait for echo to go low

    uint64_t echo_time = time_us_32() - echo_start_time;  // Measure duration
    float distance = (echo_time / 2.0) / 29.1; // Distance = time / (2 * speed of sound in air)
    return distance;
}