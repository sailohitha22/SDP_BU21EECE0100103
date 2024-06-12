Objectives:
- The objective of this code is to transmit the character 'B' over a serial communication interface.
- Timer 1 (T1) is configured in mode 2 for auto-reload operation to generate the baud rate.
- TH1 is set to a value (0xFA) that corresponds to a baud rate of 4800 bits per second.
- Serial communication control register (SCON) is configured for mode 1 (8-bit UART) with reception disabled and transmission enabled.
- Timer 1 is started.
- Inside the infinite loop, the character 'B' is loaded into the serial buffer (SBUF).
- The program waits until the transmission is complete (TI flag is set), then clears the transmission interrupt flag (TI) before transmitting the next character.

#include <reg51.h>  // Include the header file for 8051 microcontroller register definitions

void main(void)
{
    TMOD = 0X20;  // Configure Timer 1, mode 2 for auto-reload
    TH1 = 0XFA;   // Set TH1 to achieve a baud rate of 4800
    SCON = 0X50;  // Configure serial communication for mode 1, 8-bit UART, enable receiver
    TR1 = 1;      // Start Timer 1 for baud rate generation

    while(1)  // Infinite loop
    {
        SBUF = 'B';  // Load the character 'B' into the serial buffer
        while(TI == 0);  // Wait until transmission is complete (TI flag is set)
        TI = 0;  // Clear the transmission interrupt flag (TI)
    }
}


