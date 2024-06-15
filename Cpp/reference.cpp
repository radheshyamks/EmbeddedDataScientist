#include <iostream>/*header file*/
void fun(int& y){
	y++;
}
int mian(int argc, char** argv, char** env)/*main takes threee argument*/
{
	int x=10;
	fun(x);
	std::cout<<x<<std::endl;
	return 0;
}