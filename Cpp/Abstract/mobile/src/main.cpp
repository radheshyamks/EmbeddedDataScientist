#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include "../header/header.hpp"

using namespace std;
using namespace MobileNameSpace;
// EXIT_FAILURE
int main(int argc, char* argv[], char** env){
    Customer* customer = new Customer();
    CellPhone* cp1 = new Nokia();
    CellPhone* cp2 = new SamSung();
    customer->setCp(cp1);
    customer->buyCellPhone();
    customer->setCp(cp2);
    customer->buyCellPhone();
    delete customer;
    delete cp1;
    delete cp2;
    return EXIT_SUCCESS;
}