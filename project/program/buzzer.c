#ifndef buzzer_included
#define buzzer_included

#include <msp430.h>
#include "libTimer.h"
#include "led.h"

void buzzer_init() {
    // Configure timer and pin for buzzer
    timerAUpmode();  // Used to drive the speaker
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6;  // Enable output to the speaker (P2.6)
}

void buzzer_set_period(short cycles) {
    // Set the period for the buzzer
    CCR0 = cycles;
    CCR1 = cycles >> 1;  // One-half cycle
}

#endif // buzzer_included
