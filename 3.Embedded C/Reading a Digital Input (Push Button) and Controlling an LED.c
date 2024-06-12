Objectives:
- The objective of this code is to control an LED based on the state of a push-button.
- `IO_Init()` function initializes pin PD2 as an input for the push-button with an internal pull-up resistor enabled, and pin PD3 as an output for the LED.
- Inside the `main()` function, there's an infinite loop that continuously reads the state of the push-button. If the button is pressed (PD2 is low), the LED (PD3) is turned on. If the button is released (PD2 is high due to the pull-up resistor), the LED is turned off.
- A small delay of 50 milliseconds is introduced for debouncing the push-button to avoid multiple readings due to mechanical bouncing.

#include <avr/io.h>        // Include AVR I/O definitions
#include <util/delay.h>    // Include delay functions

void IO_Init() {
    // Set PD2 as input (push-button) and enable internal pull-up resistor
    DDRD &= ~(1 << PD2);  // Set pin PD2 as input by clearing the corresponding bit in the data direction register (DDR)
    PORTD |= (1 << PD2);  // Enable the internal pull-up resistor on pin PD2 by setting the corresponding bit in the PORT register
    // Pull-up resistor ensures the pin is high when the button is not pressed

    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);   // Set pin PD3 as output by setting the corresponding bit in the data direction register (DDR)
}

int main() {
    IO_Init();  // Initialize I/O configuration

    while (1) {
        // Read the state of the push-button
        if (PIND & (1 << PD2)) {
            // Button is not pressed (pull-up resistor makes it high)
            PORTD &= ~(1 << PD3); // Turn off the LED by clearing the corresponding bit in the PORT register
        } else {
            // Button is pressed (pin is low)
            PORTD |= (1 << PD3); // Turn on the LED by setting the corresponding bit in the PORT register
        }

        _delay_ms(50); // Debounce delay to avoid multiple readings due to mechanical bouncing of the button
    }
}


