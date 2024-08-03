#include <iostream>

using namespace std;
template<typename T>
class Abc{
    private:
        T* ptr_;
    public:
        ~Abc();// destructor
        Abc();// default constructor
        Abc(T*); // parameterized constructor
        Abc(Abc&); // copy constructor
        Abc(Abc&&); // move constructor
        Abc& operator=(const Abc&); // copy assignment operator
        Abc& operator=(Abc&&); // move assignment operator
        T getVal(void)const;
        void updateVal(T);
};
template<typename T>
void Abc<T>::updateVal(T data){
    *this->ptr_ = data;
}
template<typename T>
T Abc<T>::getVal(void)const{
    return *this->ptr_;
}
template<typename T>
Abc<T>& Abc<T>::operator=(Abc&& obj){
    if(this != &obj){
        if(ptr_!=nullptr) delete[] ptr_;
        ptr_ = obj.ptr_;
        obj.ptr_ = nullptr;
    }
    return *this;
}
template<typename T>
Abc<T>& Abc<T>::operator=(const Abc&obj){
    /* Check for self-assingment */
    if(this!= &obj){
        if(ptr_==nullptr){
            ptr_ = new T;
            if(obj.ptr_!=nullptr){
                *ptr_ = *obj.ptr_;
            }
        }else{
            if(obj.ptr_!=nullptr){
                *ptr_ = *obj.ptr_;
            }
        }
    }
    return *this;
}
template<typename T>
Abc<T>::Abc(Abc&& obj){
    if(obj.ptr_ != nullptr){
        // ptr_ = new T;
        ptr_ = obj.ptr_;
        // delete[] obj.ptr_;
        obj.ptr_ = nullptr;
    }
}
template<typename T>
Abc<T>::Abc(Abc& obj){
    std::cout<<"Copy Constructor\n";
    ptr_ = new T;
    *ptr_ = *obj.ptr_;
}
template<typename T>
Abc<T>::Abc(T* ptr){
    ptr_ = ptr;
    std::cout<<"param Constructor\n";
}
template<typename T>
Abc<T>::Abc(){
    ptr_ = nullptr;
    std::cout<<"Default Constructor\n";
}
template<typename T>
Abc<T>::~Abc(){
    if(ptr_!= nullptr){
        std::cout<<"Resources released\n";
        delete[] ptr_;
    }
    std::cout<<"Destructor\n";
}
int main(int argc, char* argv[], char** env){
    Abc<int> obj(new int(10));
    // Abc<std::string> obj1;
    return 0;
}