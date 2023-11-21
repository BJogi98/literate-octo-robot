#include <reg51.h>

void msdelay(unsigned int time);

void main(void)
{
    unsigned int i,j;
    // P1 = 0x00;
    for(i = 0; i <= 9; i++)
    {
        for(j = 0; j <= 9; j++)
        {
            P1 = (i << 4) | j;
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