#include <iostream>
using namespace std;
template<int N>
struct add{
    static const int val = N+add<N-1>::val;
};
template<>
struct add<0>{
    static const int val=1;
};
int main(int argc, char* argv[], char** env){
    std::cout<<add<10>::val;
    return 0;
}