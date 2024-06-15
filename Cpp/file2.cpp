#include<iostream>
class abc{
		int j, k;
		static int y;//error
	public:
		void Init(int a, int b){
			j=a;
			k=b;
		}
		void print(void){
			std::cout<<"j = "<<j<<std::endl;
			std::cout<<"k = "<<k<<std::endl;
			//std::cout<<y<<std::endl;
			//fun();
		}
		static void fun(){
			std::cout<<y<<std::endl;
			//std::cout<<k<<std::endl;
		}
};
int abc::y=10;
int main()
{
	abc obj;
	obj.Init(10, 20);
	obj.print();
	abc::fun();
	std::cout<<"abc size = "<<sizeof(obj)<<std::endl;
	std::cout<<"abc size = "<<sizeof(abc)<<std::endl;
	return 0;
}