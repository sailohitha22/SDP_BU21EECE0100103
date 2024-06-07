#include <avr/io.h>
#include <util/delay.h>

// Initialize output pin
void IO_Init() {
    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);
}

int main() {
    IO_Init(); // Call the function to initialize I/O

    while (1) {
        // Turn on the LED
        PORTD |= (1 << PD3);
        _delay_ms(500); // Wait for 500 milliseconds

        // Turn off the LED
        PORTD &= ~(1 << PD3);
        _delay_ms(500); // Wait for 500 milliseconds
    }
}