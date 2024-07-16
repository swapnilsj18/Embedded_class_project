/* 
 * File:   I2C_.h
 * Author: Dell
 *
 * Created on June 20, 2024, 11:15 PM
 */

#ifndef I2C__H
#define	I2C__H

#include "../projectsdefines.h"

//#define Bit_rate 9     //100Khz  //fosc - 4Mhz
#define Bit_rate 49     //100Khz  //fosc - 20Mhz - Actual H/W

#define SLAVE_ADDRESS 0x27<<1  //Actual H/w address
//#define SLAVE_ADDRESS 0x20<<1

#ifdef	__cplusplus
extern "C" {
#endif
    void I2C_Init(void);
    char I2C_Start(char);
    void I2C_Ready(void);
    char I2C_Stop(void);
    char I2C_Write(unsigned char data);
    void delay2(int a);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C__H */

