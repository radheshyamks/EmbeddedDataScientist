#ifndef __SINGLETON__
#define __SINGLETON__
#include <iostream>
#include <cstdint>
#include <cstdio>

using namespace std;

namespace SingleTon{
    class Singleton{
        private:
            uint32_t k;
            uint32_t uniqueId;
            /* private default Constructor */
            Singleton();
            /* private param Constructor */
            Singleton(uint32_t t, uint32_t uniqid);
            ~Singleton();
        public:
            /* Copy Constructor */
            Singleton(Singleton& obj)=delete;
            /* Move Constructor */
            Singleton(Singleton&&)=delete;
            /* deleted move assignment operator */
            void operator=(Singleton&&)=delete;
            /* deleted copy assignment operator */
            void operator=(const Singleton&)=delete;
            /* Created a instance function to return singleton object only once */
            static Singleton& getInstance(void);
            // static Singleton& getInstance(void){
            //     static Singleton Instance;
            //     return Instance;
            // }
            static Singleton& getParamInstance(void);
            // static Singleton& getParamInstance(void){
            //     static Singleton pInstance(1,20);
            //     return pInstance;
            // }
            void UpdateUniqueId(uint32_t uniqid);
            uint32_t getUniqueId(void);
    };
}
#endif /*__SINGLETON__*/