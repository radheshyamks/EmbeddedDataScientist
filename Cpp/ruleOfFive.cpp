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
        if(obj.p_!=nullptr){
            this->p_ = new int;
            *this->p_ = *obj.p_;
        }
    }
    // III. Copy Assignment Operator
    ruleOfFive& operator=(ruleOfFive& obj){
        if(this!= &obj){
            if(this->p_!=nullptr && obj.p_!=nullptr){
                *this->p_ = *obj.p_;
            }else if(this->p_==nullptr && obj.p_!=nullptr){
                this->p_ = new int;
                *this->p_ = *obj.p_;
            }else{
                ;
            }
        }
        return *this;
    }
    // IV. Move Constructor
    ruleOfFive(ruleOfFive&& obj){
        /*if(this!=&obj){
            if(obj.p_!=nullptr){
                if(this->p_!=nullptr){
                    delete[] this->p_;
                    this->p_ = obj.p_;
                    obj.p_ = nullptr;
                }else{
                    this->p_ = obj.p_;
                    obj.p_ = nullptr;
                }
            }
        }*/
        this->p_ = obj.p_;
        obj.p_ = nullptr;
    }
    // V. Move Assignement Operator
    ruleOfFive& operator=(ruleOfFive&& obj){
        if(this!=&obj){
            if(obj.p_ != nullptr){
                if(this->p_!= nullptr){
                    delete[] this->p_;
                    this->p_ = obj.p_;
                    obj.p_ = nullptr;
                }else{
                    this->p_ = obj.p_;
                    obj.p_ = nullptr;
                }
            }
        }
        return *this;
    }
};

int main(int argc, char* argv[], char**env){
    return 0;
}