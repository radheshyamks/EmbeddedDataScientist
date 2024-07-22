#ifndef __PTRSINGLETON__
#define __PTRSINGLETON__
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstdio>

using namespace std;
namespace SingleTonPtr{
    class SingletonPtr{
        // public:
        //     static SingletonPtr* singleton_;
        private:
            static SingletonPtr* singleton_;
            std::string value_;
            SingletonPtr();
            SingletonPtr(const std::string& value);
        public:
            ~SingletonPtr();
            /* deleted move constructor */
            SingletonPtr(SingletonPtr&&)=delete;
            /*deleted copy constructor */
            SingletonPtr(SingletonPtr&)=delete;
            /* assignment copy operator */
            void operator=(SingletonPtr&)=delete;
            static SingletonPtr* GetInstance(const std::string& value);
            void BussinessLogic(void);
            std::string value(void)const;
            static void clear(void);
    };
    // void ThreadBar(void*);
    // void ThreadFoo(void*);
}
#endif /*__PTRSINGLETON__*/