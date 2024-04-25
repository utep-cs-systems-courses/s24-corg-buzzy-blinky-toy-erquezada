#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void alarmSound() {
  int i = 0;
  while (1) {
    // Adding more conditions to create a complex pattern
    if ((i % 2 == 0) || (i % 5 == 0) || (i % 7 == 3)) {
      P1OUT |= LED_GREEN;          // Turn on green LED
      P1OUT &= ~LED_RED;           // Turn off red LED
      buzzer_set_period(2000000 / 2000); // 2 kHz frequency, assuming a 2MHz clock
    } else if ((i % 3 == 0) || (i % 11 == 1)) {
      P1OUT |= LED_RED;            // Turn on red LED
      P1OUT &= ~LED_GREEN;         // Turn off green LED
      buzzer_set_period(2000000 / 400); // 400 Hz frequency, assuming a 2MHz clock
    } else {
      P1OUT |= LED_RED;            // Ensure red LED is on
      P1OUT |= LED_GREEN;          // Ensure green LED is also on
      buzzer_set_period(2000000 / 1000); // 1 kHz, another frequency for variation
    }

    // Add a delay between sound patterns (adjust the value as needed)
    __delay_cycles(1000000); // Delay using the built-in delay function for MSP430

    i++;  // Increment i to toggle between the states
  }
}
