#include <reg51.h>

void main(void)
{
    int i;
    P1 = 0x00;
    while(1)
    {
        for(i = 0; i <= 255; i++)
        {
            P1 = i;
        }
        for(i = 255; i >= 0; i--)
        {
            P1 = i;
        }
    }
}