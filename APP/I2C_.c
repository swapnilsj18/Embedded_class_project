#include "I2C_.h"

void I2C_Init(void)
{
	SSPSTAT = 0x80;   // Slew rate control disabled for Standard Speed mode (100KHz and 1MHz)
	SSPCON1 = 0x28;   //Enables the serial port and configures the SDA and SCL pins as the serial port pins ,
	                  //I2C Master mode, clock = FOSC/(4 * (SSPADD + 1)) 
	SSPCON2 = 0x00;
	SSPADD  = Bit_rate;  //clk 100KHz
	PIR1bits.SSPIF = 0;
}

void I2C_Ready(void)
{
	while(PIR2bits.BCLIF); //wait if bit/bus collision interrupt flag bit is set
	while(SSPSTATbits.BF || SSPSTATbits.R);  //waiting for transmission
	PIR1bits.SSPIF = 0;
}
char I2C_Write(unsigned char data)
{
	SSPBUF = data;  //write data into SSPBUF
	I2C_Ready();
	if(SSPCON2bits.ACKSTAT)  //check ack bit 
	return 1;               //read
	else
	return 0;               //write
}

char I2C_Start(char slave_write_address)
{
	SSPCON2bits.SEN = 1;  // Initiates Start condition on SDA and SCL pins
	while(SSPCON2bits.SEN);   //wait high to low signal
	PIR1bits.SSPIF = 0;
	if(!SSPSTATbits.S)  //Check whether Start bit has been detected last
	return 0;
	return (I2C_Write(slave_write_address));  //0x85
}
char I2C_Stop(void)
{
	I2C_Ready();
	SSPCON2bits.PEN = 1;    //Initiates Stop condition on SDA and SCL pins
	while(SSPCON2bits.PEN);  //wait for end of pulse i.e low to high pulse
	PIR1bits.SSPIF = 0;
	if(!SSPSTATbits.P)    //check whether stop bit is detected last
	return 0;
}
void delay2(int a)
{
	int i,j;
	for(i=a;i<345;i++)
	for(j=0;j<12;j++);
}
