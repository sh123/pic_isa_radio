
PRJ := alpha
OBJS := main.o uart.o delay.o lcd.o radio.o
INCDIR := /usr/share/sdcc/lib/pic
LIBS := pic16f877.lib libsdcc.lib #libm.lib

CC := sdcc
LINK := gplink
CFLAGS := -V -mpic14 -p16f877

.c.o: 
	$(CC) $(CFLAGS) -c $<  
  
$(PRJ).hex: $(OBJS)   
	$(LINK) -I $(INCDIR) -m -o $(PRJ).hex $(OBJS) $(LIBS)

clean:	
	rm -f *.o *.hex *.asm *.lst *.cod *~ *.map

