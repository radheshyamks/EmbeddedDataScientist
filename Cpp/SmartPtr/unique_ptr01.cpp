#include <iostream>
#include <memory>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <stdexcept>
using namespace std;
/*
 * 1. reset will delete the current pointer and 
 * 2. release 
 * 3. * operator overloading
 * 4. -> operator overloading
 * 5. delete copy constructor
 * 6. overlaoding move operator
 * 7. 
*/
/*
template<typename T>
class unique_ptr{
    private:
        T* ptr_;
    public:
        unique_ptr(T*ptr = nullptr): ptr_(ptr){
            std::cout<<"uniq constructor"<<"\n";
        }
        ~unique_ptr(){
            std::cout<<"uniq destructor"<<"\n";
        }
};*/

int main(int argc, char* argv[], char** env){
    // unique_ptr<int> p;
    std::unique_ptr<int> p1 = std::make_unique<int>(int(10));
    std::cout<<*p1<<"\n";
    std::cout<<p1.get()<<"\n";
    p1.release();
    int* p = new int(20);
    p1.reset(p);
    return EXIT_SUCCESS;
}