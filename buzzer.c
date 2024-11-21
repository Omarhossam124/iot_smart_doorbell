#include "buzzer.h"
#include "pico/stdlib.h"

void buzzer_init(void){
        gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
}

void buzzer_stop(uint buzz){
    uint slice_num = pwm_gpio_to_slice_num(buzz);
    pwm_set_enabled(slice_num, false);
}

void buzzer_play_tone(uint buzz) {
    uint slice_num = pwm_gpio_to_slice_num(buzz);  // Get the PWM slice number for the buzzer pin

    // Configure the pin as a PWM output
    gpio_set_function(buzz, GPIO_FUNC_PWM);

    // Hardcoded frequency and duration
    uint frequency = 1000;     // Frequency in Hz (adjust as needed)
    uint32_t duration = 500;   // Duration in milliseconds (adjust as needed)
    uint wrap = 1000;          // PWM wrap value
    uint16_t duty = wrap / 2;  // 50% duty cycle

    // Set the PWM frequency and range
    pwm_set_clkdiv(slice_num, 125.0);  // Set clock divider for frequency
    pwm_set_wrap(slice_num, wrap);    // Set the wrap value (range)

    // Set the PWM level (duty cycle)
    pwm_set_gpio_level(buzz, duty);   // Set the duty cycle to 50%

    // Enable the PWM output
    pwm_set_enabled(slice_num, true);

    // Wait for the specified duration
    sleep_ms(duration);

    // Disable the PWM output
    pwm_set_enabled(slice_num, false);
}
