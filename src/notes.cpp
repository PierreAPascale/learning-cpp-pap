/*
C++ 
OOO -> based on "Models". You can define an object in many ways, choose what you need to: you don't need a car's number of seats if you're creating racecars
but you need it for a car retailer.

NAMESPACES
Splits in your code (regions) to separate otherwise identical names. If using a  library, you can use some of its functions by telling C++ to use a specific region. The scope resolution operator serves that purpose ::



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


stdint.h header file from the C library  -> <cstdint>
In C, not C++!
However, some were popular, so made into C++. Name had a c added as prefix.
uint32_t
int16_t
U = unsigned, int = integer, number = bit size, _t = type


    DECLARATIONS https://learn.microsoft.com/en-us/cpp/cpp/using-declaration?view=msvc-170
    Defining a word as a variable, function or other. 
    Declarations are always made at a specific scope (in a function, in a library, in a loop, etc.). That scope can be changed. Exiting a scope == variables deleted from memory.
        "using"
        To bring an identifier to another scope as if it was part of it. Can be used to make children function. Page above is super clear for calling function from class D, doing something, then calling the parent function.

    DIRECTIVES https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170#using_directives
        "using"
        To bring an identifier (function, var, object...) into scope so it can be
        1. Assigned to a variable (for shorter code?)

VARIABLES
Temporary data storage units. Must be declared prior to usage.
Declaration can contain initialization

varType varName;
Can use types defined in libraries -> std::string 

Can declare multiple at once using commas, initializing as needed:
    int a, b = 5;


Values they can contain:

Constant Literals:
Integers = int, with an optional Radix (la base du nombre, base 8 base 12 base 16). default = Decimal, no radix specifier
-5, 123, etc.
    Leading 0 = Octal (base 8)
    0x = Hexadecimal 0x10 (12)
    0b = Binary (1001)
    Trailing (suffix) U = Unsigned 23U

Floats:
    Float literal = Trailing f = 23.05f
    double: default = 25.4

Chars:
    integers (fitting in 8 bits), ASCII between single quotes = 'x'
    Backslash = escape character 
    '\0' == Null character, delimiting the end of a string
    '\n' == new line character

String Literals:
    "string"

Variables are declared at a specific scope.
Exiting the scope == variables deleted from memory.

"Automatic variables" == managed by compiler, allocated in the "stack" segment of memory, which itself is temporary.

Type Inference: must initialize at declaration, but compiler infers the type of the variable.
Maybe needs a line for each var???
    auto a =1, b = "", c = 'c', d = 3.14f, e = 12345678901, f = 3.14, g = true
    a = int32, e exceeds 32bits, so long int
    d = float, f = double
    g = boolean

Getting the Type:
typeid(varName).name()
    typeid is implementation dependent. Compilers will change the output... some more descriptive than others. Might be int or double, instead of i and d. Or even an error.
    name is a member function of each type.
i = int, l = long, f = float, d = double, b = bool, c = char, PKc (pointer to const char) = string

Shorthands:
Modifying variable, setting it    
    varName = varName + 2
    varName += 2


DATA TYPES
Representations encoded in bits that vary in length. 
cppreference.com/basic concepts/types
Primitive Types: basic category, without defined implementation (ex: int is primitive, vs uint32_t)
Portable Types: types that can be ported to different systems, because they are always declared and compiled with the same properties (behavior and size).  sdtint.h (library) defines fixed-width integers using the ISO C99 standard: int8_t (signed 8bit int) , uint32_t (unsigned 32bit int)

Fundamental/arithmetic/compound : https://en.cppreference.com/w/cpp/language/types
Complete/Incomplete: Wether it has all information required to define a space & layout in memory. This can apply to classes, data types, objects,  
Constant, Volatile:

    VOID
    Fundamental Type, empty set of value.


    INT (integer, variable # of bits, its length, based on implementation... generally 32bits, can be 16)
        SIGN / UNSIGNED
        Refers to the Positive/Negative split: signed 8-bit integer ranges from -128 to 127
        Unsigned ranges from 0 to 255.
        Sign is stored in the left-most bit (also called MostSignificantBit, MSB), typically the largest part of the value of the number
        
        Instead of using stdint.h library w/ ISO C99 standard, can declare them:
            unsigned int varName;
        
        Negative values loop back to the highest if stored in an unsigned variable; -2 will become 4294967294 
        It is equal to 2^32 -2, the "complement representation" in binary: exact same binary, but different interpretation.
    
    FLOAT (floating-point numbers: Real numbers) using IEEE754 binary floating point Standard
    Float
    Double : more precision and range, but computationally intense
    Long double

    BOOLEAN (true/false)
    bool
    In C++, {true,false} are defined as keywords for it. 0 = False, everything else = True

    CHAR (character, 8bits)
    ASCII as a byte. Can be used as an integer...

    STRINGS
    Not native to C++
    Arrays of characters, terminated with value 0
    std library has it as a Class: <string> header includes the class and functions to manipulate the Class/data.

    POINTERS
    Data type for memory addresses
    May act as references to variables
    Can be used to access multiple different variables sequentially.
    Nullptr = a pointer of type nullptr_t (distinct type that is neither pointer nor member type). Defined in header <cstddef>, std::nullptr_t


Struct
Extern

FUNCTIONS
outputType functionName(parameters)

Specific Functions:
int main(){ 
    functionBody
};
The main function can receive nothing, or STRINGS coming from command line (think command promt, functions with arguments after... dvars and such)


EXPRESSIONS
Temporary data storage unit which you must declare before usage with a type + name and can be initialized in declaration (like variables) 
Can contain variables, constants and operators, always producing a value


ASSIGNMENTS
Line of code that assigns value to a variable.
Left hand must be able to hold a value, right-hand side is an expression.
Expression data types must match (not enforced by compiler)

OPERATIONS
https://en.cppreference.com/w/cpp/language/operator_precedence

Increment/decrement varName++ varName-- and ++varName --Varname (prefix vs suffix expressions)

Arithmetic
    + - * / (integer division, quotient) % (modulo, remainder)

Bitwise Booleans: bit-by-bit between operands. NOT LOGICAL OPERATORS.
    & (ampersand) Bitwise AND, | (single vertical bar) Bitwise OR, ~ (tilde) Bitwise NOT , caret ^ bitwise XOR
    << >> left/right shift

Logical (Booleans):
    %% AND, || OR
    ! NOT operator inverts its operand. If any other data 
    No Logicial XOR because of Relational !=. XOR returns true if both values are the same (false false or True True), so a!=b is same result as XOR. 
    ONLY FOR BOOLEANS
        For NonBools, must convert them to bools first. Because we don't care in a XOR specifically if both values are inverted (we would care if one is) then we can use it to convert that data type to a bool (0 would become true, everything else would become false).
        if(!a != !b) {}
        Notice how it's the same as a!=b but also works for non-bools.


https://en.cppreference.com/w/cpp/language/operator_comparison
Relational:
    >, <, >=, <=

    Equality: == !=
        (do not use = in a conditional, as it returns the assigned value: a = 5 returns 5, a == 5 compares if a is equal to 5)    

    Three-way <=>

Pointer: These have a single operand, nothing to the left of operator.
    Prefix * : Dereference Pointer (of variable to its right) 
        Gives access to the variable it's pointing to. Ceases to be a pointer
    Prefix& : Address of variable at its right (
    -> Arrow : access to members of classes or structures from a pointer

KEYWORDS
return();
A keyword to output a value from the function, ending it.
0 is traditionally "no Error". Ex: 404 meaning "page not found"
Can use parentheses around returned value or not: 
    return(value) or return value

ORIENTATION
    NARROW / WIDE





HEADER FILES
IOStream is one! Contains different objects and functions.
<string> header includes the class and functions to manipulate the Class/data



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