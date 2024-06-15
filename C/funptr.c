#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef void(*funptr)(void);
typedef uint16_t arr[5];
uint16_t g_var;
static arr arr1;
void fun(void){
    static uint16_t i=0;
    i++;
    if(i==1){
        g_var = i++;
    }else{
        g_var = ++i;
        for(uint16_t k=0; k<=i; k++){
            arr1[k]=k+2;
        }
    }
}
void fun_ptr(funptr foo){
    foo();
}
int main(int argc, char* argv[], char** env){
    fun();
    printf("%d\n", g_var);
    fun_ptr(fun);
    printf("%d\n", g_var);
    for(uint16_t k=0; k<5; k++){
        printf("%d ",arr1[k]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}