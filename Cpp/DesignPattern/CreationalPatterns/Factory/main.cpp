#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "factoryheader.hpp"

using namespace std;

int main(int argc, char* argv[], char** env){
    Vehicle::Client client;
    Vehicle::MotorVehicle* bicycle = client.GetMotorVehicleType(BICYCLE);

    delete bicycle;
    return EXIT_SUCCESS;
}