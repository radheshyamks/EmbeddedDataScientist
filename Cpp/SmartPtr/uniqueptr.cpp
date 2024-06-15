#include <iostream>
#include <memory>
#include <string>
using namespace std;
class person{
    private:
        std::string name;
        std::string addr;
        uint16_t HouseNo;
    public:
        person()=default;
        person(std::string Name, std::string Addr, uint16_t houseno=0){
            this->name = Name;
            this->addr = Addr;
            this->HouseNo = houseno;
        }
        ~person(){
            std::cout<<this<<" is deleted\n";
        }
        std::string getName(){
            return this->name;
        }
        std::string getAddr(){
            return this->addr;
        }
        uint16_t getHouseNo(){
            return this->HouseNo;
        }
        void updateDetails(std::string Name, std::string Addr, uint16_t houseno){
            this->name = Name;
            this->addr = Addr;
            this->HouseNo = houseno;
        }
        void updateAddr(std::string Addr){
            this->addr = Addr;
        }
        void updateName(std::string Name){
            this->name = Name;
        }
        void updateHouseNo(uint16_t hsno){
            this->HouseNo = hsno;
        }

};
int main(int argc, char* argv[], char** env){
    std::string name = "Radheshyam Kumar Singh";
    std::string addr = "Vill-Mitwar, Post-Gayghat, Thana-Andar, Dist-Siwan, Pin-841231";
    uint16_t hsno = 12;
    unique_ptr<person> ptr = std::make_unique<person>(name, addr, hsno);
    std::cout<<"Old House No: "<<ptr->getHouseNo()<<"\n";
    ptr->updateHouseNo(40);
    std::cout<<"New House No: "<<ptr->getHouseNo()<<"\n";
    std::cout<<"Obj addr: "<<ptr.get()<<"\n";
    return 0;
}