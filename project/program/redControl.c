#include <msp430.h>
#include "led.h"

void redControl(int on)
{
  if (on) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}
