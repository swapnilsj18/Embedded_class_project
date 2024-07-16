#include "keypad.h"
#include "lcd.h"
#include "app.h"

extern int i;
extern char ch;
void col1()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
      //   type_passcode[i]='7';  //for simulation
        type_passcode[i]='1';   // for actual H/W 
        ch = '1';               // for actual H/W 
    }
    
    r1=1;
    r2=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
        //  type_passcode[i]='4';  //for simulation
        type_passcode[i]='4';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
//        type_passcode[i]='1'; //for simulation
//        ch = '1';
       type_passcode[i]='7';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c1==0)
    {
        while(c1==0)
            ;
            lcd_data('*');
           // type_passcode[i] = 'o'; //for simulation 
          type_passcode[i]='*';   // for actual H/W 
    }
    r4=1;
 }
void col2()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
        //type_passcode[i]='8'; //for simulation
        type_passcode[i]='2';   // for actual H/W 
        ch  ='2';
       
    }
    
    r1=1;
    r2=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
       // type_passcode[i]='5'; //for simulation
        type_passcode[i]='5';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
//          type_passcode[i]='2';
//          ch = '2';              //for simulation
        type_passcode[i]='8';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c2==0)
    {
        while(c2==0)
            ;
            lcd_data('*');
            //type_passcode[i] = '0';  //for simulation
            type_passcode[i]='0';   // for actual H/W 
    }
    r4=1;
 }
void col3()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
       // type_passcode[i]='9';  //for simulation
        type_passcode[i]='3';   // for actual H/W 
        ch  = '3';
    }
    
    r1=1;
    r2=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
       // type_passcode[i]='6'; //for simulation
        type_passcode[i]='6';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
//        type_passcode[i]='3';  //for simulation
//        ch = '3';
        type_passcode[i]='9';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c3==0)
    {
        while(c3==0)
            ;
            lcd_data('*');
            //  type_passcode[i] = '=';  //for simulation
            type_passcode[i]='#';   // for actual H/W 
    }
    r4=1;
 }

void col4()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
      // type_passcode[i]='/'; //for simulation
        type_passcode[i]='A';   // for actual H/W 
    }
    
    r1=1;
    r2=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
        //type_passcode[i]='x';   //for simulation
        type_passcode[i]='B';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
      //type_passcode[i]='-';     //for simulation
        type_passcode[i]='C';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c4==0)
    {
        while(c4==0)
            ;
            lcd_data('*');
           //type_passcode[i] = '+';  //for simulation
            type_passcode[i]='D';   // for actual H/W 
    }
    r4=1;
 }
void col5()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
        //set_user_passcode[i]='7';  //for simulation
        set_user_passcode[i]='1';   // for actual H/W 
    }
    
    r1=1;
    r2=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
       // set_user_passcode[i]='4';  //for simulation
        set_user_passcode[i]='4';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c1==0)
    {
        while(c1==0)
            ;
        lcd_data('*');
        //set_user_passcode[i]='1'; //for simulation
       set_user_passcode[i]='7';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c1==0)
    {
        while(c1==0)
            ;
            lcd_data('*');
         // set_user_passcode[i] = 'o'; //for simulation 
          set_user_passcode[i]='*';   // for actual H/W 
    }
    r4=1;
 }
void col6()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
       // set_user_passcode[i]='8'; //for simulation
        set_user_passcode[i]='2';   // for actual H/W 
       
    }
    
    r1=1;
    r2=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
        //set_user_passcode[i]='5'; //for simulation
        set_user_passcode[i]='5';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c2==0)
    {
        while(c2==0)
            ;
        lcd_data('*');
         //      set_user_passcode[i]='2';
        set_user_passcode[i]='8';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c2==0)
    {
        while(c2==0)
            ;
            lcd_data('*');
            //set_user_passcode[i] = '0';  //for simulation
            set_user_passcode[i]='0';   // for actual H/W 
    }
    r4=1;
 }
void col7()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
         //set_user_passcode[i]='9';  //for simulation
        set_user_passcode[i]='3';   // for actual H/W 
    }
    
    r1=1;
    r2=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
       // set_user_passcode[i]='6'; //for simulation
        set_user_passcode[i]='6';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c3==0)
    {
        while(c3==0)
            ;
        lcd_data('*');
          //    set_user_passcode[i]='3';  //for simulation
        set_user_passcode[i]='9';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c3==0)
    {
        while(c3==0)
            ;
            lcd_data('*');
          //  set_user_passcode[i] = '=';  //for simulation
            set_user_passcode[i]='#';   // for actual H/W 
    }
    r4=1;
 }

void col8()
{
    r1=r2=r3=r4=1;
    r1=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
       // set_user_passcode[i]='/'; //for simulation
        set_user_passcode[i]='A';   // for actual H/W 
    }
    
    r1=1;
    r2=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
       // set_user_passcode[i]='x';   //for simulation
        set_user_passcode[i]='B';   // for actual H/W 
    }
    
    r2=1;
    r3=0;
    if(c4==0)
    {
        while(c4==0)
            ;
        lcd_data('*');
        //set_user_passcode[i]='-';     //for simulation
        set_user_passcode[i]='C';   // for actual H/W 
    }
    
    r3=1;
    r4=0;
    if(c4==0)
    {
        while(c4==0)
            ;
            lcd_data('*');
          // set_user_passcode[i] = '+';  //for simulation
           set_user_passcode[i]='D';   // for actual H/W 
    }
    r4=1;
 }

