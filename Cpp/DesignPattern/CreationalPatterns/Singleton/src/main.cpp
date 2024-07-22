#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "../header/singleton.hpp"

using namespace std;

int main(int argc, char* argv[], char** env){
    SingleTon::Singleton& instance = SingleTon::Singleton::getInstance();
    SingleTon::Singleton& pinstance = SingleTon::Singleton::getParamInstance();
    instance.UpdateUniqueId(30);
    uint32_t id  = instance.getUniqueId();
    std::cout<<"id: "<<id<<"\n";
    return EXIT_SUCCESS;
}