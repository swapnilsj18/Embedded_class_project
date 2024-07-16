
    #include "../projectsdefines.h"
    #include "app.h"
    #include "lcd.h"
    #include "L293d.h"
    #include "keypad.h"
    #include "I2C_.h"
    void compare(char c);
    void set_user_password(void);
    void unlock_door(void);
    void lock_door(void);
    char* user_validation(void);
    char* admin_validation(const char *adminP);
    int i;
    char ch;
    char c;
    uint8_t address = 0x00;  // EEPROM address
    void runApp()
    {
       // motor_off();
        I2C_Init();
	    delay2(5);
	    I2C_Ready();
	    delay2(5);
        lcd_reset();
        delay(500);
 /*        use this part of code only first time when manufacturer has to provide password which user can use      
//       write_to_eeprom(address+4, new_user_passcode[0]);   //5
//       write_to_eeprom(address+5, new_user_passcode[1]);  //6
//       write_to_eeprom(address+6, new_user_passcode[2]); //7
//       write_to_eeprom(address+7, new_user_passcode[3]); //8
  then remove it. after writing to memory
        */
       write_to_eeprom(address, admin_passcode[0]);   //1
       write_to_eeprom(address+1, admin_passcode[1]);  //2
       write_to_eeprom(address+2, admin_passcode[2]); //3
       write_to_eeprom(address+3, admin_passcode[3]); //4
       
       admin_passcode[0] = read_from_eeprom(address);
       admin_passcode[1] = read_from_eeprom(address+1);
       admin_passcode[2] = read_from_eeprom(address+2);
       admin_passcode[3] = read_from_eeprom(address+3);
       
        c1=c2=c3=c4=1;
        
        
    while(1)
    {
        set_user_passcode[0] = read_from_eeprom(address+4);
        set_user_passcode[1] = read_from_eeprom(address+5);
        set_user_passcode[2] = read_from_eeprom(address+6);
        set_user_passcode[3] = read_from_eeprom(address+7);
         for(i=0;pass_set_msg[i]!='\0';i++)
        {
            lcd_data(pass_set_msg[i]);
        }
         delay(200);
        lcd_cmd(0xc0);
        for(i=0;unlock_msg[i]!='\0';i++)
        {
            lcd_data(unlock_msg[i]);
        }
        delay(200);
        for(i=0;lock_msg[i]!='\0';i++)
        {
            lcd_data(lock_msg[i]);
        }
         for(i=0;i<1;i++)
           { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col1();
             }
             if(c2==0)
             {
                 col2();
             }
             if(c3==0)
             {
                 col3();
             }
          }
        switch(ch)
        {
            case '1':
                lcd_reset();
                sprintf(admin_password,"%c%c%c%c",admin_passcode[0],admin_passcode[1],admin_passcode[2],admin_passcode[3]);
                     if(admin_validation(admin_password)!=NULL)
                     {
                        lcd_reset();
                        
                        sprintf(old_user_password,"%c%c%c%c",set_user_passcode[0],set_user_passcode[1],set_user_passcode[2],set_user_passcode[3]);  
                        if(user_validation())
                        {
                             lcd_reset();
                             for(i=0;password_match[i]!='\0';i++)
                             {
                                lcd_data(password_match[i]);
                             }
                        delay(200);
                        lcd_reset();
                        set_user_password();
                        set_user_passcode[0] = read_from_eeprom(address+4);
                        set_user_passcode[1] = read_from_eeprom(address+5);
                        set_user_passcode[2] = read_from_eeprom(address+6);
                        set_user_passcode[3] = read_from_eeprom(address+7);
                        lcd_reset();
                            for(i=0;new_pass_set_msg1[i]!='\0';i++)
                            {
                                lcd_data(new_pass_set_msg1[i]);
                            }
                        delay(200);
                        lcd_cmd(0xc0);
                            for(i=0;new_pass_set_msg2[i]!='\0';i++)
                            {
                                lcd_data(new_pass_set_msg2[i]);
                            }
                        delay(200);
                        lcd_reset();
                        }
                        else
                        {
                             lcd_reset();  
                             for(i=0;password_not_match[i]!='\0';i++)
                             {
                                lcd_data(password_not_match[i]);
                             } 
                        delay(200);
                        lcd_reset(); 
                        }
                    }
                    else
                    {
                        lcd_reset();  
                        for(i=0;password_not_match[i]!='\0';i++)
                        {
                             lcd_data(password_not_match[i]);
                        } 
                        delay(200);
                        lcd_reset(); 
                    }
                break;
            case '2':
                lcd_reset();
                set_user_passcode[0] = read_from_eeprom(address+4);
                set_user_passcode[1] = read_from_eeprom(address+5);
                set_user_passcode[2] = read_from_eeprom(address+6);
                set_user_passcode[3] = read_from_eeprom(address+7);
                sprintf(old_user_password,"%c%c%c%c",set_user_passcode[0],set_user_passcode[1],set_user_passcode[2],set_user_passcode[3]);
                c = '1';
                unlock_door();
                break;
             case '3': 
                lcd_reset();
                set_user_passcode[0] = read_from_eeprom(address+4);
                set_user_passcode[1] = read_from_eeprom(address+5);
                set_user_passcode[2] = read_from_eeprom(address+6);
                set_user_passcode[3] = read_from_eeprom(address+7);
                sprintf(old_user_password,"%c%c%c%c",set_user_passcode[0],set_user_passcode[1],set_user_passcode[2],set_user_passcode[3]);
                c = '2';
                lock_door();
                break;
        }
    }  //while loop end
    }  //runApp loop end
    
    char* admin_validation(const char *adminP)
    {
        for(i=0;admin_password_msg[i]!='\0';i++)
         {
              lcd_data(admin_password_msg[i]);
         }
        lcd_cmd(0xc0);
        for(i=0;i<4;i++)
         { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col1();
             }
             if(c2==0)
             {
                 col2();
             }
             if(c3==0)
             {
                 col3();
             }
             if(c4==0)
             {
                 col4();
             }
          }
      char *p,*q;
      p=strstr((char*)type_passcode,(char*)adminP); 
      
      return p;
    }
    char* user_validation()
    {
        for(i=0;renter_old_password_msg[i]!='\0';i++)
         {
              lcd_data(renter_old_password_msg[i]);
         }
        lcd_cmd(0xc0);
        for(i=0;i<4;i++)
         { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col1();
             }
             if(c2==0)
             {
                 col2();
             }
             if(c3==0)
             {
                 col3();
             }
             if(c4==0)
             {
                 col4();
             }
          }
        
      char *p,*q;
      q = strstr((char*)type_passcode,(char*)old_user_password);
      return q;
        
    }
    
    void unlock_door()
    {
        for(i=0;enter_pass_msg[i]!='\0';i++)
         {
              lcd_data(enter_pass_msg[i]);
         }
         lcd_cmd(0xc0);

         for(i=0;i<4;i++)
         { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col1();
             }
             if(c2==0)
             {
                 col2();
             }
             if(c3==0)
             {
                 col3();
             }
             if(c4==0)
             {
                 col4();
             }
          }
         compare(c);
         delay(2000);
         lcd_reset(); 
    }
    void lock_door()
    {
        for(i=0;enter_pass_msg[i]!='\0';i++)
         {
              lcd_data(enter_pass_msg[i]);
         }
         lcd_cmd(0xc0);

         for(i=0;i<4;i++)
         { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col1();
             }
             if(c2==0)
             {
                 col2();
             }
             if(c3==0)
             {
                 col3();
             }
             if(c4==0)
             {
                 col4();
             }
          }
         compare(c);
         delay(2000);
         lcd_reset(); 
    }
    void set_user_password()
    {
         for(i=0;enter_user_Pass_msg[i]!='\0';i++)
         {
              lcd_data(enter_user_Pass_msg[i]);
         }
         lcd_cmd(0xc0);
         for(i=0;i<4;i++)
         { 
             r1=r2=r3=r4=0;
             while(c1==1 && c2==1 && c3==1 && c4==1);
             if(c1==0)
             {
                 col5();
             }
             if(c2==0)
             {
                 col6();
             }
             if(c3==0)
             {
                 col7();
             }
             if(c4==0)
             {
                 col8();
             }
          } 
       write_to_eeprom(address+4, set_user_passcode[0]);
       write_to_eeprom(address+5, set_user_passcode[1]);
       write_to_eeprom(address+6, set_user_passcode[2]);
       write_to_eeprom(address+7, set_user_passcode[3]);
       
    }
    void compare(char c)
    {
      char *p,*q;
     static  unsigned int count = 0;
      unsigned int j,k;
      p=strstr((char*)type_passcode,(char*)old_user_password);
      if(p!=NULL)
      {  
          count = 0;
      switch(c)
      {
            case '1':
            if(p!=NULL)
            {
         // i=0;
            lcd_cmd(0x01);
            for(i=0;s2[i]!='\0';i++)
            {
              lcd_data(s2[i]);
              motor_forward();
            }
            delay(20000); // for H/w
            //delay(1000);    // for simulation
            motor_off();
             }
            else
            {
            lcd_cmd(0x01);
          //i=0;
            for(i=0;s3[i]!='\0';i++)
            {
              lcd_data(s3[i]);
              motor_off();
            }
            }
            
            break;
            case '2':
            if(p!=NULL)
            {
         // i=0;
            lcd_cmd(0x01);
            for(i=0;s2[i]!='\0';i++)
            {
              lcd_data(s2[i]);
              motor_reverse();
            }
             delay(20000); // for H/w
            //delay(1000);    // for simulation
            motor_off();
             }
            else
            {
            lcd_cmd(0x01);
           //i=0;
            for(i=0;s3[i]!='\0';i++)
            {
              lcd_data(s3[i]);
              motor_off();
            }
            }
            
            break;
      }
      }
else
    {
       count++;
       lcd_reset();
       for(i=0;s3[i]!='\0';i++)
            {
              lcd_data(s3[i]);
            }
       if(p==NULL&&count==3)
       {
        lcd_reset();
        for(i=0;wait1[i]!='\0';i++)
         {
              lcd_data(wait1[i]);
         }
         lcd_cmd(0xc0);
         for(i=0;wait2[i]!='\0';i++)
         {
              lcd_data(wait2[i]);
         }
        for(j=0;j<3;j++)
         {
           for(k=0;k<=9;k++)
           {
              lcd_cmd(0xca);
              delay(200);
              lcd_data(j+'0');
              lcd_data(k+'0');
              delay(2000);
           }
         }
         count = 0;  
       }  
    }
}