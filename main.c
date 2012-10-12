/*
**
**	alpha.c - test project for pic
**
*/
#include "delay.h"
#include "lcd.h"
#include "uart.h"
#include "radio.h"

// entry point
void main(void)
{
    char msgbuf[10];
    unsigned char q;
    unsigned short st_new, st_cur;
    unsigned char vol_new, vol_cur;

    uart_init();
    lcd_init();
    radio_init();

    uart_putstr("Ready");

    TRISC3 = 1;
    TRISC2 = 1;
    TRISC1 = 1;
    TRISC0 = 1;

    st_cur = 0;
    st_new = 902;

    vol_cur = 0;
    vol_new = 50;

    while(1) {

        delay_ms(50);

        if (RC3 == 0)
            st_new = st_cur + 1;
        if (RC2 == 0)
            st_new = st_cur - 1;
        if (RC1 == 0)
            vol_new = vol_cur + 1;
        if (RC0 == 0)
            vol_new = vol_cur - 1;

        if (st_cur != st_new)
        {
            st_cur = st_new;
            radio_select_fm(st_cur);
            q = st_cur / 10;
            msgbuf[0] = (q / 100) + 0x30;
            msgbuf[1] = ((q / 10) % 10) + 0x30;
            msgbuf[2] = (q % 10) + 0x30;
            msgbuf[3] = '.';
            msgbuf[4] = (st_cur % 10) + 0x30;
            msgbuf[5] = ' ';
            msgbuf[6] = 'M';
            msgbuf[7] = 'H';
            msgbuf[8] = 'Z';
            msgbuf[9] = '\0';
            lcd_cursorxy(0, 0);
            lcd_putstr(msgbuf);
            continue;
        }
        if (vol_cur != vol_new)
        {
            vol_cur = vol_new;
            radio_set_volume(vol_cur);
            msgbuf[0] = '-';
            msgbuf[1] = (vol_cur / 100) + 0x30;
            msgbuf[2] = ((vol_cur / 10) % 10) + 0x30;
            msgbuf[3] = (vol_cur % 10) + 0x30;
            msgbuf[4] = ' ';
            msgbuf[5] = 'D';
            msgbuf[6] = 'B';
            msgbuf[7] = '\0';
            lcd_cursorxy(0, 1);
            lcd_putstr(msgbuf);
            continue;
        }

    } // loop
}

