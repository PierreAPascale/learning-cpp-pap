// Learning C++ 
// Exercise 01_02
// Hello World, by Eduardo Corpeño 

#include <iostream>

int main(){
    std::cout << "Hi There!" << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}

/* Variant that changes the scope of the std namespace/library to remove the need of calling it out explicitly for those functions
#include <iostream>
using namespace std;

int main(){
    cout << "Hi There!" << endl;

    cout << endl << endl;
    return (0);
}
*/