all: libTimer.a

CPU = msp430g2553
CFLAGS = -mmcu=${CPU}

# Switch the compiler (for the internal make rules)
CC = msp430-elf-gcc
AR = msp430-elf-ar

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libTimer.a *.o
