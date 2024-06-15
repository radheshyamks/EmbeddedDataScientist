#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
void fun(T var){
    std::cout<<var<<"\n";
}
template<typename T, typename... Args>
void fun(T var, Args... args){
    std::cout<<var<<"\n";
    fun(args...);
}
int main(int argc, char* argvp[], char** env){
    std::string myName = "Radheshyam";
    fun(1,2,3,4,5,myName);
    return 0;
}