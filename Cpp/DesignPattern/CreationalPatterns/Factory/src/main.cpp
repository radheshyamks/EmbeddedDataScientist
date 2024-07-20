#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "../header/factoryheader.hpp"

using namespace std;

int main(int argc, char* argv[], char** env){
    Vehicle::Client client;
    Vehicle::MotorVehicle* bicycle = client.GetMotorVehicleType(BICYCLE);
    
    std::cout<<bicycle->GetSpeed()<<"\n";
    std::cout<<bicycle->GetDurability()<<"\n";
    std::cout<<bicycle->GetReliability()<<"\n";
    bicycle->Speed();
    bicycle->Durability();
    bicycle->Reliability();

    Vehicle::MotorVehicle* truck = client.GetMotorVehicleType(TRUCK);
    std::cout<<truck->GetSpeed()<<"\n";
    std::cout<<truck->GetDurability()<<"\n";
    std::cout<<truck->GetReliability()<<"\n";
    truck->Speed();
    truck->Durability();
    truck->Reliability();

    Vehicle::MotorVehicle* buse = client.GetMotorVehicleType(BUSE);
    std::cout<<buse->GetSpeed()<<"\n";
    std::cout<<buse->GetDurability()<<"\n";
    std::cout<<buse->GetReliability()<<"\n";
    buse->Speed();
    buse->Durability();
    buse->Reliability();

    /* deleted bicycle pointer*/
    delete bicycle;
    /* deleted truck pointer*/
    delete truck;
    /* deleted buse pointer*/
    delete buse;
    return EXIT_SUCCESS;
}