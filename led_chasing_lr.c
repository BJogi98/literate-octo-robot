#include <reg51.h>

void msdelay(unsigned int time);

void main(void)
{
    unsigned int i;
    while(1)
    {
        P1 = 0x80;
        for(i = 0; i < 8; i++)
        {
            P1 = P1 >> 1;
            msdelay(1000);
        }
    }
}

void msdelay (unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 1275; j++){}
    }
}