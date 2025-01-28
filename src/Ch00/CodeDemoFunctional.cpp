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
/*


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

//----------
#include <iostream>
 
int main()
{
    int n1 = 1;
    int n2 = ++n1;
    int n3 = ++ ++n1;
    int n4 = n1++;
//  int n5 = n1++ ++;   // error
//  int n6 = n1 + ++n1; // undefined behavior
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n'
              << "n3 = " << n3 << '\n'
              << "n4 = " << n4 << '\n';
}
*/

#include <functional>
#include <iostream>
#include <vector>

/*

int main(){
auto continuousAdd = [](int initial, int  addBy){
    int result = initial;
    return [result, addBy](int secondValueToAdd)mutable{ 
        result+=addBy;
        result+=secondValueToAdd;
        return result;
    };
};

auto add = continuousAdd(2,3);
std::cout << add(2) << std::endl;
};
*/



/*template<int toCube> //"We will define templates with some int values."

struct Cube {
    enum {value = toCube*toCube*toCube};
    //This code block fails, because it requires instantiation to initialize value (constructor). Cannot initialize in-line.
    static int value;
    Cube(){ value = toCube*toCube*toCube;}
    
};
*/

/* SPECIALIZATIONS*/
/*
template<int input, int sum = 1>
struct Factorial : Factorial<input-1, input*sum>{
}; //Infinitely Recursive : Factorial calls itself forever.

//"Overloads", replacing "if input == 1" by giving Factorial a different implementation when that input combination occurs.

template<int sum>
struct Factorial<1,sum>{
    enum {
        value = sum
    };
};

    
int main(){
    //std::cout << Cube<3>::value << std::endl;
    std::cout << Factorial<3>::value << std::endl;
    return 0;
}

*/


template<int n>
struct fibonacci {
    enum{value= fibonacci<n-1>::value + fibonacci<n-2>::value};//N is the number of iterations. fibonacci<45> invokes 43 and 44, which invoke 43 and 42 + 42 and 41 respectively, all the way down to 0.
};

template<>
struct fibonacci<0>{
    enum {value = 0};
};
template<> //Templates must directly precede their declaration, and are not cross-compatible (must write this line again, despite writing it 4 lines before) 
struct fibonacci<1>{
    enum {value = 1};
};


int main(){
    //std::cout << fibonacci<45> << std::endl; //fibonacci<N> is a TYPE, not a VALUE.
    std::cout << fibonacci<45>::value << std::endl; 
    return 0;
}