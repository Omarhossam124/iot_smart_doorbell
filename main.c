#include <stdio.h>
#include "pico/stdlib.h"
#include "button.h"
#include "buzzer.h"
#include "pir.h"
#include "led.h"
#include "ultrasonic_sensor.h"
#include "servo.h"

  // HC-SR04 Pins
#define TRIG_PIN 2
#define ECHO_PIN 3
// PIR Sensor Pin
#define PIR_PIN 4
// Button Pin
#define BUTTON_PIN 5
// LED and Buzzer Pins
#define LED_PIN 6
#define BUZZER_PIN 7
// Servo Pin
#define SERVO_PIN 9

bool pirMotion = false;
bool pressedButton = false;
bool doorOpen = false;

void openDoor(){
    doorOpen=true;
    servo_set_position(SERVO_PIN,90);
    sleep_ms(5000);
    servo_set_position(SERVO_PIN,0);
    doorOpen=false;
}

int main() {
    stdio_init_all();

    pressedButton=buttonPressed(BUTTON_PIN); //////check signal
    if( pressedButton ){
        openDoor();
      }
    else{
        pressedButton=false;
    }

    pirMotion = pir_sensor_motion_detected(PIR_PIN);
    if(pirMotion){
        led_on(LED_PIN);
        buzzer_play_tone(BUZZER_PIN);
        sleep_ms(1000);
        led_off(LED_PIN);
        buzzer_stop(BUZZER_PIN);
    }
}
