# Makefile configurations

COMMON_OBJECTS = buzzer.o mainRunner.o alarmSound.o stateMachine.o melody.o randomSound.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

# Switch the compiler (for the internal make rules)
CC = msp430-elf-gcc
AS = msp430-elf-as

all: buzzer.elf

# Additional rules for files
buzzer.elf: ${COMMON_OBJECTS} led.h ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

buzzer.o: buzzer.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

mainRunner.o: mainRunner.c buzzer.h led.h
	${CC} ${CFLAGS} -c -o $@ $<

alarmSound.o: alarmSound.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

stateMachine.o: stateMachine.c buzzer.h led.h
	${CC} ${CFLAGS} -c -o $@ $<

melody.o: melody.c buzzer.h
	${CC} ${CFLAGS} -c -o $@ $<

randomSound.o: randomSound.c buzzer.h led.h
	${CC} ${CFLAGS} -c -o $@ $<
