#ifndef __FACTORYDESIGN__
#define __FACTORYDESIGN__
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef enum{
   BICYCLE,TRUCK,BUSE, 
}VehicleType;
namespace Vehicle{
    class MotorVehicle {
        protected:
            uint32_t _speed;
            uint32_t _Durability;
            uint32_t _Reliability;
        public:
            virtual void Speed(void)=0;
            virtual void Durability(void)=0;
            virtual void Reliability(void)=0;
            MotorVehicle();
            MotorVehicle(uint32_t spd,uint32_t durability,uint32_t reliability);
            MotorVehicle(MotorVehicle&);
            virtual ~MotorVehicle();            
            virtual uint32_t GetSpeed(void)const=0;
            virtual void UpdateSpeed(uint32_t)=0;
            virtual uint32_t GetDurability(void)const=0;
            virtual void UpdateDurability(uint32_t)=0;
            virtual uint32_t GetReliability(void)const=0;
            virtual void UpdateReliability(uint32_t)=0;
    };
    class Bicycle:public MotorVehicle{
        public:
            virtual void Speed(void)override;
            virtual void Durability(void)override;
            virtual void Reliability(void)override;
            Bicycle();
            Bicycle(uint32_t spd,uint32_t durability,uint32_t reliability);
            Bicycle(Bicycle&);
            virtual ~Bicycle();
            uint32_t GetSpeed(void)const override;
            void UpdateSpeed(uint32_t)override;
            uint32_t GetDurability(void)const override;
            void UpdateDurability(uint32_t)override;
            uint32_t GetReliability(void)const override;
            void UpdateReliability(uint32_t)override;
    };
    class Truck:public MotorVehicle{
        public:
            virtual void Speed(void)override;
            virtual void Durability(void)override;
            virtual void Reliability(void)override;
            Truck();
            Truck(uint32_t spd,uint32_t durability,uint32_t reliability);
            Truck(Truck&);
            virtual ~Truck();
            uint32_t GetSpeed(void)const override;
            void UpdateSpeed(uint32_t)override;
            uint32_t GetDurability(void)const override;
            void UpdateDurability(uint32_t)override;
            uint32_t GetReliability(void)const override;
            void UpdateReliability(uint32_t)override;
    };
    class Buse:public MotorVehicle{
        public:
            virtual void Speed(void)override;
            virtual void Durability(void)override;
            virtual void Reliability(void)override;
            Buse();
            Buse(uint32_t spd,uint32_t durability,uint32_t reliability);
            Buse(Buse&);
            virtual ~Buse();
            uint32_t GetSpeed(void)const override;
            void UpdateSpeed(uint32_t);
            uint32_t GetDurability(void)const override;
            void UpdateDurability(uint32_t)override;
            uint32_t GetReliability(void)const override;
            void UpdateReliability(uint32_t)override;
    };
    class Client{
        private:
            MotorVehicle* MotVeh;
        public:
            void SetUpMotorVehicle(MotorVehicle* mtv);
            uint32_t GetSpeed(void)const;
            uint32_t GetDurability(void)const;
            uint32_t GetReliability(void)const;
            void UpdateSpeed(uint32_t);
            void UpdateDurability(uint32_t);
            void UpdateReliability(uint32_t);
            Client();
            Client(MotorVehicle*);
            Client(Client&);
            MotorVehicle*GetMotorVehicleType(VehicleType t);
    };
}
namespace Toy{
    class toy{
        public:
            virtual void Sturdy(void)=0;
            virtual void Durable(void)=0;
            virtual void LongLasting(void)=0;
    };
    class Car:public toy{
        public:
            virtual void Sturdy(void)override;
            virtual void Durable(void)override;
            virtual void LongLasting(void)override;
        };
    class Doll: public toy{
        public:
            virtual void Sturdy(void)override;
            virtual void Durable(void)override;
            virtual void LongLasting(void)override;
    };
    class Puppet: public toy{
        public:
            virtual void Sturdy(void)override;
            virtual void Durable(void)override;
            virtual void LongLasting(void)override;
    };
}
#endif /*__FACTORYDESIGN__*/