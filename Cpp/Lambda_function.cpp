/*Lambda function is a very good idea in C++
  Syntax:
  #include <functional>
  std::function<return_data_type(argument)>funcn_name = [capture](argument)->return_data_type{// code};
*/
#include <iostream>
#include <functional>
#include <cstdint>

int main()
{
 std::function<int(void)> fptr = []()->int{std::cout<<"This is lambda function\n"; return 1;};
 int x = fptr();
 std::cout<<"x = "<< x <<std::endl;
 uint32_t z=1, y=2;

 // Other way to call lambda function
//  [=]()->int{y = ++x;return x+y;}();// it is compile time error
auto f = [=]()->int{return z+y;};
std::cout<<f()<<std::endl;

uint32_t k=0,l=0;
std::function<int(void)> foo = [&]()->int{l = ++k; return k+l;};
std::cout<<foo()<<"\n";

uint32_t a=0, b=0;
std::function<uint32_t(uint32_t, uint32_t)> f1 = [=](uint32_t t, uint32_t u)->uint32_t{ return t+u+z+y;};
f1(++a, ++b);
return 0;
}