#include <p18f4550.h>
#include "vector_relocate.h"

void msdelay(unsigned int time);

#define LCD_data PORTD;
#define ctrl PORTE;
#define rs PORTEbits.RE0;
#define rw PORTEbits.RE1;
#define en PORTEbits.RE2;

void init();
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_write_string(static char *arr);

void main(void)
{
    INTCON2bits.RBPU = 0;
    ADCON1 = 0x0F;

    char var1[] = "welcome";
    char var2[] = "to MC";

    init();
    msdelay(100);

    LCD_write_string(var1);
    msdelay(100);

    LCD_command(0xC0);
    msdelay(100);
    
    LCD_write_string(var2);
    msdelay(100);

    while (1);
}

void init()
{
    LCD_command(0x38); // initializes the LCD
    msdelay(100);
    LCD_command(0x01); // clear the screen
    msdelay(100);
    LCD_command(0x0E); // curson on
    msdelay(100);
    LCD_command(0x80); // selects the first line
    msdelay(100);
}

void LCD_command(unsigned char cmd)
{
    LCD_data = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    msdelay(100);
    en = 0;
}

void LCD_data(unsigned char data)
{
    LCD_data = data;
    rs = 1;
    rw = 0;
    en = 1;
    msdelay(100);
    en = 0;
}

void LCD_write_string(static char *arr)
{
    unsigned int i;
    while (arr[i] != '\0')
    {
        LCD_data(str[i]);
        msdelay(100);
        i++;
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