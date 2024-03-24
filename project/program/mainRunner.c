#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

int main() {
  configureClocks(); // Starts timing from MSP
  enableWDTInterrupts(); // Enables buttons
  // Lights are set to be off by default
  P1DIR |= LEDS; // Output bits in MSP to the bottom lights
  P1OUT &= ~LEDS;

  // Enables resistors for bottom switches
  P1REN |= SWITCHES;
  P1IE |= SWITCHES; // Interrupts are enabled

  P2REN |= TOPSW;
  P2IE |= TOPSW;

  buzzer_init();
  /* Higher the pitch, the higher the number the lower the pitch */
  or_sr(0x18);          // CPU off, GIE (General Interrupt Enable) on
} // main ends

// VECTORS THAT ALLOW THE STATE MACHINE WDT

void stateMachine();

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & TOPSW) {
    P2IFG &= ~TOPSW;
    stateMachine();
  }
}

/* Switch on P1 (S2) */

void __interrupt_vec(PORT1_VECTOR) Port_1() {
  if (P1IFG & SWITCHES) {
    P1IFG &= ~SWITCHES;
    stateMachine();
  }
}

void __interrupt_vec(WDT_VECTOR) WDT_ISR() {
  stateMachine();
}
