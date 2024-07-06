#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
struct name{

} ;
typedef struct{
    uint8_t ch;
    uint32_t temp;
    uint16_t short_temp;
}tmp_struct;
typedef void(*fun_ptr)(void);
struct{
    char a;
    int b;
    short c;
}abc={0x1,0x2,0x3};
// abc ={0};
struct xyz{
    char c;
    int i;
    short s;
}xaz = {0x1,0x3,0x4};

int main(int argc, char* argv[], char** env){
    tmp_struct var = {.ch=0xFE, .short_temp=0xF0,.temp=0x300,};
    tmp_struct arr[2] = {[0]={.ch=0xFA, .temp=0xFFFE, .short_temp=0xFEF0},0x4,0x0,0x40};
    printf("var.ch = 0x%hx\n", var.ch);
    printf("var.temp = 0x%hx\n", var.temp);
    printf("var.short_temp = 0x%hx\n", var.short_temp);
    printf("arr[0].ch = 0x%hx\n", arr[0].ch);
    printf("arr[0].temp = 0x%hx\n", arr[0].temp);
    printf("arr[0].short_temp = 0x%hx\n", arr[0].short_temp);
    printf("arr[1].short_temp = 0x%hx\n", arr[1].short_temp);
    abc.a = 0x50;
    // xaz={0x1,0x3,0x4};
    printf("abc.a = 0x%hx\n", abc.a);
    return 0;
}