#include <iostream>
class Base{
	private:
		int x;
	public:
		Base(int i=0)
		{
			x = i;
			std::cout<<"It is constructor\n";
		}
		void print()
		{
			std::cout<<"x = "<< x << std::endl;
			return;
		}
};
int main()
{
	Base obj(20);
	obj.print();
    return 0;
}