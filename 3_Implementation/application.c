/*
 * operational.c
 *
 * Created: 20-5-2017 15:07:22
 * Author: HdH
 * Description: Application for multi threat, show lcd clock
 */
 
#include <avr/io.h>
#include "i2c.h"
#include "i2cdisplay.h"
 
void showTime(); // showing the time
 
/****************************************************************************
    Public vars
****************************************************************************/
 
extern int alarmCode;
extern int timeSecApp1;
extern int timeMinApp1;
int oldTime;
 
void Application1(void){
 
    showTime();
     
}
 
void showTime(){
    int seconds;
    int minutes;
     
     
    seconds = timeSecApp1;
    minutes = timeMinApp1;
     
    if (oldTime == timeSecApp1){
        return;
    }
    if (seconds >= 10){
        setCursor(11,2);
        writeI2cDisplay(seconds/10+48, DATAREGISTER);
        setCursor(12,2);
        writeI2cDisplay(seconds%10+48, DATAREGISTER);
        if (minutes>=10){
            setCursor(8,2);
            writeI2cDisplay(minutes/10+48, DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes%10+48, DATAREGISTER);
        }
        if (minutes<10){
            setCursor(8,2);
            writeI2cDisplay('0', DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes+48, DATAREGISTER);
        }
    }
    else if (seconds < 10){ setCursor(12,2); writeI2cDisplay(seconds+48, DATAREGISTER); setCursor(11,2); writeI2cDisplay('0', DATAREGISTER); if (minutes>=10){
            setCursor(8,2);
            writeI2cDisplay(minutes/10+48, DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes%10+48, DATAREGISTER);
        }
        if (minutes<10){
            setCursor(8,2);
            writeI2cDisplay('0', DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes+48, DATAREGISTER);
        }
    }
    oldTime = timeSecApp1;
}