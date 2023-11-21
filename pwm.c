#include <p18f4550.h>
#include "vector_relocate.h"

void msdelay(unsigned int time);

void main(void)
{
    TRISCbits.TRISC2 = 0;
    TRISD = 0;
    PR2 = 0xBB;
    CCP1CON = 0x0C;
    T2CON = 0x07;
    PORTDbits.RD5 = 1;
    PORTDbits.RD6 = 0;

    while(1)
    {
        // for 20% duty cycle
        CCPR1L = 0x25;
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        msdelay(1000);

        // for 40% duty cycle
        CCPR1L = 0x4B;
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 0;
        msdelay(1000);
    }
}

void msdelay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 710; j++){}
    }
}