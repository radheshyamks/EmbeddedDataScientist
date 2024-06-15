#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
typedef enum status{
    E_ERROR=1, E_SUCCESS,E_FAILED,
}Status;
int main(){
    uint8_t x;
    scanf("%d", &x);
    uint16_t y = x;
    Status t;
    if(y==1){
        t = E_SUCCESS;
    }else if(y==2){
        t = E_ERROR;
    }else{
        t = E_FAILED;
    }
    switch(t){
        case E_ERROR:
            printf("Error\n");
            break;
        case E_SUCCESS:
            printf("Success\n");
            break;
        default:
            printf("Not matched\n");
            break;
    }
    return 0;
}