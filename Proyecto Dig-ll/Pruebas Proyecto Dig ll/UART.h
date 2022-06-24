/*
 * File:   Conf_usart.h
 * Author: Braya
 *
 * Created on 16 de junio de 2022, 08:57 AM
 */
#ifndef CONFIG
#define	CONFIG

// PIC16F877A Configuration Bit Settings

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

#define _XTAL_FREQ 4000000

#include <../include/proc/pic16f877.h>

//#include <../include/proc/pic16f877a.h>
#include <stdint.h>     // uint8_t, uint16_t, ...
#include <stdio.h>      // sprintf(), printf(), scanf(), ...
//#include "lcd.h"        // lcd header file

#endif	/* CONFIG */


/************** Prototipo de funciones ******************/

void UART_init(void);
char UART_read(void);
//void UART_write(char dato);


/************* Implementacion de funciones ****************/

void UART_init(void)
{
    TRISCbits.TRISC7 = 1;   //RX input
    TRISCbits.TRISC6 = 0;   //TX output 
    
    TXSTAbits.SYNC = 0;     //UART
    TXSTAbits.TX9 = 0;      //8 BITS
    TXSTAbits.BRGH = 1;     //ALTA VELOCIDAD
    SPBRG = 129;            //9600 a 20MHZ
    RCSTAbits.SPEN = 1;     //UART on    
    TXSTAbits.TXEN = 1;     //TX on
    RCSTAbits.CREN = 1;     //RX on
}

char UART_read(void)
{
    if (PIR1bits.RCIF == 1)
        return RCREG;
    else
        return 0;
}

 /*void UART_write(char dato)  //Enviar datos-caracteres
{
    TXREG = dato;
     while(TXSTAbits.TRMT == 0);
}

*/
