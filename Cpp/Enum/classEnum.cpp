#include <iostream>

using namespace std;
enum class color{
    RED,BLUE, GREEN, YELLOW,
};
typedef enum{
    Z_RED,Z_BLUE, Z_GREEN, Z_YELLOW,
}clor;
int main(int argc, char* argv[], char** env){
    if(color::RED==color::BLUE){
        std::cout<<"Z_RED: "<<Z_RED<<"\n";
    }
    return 0;
}