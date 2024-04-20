
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void melody(int counter) {
  //specific pitch number
  int notes[] = {784, 784, 784, 622, 698, 698, 698, 587};
  // Notes are G5, G5, G5, Eb5 F5,F5,F5,D5
  int numNotes = sizeof(notes) / sizeof(notes[0]);//array size
  // Play each note twice simultaneously
  int cycle;
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
  if(counter == 3){return;}
  melody(counter++);
}