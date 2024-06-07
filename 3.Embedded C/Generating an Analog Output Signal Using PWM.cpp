#include <avr/io.h>
#include <util/delay.h>

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
    PWM_Init();

    while (1) {
        for (uint8_t duty = 0; duty <= 255; duty++) {
            set_PWM(duty); // Increase duty cycle
            _delay_ms(10); // Small delay
        }
        
        for (uint8_t duty = 255; duty > 0; duty--) {
            set_PWM(duty); // Decrease duty cycle
            _delay_ms(10); // Small delay
        }
    }
}