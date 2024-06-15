#include <iostream>
class Base{
	private:
			int x, y;
	public:
			Base(int i=0, int y=10):x{x}, y{y}{std::cout<<"It is a constructor\n";}
			void set_value(int x, int y){
			 this->x = x;
			 this->y = y;
			}
			void print(){
			 std::cout<<"x = "<< x <<std::endl;
			 std::cout<<"y = "<< y <<std::endl;
			}
};
int main()
{
	Base obj(20, 30);
	obj.set_value(100, 200);
	obj.print();
	Base *bptr, obj1(50, 150);
	bptr = &obj1;
	bptr->set_value(300, 600);
	bptr->print();
}