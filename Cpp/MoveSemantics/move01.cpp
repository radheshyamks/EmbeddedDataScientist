#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdint>
using namespace std;
template<typename T>
class MoveSemanticsClass{
    private:
        T*ptr_;
    public:
        explicit MoveSemanticsClass(T*ptr=nullptr):ptr_(ptr){}
        virtual ~MoveSemanticsClass(){
            if(this->ptr_!=nullptr)delete this->ptr_;
        }
        T get_val(){
            return *this->ptr_;
        }
        void update_val(T newVal){
            if(this->ptr==nullptr)return;
            *this->ptr_ = newVal;
        }
        template<class Y>
        friend std::ostream& operator<<(std::ostream& out, const MoveSemanticsClass<Y>& obj);
};

template<typename Y>
std::ostream& operator<<(std::ostream& out,const MoveSemanticsClass<Y>& obj){
    out<<*obj.ptr_<<"\n";
    return out;
}
int main(int argc, char* argv[], char** env){
    MoveSemanticsClass<int>obj(new int(100));
    std::cout<<obj;
    std::cout<<obj.get_val()<<"\n";
    return 0;
}