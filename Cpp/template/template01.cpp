#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
// #include <bool>
#include <cstdbool>

using namespace std;
// int fun(int, int)=delete;
template<int, int>int fun(int, int)=delete;
// template<typename T1, typename T2>T1 fun(T1 x, T2 y)=delete;
template<typename T1, typename T2>
T1 fun(T1 x, T2 y){
    return x+y;
}
int main(int argc, char* argv[], char** env){
    string s1,s2;
    s1 = "Radhe";
    s2 = "Shyam";
    string s3 = fun<string, string>(s1,s2);
    std::cout<<s3<<"\n";
    int x=30, y=20;
    int k = fun<int, int>(x,y);
    std::cout<<k<<"\n";
    return EXIT_SUCCESS;
}