#include <stdio.h>
#include <stdint.h>

typedef enum{
    LOW,
    HIGH,
}LedStatus;
typedef enum{
    INPUT,
    OUTPUT,
}LedPinStatus;
typedef struct{
    uint16_t Led1;
    uint16_t Led2;
    uint16_t Led3;
    uint16_t Led4;
    uint16_t Led5;
    uint16_t Led6;
    uint16_t Led7;
    uint16_t Led8;
    uint16_t Led9;
    uint16_t Led10;
}LedPinNumber;
LedPinNumber LedNumber;
void loop(void);
void delay(uint32_t);
void digitalWrite(uint16_t led, LedStatus status);
void pinMode(uint16_t led, LedPinStatus pinStatus);
void LedPinSetup(uint16_t led, LedStatus status);
void setup(void);
void status(void);

uint16_t led=10;
uint16_t LedPin=0;
LedStatus LedState=LOW;
LedPinStatus LedPinState=INPUT;

int main(int argc, char* argv[], char** env){
    setup();
    loop();
    status();
    return 0;
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
    delay(100000000); // wait for a second
    digitalWrite(led,LOW); // turn the LED OFF(LOW is the voltage level)
    delay(100000000); // wait for a second
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