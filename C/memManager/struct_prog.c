#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include "hdr.h"
struct MemoryConfig memcfg;
process MemManagerPartition;
int main(int argc, char* argv[], char** env){
    uint16_t channelNo=0;
    uint16_t channelId=0;
    process* proc = memoryManagerPartition();
    initManager(proc);
    if(proc->MemManager==NULL){
        channelNo=2;
        channelId=10;
        memcfg.MemChannel = channelNo;
        memcfg.MemChID = channelId;
    }else{
        MemManager* MemManagerptr= *proc->MemManager;
        initMemCfg(MemManagerptr);
        struct MemConfig *MemCfgPtr = MemManagerptr->MemCfgPtr;
    }
    printf("memcfg.MemChannel = %u\n", memcfg.MemChannel);
    printf("memcfg.MemChID = %u\n", memcfg.MemChID);
    return 0;
}