#include "lcd.h"


void lcd_reset()
{
	lcd_cmd(0x02);    //LCD 4 Bit mode
	lcd_cmd(0x0e);    //Pass Command as Argument //Display On, Cursor blinking
	lcd_cmd(0x01);    //Pass Command as Argument //Clear Display Screen
	lcd_cmd(0x28);    //Pass Command as Argument //4 bit, 2 line, 5x7 dots/pixel 
	lcd_cmd(0x80);    //Pass Command as Argument //Force Cursor to beginning of 2nd row
}
void lcd_cmd(unsigned char data)
{
 unsigned char data_l, data_u;
 data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
 data_u = data&0xf0;  //select upper nibble

 I2C_Start(SLAVE_ADDRESS);
 //I2C_write (SLAVE_ADDRESS);
 I2C_Write (data_u|0x0C);  //enable=1 and rs =0
 delay1();
 I2C_Write (data_u|0x08);  //enable=0 and rs =0

 I2C_Write (data_l|0x0C);  //enable =1 and rs =0
 delay1();
 I2C_Write (data_l|0x08);  //enable=0 and rs =0

 I2C_Stop();
}	
void lcd_data(unsigned char data)
{
unsigned char data_l, data_u;
 data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
 data_u = data&0xf0;  //select upper nibble

 I2C_Start(SLAVE_ADDRESS);
 //I2C_write (SLAVE_ADDRESS);
 I2C_Write (data_u|0x0D);  //enable=1 and rs =1
 delay1();
 I2C_Write (data_u|0x09);  //enable=0 and rs =1

 I2C_Write (data_l|0x0D);  //enable =1 and rs =1
 delay1();
 I2C_Write (data_l|0x09);  //enable=0 and rs =1

 I2C_Stop();
}				 
void delay1()
{
	int i,j;
	for(i=0;i<100;i++)
	 for(j=0;j<50;j++);
}


//void lcd_reset()
//{
//    lcd_cmd(0x38);
//    lcd_cmd(0x0E);
//    lcd_cmd(0x01);
//    lcd_cmd(0x80);
//    lcd_cmd(0x06);
//}
//
//void lcd_cmd(unsigned char cmd)
//{
//    LATD = cmd;
//    rs = 0;
//    rw = 0;
//    en = 0;
//    delay(15);
//    en = 1;    
//}
//
//void lcd_data(unsigned char dt)
//{
//    LATD = dt;
//    rs = 1;
//    rw = 0;
//    en = 0;
//    delay(15);
//    en = 1;    
//}
void delay(int a)
{
    int i,j;
    for(i = 0; i<100;i++)
        for(j = 0;j<a;j++);
}

