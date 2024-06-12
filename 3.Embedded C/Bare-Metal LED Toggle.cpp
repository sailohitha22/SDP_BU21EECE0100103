Objectives:
- The objective of this code is to blink an LED connected to pin PD6 of the AVR microcontroller.
- It sets pin PD6 as an output pin by setting the corresponding bit in the data direction register (DDRD).
- Inside the infinite loop, it toggles the state of pin PD6 by XORing its current state with 1 (which effectively toggles the pin).
- It then introduces a delay of 500 milliseconds using the `_delay_ms()` function from the `util/delay.h` library before repeating the loop.

#include <avr/io.h>        // Include AVR I/O definitions
#include <util/delay.h>    // Include delay functions

int main() {
    // Set PD6 as output
    DDRD |= (1 << PD6);    // Set the data direction register D for pin PD6 as output

    while (1) {
        // Toggle the LED state
        PORTD ^= (1 << PD6);  // Toggle the state of pin PD6 by XORing its current state with 1
        
        // Delay for a short time (500 milliseconds)
        _delay_ms(500);  // Delay function provided by the util/delay.h library
    }

    return 0;
}


