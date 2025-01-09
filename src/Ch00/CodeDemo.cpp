// Learning C++ 
// Exercise 00_03 - Modified
// Using the exercise files on GitHub, by Eduardo Corpeño 
/*
#include <iostream>

int main(){
    float num_1, num_2, result;

    std::cout << "Enter number 1: " << std::flush;
    std::cin >> num_1;
    std::cout << "Enter number 2: " << std::flush;
    std::cin >> num_2;
    
    result = num_1 + num_2;
    
    std::cout << "The result of the addition is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
*/




// C++ program to point address 
// of a pointer 
#include <iostream> 
using namespace std; 
  
// Driver code 
int main() 
{ 
    int* ptr, var; 
    var = 5; 
  
    // Assign address of var 
    // to ptr 
    ptr = &var; 
  
    // Access value pointed by ptr 
    cout << "Value pointed by ptr: " <<  
            *ptr << endl; 
  
    // Address stored by ptr 
    cout << "Address stored at ptr: " <<  
             ptr << endl; 
  
    // Address of pointer ptr 
    cout << "Address of ptr: " <<  
             &ptr; 

    cout << endl << endl;
}