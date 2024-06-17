#include <iostream>
using namespace std;
namespace abc{
    int a;
    int b;
    class xyz{
        private:
            int*p_;
        public:
            // xyz()=default;
            // xyz(){p_=nullptr;}
            // deleted copy constructor
            xyz(xyz&)=delete;
            // deleted copy assignment operator
            xyz& operator=(xyz&)=delete;
            // deleted move assignment operator
            xyz operator=(xyz&&)=delete;

            // deleted move constructor
            xyz(xyz&&)=delete;

            // xyz(xyz&&);

            xyz(int*ptr=nullptr):p_{ptr}{}
            int getval(){
                return *this->p_;
            }
    };
}
// using namespace abc;
int main(int argc, char* argv[], char** env){
    abc::a=10;
    abc::b=20;
    std::cout<<abc::a<<'\n'<<abc::b<<'\n';
    abc::xyz obj1(new int(10));
    std::cout<<obj1.getval()<<"\n";
    // compile time error
    // abc::xyz obj2(std::move(obj1)); // error use of deleted function
    // abc::xyz obj2;
    // compile time error
    // obj2 = obj1; // error: use of deleted function
    // abc::xyz obj2 = std::move(obj1); // error: use of deleted function
    return 0;
}