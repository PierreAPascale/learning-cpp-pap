/*
C++ 

MODELS
OOO -> based on "Models". You can define an object in many ways, choose what you need to: you don't need a car's number of seats if you're creating racecars
but you need it for a car retailer.

ENCAPSULATION

Of Models; to only include information about themselves.
Don't include gas price in the car model; the gas station model would have it.

CLASSES
Classes contain two types of members: data + function
Car.make, Car.paint
Each instance = an object of the class (can have 3 car objects)
    CONSTRUCTORS
    Function to define the class within a class definition:
        className( arg1, arg2){
            var1 = arg1;
            var2 = arg2;
        }
    Best practice: discernable names (_i for initializer variables)
ACCESS
Of Members.
Private : accessible only by itself, not even by inherited classes
Public : accessible by any other part of the code
Protected : accessible by itself and inherited classes

INHERITANCE AND POLYMORPHISM
Subclasses (class based on another) and superclasses (the class it inherits from)
Poly = Function can be implemented differently in subclasses (inherited) vs superclass
"Children" and "Sibling" classes with these re-implementations are polymorphic.
Can add on to a parent's implementation by calling it in the Child's polymorphic implementation.

SYNTAX
Case-Sensitive
Indents ignored by converters, but readability ++
; at end of most lines, specifically at the end of STATEMENTS.
Library inclusions are NOT statements. (Preprocessor Directive)
Functions are NOT statements. It only links a sequence of statements (body of the function) to a name/arguments/etc.



CPP TO EXE : CODE PROCESSING
Written code is Preprocessed, then Compiled.
Because this is done before compiling, anything set as part of these directives has no SCOPE. They never use ;

    INITIALIZER
        (could be after Preprocessor directives)
        Operates on some keywords like auto, to deduce the data type of the variable.

    PREPROCESSOR DIRECTIVES https://learn.microsoft.com/en-us/cpp/preprocessor/hash-line-directive-c-cpp?view=msvc-170
    # == directive
    Can be used at multiple places in the same code. They are not statements, therefore out of that sequence. 

    Software part of compiler tool chain : directives are information about what to remove/add in the code.
    Used for constants, libraries, selecting code blocks, ........
    #include (libraries) 
        It inserts referenced file into the code, replacing the directive (#) line (#line). It replaces that single line with ALL of the specified file, so it can be used. A copy/paste of the entire thing into your file. This is why you want to include HEADERS(.h), not IMPLEMENTATION (.cpp) in your files. 
        A further step in the process, the (linker?) will recognize the relation and create the required links to the compiled implementation file AKA Object?
        <name>
            Not a path: will always look for file in a given location, ie. Environment variable that sets a default folder!
            Would otherwise need a path + file type (.h, .hpp)
            <iostream>, <string>, <stdint.h>
    #define MACRO_NAME (constants)*see further down
        defines a symbol to mean whatever you put to its right. They become MACROS. Often written with all caps.
        #define CAPACITY 5000 (no semicolumn, no = for assignment. It's not assigning, it's a preprocessor directive. It's not code.)
        If used to drive an #ifdef (see below) directive, can be commented out to skip definition, skipping ifdef block.

    #ifdef MACRONAME(select code block for different compile scenarios) "if defined", finishes with #endif
        Can be used for debug purposes. Code between these will only be run if the macro is defined in the code.
        Macro doesn't need a value if it's purely for an ifdev.


    
    #line digit-sequence ["filename"]
        Tells the compiler to use line number + (optional) filename from that point on. That number is always incremented per line (to let you find it)
        #line 20 
            tells the compiler that the next line is line20 if an error occurs there. Can request those 2 values using preprocessor macros:  __LINE__ and __FILE__ 



NAMESPACES
Splits in your code (regions) to separate otherwise identical names. If using a  library, you can use some of its functions by telling C++ to use a specific region. The scope resolution operator serves that purpose ::

//Similar to Houdini's "Geometry" inputs - you have to tell the program where to find the model's members

HEADER FILES
IOStream is one! Contains different objects and functions.
<string> header includes the class and functions to manipulate the Class/data

LIBRARIES
https://cplusplus.com/reference/iolibrary/
Collections of objects and member functions to avoid rewriting them.
Inclusions: #include <library> (IOStream is one of the headers from the standard library) 
Libraries contain header file(s) sharing a purpose.
Example hierarchy:

Standard Library
    Input/Output library
        <iomanip> (iomanip.h) header, for manipulators of inputs/outputs, not only streams.
            get_time (function) gets characters from the input stream, interpreting as time and date
        
        <iostream> (iostream.h) header, specifically handling the "Streams". Abstractions called streams are specially designed to perform input and output operations on sequences of character, like files or strings. Can be used to print to screen and receive text from keyboard
            cin (object) standard input strream



Calling Functions from libraries is done by calling members of a library with OPERATOR - SCOPE RESOLUTION :: 
Scope is where the function/variable is accessible in the code, so you're telling where to find the object (here, defined in library)
member::object
(see Enum Classes - :: is used to access the single 'enumeration' object.)

OPERATOR - MEMBER OF . (dot)
To access a member of an object

OPERATOR - MEMBER OF POINTER ->


OPERATOR - LEFT BOUND INSERTION << Data can be inserted into Object (instance of class) to their left using this. 

IOStream : contains input output functions, to print to screen and receive text from keyboard. https://cplusplus.com/reference/iostream/
Can call on special characters that are part of libraries. Ex: std::endl is a symbol to add the character for endLine

std::cout 
standardlibrary::standardOutputStream, or default destination of the environment (an output log, a dedicated text object, wtvr environ defined) 

std::cout<<"String" << "as many consecutive strings as you need" 

CODE TYPES SEEN BY THE COMPILER
    DECLARATIONS https://learn.microsoft.com/en-us/cpp/cpp/using-declaration?view=msvc-170
    Defining a word as a variable, function or other. 
    Declarations are always made at a specific scope (in a function, in a library, in a loop, etc.). That scope can be changed. Exiting a scope == variables deleted from memory.
        "using"
        To bring an identifier to another scope as if it was part of it. Can be used to make children function. Page above is super clear for calling function from class D, doing something, then calling the parent function.

    DIRECTIVES https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170#using_directives
        "using"
        To bring an identifier (function, var, object...) into scope so it can be
        1. Assigned to a variable (for shorter code?)

TOKENS
Smallest unit of any CPP program; they cannot be evaluated & simplified down.
    
Examples: 
Keywords: #include, int, if, return
    Reserved words
    Qualifiers : const, volatile...  Modifications to how the compiler handles variables and constructs
Identifiers: iostream, main, x, std, cout, endl
    Variable names, functions, classes... Start w/ letter or underscore. Only contains letters, digits, underscores.
Literals: 10, 5, "x is greater than 5"
    Constant values. 2+2 is NOT a literal, it is an expression, but 4 is.
Operators: +, =, >, <<
    Assignment?, Arithmetic, comparisons, logical operators
Punctuators: <, >, ;, {, }, (, )
    Code structure


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