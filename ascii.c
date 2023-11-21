#include <reg51.h>

void msdelay(unsigned int time);

void main(void)
{
    unsigned int z;
    for(z = 'A'; z <= 'Z'; z++)
    {
        P1 = z;
        msdelay(1000);
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