/* 
 * File:   lcd.h
 * Author: Dell
 *
 * Created on May 2, 2024, 3:30 PM
 */

#ifndef LCD_H
#define	LCD_H

#include "../projectsdefines.h"
#include "I2C_.h"

//#define rs PORTCbits.RC0
//#define rw PORTCbits.RC1
//#define en PORTCbits.RC2

#define c1 PORTBbits.RB4
#define c2 PORTBbits.RB5
#define c3 PORTBbits.RB6
#define c4 PORTBbits.RB7

#define r1 PORTBbits.RB0
#define r2 PORTBbits.RB1
#define r3 PORTBbits.RB2
#define r4 PORTBbits.RB3

#ifdef	__cplusplus
extern "C" {
#endif
    
    void lcd_cmd(unsigned char);
    void lcd_data(unsigned char);
    void lcd_reset(void);
    void delay1(void);
    void delay(int a);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

