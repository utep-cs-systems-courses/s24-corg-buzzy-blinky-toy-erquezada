void randomSound() {
  int notes[] = {440, 830, 740, 466}; // plays random notes
  int durations[] = {500000, 500000, 500000, 500000}; // Adjust durations as needed

  int numNotes = sizeof(notes) / sizeof(notes[0]);

  // Repeat the melody and LED dimming effect four times
  for (int repeat = 0; repeat < 4; repeat++) {
    for (int i = 0; i < numNotes; i++) {
      buzzer_set_period(notes[i]);
      __delay_cycles(durations[i]); // Delay based on note duration
    }
  }

  // Turn off the buzzer when the melody is done
  buzzer_set_period(0);
}
