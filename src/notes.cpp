/*
C++ 
OOO -> based on "Models". You can define an object in many ways, choose what you need to: you don't need a car's number of seats if you're creating racecars
but you need it for a car retailer.

NAMESPACES
Splits in your code (regions) to separate otherwise identical names. If using a  library, you can use some of its functions by telling C++ to use a specific region. The scope resolution operator serves that purpose ::

MODELS
How objects are defined

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

DECLARATIONS https://learn.microsoft.com/en-us/cpp/cpp/using-declaration?view=msvc-170
    "using"
    To bring an identifier to another scope as if it was part of it. Can be used to make children function. Page above is super clear for calling function from class D, doing something, then calling the parent function.

DIRECTIVES https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170#using_directives
    "using"
    To bring an identifier (function, var, object...) into scope so it can be
    1. Assigned to a variable (for shorter code?)

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
Can use parentheses around returned value or not: 
    return(value) or return value

ORIENTATION
Narrow or Wide




HEADER FILES
IOStream is one! Contains different objects and functions



*/



/*
VS Code can give prompts for each installation, etc. automatically, in a step by step manner, like Idea editors, so that it wont be so long procedure for beginners.

Sequence of steps to do (most of the things are one time):

  
    one time:  
        install a C/C++ complier, add to PATH environment variable  
        install C/C++ plugin for visual studio code  
        tell visual studio code where the compiler is and what is the short cut to build and run  
           these are files under ".vscode" (see below)
    every project:  
        crate a project  
        build project  
        run project  
Detailed:

One time:


Note: Point 'A' below can be skipped if you already have a compiler.

A. Install a compiler (if you don't have one already)  
    Example below, installs MinGW c++ compiler on Windows:  
    Download from here: https://sourceforge.net/p/mingw-w64/mailman/message/36103143/  
    1. For windows, I downloaded https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/mingw-w64-v5.0.3.zip  
    2. unzip mingw-w64-v5.0.3.zip  
    3. rename unzipped folder to MinGW, Move it to C:\MinGW\  
    4. verify that you have "C:\MinGW\bin\gcc.exe" director/file, otherwise make necessary change to folder  

B. Add your compiler to PATH environment variable
    1. Add "C:\MinGW\bin" to PATH > user environment variable  
    2. verify gcc command works from cmd  
        restart your cmd  
        run below command in 'cmd'  
            where gcc  
            The output should be: C:\MinGW\bin\gcc.exe  

C. Restart your visual studio code  
    1. install C/C++ plugin, as below:  
        From Menu  
             View > Extension  
        Search & Install below extension  
            C/C++  

Every project:

Note: You can copy paste the .vscode folder every time


A. Create a below "myproj" folder & files, like below in below structure:  
    C:\myproj\myfile.cpp  
    C:\myproj\.vscode\  
    C:\myproj\.vscode\c_cpp_properties.json  
    C:\myproj\.vscode\launch.json  
    C:\myproj\.vscode\settings.json  
    C:\myproj\.vscode\tasks.json  

B. Download & overwrite the above ((5 files)), from below link

https://github.com/manoharreddyporeddy/my-programming-language-notes/tree/master/vscode-c%2B%2B

C. Restart your visual studio/vs code  

D. Open project in vs code & run project:

  Drag and drop "myproj" folder into visual studio code  
  BUILD PROJECT:   press "Ctrl + Shift + B" to build your myfile.exe  
  RUN PROJECT:     press "Ctrl + F5" to run your myfile.exe  

Thats all, hope that helped.

More info: https://code.visualstudio.com/docs/languages/cpp

*/