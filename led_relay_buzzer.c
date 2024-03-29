#include <p18f4550.h>
#include "vector_relocate.h"

void msdelay(unsigned int time);

void main(void)
{
    unsigned char val = 0;
    unsigned int i;
    INTCON2bits.RBPU = 0;
    ADCON1 = 0x0F;
    TRISD = 0;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;

    while (1)
    {
        if (PORTBbits.RB0 == 0)
            val = 1;
        if (PORTBbits.RB1 == 0)
            val = 2;
        if (val == 1)
        {
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;
            msdelay(100);
            PORTD = 0x80;
            for (i = 0; i < 8; i++)
            {
                PORTD = PORTD >> 1;
            }
            msdelay(100);
        }
        if (val == 2)
        {
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            msdelay(100);
            PORTD = 0x01;
            for (i = 0; i < 8; i++)
            {
                PORTD = PORTD << 1;
            }
            msdelay(100);
        }
    }
}

void msdelay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 710; j++){}
    }
}