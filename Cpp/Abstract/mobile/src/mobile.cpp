#include "../header/header.hpp"
#include <iostream>
using namespace std;

namespace MobileNameSpace{
    /*virtual */CellPhone::~CellPhone(){
        std::cout<<"this is CellPhone Destructor\n";
    }
    /*explicit*/ CellPhone::CellPhone(){
        std::cout<<"this is CellPhone Constructor\n";
    }
    /*explicit*/ Nokia::Nokia(){
        std::cout<<"This is Nokia Constructor\n";
    }
    /*virtual*/ Nokia::~Nokia(){
        std::cout<<"this is Nokia Destructor\n";
    }
    /*virtual*/ void Nokia::buy(void)/*override*/{
        std::cout<<"Buy Nokia CellPhone\n";
    }
    /*explicit*/ SamSung::SamSung(){
        std::cout<<"this is SamSung Constructor\n";
    }
    /*virtual*/ SamSung::~SamSung(){
        std::cout<<"This is SamSung Destructor\n";
    }
    /*virtual*/ void SamSung::buy(void)/*override*/{
        std::cout<<"Buy SamSung CellPhone\n";
    }
    /*explicit*/ Customer::Customer(){
        std::cout<<"this is Customer Constructor\n";
    }
    /*virtual*/ Customer::~Customer(){
        std::cout<<"This is Customer Destructor\n";
    }
    void Customer::setCp(CellPhone* cp){
        this->cp = cp;
    }
    /*virtual*/ void Customer::buyCellPhone(void){
        cp->buy();
    }
}