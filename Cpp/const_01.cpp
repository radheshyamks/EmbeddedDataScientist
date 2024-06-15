#include <iostream>
using namespace std;
template <typename T>
void fun(T x, T y)
{
	cout<<"x = "<< x << endl;
	cout<<"y = "<<y << endl;
	return;
}
int main()
{
	fun(1, 2);
	fun('A', 'B');
	fun(2.56f, 4.6f);
}