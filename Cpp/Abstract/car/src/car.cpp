#include "../header/carHeader.hpp"
#include <iostream>
using namespace std;
namespace CarNameSpace{
    Car::Car(){
        std::cout<<"this is Car class Constructor\n";
    }
    Car::~Car(){
        std::cout<<"this is Car class Destructor\n";
    }
    Toyota::Toyota(){
        std::cout<<"this is Toyota class Constructor\n";
    }
    Toyota::~Toyota(){
        std::cout<<"this is Toyota class Constructor\n";
    }
    void Toyota::wheel(void){
        std::cout<<"this is Toyota Wheel\n";
    }
    void Toyota::pressure(void){
        std::cout<<"Toyota car pressure is Normal\n";
    }
    BMW::BMW(){
        std::cout<<"this is BMW class Constructor\n";
    }
    BMW::~BMW(){
        std::cout<<"this is BMW class Destructor\n";
    }
    void BMW::wheel(void){
        std::cout<<"this is BMW wheel\n";
    }
    void BMW::pressure(void){
        std::cout<<"BMW car pressure is normal\n";
    }
    Customer::Customer(){
        std::cout<<"this is costomer class constructor\n";
    }
    Customer::~Customer(){
        std::cout<<"this is costomer class destructor\n";
    }
    void Customer::carSetUp(Car* cp){
        this->cr = cp;
    }
    void Customer::wheelType(void){
        cr->wheel();
    }
    void Customer::pressureGauge(void){
        cr->pressure();
    }
}