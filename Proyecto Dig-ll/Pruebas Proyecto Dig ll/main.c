/*
 * File:   main.c
 * Author: Braya
 *
 * Created on 16 de junio de 2022, 09:03 AM
 */



#include <xc.h>
#include "UART.h"

#define LED1 PORTBbits.RB0
#define LED2 PORTBbits.RB1
#define LED3 PORTBbits.RB2
#define MOTOR PORTBbits.RB3

void main(void) {
    TRISCbits.TRISC0 = 1; // como entrada C0
    char dato_rx;
    TRISB = 0B11110000;     // Como salida B0,B1,B2,B3
    PORTB = 0X00;   // Limpiar Puerto
    UART_init();
    
    
    while(1)
    {
        if(PORTCbits.RC0 == 1)  //Botón
         {
             PORTBbits.RB3 = 0XFF ;
         }
        dato_rx = UART_read();
          
        switch(dato_rx)     //Leds y motor
        {            
            case 'A':
                LED1 = 1;
               
                break;
                
            case 'B':
              
                LED1 = 0;
                break;
                
            case 'C':
                LED2 = 1;
               
                     break;
                     
            case 'D':
                LED2 = 0;
                
                      break;
                      
            case 'E':
                LED3 = 1;
                
                     break;
                     
            case 'F':
                LED3 = 0;
                
                      break;     
                     
            case'G':
                MOTOR = 1;
                
                      break;
                      
             case'H':   
                MOTOR = 0;
                
                      break;         
                      
        }           
    }
    return;
}
