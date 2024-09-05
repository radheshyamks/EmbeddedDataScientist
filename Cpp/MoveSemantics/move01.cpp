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
        explicit MoveSemanticsClass(T*ptr=nullptr):ptr_(ptr){
            std::cout<<"It is Constructor\n";
        }
        explicit MoveSemanticsClass(MoveSemanticsClass&& obj){
            if(this != &obj){
                // if(obj.ptr_!=nullptr){
                //     this->ptr_ = obj.ptr_;
                // }
                this->ptr_ = obj.ptr_;
                obj.ptr_ = nullptr;
            }
            std::cout<<"It is Move Constructor\n";
        }
        virtual ~MoveSemanticsClass(){
            if(this->ptr_!=nullptr)delete this->ptr_;
        }
        T get_val(){
            if(this->ptr_==nullptr) return -1;
            return *this->ptr_;
        }
        void update_val(T newVal){
            if(this->ptr==nullptr)return;
            *this->ptr_ = newVal;
        }
        template<class Y>
        friend std::ostream& operator<<(std::ostream& out, const MoveSemanticsClass<Y>& obj);
};

template<typename T>
std::ostream& operator<<(std::ostream& out,const MoveSemanticsClass<T>& obj){
    out<<*obj.ptr_<<"\n";
    return out;
}
int main(int argc, char* argv[], char** env){
    MoveSemanticsClass<int>obj(new int(100));
    std::cout<<obj;
    std::cout<<obj.get_val()<<"\n";
    MoveSemanticsClass<int>obj1(std::move(obj));
    std::cout<<obj1.get_val()<<"\n";
    std::cout<<obj.get_val()<<"\n";
    return 0;
}