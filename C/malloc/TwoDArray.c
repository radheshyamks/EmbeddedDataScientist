#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[], char** env){
    int**p = (int**)malloc(sizeof(int*)*5);
    for(int i=0; i<5; i++){
        p[i] = (int*)malloc(sizeof(int)*5);
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            p[i][j]=0x10;
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ",p[i][j]);
        }
    }
    printf("\n");
    for(int i=0; i<5; i++){
        free(p[i]);
    }
    free(p);
    p = NULL;
    return EXIT_SUCCESS;
}