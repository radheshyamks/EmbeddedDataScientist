#include <stdio.h>
#include <stdint.h>
#include "led.h"
extern uint16_t led;
extern uint16_t LedPin;
extern LedStatus LedState;
extern LedPinStatus LedPinState;

int main(int argc, char* argv[], char** env){
    AfterStatus();
    setup();
    loop();
    status();
    return 0;
}
void AfterStatus(void){
    printf("led = %u\n",led);
    printf("LedPin = %u\n",LedPin);
    printf("LedState = %u\n",LedState);
    printf("LedPinState = %u\n",LedPinState);
    printf("LedNumber.Led10 = %u\n\n",LedNumber.Led10);
}
void status(void){
    printf("led = %u\n",led);
    printf("LedPin = %u\n",LedPin);
    printf("LedState = %u\n",LedState);
    printf("LedPinState = %u\n",LedPinState);
    printf("LedNumber.Led10 = %u\n",LedNumber.Led10);
}
// the function loop will run over and over again
void loop(){
    digitalWrite(led,HIGH); // turn the LED ON(HIGH is the voltage level)
    delay(100000000); // wait for two second
    digitalWrite(led,LOW); // turn the LED OFF(LOW is the voltage level)
    delay(100000000); // wait for two second
}
void setup(void){
    // initialize the digital pin as an output
    pinMode(led,OUTPUT);
}
void delay(uint32_t cnt){
    printf("Waiting...\n");
    while(--cnt);
    printf("Waiting is Over\n");
}
void digitalWrite(uint16_t led, LedStatus status){
    // LedSerNu.Led10 = lednum;
    LedPinSetup(led,status);
    // OutputPORT(status);
}/*
void OutputPORT(LedStatus status){
    LedState = status;
}*/
void LedPinSetup(uint16_t led, LedStatus status){
    LedPin = led;
    LedState = status;
}
void pinMode(uint16_t led, LedPinStatus pinStatus){
    LedNumber.Led10 = led;
    LedPinState = pinStatus;
}