#ifndef __PTRSINGLETON__
#define __PTRSINGLETON__
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstdio>

using namespace std;
namespace SingleTonPtr{
    class SingletonPtr{
        private:
        static SingletonPtr* singleton_;
        SingletonPtr();
        SingletonPtr(SingletonPtr*);
        public:
        /* deleted move constructor */
        SingletonPtr(SingletonPtr*&&)=delete;
        /*deleted copy constructor */
        SingletonPtr(SingletonPtr*&)=delete;
        /* assignment copy operator */
        void operator=(SingletonPtr*&)=delete;
    };
}
#endif /*__PTRSINGLETON__*/