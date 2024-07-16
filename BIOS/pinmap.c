/* 
 * File:   pinmap.c
 * Author: Dell
 *
 * Created on May 2, 2024, 3:36 PM
 */

#include "pinmap.h"

void initPinmap(void)
{
    ADCON1 = 0x0F;
    //TRISC = 0x10;
    TRISD = 0x00;
    TRISB = 0xF0;
    TRISA = 0xFE;
    //LATC = 0x00;
   // LATD = 0x00;
    INTCON2bits.RBPU = 0;
}
