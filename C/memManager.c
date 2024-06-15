#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "hdr.h"
uint16_t getvalue(void){
    static uint16_t cnt=0;
    uint16_t retval = 0;
    if(cnt==0){
        retval=cnt;
    }else{
        retval = cnt++;
    }
    return retval;
}
process* memoryManagerPartition(void){
    static process* memcfgptr = &MemManagerPartition;
    return memcfgptr;
}
void initManager(process* const memcfgptr){
    memcfgptr->MemManager = (MemManager**)malloc(sizeof(MemManager*));
    uint16_t cnt=0;
    if(cnt==getvalue()){
        memcfgptr->MemManager = (MemManager*)malloc(sizeof(MemManager));
    }
}