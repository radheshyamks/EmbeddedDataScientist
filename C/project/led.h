
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
void AfterStatus(void);

uint16_t led=10;
uint16_t LedPin=0;
LedStatus LedState=HIGH;
LedPinStatus LedPinState=INPUT;