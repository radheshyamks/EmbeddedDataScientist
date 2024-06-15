#include <vector>
#include <iostream>
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        
    }
};

int main(int argc, char* argv[], char** env){
    Solution s;
    std::vector<int> color = {2,0,2,1,1,0};
    for(std::vector<int>::iterator ptr=color.begin(); ptr != color.end(); ptr++){
        std::cout<<*ptr<<" ";
    }
    std::cout<<"\n";
    return 0;
}