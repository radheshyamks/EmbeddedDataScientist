#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <array>
#include <set>
#include <map>
namespace ConstExpr{
    constexpr int x=10;
    /*constexpr*/int arr[x]={1,2,3,4,5,6,7,8,9,10};
};
int main(int argc, char* argv[], char** env){
    for(int k:ConstExpr::arr){
        // /*constexpr*/int k = ConstExpr::arr[0];
        std::cout<<k<<"\n";
    }
    return EXIT_SUCCESS;
}