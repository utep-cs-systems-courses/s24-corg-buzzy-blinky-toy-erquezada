#include "timerLib.h"

int main() {
    // Call functions from timerLib.h
    configureClocks();
    enableWDTInterrupts();
    timerAUpmode();
    // Rest of your code
    return 0;
}
