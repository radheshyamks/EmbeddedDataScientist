#include <iostream>
int fun(char x){
	std::cout<<"char"<<std::endl;
}
float fun(int t, int x){
	std::cout<<"int"<<std::endl;
}
int main()
{
	int * ptr = new int[10];
	for(int i=0; i<10; i++){
		*(ptr+i) = 10*i;
	}
	for(int i=0; i<10; i++){
		std::cout<<*(ptr+i) <<std::endl;
	}
	delete[] ptr;
	return 0;
}