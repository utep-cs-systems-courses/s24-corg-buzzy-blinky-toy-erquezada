#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void alarmSound() {
  int i = 0;
  while (1) {
    if (i % 2 == 0 || i % 4 == 0 || i % 8 == 0 || i % 16 == 0 || i % 32 == 0) {
      P1OUT |= LED_GREEN;         // Turn on green LED
      P1OUT &= ~LED_RED;          // Turn off red 
      buzzer_set_period(8000);    // 2kHz
    } else {
      P1OUT |= LED_RED;           // tURN ON RED led
      P1OUT &= ~LED_GREEN;        // tURN OFF GREEN led
      buzzer_set_period(500);
    }
    // Add a delay between sound patterns (adjust the value as needed)
    __delay_cycles(1000000); // This uses the built-in delay function for MSP430
    // Toggle i to switch between two frequencies
    i++;
  }
}