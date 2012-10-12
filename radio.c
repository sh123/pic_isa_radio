// radio.c - radio module access
#include "radio.h"
#include "delay.h"

/*
**
**  Data format (24 bits = 3 bytes):
** 
** [D0-D13][T0-T1][B0-B2][TB][R0-R2][S]
**
** 1. [D0-D13] (14 bits) - division ratio data
**   lsb     msb  
**
** 2. [T0-T1] (2 bits) - both 0
**
** 3. [B0-B2][TB] (4 bits) - band data
**
** 4. [R0-R2] (3 bits) - reference frequency data
**
** 5. [S] (1 bit) - divider 1-FMIN, 0-AMIN
**
** Example 100.7MHz VCO FM (= 90.0MHz):
**
**  [11110111:110000][00][0000][000][1]
**
*/
void radio_select_fm(unsigned short freq)
{

    unsigned char byte0, byte1, byte2;
    freq += R_FM_IF_FREQ;

    byte0 = (unsigned char)(freq & 0xff);
    byte1 = (unsigned char)(freq >> 8) | 0x0;
    byte2 = 0x80;

    radio_set_address(R_ISA_ADDR);
    R_PLL_CE = 1;
    radio_clockdata(byte0);
    radio_clockdata(byte1);
    radio_clockdata(byte2);
    R_PLL_CE = 0;
    R_PLL_CLK = 0;
    RADIO_ISA_WRITE();
}

// set radio isa bus address
void radio_set_address(unsigned char addr)
{
    // accept inverted RE1-R0,RA5-RA0
    R_ADDR_MSB = (addr) & 0x3f;
    R_ADDR_LSB = (addr >> 6) & 0x03;
}

// clock bits to radio PLL
void radio_clockdata(unsigned char bits)
{
    unsigned char bitcnt;
    for (bitcnt = 8; bitcnt > 0; bitcnt--) {

        // clocks LSB first
        if ((bits & 0x01) == 0x01)
            R_PLL_DATA = 1;
        else
            R_PLL_DATA = 0;

        R_PLL_CLK = 0;
        RADIO_ISA_WRITE();
        R_PLL_CLK = 1;
        RADIO_ISA_WRITE();

        bits >>= 1;
    }
}

// set volume
void radio_set_volume(unsigned char volume)
{
}

// set treble
void radio_set_treble(unsigned char treble)
{
}

// set bass
void radio_set_bass(unsigned char bass)
{
}

