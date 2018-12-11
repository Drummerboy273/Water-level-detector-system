#include <16F877.h>                                                            // include the PIC16F877A library
#device  adc=10                                                                // setting the adc at 10 bit
#include <math.h>                                                              // including the library for the math operation
#fuses   XT,NOWDT,NOLVP                                                        // setting Cristal Clock, No watch dog timer and No low voltage protection
#use     delay(clock=4000000)                                                  // set the internal clock as 4MHz
#include "flex.c"   

void main()
{
float counter;
float percent;

   lcd_init();   
    while(1)
   {
   if(input(PIN_A1)==1){
   output_high(PIN_C0);
    delay_ms(300);
   }
   else output_low(PIN_C0);
   
   if(input(PIN_A2)==0){
   counter=0;
   output_low(PIN_C1);
    delay_ms(300);
   }
   else output_high(PIN_C1);
   
   if(input(PIN_A3)==1){
   output_high(PIN_C2);
    delay_ms(300);
   }
   else output_low(PIN_C2);
   
   if(input(PIN_A4)==1){
   output_high(PIN_C3);
    delay_ms(300);
   }
   else output_low(PIN_C3);
   
   
   if((input(PIN_A1)==1) &&input(PIN_A2)==1  && (input(PIN_A3)==1) && (input(PIN_A4)==1)){
   percent=80;
   }
   if((input(PIN_A1)==0) &&input(PIN_A2)==1  && (input(PIN_A3)==1) && (input(PIN_A4)==1)){
   percent=50;
   }
   if((input(PIN_A1)==0) &&input(PIN_A2)==0  && (input(PIN_A3)==1) && (input(PIN_A4)==1)){
   percent=20;
   }  
   if((input(PIN_A1)==0) &&input(PIN_A2)==0  && (input(PIN_A3)==0) && (input(PIN_A4)==1)){
   percent=5;
   } 
    if (input(PIN_A2)==1  || (input(PIN_A3)==1) || (input(PIN_A4)==1)){
    delay_ms(300);
     lcd_gotoxy(1,1);                                                         
      printf(LCD_PUTC,"water level at ");                        
      lcd_gotoxy(1,2);                                                         
      printf(LCD_PUTC,"%f percent", percent);
                     
    
   
   }
   if(percent== 80){
   output_high(PIN_C4);
    delay_ms(300);
    output_low(PIN_C5);
    delay_ms(300);
   
   }
   if(percent== 5){
   output_low(PIN_C4);
    delay_ms(300);
    output_high(PIN_C5);
    delay_ms(300);
   
   }
    delay_ms(200);
    }
             
     //delay_ms(350);  
}


