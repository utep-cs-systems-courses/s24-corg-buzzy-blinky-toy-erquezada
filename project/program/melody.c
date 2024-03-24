void melody(int counter) {
  // Specific pitch numbers and note durations (in microseconds)
  int notes[] = {523, 659, 783, 493, 523, 587, 523, 880, 783, 1046, 783, 698, 659, 698, 659}; // Plays a small melody
  int durations[] = {300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000, 300000};
  int numNotes = sizeof(notes) / sizeof(notes[0]); // Array size
  
  // Play each note
  for (int i = 0; i < numNotes; i++) {
    // Turn on green LED and turn off red LED
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    buzzer_set_period(notes[i]);
    __delay_cycles(durations[i]); // Delay based on note duration
    
    // Turn on red LED and turn off green LED
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    buzzer_set_period(notes[i]);
    __delay_cycles(durations[i]); // Delay based on note duration
  }
  
  // Turn off both LEDs after playing the melody
  P1OUT &= ~LED_RED;
  P1OUT &= ~LED_GREEN;
  
  // If counter is less than 3, repeat the melody (recursive call)
  if (counter < 3) {
    melody(counter + 1); // Increment the counter for recursion
  }
}
