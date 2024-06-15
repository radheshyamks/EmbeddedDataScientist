#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define STR_SIZE 100

int main(int argc, char* argv[], char** env){
    char str[STR_SIZE]="Radheshyam kumar singh";
    printf("%s\n", str);
    char dest[STR_SIZE];
    strcpy(dest, str);
    printf("%s\n", str);
    return 0;
}