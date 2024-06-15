#include<iostream>
using namespace std;
class str
{
	public:
	      int a;
		  float b;
}obj;
int main()
{
	obj.a=10;
	obj.b=10.25f;
	cout << obj.a << endl << obj.b << endl;
	return 0;
}