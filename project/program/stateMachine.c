
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void stateMachine()
{
  char p1val = P1IN;  //define botton from bottom
  char p2val = P2IN;  //help detects upper bottons
  
  switch (p2val) {
    case TOPS1:
      //bottom 1: a friendly melody
      P1OUT &= ~LED_RED;
      melody(0); 
      break;
      
    case TOPS2:
      //bottom 2: random sound and dim lights
      randomSound();
      break;
      
    case TOPS3:
      //bottom 3: a sound that corresponds with the lights
      alarmSound();
      break;
      
    case TOPS4:
      //bottom 4: no action
      break;
      
    default:
      //no button pressed: turn off buzzer and LEDs
      buzzer_set_period(0);
      P1OUT &= ~LEDS;
      break;
  }
}
