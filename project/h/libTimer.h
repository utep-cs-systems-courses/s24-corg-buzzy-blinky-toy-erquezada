#ifndef libTimer_included
#define libTimer_included

void configureClocks();
void enableWDTInterrupts();
void timerAUpmode();

unsigned char get_sr();
void set_sr(unsigned short value);
void or_sr(unsigned short value);
void and_sr(unsigned short value);

#endif // libTimer_included
