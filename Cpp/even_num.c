// 1...100
#include<stdio.h>
#include <stdint.h>
// << >> | & ^ ~
#define LEFTSHIFT(X,N) (X<<N)
#define RIGHTSHIFT(X,N) (X>>N)
#define BITWISEOR(X,N) (X | N)
#define BITWISEAND(X,N) (X & N)
#define BITWISEXOR(X,N) (X  ^ N)
#define BITWISENOT(X) (~((uint8_t)X))
struct abc{
    uint16_t std_id;
    uint8_t* std_name;
    float std_ht;
};
int main(){
    // struct abc studendt = {0x123,"Yogesh", 5.8};
    printf("%d\n", LEFTSHIFT(10,2));
    printf("%d\n", RIGHTSHIFT(10,2));
    printf("%d\n", BITWISEOR(10,3));
    printf("%hx\n", BITWISENOT(10));
    return 0;
}