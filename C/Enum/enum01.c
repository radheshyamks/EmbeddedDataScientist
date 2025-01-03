#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
uint8_t timer;
uint8_t timer_cnt;
void TimerReset(void);
enum abc{
    CONDUNDEF=0,
    POWEROFF,
    POWERON,
    RESTART,
    ERRORDETECT,
};
enum array_size{
    ARRAY_SIZE=10,
};
typedef enum{
    RESET1=1,
    POWEROFF1=2,
    RESTART1=3,
}PowerButton;
uint32_t arr[ARRAY_SIZE]={10,20,30,40,[9]=40};
int main(int argc, char* argv[], char** env){
    PowerButton PwrBtn = POWEROFF1;
    for(int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter PwrBtn value: ");
    scanf("%d", &PwrBtn);
    switch(PwrBtn){
        case RESET1:
            printf("RESET1 = %d\n", PwrBtn);
            TimerReset();
            break;
        case POWEROFF1:
            printf("POWEROFF1 = %d\n", PwrBtn);
            break;
        case RESTART1:
            printf("RESTART1 = %d\n", PwrBtn);
            break;
        default:
            printf("Wrong Choice = %d\n", PwrBtn);
            break;
    }
    printf("\n");
    return 0;
}
void TimerReset(void){
    timer=0;
    timer_cnt=0;
    return;
}