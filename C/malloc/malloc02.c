#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define ONEGB (1<<30)

int main(int argc, char* argv[], char** env){
    // printf("0x%X\n", ONEGB);
    uint16_t cnt=0;
    while(1){
        // uint32_t*p  = (uint32_t*)malloc(ONEGB);
        if(malloc(ONEGB)==NULL){
            printf("No more memory is available\n");
            break;
        }else{
            // memset(p, 1, ONEGB);
            printf("Allocated Memory: %dGB\n", ++cnt);
        }
    }
    return 0;
}