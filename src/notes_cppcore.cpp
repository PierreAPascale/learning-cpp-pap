/*
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

SYNTAX
Case-Sensitive
Indents ignored by converters, but readability ++
; at end of most lines, except library inclusions, } to end functions, ---- Does it mean "do this line of code"? Closing a function isn't taking an action...


HOW IT WORKS

Written code is Preprocessed, then Compiled.
Because this is done before compiling, anything set as part of these directives has no SCOPE. They never use ;

    INITIALIZER
        (could be after Preprocessor directives)
        Operates on some keywords like auto, to deduce the data type of the variable.

    PREPROCESSOR DIRECTIVES https://learn.microsoft.com/en-us/cpp/preprocessor/hash-line-directive-c-cpp?view=msvc-170
    # == directive
    Can be used at multiple places in the same code
    Software part of compiler tool chain : directives are information about what to remove/add in the code.
    Used for constants, libraries, selecting code blocks, ........
    #include (libraries) 
        Need more info : It inserts referenced file into the code, replacing the directive (#) line (#line). It replaces that single line with ALL of the specified file, so it can be used. A copy/paste of the entire thing into your file.
        <name>
            Not a path: will always look for file in a given location, ie. Environment variable that sets a default folder!
            Would otherwise need a path + file type (.h, .hpp)
            <iostream>, <string>, <stdint.h>
    #define MACRO_NAME (constants)*see further down
        defines a symbol to mean whatever you put to its right. They become MACROS. Often written with all caps.
        #define CAPACITY 5000 (no semicolumn, no = for assignment. It's not assigning, it's a preprocessor directive. It's not code.)

    #ifdef MACRONAME(select code block for different compile scenarios) "if defined", finishes with #endif
        Can be used for debug purposes. Code between these will only be run if the macro is defined in the code.
        Macro doesn't need a value if it's purely for an ifdev.


    
    #line digit-sequence ["filename"]
        Tells the compiler to use line number + (optional) filename from that point on. That number is always incremented per line (to let you find it)
        #line 20 
            tells the compiler that the next line is line20 if an error occurs there. Can request those 2 values using preprocessor macros:  __LINE__ and __FILE__ 

    CONSTANTS
        Useful as parameters in the code: size of screen, length of a memory buffer.
        Can be directives or variables.
        #define -> "find and replace" all of the instances of that symbol. AKA Macros
        Can be discouraged bc "Macros have no Context" + no compiler enforcement for basic features (type & syntax correctness)
        Better alternative: a qualifier for variables, const 
            In C: constants cannot be changed. In C++, that and macros
        Because variables enforce a type, syntax and scope, instead of preprocess.


    QUALIFIERS
        const

        
    COMPILATION

DECLARATIONS can be done anywhere in the code, not all at the beginning. Hurray for modernity.

OPERATOR OVERLOADING
Redefining the operation to support combinations of inputs.
+ operator : works for integers as addition, but for strings it means concatenation.

For a quotient (x/y), int (5/9) == 0, but if either is a float or double, the output will change. 
Expressions change their size automatically to the largest value present in them.
((float)5/9) will result in an expression of type Float, where (5/9.0) will result in an expression of type Double.
The output of the expression can constrain the output; (5/9.0) output in an Integer will result in 0, despite the expression resulting in 0.555555...


*/