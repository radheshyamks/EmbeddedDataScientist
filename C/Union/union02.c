#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
typedef union union01
{
    /* data */
    uint32_t U;
    struct pwrswtdrv{
        uint16_t a;
        uint8_t b;
        uint8_t c;
    }B;
}pwr;
pwr pwrswtch= {.U = 0xFF00FFFF};
struct xyz{
    uint32_t a;
    uint32_t b;
};
pwr fun(){
    pwr A ={.B = pwrswtch.B}; 
    return A;
}
int main(int argc, char* argv[], char** env){
    uint32_t localpwrswt = fun().U;
    struct xyz strct_k;
    strct_k.a = 10;
    strct_k.b = 0xFF;
    if(fun().B.a != 0xFFFF){
        printf("fun().B.a = 0x%x\n", fun().B.a);
    }else{
        printf("fun().B.a = 0x%X\n", fun().B.a);
    }
    printf("localpwrswt = 0x%X\n", localpwrswt);
    printf("pwrswtch = 0x%X\n",pwrswtch);
    printf("strct_k = 0x%X\n", strct_k.b);
    return 0;
}