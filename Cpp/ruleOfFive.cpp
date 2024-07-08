#include <iostream>
using namespace std;

class ruleOfFive{
    private:
        int* p_;
    public:
    explicit ruleOfFive(int*p=nullptr){
        this->p_ = p;
        std::cout<<"Constructor\n";
    }
    // I. Destructor
    virtual ~ruleOfFive(){
        std::cout<<"Destructor\n";
        if(this->p_!=nullptr){
            delete[] p_;
        }
    }
    // II. Copy Constructor
    ruleOfFive(ruleOfFive& obj){
        std::cout<<"Copy Constructor\n";
    }
    // III. Copy Assignment Operator
    ruleOfFive& operator=(ruleOfFive& obj){}
    // IV. Move Constructor
    ruleOfFive(ruleOfFive&& obj){}
    // V. Move Assignement Operator
    ruleOfFive&& operator=(ruleOfFive&& obj){}
};