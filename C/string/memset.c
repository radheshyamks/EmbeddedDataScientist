#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 20
int main(int argc, char* argv[], char** env){
    char str[STR_SIZE];
    memset(str,0x41,STR_SIZE* sizeof(char));
    str[STR_SIZE-1] = '\0';
    printf("%s\n", str);
    return 0;
}