#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void stateMachine() {
  char p1val = P1IN;  // Read bottom buttons
  char p2val = P2IN;  // Read upper buttons

  if (!(p2val & TOPS1)) {
    // Button TOPS1 pressed
    P1OUT &= ~LED_RED;
    melody(0);
  } else if (!(p2val & TOPS2)) {
    // Button TOPS2 pressed
    randomSound();
  } else if (!(p2val & TOPS3)) {
    // Button TOPS3 pressed
    alarmSound();
  } else if (!(p2val & TOPS4)) {
    // Button TOPS4 pressed
    // Handle TOPS4 button press here
  } else if (!(p1val & SW1)) {
    // Button SW1 pressed
    // Handle SW1 button press here
  } else {
    // No button pressed, turn off buzzer and LEDs
    buzzer_set_period(0);
    P1OUT &= ~LEDS;
  }
}
