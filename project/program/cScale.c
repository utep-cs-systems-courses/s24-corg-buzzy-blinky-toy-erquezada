
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void cScale(int counter) {
  //specific pitch number
  float notes[] = {523.25, 587.33, 659.25, 698.46, 783.99, 880, 987.77};
  // Notes are reversed
  int numNotes = sizeof(notes);//array size
  // Play each note twice simultaneously
  for (int i = 0; i < numNotes; i++) {
    //first note turn off red and on green
    P1OUT |= LED_GREEN;
    __delay_cycles(10000);
    P1OUT &= ~LED_RED;
    buzzer_set_period(notes[i]);
    __delay_cycles(1000000);
    //little wait

    //the opposite lights
    P1OUT |= LED_RED;
    __delay_cycles(100000);
    P1OUT &= ~LED_GREEN;
    buzzer_set_period(notes[i]); 
    __delay_cycles(7000000);
  }
  //after notes , there both lights on , then off , and repeat cycle
  __delay_cycles(1000000);
  P1OUT &= ~LED_RED;
  P1OUT &= ~LED_GREEN;
  __delay_cycles(100000);
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;
  if(counter == 1){return;}
  cScale(++counter);
}
