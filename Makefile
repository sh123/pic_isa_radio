PRJ := radio
OBJS := main.o uart.o delay.o lcd.o radio.o

LIBDIR := /usr/share/sdcc/lib/pic14
LIBDIR_NONFREE := /usr/share/sdcc/non-free/lib/pic14

LIBS := pic16f877.lib libsdcc.lib

CC := sdcc
LINK := gplink
CFLAGS := -V -mpic14 -p16f877 --use-non-free

.c.o: 
	$(CC) $(CFLAGS) -c $<  
  
$(PRJ).hex: $(OBJS)   
	$(LINK) -I $(LIBDIR) -I $(LIBDIR_NONFREE) -m -o $(PRJ).hex $(OBJS) $(LIBS)

clean:	
	rm -f *.o *.hex *.asm *.lst *.cod *~ *.map

