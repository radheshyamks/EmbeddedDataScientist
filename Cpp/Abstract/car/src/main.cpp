#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <memory>
#include <cstdio>

#include "../header/carHeader.hpp"

using namespace std;
// using namespace CarNameSpace;

int main(int argc, char* argv[], char** env){
    CarNameSpace::Customer *customer = new CarNameSpace::Customer();
    CarNameSpace::Car*cr1 = new CarNameSpace::Toyota();
    CarNameSpace::Car*cr2 = new CarNameSpace::BMW();
    customer->carSetUp(cr1);
    customer->wheelType();
    customer->pressureGauge();
    customer->carSetUp(cr2);
    customer->wheelType();
    customer->pressureGauge();
    delete cr1;
    delete cr2;
    delete customer;
    return EXIT_SUCCESS;
}