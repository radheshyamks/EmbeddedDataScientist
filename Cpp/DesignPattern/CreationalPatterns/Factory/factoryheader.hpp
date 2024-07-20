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
        virtual void Speed(void)override;
        virtual void Durability(void)override;
        virtual void Reliability(void)override;
    };
    class Truck:public MotorVehicle{
        virtual void Speed(void)override;
        virtual void Durability(void)override;
        virtual void Reliability(void)override;
    };
    class Buse:public MotorVehicle{
        virtual void Speed(void)override;
        virtual void Durability(void)override;
        virtual void Reliability(void)override;
    };
}
namespace Toy{
    class toy{
        virtual void Sturdy(void)=0;
        virtual void Durable(void)=0;
        virtual void LongLasting(void)=0;
    };
    class Car:public toy{
        virtual void Sturdy(void)override;
        virtual void Durable(void)override;
        virtual void LongLasting(void)override;
    };
    class Doll: public toy{
        virtual void Sturdy(void)override;
        virtual void Durable(void)override;
        virtual void LongLasting(void)override;
    };
    class Puppet: public toy{
        virtual void Sturdy(void)override;
        virtual void Durable(void)override;
        virtual void LongLasting(void)override;
    };
}
#endif /*__FACTORYDESIGN__*/