
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void stateMachine()
{
  char p1val = P1IN;  // define button from bottom
  char p2val = P2IN;  // help detects upper buttons

  switch (p2val & (TOPS1 | TOPS2 | TOPS3 | TOPS4))
  {
    case TOPS1:
      // Bottom 1: play a friendly melody
      P1OUT &= ~LED_RED;
      melody(0);
      break;
    case TOPS2:
      // Bottom 2: play alarm sound
      alarmSound();
      break;
    case TOPS3:
      // Bottom 3: play a crazy song corresponding with lights
      randomSound();
      break;
    case TOPS4:
      // Bottom 4: add code for this case if needed
      break;
    default:
      // No top buttons pressed: turn off buzzer and LEDs
      buzzer_set_period(0);
      P1OUT &= ~LEDS;
      break;
  }
}
