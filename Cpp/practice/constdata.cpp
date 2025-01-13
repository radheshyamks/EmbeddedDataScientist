#include <iostream>
#include <cstdint>

using namespace std;
constexpr void fun(const uint16_t& x){
    //std::cout<<"fun x: "<<x<<"\n";
    //x++;
    return;
}
class Const{
    private:
        uint32_t x;
    public:
        Const(){
            std::cout<<"Const Constructor\n";
            this->x = 0;
        }
        ~Const(){
            std::cout<<"Const Destructor\n";
        }
        void setVal(uint32_t x){
            this->x = x;
            return;
        }
        uint32_t getVal(void) const{
            // can not modify the class member variable
            // this->x++;
            return this->x;
        }
};
int main(int argc, char* argv[], char** env){
    const uint32_t x=10;
    constexpr uint32_t y=20;
    std::cout<<"x = "<<x<<"\n";
    std::cout<<"y = "<<y<<"\n";
    fun(x);
    Const abc;
    abc.setVal(y);
    std::cout<<abc.getVal()<<"\n";
    return EXIT_SUCCESS;
}