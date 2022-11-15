#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"
#include "diskoteka.h"
LCD_DISCO_F469NI lcd;

#define T1DELAY 1s
#define T2DELAY 1500ms
#define T3DELAY 500ms

#define T1TEXT "Thread 1"
#define T2TEXT "Thread 2"
#define T3TEXT "Thread 3"

Thread t1,t2,t3;

void worker1(){
    while (true) {
        lcd.SetTextColor(LCD_COLOR_BLACK); 
        lcd.DisplayStringAt(0, LINE(1), (uint8_t *)T1TEXT, CENTER_MODE);
        ThisThread::sleep_for(T1DELAY);
        lcd.SetTextColor(LCD_COLOR_WHITE); 
        lcd.DisplayStringAt(0, LINE(1), (uint8_t *)T1TEXT, CENTER_MODE);
        ThisThread::sleep_for(T1DELAY);
    }
}

void worker2(){
    while (true) {
        lcd.SetTextColor(LCD_COLOR_BLACK); 
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)T2TEXT, CENTER_MODE);
        ThisThread::sleep_for(T2DELAY);
        lcd.SetTextColor(LCD_COLOR_WHITE); 
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)T2TEXT, CENTER_MODE);
        ThisThread::sleep_for(T2DELAY);
    }
}

void worker3(){
    while (true) {
        lcd.SetTextColor(LCD_COLOR_BLACK); 
        lcd.DisplayStringAt(0, LINE(3), (uint8_t *)T3TEXT, CENTER_MODE);
        ThisThread::sleep_for(T3DELAY);
        lcd.SetTextColor(LCD_COLOR_WHITE); 
        lcd.DisplayStringAt(0, LINE(3), (uint8_t *)T3TEXT, CENTER_MODE);
        ThisThread::sleep_for(T3DELAY);
    }
}


int main() {  
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_WHITE);
    t1.start(worker1);
    t2.start(worker2);
    t3.start(worker3);
}

