
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void stateMachine()
{
  char p1val = P1IN;  //define botton from bottom
  char p2val = P2IN;  //help detects upper bottons
 
  if( p2val & TOPS1 ? 0 : 1 )
    { //bottom 1 a friendly melody :D
      P1OUT &= ~LED_RED;
      melody(0); 
    }
  else if( p2val & TOPS2 ? 0 : 1)
    { //bottom 2 random sound and dimmy lights
      randomSound();
    }
  else if( p2val & TOPS3 ? 0 : 1)
    {
      // A sound that corresponds with the lights.
      alarmSound();
    }
  else if( p2val & TOPS4 ? 0 : 1){
    
  }
  else if (p1val & SW1 ? 0 : 1){
   
  }
  else{
    buzzer_set_period(0);
    P1OUT &= ~LEDS;
  }
}