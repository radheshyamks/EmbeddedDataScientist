#include <iostream>
namespace abc{
    int a;
    int b;
}
int main(int argc, char* argv[], char** env){
    abc::a=10;
    abc::b=20;
    std::cout<<abc::a<<'\n'<<abc::b<<'\n';
    return 0;
}