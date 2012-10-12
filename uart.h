// uart.h - uart module access
#ifndef __UART_H
#define __UART_H

#include "common.h"

// uart configurations
#define FOSC        20000000L
#define BAUD        19200
#define HIGH_SPEED  1

#define DIVIDER     ((int)(FOSC/(16UL * BAUD) -1))

// high speed?
#if HIGH_SPEED == 1
#define SPEED       0x4
#else
#define SPEED       0
#endif

// pins
#define RX_PIN      TRISC7
#define TX_PIN      TRISC6

// initialize uart
#define uart_init() \
{\
    TX_PIN = 1; \
    RX_PIN = 1; \
    SPBRG = DIVIDER; \
    RCSTA = 0x90; \
    TXSTA = (SPEED | 0x20);\
}

/*
**  Write one byte to uarts
**  Input:
**      data - byte to write
*/
void uart_write_byte(unsigned char data);

/*
**  Read one byte
**  Output:
**      read byte
*/
unsigned char uart_read_byte(void);

/*
**  Write strign to uart
**  Input:
**      str - string to write
*/
void uart_putstr(const char * str);

#endif // __UART_H

