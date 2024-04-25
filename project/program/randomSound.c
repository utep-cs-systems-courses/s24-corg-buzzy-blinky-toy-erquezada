#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

float notes[] = {587.33, 523.25, 659.25, 587.33, 698.46, 659.25, 698.46};  // Notes are F5, C5, E5, F5, D5, E5, D5

// Function to play the melody and control the LED dimming
void randomSound() {
  int numNotes = sizeof(notes) / sizeof(notes[0]);
  
  // Repeat the melody and LED dimming effect four times
  for (int repeat = 0; repeat < 4; repeat++) {
    for (int i = 0; i < numNotes; i++) {
      buzzer_set_period(2000000 / notes[i]);  // Convert frequency to timer period assuming a 2 MHz clock

      // Simple LED dimming: cycle brightness with PWM or by varying delay
      for (int brightness = 0; brightness < 1000; brightness += 100) {
        P1OUT |= LED_GREEN; // Turn on green LED
        __delay_cycles(brightness);  // On time varies
        P1OUT &= ~LED_GREEN; // Turn off green LED
        __delay_cycles(1000 - brightness); // Off time compensates to keep frequency consistent
      }

      __delay_cycles(10000000); // Delay to hold the note
    }
  }
  
  // Turn off the buzzer when the melody is done
  buzzer_set_period(0);
}
