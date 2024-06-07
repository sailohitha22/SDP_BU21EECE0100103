#include <avr/io.h>
#include <util/delay.h>

void IO_Init() {
    // Set PD2 as input (push-button) and enable internal pull-up resistor
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);
}

int main() {
    IO_Init();

    while (1) {
        // Read the state of the push-button
        if (PIND & (1 << PD2)) {
            // Button is not pressed (pull-up resistor makes it high)
            PORTD &= ~(1 << PD3); // Turn off the LED
        } else {
            // Button is pressed (pin is low)
            PORTD |= (1 << PD3); // Turn on the LED
        }

        _delay_ms(50); // Debounce delay
    }
}