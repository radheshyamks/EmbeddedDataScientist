#include <iostream>
using namespace std;
namespace abc{
    int a;
    int b;
    int c;
}
using namespace abc;
int main(int argc, char*argv[], char** env){
    a=20;
    b=30;
    c=40;
    std::cout<<a<<'\n'<<b<<'\n'<<c<<'\n';
    return 0;
}