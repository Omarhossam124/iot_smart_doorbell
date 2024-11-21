#include "servo.h"
#include "pico/stdlib.h"

void servo_init(void) {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  // Set servo pin for PWM functionality
}

// Function to set the servo motor's position
void servo_set_position(uint servo_pin,uint angle) {
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);  // Get the PWM slice number for the servo pin

    // Map the angle (0 to 180) to a pulse width (1000us to 2000us)
    uint16_t pulse_width = 1000 + (angle * 1000 / 180);  // 1000us for 0°, 2000us for 180°

    // Set the PWM wrap (max value) to generate a 50Hz signal (PWM period of 20ms)
    pwm_set_wrap(slice_num, 2500);  // 20ms period (50Hz)

    // Set the PWM pulse width (duty cycle)
    pwm_set_gpio_level(servo_pin, pulse_width);

    // Enable the PWM signal
    pwm_set_enabled(slice_num, true);
}