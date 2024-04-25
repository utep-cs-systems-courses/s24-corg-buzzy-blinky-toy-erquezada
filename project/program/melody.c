#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void melody(int counter) {
  // Define an array of float for pitches (frequencies in Hz)
  float notes[] = {587.33, 659.25, 698.46, 783.99, 880.00, 987.77, 1046.50};  // Added more pitches

  // Calculate the number of notes
  int numNotes = sizeof(notes) / sizeof(notes[0]);

  // Loop through each note in the array
  for (int i = 0; i < numNotes; i++) {
    // Turn on green LED and turn off red LED
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;

    // Set buzzer to current note frequency and delay
    buzzer_set_period(2000000 / notes[i]);  // Correct calculation of the period from frequency
    __delay_cycles(1000000);  // Delay for the duration of the note

    // Turn on red LED and turn off green LED
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;

    // Repeat the note with a different LED configuration
    buzzer_set_period(2000000 / notes[i]);  // Repeat with the same note
    __delay_cycles(7000000);  // Longer delay
  }

  // Turn off both LEDs after the sequence
  P1OUT &= ~(LED_RED | LED_GREEN);
  __delay_cycles(100000);

  // If counter reaches 6, stop the recursion
  if (counter == 2) return;
  melody(++counter);  // Recursive call to play the melody again
}
