#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 50

int main(int argc, char* argv[], char** env){
    char str[BUFF_SIZE] = "Here is my name";
    char dest[BUFF_SIZE] = "Here";
    int32_t retval = strncmp(dest, str, strlen(dest));
    if(retval==0){
        fprintf(stdout, "sub string is present. Success Code: %d\n", retval);
    }else{
        fprintf(stderr, "sub string is not present. Error Code: %d\n", retval);
    }
}