Objectives:
- The objective of this code is to blink an LED connected to pin PD3 at intervals of 500 milliseconds.
- `IO_Init()` function initializes pin PD3 as an output for the LED.
- Inside the `main()` function, there's an infinite loop that continuously toggles the state of pin PD3 to turn the LED on and off.
- To turn on the LED, the corresponding bit in the PORT register (PORTD) for pin PD3 is set high. To turn off the LED, the corresponding bit is cleared low.
- `_delay_ms(500)` is used to introduce a delay of 500 milliseconds between turning the LED on and off, creating the blinking effect.

    #include <avr/io.h>        // Include AVR I/O definitions
#include <util/delay.h>    // Include delay functions

// Initialize output pin
void IO_Init() {
    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);  // Set pin PD3 as output by setting the corresponding bit in the data direction register (DDR)
}

int main() {
    IO_Init();  // Call the function to initialize I/O

    while (1) {
        // Turn on the LED
        PORTD |= (1 << PD3);  // Set pin PD3 high by setting the corresponding bit in the PORT register
        _delay_ms(500);       // Wait for 500 milliseconds

        // Turn off the LED
        PORTD &= ~(1 << PD3); // Set pin PD3 low by clearing the corresponding bit in the PORT register
        _delay_ms(500);       // Wait for 500 milliseconds
    }
}


