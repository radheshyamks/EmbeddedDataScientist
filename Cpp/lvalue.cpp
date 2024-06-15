#include <iostream>
#include <cstdio>

using namespace std;
int main(int argc, char* argv[], char** env){
    int ref = 10;
    int& rref = ref;
    std::cout<<rref<<"\n";
    // int&& lvalref = ref; // compile time error
    int&& lvalref = 11;// lvalue reference
    std::cout<<lvalref<<"\n";
    int*p = &lvalref;
    std::cout<<p<<"\n";
    std::cout<<*p<<"\n";
    lvalref++;
    std::cout<<*p<<"\n";
    (*p)++;
    std::cout<<*p<<"\n";
    return EXIT_SUCCESS;
}