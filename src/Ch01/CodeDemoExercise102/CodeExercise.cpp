#include <iostream>
#include <string>

int main(){

    std::cout << "Please click and type:" << std::flush; // Flush forces the output to be sent to the terminal before input is requested
    std::string strVar;
    std::cin >> strVar; //Assigns value to variable. Only works for single words!
    std::cout << "You have typed: " << std::endl << strVar; // Inserts value from variable to the output object

    std::cout << std::endl;
    return(0);
}