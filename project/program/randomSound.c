#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

float notes[] = {587.33, 523.25, 659.25, 587.33, 698.46, 659.25, 698.46};
// Notes are F5, E5, F5, D5, E5, C5, D5
// Function to control the LED dimming from brightest to dimmest

 

// Function to play the melody
void randomSound() {
  int numNotes = sizeof(notes) / sizeof(notes[0]);
  // Repeat the melody and LED dimming effect four times
  for (int repeat = 0; repeat < 4; repeat++) {
    for (int i = 0; i < numNotes; i++) {
      buzzer_set_period(notes[i]);
          __delay_cycles(10000000);
    }
  }
  // Turn off the buzzer when the melody is done
  buzzer_set_period(0);
}
      