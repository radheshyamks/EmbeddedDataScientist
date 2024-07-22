#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

namespace SingleTon{
	class Singleton{
	    private:
		static Singleton* instance_;
		std::string value_;
		Singleton();
		Singleton(const std::string& value);
	    public:
		/* deleted copy assignment operator */
		void operator=(Singleton&)=delete;
		/* deleted move assignment operator */
		void operator=(Singleton&&)=delete;
		/* deleted copy constructor */
		Singleton(Singleton&)=delete;
		/* deleted move constructor */
		Singleton(Singleton&&)=delete;
		/* Created destructor */
		~Singleton();
		static Singleton* GetInstance(const std::string& value);
		std::string get_value(void)const;
		void update_data(const std::string &value);
	};
}
static SingleTon::Singleton* instance_=nullptr;
SingleTon::Singleton::Singleton(){
    std::cout<<"Singleton Constructor\n";
}
SingleTon::Singleton::Singleton(const std::string& value){
    std::cout<<"Singleton param Constructor\n";
    value_ = value;
}
SingleTon::Singleton::~Singleton(){
    std::cout<<"Singleton Destructor\n";
}
SingleTon::Singleton* SingleTon::Singleton::GetInstance(const std::string& value){
    static Singleton* instance_;
    if(instance_==nullptr){
	instance_=new Singleton(value);
    }
    return instance_;
}
std::string SingleTon::Singleton::get_value(void)const{
    return value_;
}
void SingleTon::Singleton::update_data(const std::string &value){
	value_ = value;
}
int main(int argc, char* argv[], char** env){
    std::string data = "I am here";
    SingleTon::Singleton*instance =  SingleTon::Singleton::GetInstance(data);
    std::cout<<instance->get_value()<<"\n";
	std::string s = "Bye Bye";
	instance->update_data(s);
	std::cout<<instance->get_value()<<"\n";
    delete instance;
    return EXIT_SUCCESS;
}
