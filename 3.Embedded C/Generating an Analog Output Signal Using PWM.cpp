Objectives:
- The objective of this code is to generate a PWM signal on pin PD6 (Arduino pin 6) using Timer 0 of the AVR microcontroller.
- `PWM_Init()` function initializes Timer 0 to operate in Fast PWM mode with a prescaler of 64, and sets PD6 (OC0A) as an output pin.
- `set_PWM()` function sets the duty cycle of the PWM signal by writing to the Output Compare Register (OCR0A).
- Inside the `main()` function, there's an infinite loop that gradually increases and then decreases the PWM duty cycle to create a fading effect or control the speed of a motor.
- `_delay_ms(10)` is used to introduce a small delay between each step of changing the PWM duty cycle.

#include <avr/io.h>        // Include AVR I/O definitions
#include <util/delay.h>    // Include delay functions

void PWM_Init() {
    // Set Fast PWM mode with non-inverting output on OC0A (PD6/Arduino pin 6)
    TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);

    // Set prescaler to 64 and start the timer
    TCCR0B = (1 << CS01) | (1 << CS00);

    // Set PD6 (OC0A) as output
    DDRD |= (1 << PD6);
}

void set_PWM(uint8_t value) {
    OCR0A = value; // Set the PWM duty cycle
}

int main() {
    PWM_Init();  // Initialize PWM configuration

    while (1) {
        // Increase PWM duty cycle from 0 to 255
        for (uint8_t duty = 0; duty <= 255; duty++) {
            set_PWM(duty); // Set duty cycle
            _delay_ms(10); // Small delay
        }
        
        // Decrease PWM duty cycle from 255 to 0
        for (uint8_t duty = 255; duty > 0; duty--) {
            set_PWM(duty); // Set duty cycle
            _delay_ms(10); // Small delay
        }
    }
}


