/*Lambda function is a very good idea in C++
  Syntax:
  #include <functional>
  std::function<return_data_type(argument)>funcn_name = [capture](argument)->return_data_type{// code};
*/
#include <iostream>
#include <functional>
int main()
{
 std::function<int(void)> fptr = []()->int{std::cout<<"This is lambda function\n"; return 1;};
 int x = fptr();
 std::cout<<"x = "<< x <<std::endl;
 return 0;
}