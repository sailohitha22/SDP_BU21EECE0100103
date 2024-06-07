#include <avr/io.h>
#include <util/delay.h>

int main() {
    // Set PD6 as output
    DDRD |= (1 << PD6);

    while (1) {
        // Toggle the LED
        PORTD ^= (1 << PD6);
        // Delay for a short time
        _delay_ms(500);
    }

    return 0;
}