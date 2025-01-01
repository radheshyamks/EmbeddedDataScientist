#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstdlib>

using namespace std;
class A{
    private:
        uint32_t x;
    public:
        ~A();
        A();
        void set_x(uint32_t);
        uint32_t get_x(void);
};
A::A(){
    std::cout<<"Constrcutor\n";
    this->x = 10;
}
A::~A(){
    std::cout<<"Destructor\n";
}
void A::set_x(uint32_t y){
    this->x = y;
}
uint32_t A::get_x(void){
    return this->x;
}
int main(int argc, char* argv[], char** env){
    std::cout<<"Hello World\n";
    A obj;
    std::cout<<obj.get_x()<<"\n";
    obj.set_x(20);
    std::cout<<obj.get_x()<<"\n";
    return EXIT_SUCCESS;
}