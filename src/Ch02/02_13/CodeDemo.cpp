// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>
#include <array>
#include <cstddef>

int main(){
    const std::size_t n = 5;
    int nums[n] = {1,23,32,24,337};
    float result; 

    // Write your code here
    result =nums[0]+nums[1]+nums[2]+nums[3]+nums[4];
    result /= (float)n;
    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
