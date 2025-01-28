#include <iostream>

//Exit Function.
//Returns integer from a single parameter (last remaining). Return type was INT in example for both SUMMER functions, but I used i to make it work with both int and float... The first argument determines the return type.
template<typename i>
i summer(i last){ 
    return last;
}

//Recursive Add.
//
template<typename i,typename ... Args> //Both use typename. If "first" is int, errors when calling it (main). If Args is int, Parameter pack isn't initialized properly: errors when called 
i summer(i first, Args ... args){
    return first+summer(args ...);
} 

int main(){
    auto result = summer(1.0f,4.8f,3.6f,5.5f); //Considers them Ints because they all go through template<typename i>, which returns them as int.
    auto result2 = summer(1,4,3,5);
    std::cout << result << " " << result2 << std::endl;

    return 0;
};