#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"

LCD_DISCO_F469NI lcd;

#define T1DELAY 1s


Thread t1,t2;

void worker1(){
     lcd.SetTextColor(LCD_COLOR_BLACK); 
     lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Thread 1", CENTER_MODE);
     HAL_Delay(1000);
}

void worker2(){
        lcd.SetTextColor(LCD_COLOR_BLACK); 
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Thread 2", CENTER_MODE);
        HAL_Delay(2000);
}

int main() {  
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_WHITE);

    t1.start(worker1);
    t1.join();
    lcd.Clear(LCD_COLOR_WHITE);
    ThisThread::sleep_for(T1DELAY);

    t2.start(worker2);
    t2.join();
    lcd.Clear(LCD_COLOR_WHITE);
    ThisThread::sleep_for(T1DELAY * 2);
}

