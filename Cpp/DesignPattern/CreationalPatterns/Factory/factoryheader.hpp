#ifndef __FACTORYDESIGN__
#define __FACTORYDESIGN__
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
namespace Vehical{
    class MotorVehicle {
        virtual void Speed(void)=0;
        virtual void Durability(void)=0;
        virtual void Reliability(void)=0;
    };
    class Bicycle:public MotorVehicle{
        virtual void Speed(void);
        virtual void Durability(void);
        virtual void Reliability(void);
    };
    class Truck:public MotorVehicle{
        virtual void Speed(void);
        virtual void Durability(void);
        virtual void Reliability(void);
    };
    class Buse:public MotorVehicle{
        virtual void Speed(void);
        virtual void Durability(void);
        virtual void Reliability(void);
    };
}
namespace Toy{
    class toy{
        virtual void Sturdy(void)=0;
        virtual void Durable(void)=0;
        virtual void LongLasting(void)=0;
    };
    class Car:public toy{
        virtual void Sturdy(void);
        virtual void Durable(void);
        virtual void LongLasting(void);
    };
    class Doll: public toy{
        virtual void Sturdy(void);
        virtual void Durable(void);
        virtual void LongLasting(void);
    };
    class Puppet: public toy{
        virtual void Sturdy(void);
        virtual void Durable(void);
        virtual void LongLasting(void);
    };
}
#endif /*__FACTORYDESIGN__*/