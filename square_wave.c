#include <reg51.h>

void msdelay(unsigned int time);

void main(void)
{
    int i;
    P1 = 0x00;
    while(1)
    {
        P1 = 0x00;
        msdelay(250);
        P1 = 0xFF;
        msdelay(250);
    }
}

void msdelay(unsigned int time)
{
    unsigned int i,j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 1275; j++){}
    }
}