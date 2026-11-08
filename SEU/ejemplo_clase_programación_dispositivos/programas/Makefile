CFLAGS=-Wall

PROGRAMAS= cpuid key-iopl key-ioperm key-bf key-bits rtc rtc-bits rtc-bf lAPIC lAPIC-bf lAPIC-bits size getPCI-b0-r0-f0 gpio gpio-bits

all: $(PROGRAMAS)

key-bits.o rtc-bits.o lAPIC-bits.o lAPIC2-bits.o gpio-bits.o: bits.h

clean:
	rm -f $(PROGRAMAS) *.o
