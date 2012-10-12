// delay.cpp - usecond and msecond delay routines
#include "common.h"
#include "delay.h"

// micro seconds delay
unsigned char sleep_us;
void delay_us(unsigned char us)
{
// 1 us x us
// this is 200 + 200 + 200 + 400 = 1us delay
    sleep_us = us;
__asm
_BACK:
    nop
    nop
    decfsz  _sleep_us,f
    goto    _BACK
__endasm;
}

// millisecond delay
void delay_ms(unsigned char ms)
{
    unsigned char i;
    do {
        i = 4;
        do {
            delay_us(250);
             __asm clrwdt __endasm;
        } while(--i);
    } while(--ms);
}

