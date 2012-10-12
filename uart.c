//uart.c - pic uart access
#include "uart.h"

// send one byte
void uart_write_byte(unsigned char d)
{
    while (!TXIF)
        continue;
    TXREG = d;
}

// receive one byte
unsigned char uart_read_byte(void)
{
    while (!RCIF)
        continue;
    return RCREG;
}

// write string
void uart_putstr(const char * str)
{
    const char * ps = str;

    while (*ps)
    {
        while (!TXIF)
            continue;
        TXREG = *ps;
        ps++;
    }
}

