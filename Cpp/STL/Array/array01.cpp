#include <array>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>

/* syntax of creating an array
* std::array<T,N> Arr_Name
* Array class Methods:
* Element Access:
* front --> Access the first element
* back --> Access the last element
* data -> Direct access to the underlying contiguous storage
* at --> Access specified element with bounds checking
* operator[] --> Access specified element
* 
* begin() --> returns an iterator to the beginning
* end() --> returns an iterator to the end
* 
* Capacity:
* empty --> checks whether the container is empty
* size --> returns the number of elements
* max_size --> returns the maximum possible number of elements
*/
#define ARR_SIZE 10

using namespace std;
int main(int argc, char* argv[], char**env){
    std::array<uint32_t, ARR_SIZE> arr={1,2,3,4,5,6,7,8,9,0};
    for(int i=0; i<ARR_SIZE; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=0; i<ARR_SIZE; i++){
        std::cout<<arr.at(i)<<" "; /* it will check the bound of array index */
    }
    std::cout<<"\n";
    /* It will access the first element of an array */
    std::cout<<arr.front()<<"\n";
    /* It will access the last element of an array */
    std::cout<<arr.back()<<"\n";
    for(int i=0; i<ARR_SIZE; i++){
        std::cout<<*(arr.data()+i)<<" ";
    }
    std::cout<<"\n";
    return EXIT_SUCCESS;
}