#include <reg51.h>

void msdelay(unsigned int time);

void main(void)
{
    while(1)
    {
        P1 = 0x06;
        msdelay(250);
        P1 = 0x0C;
        msdelay(250);
        P1 = 0x09;
        msdelay(250);
        P1 = 0x03;
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