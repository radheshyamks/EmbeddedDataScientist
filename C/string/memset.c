#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 20
int main(int argc, char* argv[], char** env){
    char str[STR_SIZE];
    char str1[STR_SIZE];
    char str2[STR_SIZE];
    memset(str,0x41,STR_SIZE* sizeof(char));
    memset(str1, 0x42, STR_SIZE* sizeof(char));
    memset(str2, 0x43, STR_SIZE* sizeof(char));
    str[STR_SIZE-1] = '\0';
    str1[STR_SIZE-1] = '\0';
    str2[STR_SIZE-1] = '\0';
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}