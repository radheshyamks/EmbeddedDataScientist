#ifndef __HDR__
#define __HDR__
#include <stdint.h>
struct MemoryConfig{
    uint32_t MemChannel;
    uint16_t MemChID;
};
struct MemoryPartition{
    uint16_t MemSize;
    uint16_t MemPage;
    uint32_t MaxMemory;
};
struct MemConfig{
    struct MemoryPartition* memPartitionCfg;
    struct MemoryConfig* MemConfigPtr;
};
struct MemoryManager{
    struct MemConfig** MemCfgPtr;
};
struct proc{
    struct MemoryManager** MemManager;
};
typedef struct MemoryManager MemManager;
typedef struct proc process;
extern process MemManagerPartition;
extern process* memoryManagerPartition(void);
extern void initManager(process* memcfgptr);
#endif /*__HDR__*/