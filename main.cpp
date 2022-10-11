#include <iostream>
#include "mbed.h"

DigitalOut led(LED1);
using namespace std;
void blink(const string& basicString);

const float DOT_DURATION = 0.2;
const float DASH_DURATION = 0.8;
const float DOT_DASH_SPACE = 0.5;
const float LETTER_PAUSE = 2;

int main() {
    std::string morseCode[26];
    morseCode[0] = ".-"; //A
    morseCode[1] = "-..."; //B
    morseCode[2] = "-.-."; //C
    morseCode[3] = "-.."; //D
    morseCode[4] = "."; //E
    morseCode[5] = "..-."; //F
    morseCode[6] = "--."; //G
    morseCode[7] = "...."; //H
    morseCode[8] = ".."; //I
    morseCode[9] = ".---"; //J
    morseCode[10] = "-.-"; //K
    morseCode[11] = ".-.."; //L
    morseCode[12] = "--"; //M
    morseCode[13] = "-."; //N
    morseCode[14] = "---"; //O
    morseCode[15] = ".--."; //P
    morseCode[16] = "--.-"; //Q
    morseCode[17] = ".-."; //R
    morseCode[18] = "..."; //S
    morseCode[19] = "-"; //T
    morseCode[20] = "..-"; //U
    morseCode[21] = "...-"; //V
    morseCode[22] = ".--"; //W
    morseCode[23] = "-..-"; //X
    morseCode[24] = "-.--"; //Y
    morseCode[25] = "--.."; //Z

    string name = "petr";

    while(1)
    {
        for (int i = 0; i < name.size(); i++) {
            blink(morseCode[name[i] - 'a']);
        }
    }

    return 0;
}

void blink(const string& code) {
    for (int i = 0; i < code.size(); i++) {
        switch(code[i]) {
            case '.':
                led = 0;
                wait(DOT_DURATION);
                break;
            case '-':
                led = 0;
                wait(DASH_DURATION);
                break;
            default:
                break;
        }
        led = 1;
        wait(DOT_DASH_SPACE);
    }
    wait(LETTER_PAUSE);
}