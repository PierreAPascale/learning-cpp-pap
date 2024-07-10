/*
C++ 
OOO -> based on "Models". You can define an object in many ways, choose what you need to: you don't need a car's number of seats if you're creating racecars
but you need it for a car retailer.

ENCAPSULATION
Only include information about themselves.
Don't include gas price in the car; the gas station would have it.

CLASSES
Classes contain two types of members: data + function
Car.make, Car.paint
Each instance = an object of the class (3 car objects)


ACCESS
Private : accessible only by itself, not even inherited classes
Public : accessible by any other part of the code
Protected : accessible by inherited classes

INHERITANCE AND POLYMORPHISM
Subclasses (class based on another) and superclasses (the class it inherits from)
Poly = Function can be implemented differently in subclasses (inherited) vs superclass
Such "sibling" classes are polymorphic.

////

SYNTAX
Case-Sensitive
Indents ignored by converters, but readability ++
; at end of most lines, except library inclusions, } to end functions, ---- Does it mean "do this line of code"? Closing a function isn't taking an action...


LIBRARIES
Collections of objects and member functions to avoid rewriting them.
Inclusions: #include <library> (or Header?? IOStream is one of the headers for the standard library) 
No ; at end of line

Calling Functions from libraries is done by calling members of a library with OPERATOR - SCOPE RESOLUTION :: 
Scope is where the function/variable is accessible in the code, so you're telling where to find the object (here, defined in library)
member::object


Data can be inserted into objects using OPERATOR - LEFT BOUND INSERTION << 

IOStream : contains input output functions, to print to screen and receive text from keyboard. https://cplusplus.com/reference/iostream/
Can call on special characters that are part of libraries. Ex: std::endl is a symbol to add the character for endLine

std::cout 
standardlibrary::standardOutputStream, or default destination of the environment (an output log, a dedicated text object, wtvr environ defined) 

std::cout<<"String" << "as many consecutive strings as you need" 

String Standard Library
#include <string>

VARIABLES
varType varName;
Can use types defined in libraries -> std::string 

FUNCTIONS
outputType functionName(parameters)

Specific Functions:
int main(){ 
    functionBody
};
The main function can receive nothing, or STRINGS coming from command line (think command promt, functions with arguments after... dvars and such)

KEYWORDS
return();
A keyword to output a value from the function, ending it.
0 is traditionally "no Error". Ex: 404 meaning "page not found"
Can use parentheses around returned value.

ORIENTATION
Narrow or Wide








*/