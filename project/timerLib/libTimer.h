#ifndef libTimer_included
#define libTimer_included

void configureClocks();
void enableWDTInterrupts();
void timerAUpmode();

unsigned int get_sr();
void set_sr(unsigned int sr);
void or_sr(unsigned int mask);
void and_sr(unsigned int mask);


#endif // libTimer_included
