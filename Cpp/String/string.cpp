#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdint> 
using namespace std;

class String{
    private:
        char* str_;
        uint32_t len;
    public:
        String(){
            str_ = nullptr;
            len = 0; 
        };
        // str_ing()=delete;
        String(const char* p){
            if(!p) return;
            this->len = strlen(p);
            this->str_ = new char[this->len+1];
            strcpy(this->str_, p);
        }
        char* getval(void){
            return this->str_;
        }
        //copy constructor
        String(const String& other){
            if(!other.str_)return;
            this->len = other.len;
            this->str_ = new char[this->len+1];
            strcpy(this->str_,other.str_);
        }
        // str_ing(char p[]):str_{p}{}
        // assignment operator overloading
        String& operator=(const String& other){
            if(this!=&other){
                this->len = other.len;
                if(!this->str_){
                    this->str_ = new char[this->len+1];
                    strcpy(this->str_, other.str_);
                }else{
                    delete[] this->str_;
                    this->str_ = new char[this->len+1];
                    strcpy(this->str_,other.str_);
                }
            }
            return *this;
            // this->str_ = other.str_;
        }
        String& operator=(const char* str){
            uint32_t len = strlen(str);
            if(!this->str_){
                this->str_ = new char[len+1];
            }else{
                delete[] this->str_;
                this->str_ = new char[len+1];
                strcpy(this->str_, str);
            }
            return *this;
        }
        ~String(){
            if(!str_)return;
            delete[] str_;
        }
};

int main(int argc, char* argv[], char** env){
    // printf("%s\n", "Hello Geeks");
    String s = "Hello";
    String s1 = "Bye";
    String s2 = s1;
    std::cout<<s2.getval()<<"\n";
    s2 = "Hi How are you!!!";
    std::cout<<s2.getval()<<"\n";
    s2 = s;
    std::cout<<s2.getval()<<"\n";
    return EXIT_SUCCESS;
}