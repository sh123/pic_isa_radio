// radio.h - radio module access
#ifndef __RADIO_H
#define __RADIO_H

#include "common.h"

// isa bus address
#define R_ISA_ADDR      0xc3

// FM intermediate frequency
#define R_FM_IF_FREQ    107

// pic <-> radio connections
#define R_DATA          PORTB

// RA0-RA5,RE0-RE1 (8 bits)
#define R_ADDR_MSB      PORTA  // msb RA0-RA5 lsb
#define R_ADDR_LSB      PORTE  // msb RE0-RE1 lsb

// IOW port
#define R_IOW           RE2

// PLL data pins
#define R_PLL_STRQ      RB3
#define R_PLL_CE        RB7
#define R_PLL_CLK       RB6
#define R_PLL_DATA      RB5

// tone/volume pins
#define R_VOL_CLK       RB4
#define R_VOL_DATA      RB0
#define R_BOL_CE        RB1

// write to isa bus
#define RADIO_ISA_WRITE()\
{\
    R_IOW = 0;\
    delay_us(5);\
    R_IOW = 1;\
    delay_us(5);\
}

// initalize radio module
#define radio_init()\
{\
    TRISB = 0x0;\
    TRISA = 0x0;\
    TRISE = 0x0;\
    PCFG0 = 0x1;\
    PCFG1 = 0x1;\
    PCFG2 = 0x1;\
    R_IOW = 1;\
    R_PLL_STRQ = 0;\
}

// set isa bus address
void radio_set_address(unsigned char addr);

// clock data to radio PLL
void radio_clockdata(unsigned char bits);

// select fm station
void radio_select_fm(unsigned short freq);

// set volume
void radio_set_volume(unsigned char volume);

// set treble
void radio_set_treble(unsigned char treble);

// set bass
void radio_set_bass(unsigned char bass);

#endif // __RADIO_H

