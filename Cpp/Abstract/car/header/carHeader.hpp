/*file name: carHeader.hpp*/
#ifndef __CARHEADER__
/*extern "C"{*/
/*}*/
#include <iostream>
using namespace std;
namespace CarNameSpace{
    class Car{
        public:
            /*pure virtual function*/
            virtual void wheel(void)=0;
            virtual void pressure(void)=0;
            Car();
            virtual ~Car();
    };
    class Toyota:public Car{
        public:
            Toyota();
            virtual ~Toyota();
            void wheel(void)override;
            void pressure(void)override;
    };
    class BMW:public Car{
        public:
            virtual ~BMW();
            BMW();
            virtual void wheel(void)override;
            virtual void pressure(void)override;
    };
    class Customer{
        private:
            /*cr is car*/
            Car* cr;
        public:
            virtual ~Customer();
            Customer();
            void carSetUp(Car* cp);
            void Buyer(void);
            void wheelType(void);
            void pressureGauge(void);
    };
}
#endif /*__CARHEADER__*/