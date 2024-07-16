/* 
 * File:   app.h
 * Author: Dell
 *
 * Created on May 2, 2024, 3:29 PM
 */

#ifndef APP_H
#define	APP_H
#include "../BIOS/bios.h"
#include "../projectsdefines.h"
#include "../APP/EEPROM.h"
#ifdef	__cplusplus
extern "C" {
#endif
    
    void runApp(void);
    
    
unsigned char s2[] = "Access Granted";
unsigned char s3[] = "Access Denied";
unsigned char wait1[] = "Wait for";
unsigned char wait2[] = "30 second:";
unsigned char admin_password_msg[]= "Admin Password";
unsigned char admin_passcode[4] = "1234";
unsigned char new_user_passcode[4] = "5678";
unsigned char type_passcode[] = "0000";
unsigned char enter_pass_msg[] = "Enter Password";
unsigned char set_user_passcode[4] = "5678";
unsigned char pass_set_msg[] = "1.Admin User";
unsigned char unlock_msg[] = "2.unlock  ";
unsigned char lock_msg[] = "3.lock";
char old_user_password[4] = {0};
char admin_password[4] = {0};

unsigned char renter_old_password_msg[] = "Enter old Pass";
unsigned char enter_user_Pass_msg[] = "Enter new Pass";
unsigned char password_match[] = "password match";
unsigned char new_pass_set_msg1[] = "New password";
unsigned char new_pass_set_msg2[] = "Set Successfully";
unsigned char password_not_match[] = "Wrong Password";
#ifdef	__cplusplus
}
#endif

#endif	/* APP_H */

