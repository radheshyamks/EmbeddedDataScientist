#include <iostream>
#include <cstdint>
#include "../header/factoryheader.hpp"

using namespace std;
namespace Vehicle{
    MotorVehicle::MotorVehicle(){}
    MotorVehicle::MotorVehicle(uint32_t spd,uint32_t durability,uint32_t reliability){
        /*_speed = spd;
        _Durability = durability;
        _Reliability = reliability;*/
        std::cout<<"MotorVehicle param Constructor\n";
    }
    MotorVehicle::MotorVehicle(MotorVehicle& obj){
        std::cout<<"MotorVehicle Copy Constructor\n";
    }
    MotorVehicle::~MotorVehicle(){
        std::cout<<"MotorVehicle Destructor\n";
    }

    Bicycle::Bicycle(){
        /* max speed is 35km/hr */
        _speed = 35;
        /* max durability is 10years */
        _Durability = 10;
        /* Relaibility rating is 5 Star */
        _Reliability = 5;
        std::cout<<"Bicycle default Constructor\n";
    }
    Bicycle::Bicycle(uint32_t spd,uint32_t durability,uint32_t reliability){
        _speed = spd;
        _Durability = durability;
        _Reliability = reliability;
        std::cout<<"Bicycle param Constructor\n";
    }
    Bicycle::Bicycle(Bicycle& obj){
        std::cout<<"Bicycle Copy Constructor\n";
    }
    Bicycle::~Bicycle(){
        std::cout<<"Bicycle Destructor\n";
    }
    void Bicycle::Speed(void){
        std::cout<<"Top Speed: "<<_speed<<"km/hrs\n";
    }
    void Bicycle::Durability(void){
        std::cout<<"Durability: "<<_Durability<<"years\n";
        /*for(uint32_t i=0; i<_Durability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
        */
    }
    void Bicycle::Reliability(void){
        std::cout<<"Reliability Star:\n";
        for(uint32_t i=0; i<_Reliability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    uint32_t Bicycle::GetSpeed(void)const{
        return _speed;
    }
    void Bicycle::UpdateSpeed(uint32_t speed){
        _speed = speed;
    }
    uint32_t Bicycle::GetDurability(void)const{
        return _Durability;
    }
    void Bicycle::UpdateDurability(uint32_t durability){
        _Durability = durability;
    }
    uint32_t Bicycle::GetReliability(void)const{
        return _Reliability;
    }
    void Bicycle::UpdateReliability(uint32_t reliability){
        _Reliability = reliability;
    }
    
    Truck::Truck(){
        /* max speed is 100km/hr */
        _speed = 100;
        /* max durability is 40years */
        _Durability = 40;
        /* Relaibility rating is 4 Star */
        _Reliability = 4;
        std::cout<<"Truck default Const\n";
    }
    Truck::Truck(uint32_t spd,uint32_t durability,uint32_t reliability){
        _speed = spd;
        _Durability = durability;
        _Reliability = reliability;
        std::cout<<"Truck param Constructor\n";
    }
    Truck::Truck(Truck& obj){
        std::cout<<"Truck Copy Constructor\n";
    }
    Truck::~Truck(){
        std::cout<<"Truck Destructor\n";
    }
    void Truck::Speed(void){
        std::cout<<"Top Speed: "<<_speed<<"km/hrs\n";
    }
    void Truck::Durability(void){
        std::cout<<"Durability: "<<_Durability<<"years\n";
        /*for(uint32_t i=0; i<_Durability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";*/
    }
    void Truck::Reliability(void){
        std::cout<<"Reliability Star:\n";
        for(uint32_t i=0; i<_Reliability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    uint32_t Truck::GetSpeed(void)const{
        return _speed;
    }
    void Truck::UpdateSpeed(uint32_t speed){
        _speed = speed;
    }
    uint32_t Truck::GetDurability(void)const{
        return _Durability;
    }
    void Truck::UpdateDurability(uint32_t durability){
        _Durability = durability;
    }
    uint32_t Truck::GetReliability(void)const{
        return _Reliability;
    }
    void Truck::UpdateReliability(uint32_t reliability){
        _Reliability = reliability;
    }
    
    Buse::Buse(){
        /* max speed is 30km/hr */
        _speed = 110;
        /* max durability is 30years */
        _Durability = 30;
        /* Relaibility rating is 5 Star */
        _Reliability = 5;
        std::cout<<"Buse default Const\n";
    }
    Buse::Buse(uint32_t spd,uint32_t durability,uint32_t reliability){
        _speed = spd;
        _Durability = durability;
        _Reliability = reliability;
        std::cout<<"Buse param Constructor\n";
    }
    Buse::Buse(Buse& obj){
        std::cout<<"Buse Copy Constructor\n";
    }
    Buse::~Buse(){
        std::cout<<"Buse Destructor\n";
    }
    void Buse::Speed(void){
        std::cout<<"Top Speed: "<<_speed<<"km/hrs\n";
    }
    void Buse::Durability(void){
        std::cout<<"Durability: "<<_Durability<<"years\n";
        /*for(uint32_t i=0; i<_Durability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
        */
    }
    void Buse::Reliability(void){
        std::cout<<"Reliability Star:\n";
        for(uint32_t i=0; i<_Reliability; i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    uint32_t Buse::GetSpeed(void)const{
        return _speed;
    }
    void Buse::UpdateSpeed(uint32_t speed){
        _speed = speed;
    }
    uint32_t Buse::GetDurability(void)const{
        return _Durability;
    }
    void Buse::UpdateDurability(uint32_t durability){
        _Durability = durability;
    }
    uint32_t Buse::GetReliability(void)const{
        return _Reliability;
    }
    void Buse::UpdateReliability(uint32_t reliability){
        _Reliability = reliability;
    }
    
    void Client::SetUpMotorVehicle(MotorVehicle* mtv){}
    uint32_t Client::GetSpeed(void)const{
        if(MotVeh != nullptr){
            return MotVeh->GetSpeed();
        }
        return 0;
    }
    uint32_t Client::GetDurability(void)const{
        if(MotVeh != nullptr){
            return MotVeh->GetDurability();
        }
        return 0;
    }
    uint32_t Client::GetReliability(void)const{
        if(MotVeh != nullptr){
            return MotVeh->GetReliability();
        }
        return 0;
    }
    void Client::UpdateSpeed(uint32_t speed){
        if(MotVeh != nullptr){
            MotVeh->UpdateSpeed(speed);
        }
    }
    void Client::UpdateDurability(uint32_t durability){
        if(MotVeh != nullptr){
            MotVeh->UpdateDurability(durability);
        }
    }
    void Client::UpdateReliability(uint32_t reliability){
        if(MotVeh!=nullptr){
            MotVeh->UpdateReliability(reliability);
        }
    }
    Client::Client(){
        MotVeh=nullptr;
    }
    Client::Client(MotorVehicle*motveh){
        MotVeh = motveh;
    }
    Client::Client(Client&obj){}
    MotorVehicle*Client::GetMotorVehicleType(VehicleType t){
        switch(t){
            case BICYCLE:
                return new Bicycle();
            case TRUCK:
                return new Truck();
            case BUSE:
                return new Buse();
            default:
                return nullptr;
        }
    }
}