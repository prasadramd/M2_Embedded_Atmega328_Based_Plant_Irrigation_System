/*
 * initialize.c
 *
 * Created: 20-5-2017 15:07:22
 * Author: HdH
 * Description: initialization off the project
 */
 
#define PIN_LED1 6
#define PIN_LED2 7
#define PIN_LED3 8
 
#include <avr/interrupt.h>
#include "gpiolib.h"
#include "timer4clocklib.h"
#include "i2c.h"
#include "i2cdisplay.h"
 
 
void initialize(){
     
    char openingText[] = "www.hdhprojects.nl";
    char clockText[] = "Clock";
    int i;
 
    cli();//interrupts disable
    tmr2_init(); // initialize timer2
    i2c_init(); // initialize i2c protocol
    i2cLcd_Init(); // initialize i2c lcd
    sei();//interrupts enable
     
    clear();
    setCursor(1,0);
    for(i=0; i<18; i++){     
        writeI2cDisplay(openingText[i], DATAREGISTER);
    }
    setCursor(1,2);
    for(i=0; i<5; i++){
        writeI2cDisplay(clockText[i], DATAREGISTER);
    }
    setCursor(10,2);
    writeI2cDisplay(':', DATAREGISTER);
     
     
    pinMode(PIN_LED1,PINMODEOUTPUT); //set pin to output
    pinMode(PIN_LED2,PINMODEOUTPUT); //set pin to output
    pinMode(PIN_LED3,PINMODEOUTPUT); //set pin to output    
}