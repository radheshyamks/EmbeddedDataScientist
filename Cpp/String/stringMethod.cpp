#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[], char** env){
    std::string str = "Radheshyam Kumar Singh";
    // Accessing string using indexing method
    for(int i=0; i<str.length(); i++){
        std::cout<<str[i];
    }
    std::cout<<"\n";
    // Accessing string using range-for loop
    for(char i:str){
        std::cout<<i;
    }
    std::cout<<"\n";
    // accessign string using at() method
    for(int i=0; i<str.length(); i++){
        std::cout<<str.at(i);
    }
    std::cout<<"\n";
    std::cout<<"size = "<<str.size()<<"\n";
    std::cout<<"length = "<<str.length()<<"\n";
    // Append method
    str.append(" Mitwar");
    std::cout<<str<<"\n";
    const char* cString = str.c_str();
    for(int i=0; cString[i]!='\0'; i++){
        std::cout<<cString[i];
    }
    std::cout<<"\n";
    return 0;
}