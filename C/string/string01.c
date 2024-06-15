#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char** env){
    char str[20] = "Radheshyam";
    printf("%s\n", str);
    printf("len = %d\n", strlen(str));
    char dest[20];
    char* p = strncpy(dest, str, strlen(str));
    dest[strlen(str)]='\0';
    printf("%s\n", dest);
    printf("%s\n", p);
    return 0;
}