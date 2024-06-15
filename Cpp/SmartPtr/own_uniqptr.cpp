#include <iostream>
#include <memory>
using namespace std;
class uniqptr{
    private:
        int* _ptr;
    public:
        // uniqptr()=default;
        // contructor
        explicit uniqptr(int* ptr = nullptr){
            this->_ptr = ptr;
        }
        // delete copy constructor
        uniqptr(const uniqptr&) = delete;
        uniqptr& operator=(const uniqptr&)=delete;
        // move constructor
        uniqptr(uniqptr&& other) noexcept: _ptr(other._ptr){
            // delete other._ptr;
            other._ptr = nullptr;
        }
        // assignment operator
        uniqptr& operator=(uniqptr& other) noexcept{
            if(this != &other){
                delete this->_ptr;
                this->_ptr = other._ptr;
                other._ptr = nullptr;
            }
            return *this;
        }
        // to get the address of object pointer
        int* get()const noexcept{
            if(this->_ptr==nullptr){
                return nullptr;
            }
            return this->_ptr;
        }
        // to assign this current object pointer into other pointer and assign nullptr to the current object pointer
        int* release() noexcept{
            int*tmp = this->_ptr;
            this->_ptr = nullptr;
            return tmp;
        }
        void reset(int* ptr = nullptr) noexcept{
            delete this->_ptr;
            this->_ptr = ptr;
        }
        // overloading the * operator
        int& operator*()const noexcept{
            return *(this->_ptr);
        }
        int* operator->()const noexcept{
            return this->_ptr;
        }
        explicit operator bool() const noexcept{
            return this->_ptr!=nullptr;
        }
        // destructor
        ~uniqptr(){
            delete _ptr;
        }
};

int main(int argc, char* argv[], char** env){
    // uniqptr p = uniqptr(new int(10));
    // std::cout<<p.get()<<"\n";
    // p = p;
    std::unique_ptr<int> p = std::make_unique<int>(int(10));
    std::cout<<*p<<"\n";
    return 0;
}