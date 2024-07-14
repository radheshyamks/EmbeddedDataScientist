#ifndef __HEADER__
#define __HEADER__
// #ifdef __cplusplus__
// extern "C"{
// #endif /*__cplusplus__*/

// #ifdef __cplusplus__
// }
// #endif /*__cplusplus__*/

namespace MobileNameSpace{
    class CellPhone{
        public:
            virtual ~CellPhone();
            explicit CellPhone();
            virtual void buy(void)=0;
    };
    class Nokia: public CellPhone{
        public:
            virtual ~Nokia();
            explicit Nokia();
            virtual void buy(void)override;
    };
    class SamSung: public CellPhone{
        public:
            virtual ~SamSung();
            explicit SamSung();
            virtual void buy(void)override;
    };
    class Customer{
        public:
            virtual ~Customer();
            explicit Customer();
            void setCp(CellPhone* cp);
            virtual void buyCellPhone(void); 
        private:
            CellPhone* cp;
    };
}
#endif /*__HEADER__*/