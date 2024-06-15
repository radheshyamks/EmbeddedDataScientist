#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/*
int main(int argc, char* argv[], char** env){
    uint32_t* cntSbrk = sbrk(0);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
*/

int main(int argc, char* argv[], char** env){
    uint32_t* cntSbrk = (uint32_t* )sbrk(0);
    int32_t c  = brk(cntSbrk);
    printf("c = %d\n",c);
    printf("%d\n", cntSbrk);
    cntSbrk = (uint32_t* )sbrk(0);
    c  = brk(cntSbrk);
    printf("c = %d\n",c);
    printf("%p\n", cntSbrk);
    cntSbrk = (uint32_t* )sbrk(0xa);
    c  = brk(cntSbrk);
    printf("c = %d\n",c);
    printf("%p\n", cntSbrk);
    return 0;
}