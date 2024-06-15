#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100

int main(int argc, char* argv[], char** env){
    char src[STR_SIZE]="Radheshyam Kumar Singh";
    char dest[STR_SIZE];
    memset(dest, 0, STR_SIZE);
    memcpy(dest, src, STR_SIZE);
    printf("%s\n", src);
    printf("%s\n", dest);
    return 0;
}