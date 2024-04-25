#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void cScale(int counter) {
  // Specific pitch numbers in Hz (notes of a descending C scale)
  float notes[] = {987.77, 923.33, 880, 783.99, 698.46, 659.25, 587.33, 523.25};

  // Calculate the number of notes in the array
  int numNotes = sizeof(notes) / sizeof(notes[0]);

  // Play each note with corresponding LED patterns
  for (int i = 0; i < numNotes; i++) {
    // Turn on green LED and turn off red LED
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;

    // Set buzzer to current note frequency and delay for note duration
    buzzer_set_period(2000000 / notes[i]);  // Calculate period from frequency assuming 2 MHz clock
    __delay_cycles(1000000);  // Short pause with note

    // Switch LED states
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;

    // Repeat the note with opposite LED states
    buzzer_set_period(2000000 / notes[i]);  // Same frequency as before
    __delay_cycles(7000000);  // Longer pause with same note
  }

  // Turn off both LEDs after the sequence
  P1OUT &= ~(LED_RED | LED_GREEN);
  __delay_cycles(100000);

  // Turn on both LEDs briefly
  P1OUT |= (LED_GREEN | LED_RED);
  __delay_cycles(1000000);

  // Recursive call to repeat the scale if counter is not 1
  if (counter != 1) {
    cScale(++counter);
  }
}
