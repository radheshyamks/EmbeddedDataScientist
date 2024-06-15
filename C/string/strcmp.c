#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 100

int main(int argc, char* argv[], char** env){
    char str[BUFF_SIZE] = "Here is my name";
    char dest[BUFF_SIZE] = "here is My Name";

    char str1[BUFF_SIZE] = "Here is my name";
    char str2[BUFF_SIZE] = "Here is my name";

    // printf("%d\n", strlen(str));
    int32_t ret_val = strcmp(str, dest);
    if(ret_val == 0 ){
        fprintf(stdout, "Strings are Same: %d", ret_val);
    }else{
        fprintf(stderr, "Strings are not same: %d\n", ret_val);
    }

    // printf("%d\n", strlen(str));
    int32_t ret_val1 = strcmp(str1, str2);
    if(ret_val1 == 0 ){
        fprintf(stdout, "Strings are Same: %d", ret_val1);
    }else{
        fprintf(stderr, "Strings are not same: %d\n", ret_val1);
    }

    return EXIT_SUCCESS;
}