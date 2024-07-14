#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef union{
    struct{
        uint8_t ch1;
        uint8_t ch2;
    }B;
    uint16_t U;
}abc;
typedef union{
    uint8_t ch;
    uint16_t U;
}A;
abc xyz;
A x1 = {.U=0xFFFF};
// x1.ch = 0xFF;
abc fun(void){
    xyz.B.ch1 = 0xFF;
    xyz.B.ch2 = 0xFF;
    return xyz;
}
char* Str(){
    return "Hello Chaudhary";
}
// uint16_t fun1(){
//     return 1;
// }
int main(int argc, char* argv[], char** env){
    // x1.ch = 0xFF;
    if(fun().U == 0xFF){
        printf("Equal = 0x%hx\n", xyz.U);
    }else{
        // printf("Not equal = 0x%hX\n",xyz.U);
        printf("Not equal = 0x%hX\n",fun().U);
    }
    // uint16_t x = tmp_var;
    printf("%s\n", Str());
    char* p = str();
    printf("0x%hx\n", x1.ch);
    return EXIT_SUCCESS;
}