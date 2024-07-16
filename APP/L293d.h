/* 
 * File:   L293d.h
 * Author: Dell
 *
 * Created on May 2, 2024, 3:31 PM
 */

#ifndef L293D_H
#define	L293D_H

#include "../projectsdefines.h"

#define IN3 PORTDbits.RD6
#define IN4 PORTDbits.RD7  //for H/W

#define relayPin PORTAbits.RA0  //for led control or solenoid lock

//#define IN3 PORTDbits.RD3
//#define IN4 PORTDbits.RD4 //for simulation


#ifdef	__cplusplus
extern "C" {
#endif
    
    void motor_forward(void);
    void motor_reverse(void);
    void motor_off(void);




#ifdef	__cplusplus
}
#endif

#endif	/* L293D_H */

