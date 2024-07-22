#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <thread>
// #include <cthread>

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

#include "../header/ptrsingleton.hpp" 
using namespace std;
using std::cout;
namespace SingleTonPtr{
    SingletonPtr* SingletonPtr::singleton_=nullptr;
    SingletonPtr::SingletonPtr(){
        value_ = "Radheshyam";
        std::cout<<"Default Constructor\n";
    }
    SingletonPtr::SingletonPtr(const std::string& value){
        value_ = value;
        std::cout<<"parameterized Constructor\n";
    }
    SingletonPtr::~SingletonPtr(){
        if(singleton_ != nullptr){
            delete[] singleton_;
            singleton_=nullptr;
        }
        std::cout<<"Destructor\n";
    }
    SingletonPtr* SingletonPtr::GetInstance(const std::string& value){
        if(singleton_==nullptr){
            singleton_ = new SingletonPtr(value);
        }
        return singleton_;
    }
    std::string SingletonPtr::value(void)const{
        return value_;
    }
    void SingletonPtr::BussinessLogic(void){
        std::cout<<"Data manupulation statements\n";
    }
    // void SingletonPtr::clear(void){
    //     if(singleton_ != nullptr){
    //         delete[]singleton_;
    //     }
    // }
//     void ThreadBar(void*p){
//         // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//         SingletonPtr* singleton = SingletonPtr::GetInstance("FOO");
//         std::cout << singleton->value() << "\n";
//     }
//     void ThreadFoo(void*p){
//         // Following code emulates slow initialization.
//         // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//         SingletonPtr* singleton = SingletonPtr::GetInstance("BAR");
//         std::cout << singleton->value() << "\n";
//     }
}
int main(int argc, char* argv[], char** env){
    // std::thread t1(ThreadFoo);
    // std::thread t2(ThreadBar);
    // pthread_t thread1, thread2;
    // t1 = pthread_create(&thread1,NULL,&ThreadBar, NULL);
    // t1 = pthread_create(&thread2,NULL,&ThreadFoo, NULL);
    // t1.join();
    // t2.join();
    // SingleTonPtr
    SingleTonPtr::SingletonPtr*instance = SingleTonPtr::SingletonPtr::GetInstance("This is me");
    std::cout<<instance->value()<<"\n";
    delete[] instance;
    std::cout<<instance->value()<<"\n";
    if(instance != nullptr){
        instance->value();
    }else{
        std::cout<<instance<<"\n";
    }
    
    // instance->clear();
    return EXIT_SUCCESS;
}