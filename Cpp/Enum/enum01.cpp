#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <memory>
#include <stdlib.h>
using namespace std;
enum color{
    RED=1,BLUE,GREEN, YELLOW
};
enum class color1{
    RED=1,BLUE,GREEN,YELLOW
};
int main(int argc, char* argv[], char** env){
    std::cout<<"Hello World"<<"\n";
    color1 x = color1::GREEN;
    if(color1::RED==x){
        std::cout<<RED<<"\n";
    }else{
        std::cout<<int(color1::GREEN)<<"\n";
    }
    return 0;
}
