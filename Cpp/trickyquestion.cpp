#include <iostream>
#include <stdio.h>
void fun(int x, int y)
{
	std::cout<<x<<y<<std::endl;
}
template <typename T1, typename T2>
void fun(T1 x, T2 y)=delete;
class A{
	private:
		virtual void fun(){
			std::cout<<"class A fun"<<std::endl;
		}
};
class B: public A{
	public:
		void fun()override{
			std::cout<<"override fun"<<std::endl;
		}
};
int main(int argc, char* argv[], char** env)
{
	fun(10, 40);
	//fun(39.45f, 43.29f);it will through error
	B* ptr = static_cast<B*>(new A());
	ptr->fun();
	while(argc<=100 && printf("%d ", ++argc)){}
	std::cin>>n;
	std::string arr[2] = {"Even", "Odd"};
	std::cout<<"Number is: "<<arr[n%2]<<std::endl;
	return 0;
}