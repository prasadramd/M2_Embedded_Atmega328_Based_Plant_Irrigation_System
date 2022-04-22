/*
* main.c
*
* Created: 20-5-2017
* Author: HdH
* Description: main, initializing en starting the app
* Global functions:
*
*
*/
 
#define WATCHDOG_ALARM 2
#define NO_ALARM 0
 
#include <avr/io.h>
#include "i2cdisplay.h"
 
void errorHandle(int receivedAlarm);
int operational(void);
void initialize(void);
 
/****************************************************************************
    Public vars
****************************************************************************/
 
int errorCode = NO_ALARM; //
char alarmText[] = "Alarm in app";
 
int main(void)
{
    initialize(); //start only once (setup with Arduino)
     
    errorCode = operational(); //the main loop
    if (errorCode == WATCHDOG_ALARM){ // you only end up here if there is an alarm.
        errorHandle(errorCode);
    }
    else{
        errorHandle(errorCode); //one of the apps is returning the error
    }
}
 
void errorHandle(int receivedAlarm){
     
    int i;
     
    while(1){ //blink some leds or show an error message on a display..
         
        clear();
        setCursor(1,0);
        for(i=0; i<12; i++){
            writeI2cDisplay(alarmText[i], DATAREGISTER);
        }
    }
}