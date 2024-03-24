#include <msp430.h>
#include "libTimer.h"

// Configure clock settings
void configureClocks() {
  WDTCTL = WDTPW | WDTHOLD; // Disable Watchdog Timer
  BCSCTL1 = CALBC1_16MHZ;   // Set DCO to 16 MHz
  DCOCTL = CALDCO_16MHZ;
  
  BCSCTL2 &= ~SELS;          // SMCLK source = DCO
  BCSCTL2 |= DIVS_3;         // SMCLK = DCO / 8
}

// Enable watchdog timer periodic interrupt
// Period = SMCLK / 32768
void enableWDTInterrupts() {
  WDTCTL = WDTPW |      // Password required, otherwise the device resets
           WDTTMSEL |   // Watchdog interval mode
           WDTCNTCL |   // Clear watchdog count
           1;           // Divide SMCLK by 8192
  IE1 |= WDTIE;          // Enable watchdog interval timer interrupt
}

// Configure Timer A in up mode
void timerAUpmode() {
  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;  // Toggle P1.6 when the timer reaches CCR1
  
  // Timer A control:
  // - Timer clock source: SMCLK (2: system clock)
  // - Mode Control 1: Up mode, continuously count from 0 to CCR0
  TACTL = TASSEL_2 + MC_1;
}
