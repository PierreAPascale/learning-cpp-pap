/*
COMMON DATA TYPE LIBRARIES
    STRING STANDARD LIBRARY
    #include <string>


stdint.h header file from the C library, <cstdint>
In C, not C++!
However, some were popular, so made into C++. Name had a c added as prefix.
uint32_t
int16_t
U = unsigned, int = integer, number = bit size, _t = type\

VARIABLES
Temporary data storage units. Must be declared prior to usage.
Declaration can contain initialization

varType varName;
Can use types defined in libraries, std::string (check "std" for token "string")

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
    Arrays of characters (char type), terminated with value 0 (null character)
    std library has it as a Class: <string> header includes the class and functions to manipulate the Class/data.
    <cstring> : header from the C library with functions to manipulate strings.

    String class should be used instead of character arrays... but if code NEEDS to be compatible w/ C, then we can use character arrays and import the <cstring> library to get the functions to achieve the same results as the C++ <string> header offers for its string class.


    POINTERS
        Data type for memory addresses. System architecture (32bit, 64bit, 96bit) dictates maximum memory size of the pointer, ie. the full precision that data could ever be located at. Pointers will use X Bytes, depending on what they need to contain.
    Memory Map:
    Location (address), Unit (content)
    1 address per byte.
    32bit data (ex: int32)  == Each unit is 4 bytes

    May act as references to variables.
    Pointers have a type: int&, float&, string&...
    Can be used to access multiple different variables sequentially.
    
    Can also be VOID or NULL to point to any function or object requiring these.

    Nullptr = a pointer of type nullptr_t (distinct type that is neither pointer nor member type). Defined in header <cstddef>, std::nullptr_t

        Symbols:
        dataType *ptrname;  (* == Indirection operator; "consider this an indirection")
        ptrname = &a; (& == Address Of)
        "ptrname points to a" (colloquial)

        *ptrName will return whatever is contained at the "pointed" address, in this ex., the value of a.

    Addresses will look like "0x7fffffffffde40"
        MAIN USE OF POINTERS : DYNAMIC MEMORY MANAGEMENT
        Allocation of memory (malloc functions) to create and remove data at runtime, instead of strictly at executable startup
        Called by constructors.

        ex: When creating an instance of class cow: 
            cow *my_cow;
            my_cow = new cow(constructor args);
        
        Q: Why is a pointer required here? 
        A: Because the variable is not at a static location on disk; it's somewhere dynamic. We can't ask program to predict it, and we do not want to reserve it.
        So we ask the program to create an address of type cow, then we tell program "create a new instance of what follows at this address".
        
        To use pointed data, *ptrName. 
        To access members of a class, basic way is: (*ptrName) to prioritize dereferencing the pointer in the sequence of operations.
        However, messy if trees and lists... Dedicated OPERATOR - MEMBER OF POINTER ->
        DESTRUCTOR
            delete varName;
            This keyword calls the destructor function of a class and removes it from memory.
        SMART POINTERS
        To prevent "dangling pointers" and memory leaks.

    REFERENCES
    type& name = memberToReference        
    Simple rewiring of tokens
        Not Pointers, nor objects, nor address (no array of ref bc no address)
        Always initialized (guarantee of finding data)
        1 Ref = Alias to a single object (at declaration)
        Single level of indirection, ever.

        USAGE OF REFERENCES:
        Passing parameters by ref (instead of by value)
            Allows modifying the argument variable directly within the function
        Avoiding Copies. Function parameters are typically copied. If large object, you do not want to unnecessarily copy it. 
        Optimizing ForLoops by avoiding copies each iteration.
            A form of for loop uses variable to iterate through a container. This variable MAY require copy each iteration.

    STL VECTORS (instead of ARRAYS)
    Dynamic Size
    Memory-managed (unless objects within vector are manually allocated)
    Template - Generic container class (can implement for any type of element)
        Member functions to manipulate them
        Part of C++ STD library (generic programming style?)
        Iterators can be used (container): vectorName.begin() // iterator to the first element. .end() last element+1. Can do (instance.end()-1)->memberFunctionName, or prev(iterator, positionsToMoveBack
        Template<type>    
    Consecutive in Memory: Can only add items from the back end (furthest)
        Indexed beginning at 0 : instance[2] returns the third element.
        
    Vector Header:
        std::vector<type> vectorName;
        vectorName.push_back() // To insert elements.
        vectorName[index] = value // To set elements.

ITERATORS
    Used to traverse containers.
    Work like pointers (addresses); use the same Operators, such as ->

TYPE CASTING
    Specify how to interpret data. 
    Ex: int & float are very different in their binary encoding.

    Implicit Conversion
        float VarName = 25.3; //type is defined as Float, but expression says Double (25.3f would be float). It is implicitly converted to a Float.
        int VarName = floatExpression // converts from 25.3 float to 25 int 
        uint32_t = int32_t expression // converts from unsigned to signed, copying binary value as-is but interpreting it differently (wrapping around to show the complement value; -7 converted to 4294967289. Most significant bit = 1, AKA huge number.


    Explicit (Casting) Conversion: explicitly specifying the data type of an expression, so that the compiler interprets it as such.
        Syntax: (desiredType) expression // Expression that evaluates to value you want to convert
        uint32_t uint32_number= -7; // stores binary value as complement of -7, AKA 4294967289
        (int32_t) uint32_number // this expression will result in the expected -7 if printed, unlike Implicit conversion. This is because it took the binary value but interpreted it differently, as an unsigned int.


    Important: "Constant Expressions"
    (5/9) // This expression doesn't make it to the code (which is then executed by the processor).
    Why? Because it can be evaluated when compiled. 

    From Copilot:
        This can be compiled:
        const int cn = 2;
        std::array<int, cn> a2; // OK: cn is a constant expression

        This can not, and would result in an error:
        int n = 1;
        std::array<int, n> a1; 

        const, or constexpr keywords, both enforce the value cannot be changed at runtime.


Struct
Extern

COLLECTIONS
    ARRAYS
    Collections of data, all of the same type (as opposed to structs?). Fixed Size.
    Indexed from 0 to N-1 (N = capacity of array)
    Contiguous in memory: next to each other, creating a sequential block of memory addresses
    Declaration only:
        varType arrayName[arrayCapacity];
    Declaration and Initialization:
        varType arrayName[] = {expression1, expression2, expression3};
        CANNOT use auto.
    Access (read/write)
        arrayName[itemIndex]
        arrayName[itemIndex] = expression;

    ENUMERATIONS
    List of identifiers (enumerators) that are integers.
        In C, operate in global scope... aka naming conflicts
        Limited type safety
    In C++ 11, Enum Classes (scoped enums, strongly typed enums). Encapsulation == OOP!
    Type Safety to prevent conversion between enum and int

    Non-Scoped Enums example:

    enum varName {data0, data1, data2};
    int main(){
        int a;
        a = data1; //printing this will print 1, the corresponding enumerator of the enumeration)


        int a;
        int data1 = 5; //creating a local variable in scope of main.
        a = data1; //printing this will print 5, the corresponding enumerator of the enumeration)
    }
    int c;
    c = data1; //printing this will print 1, because the value 5 was only true as part of Main. Because a is a local variable in main, main would output it first. :: could be used to define the scope and get main's value... but still a problem. data0, data1, etc. are names which do not have a scope, as they're outside all functions. Reusing the name will cause an error: redefining the same names with potentially different values. What would the program output? This is compiled, not interpreted, so it doesn't simply take the last one.

    Class Enums (scoped, strongly typed): <cstdint>?
    enum class enumName{data0, data1, data2}; //because this is now a class, the values are in the scope of that class. No need for "" for strings; they are simply tokens that can be interpreted as integers. Doing so returns the index in the enumeration, AKA the enumerator
    int main(){
        int a;
        // a = enumName::data1 (writing it like this will be an error if data1 isn't an int; that's expected (strongly typed))
        a = (int) enumName::data1 // casting as an integer

        // the alternative, preferable:
        enumName a; // this makes a variable of type enumName. It will contain 
        a = enumName::data1 // No type mismatch. To print it, we would need to cast it as another value: (int)a. It will return 1, the enumerator.
    }
    

CONSTANTS
    MACROS [Typically Do Not Use]
    macros or constant variables can achieve the same objective. Prefer const variables, as they have a scope.
    #define MACRO_NAME = 4;

        Useful as parameters in the code: size of screen, length of a memory buffer.
        Can be directives or variables.
        #define "find and replace" all of the instances of that symbol. AKA MACROS
        Can be discouraged bc "Macros have no Context" + no compiler enforcement for basic features (type & syntax correctness)
        Better alternative: a qualifier for variables, const 
            In C: constants cannot be changed. In C++, that and macros
        Because variables enforce a type, syntax and scope, instead of the preprocess, which is "out of the code".


    QUALIFIERS
        const size_t varName = 4; // this type of variable is specifically for array sizes. (size_type)

    Enforces a compile behavior for an Object's member.
        const
            Throws compile errors if member is changed + optimizes the member (immutability).
            Nothing in a const function can changed, unless it's using a mutable member... see mutable below
        volatile
            code is not optimized for these vars/structs/unions, by preventing caching in registers + removing seemingly redundant addresses (pointers?)
        mutable 
            Forces member of a class (even a Const one) to be mutable (can be changed).
            EX: This allows you to make some functions const while using mutable variables within.


DECLARATIONS can be done anywhere in the code, not all at the beginning. Hurray for modernity.

OPERATOR OVERLOADING
Redefining the operation to support combinations of inputs.
+ operator : works for integers as addition, but for strings it means concatenation.

For a quotient (x/y), int (5/9) == 0, but if either is a float or double, the output will change. 
Expressions change their size automatically to the largest value present in them.
((float)5/9) will result in an expression of type Float, where (5/9.0) will result in an expression of type Double.
The output of the expression can constrain the output; (5/9.0) output in an Integer will result in 0, despite the expression resulting in 0.555555...

    To declare an overload: declare multiple functions with:
    Same Name
    Different Parameters (dissociation based on params/arguments type or number)
    Same Scope (class or namespace, otherwise both can exist and be called manually with different scope resolution ::


ASSIGNMENTS
Line of code that assigns value to a variable.
Left hand must be able to hold a value, right-hand side is an expression.
Expression data types must match (not enforced by compiler)

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

ORIENTATION
    NARROW / WIDE
    Character Types:
    Narrow characters
    A narrow character may not be able to represent all characters. Multiple narrow characters can be combined to form a multibyte character, which is a single logical character.
    Wide characters
    Wide characters can represent any character in a supported character set. Wide character literals start with the L prefix.

    Wide character types
    Some wide character types include:
    wchar_t: An implementation-defined wide character type. In the Microsoft compiler, wchar_t is a 16-bit wide character that stores Unicode encoded as UTF-16LE. 
    char8_t: An 8-bit wide character type that can store Unicode encoded as UTF-8. 
    char16_t: A 16-bit wide character type that can store Unicode encoded as UTF-16. 
    char32_t: A 32-bit wide character type that can store Unicode encoded as UTF-32. 
    Wide character string manipulation functions
    C++ provides functions for manipulating wide character strings, such as wcslen, wcscmp, wcsncpy, and wcstok.

*/