#include <iostream>
#include "../header/singleton.hpp"

using namespace std;
namespace SingleTon{
    Singleton::~Singleton(){
        std::cout<<"Singleton Destructor\n";
    }
    Singleton::Singleton(){
        k = 0;
        uniqueId = 1;
        std::cout<<"Singleton Constructor\n";
    }
    Singleton::Singleton(uint32_t t, uint32_t uniqid){
        k = t;
        uniqueId = uniqid;
        std::cout<<"Parameterized Singleton Constructor\n";
    }
    /* Created a instance function to return singleton object only once */
    Singleton& Singleton::getInstance(){
        static Singleton Instance;
        return Instance;
    }
    void Singleton::UpdateUniqueId(uint32_t uniqid){
        uniqueId = uniqid;
    }
    uint32_t Singleton::getUniqueId(void){
        return uniqueId;
    }
    Singleton& Singleton::getParamInstance(void){
        static Singleton pInstance(1,20);
        return pInstance;
    }
}