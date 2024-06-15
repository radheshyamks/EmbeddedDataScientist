#include <iostream>
int main(int argc, char* argv[], char** env){
	int *p = new int(10);
	std::cout<<"before *p = "<<*p<<"\n";
	*p = 20;
	std::cout<<"*p = "<<*p<<"\n";
	return 0;
}