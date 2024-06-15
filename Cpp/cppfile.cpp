#include <iostream>
class A{
	public:
		int a;
		A(int i){/*code*/;}
		A(){}
		~A(){/*code*/;}
};
namespace SID{
	class addr{
		public:
			std::string name = "Sid";
			std::string vill = "Mit";
			std::string Father_name = "ABC";
	};
	addr Add;
	int hight(){int hght = 6;}
	int weight(float W){ float wgt = W;}
}
namespace VIN{
	class addr{
		public:
			std::string name = "Sid";
			std::string vill = "Mit";
			std::string Father_name = "ABC";
	};
	addr Add;
	int hight(){float hght = 5.5;}
	int weight(float W){ float wgt = W;}
}
using namespace SID;
using namespace VIN;
int main()
{
	std::cout<<SID::Add.name<<std::endl;
	SID::hight();
	VIN::weight(68.67f);
	return 0;
}