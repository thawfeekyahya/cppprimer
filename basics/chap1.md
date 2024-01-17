## Program input & output using file redirection 
```
./program < input.txt > ouput.txt
```

## Type Literals Prefix / Suffix

Type literals make the coding intentions clear

***Prefix***
0x -> Indicates Hexadecimal ex) 0x000010 // 16 in decimal
0  -> Indicates Octal ex) 0020 // 16 in decimal

***Suffix***

U/u -> Indicates Unsigned int type
L/l -> Indicates Long int type
F/f -> Indicates Float type


## Narrowed type conversion !
```
bool b = 42;            // b is true
int i = b;              // i has value 1
i = 3.14;               // i has value 3
double pi = i;          // pi has value 3.0
unsigned char c = -1;   // assuming 8-bit chars, c has value 255
signed char c2 = 256;   // assuming 8-bit chars, the value of c2 is undefined
```

## Alternative Operators in C++

* and -> &&
* or  -> ||
* not -> !

Bitwise Alternate Operators

* bit_and -> bitwise AND (&)
* bit_or  -> bitwise OR  (|)
* xor     -> Exlusive OR (^) 
* or_eq   -> |=
* and_eq  -> &=
* xor_eq  -> ^=

## Identifiers rules in C++

* The identifiers we define in our own programs may not contain two consecutive underscores, nor can an identifier begin with an underscore followed immediately by
an uppercase letter

* identifiers defined outside a function may not begin with an underscore.

## Void Pointers (void* p)

void pointer is a special pointer which can hold pointer of any type. But it cannot address the pointer object stored in it.Genarally void pointer is used to deal with memory as it is (memory).

```

int i=5, *ip = &i;  // creates integer i and interger pointer ip and assigns the address of i to ip
void* pv = &i;  // creates a void pointer pv and assigns the address of i 
pv = ip; // now pv (void pointer) is give new object (ip) to refer ie) assigned to ip pointer which in turn points to i 

```


## const keyword

To substitute the value for the variable, the compiler has to see the variable’s initializer. When we split a program into multiple files, every file that uses th const must have access to its initializer. In order to see the initializer, the variable must be defined in every file that wants to use the variable’s value . To support this usage, yet avoid multiple definitions of the same variable, const variables are defined as local to the file

***constexpr cannot be used as pointer to point object variables which are defined inside the function***


## Top-level & Low-level constants

The term top level and low level points to variants of constant, The primary object which the variable points to is called top level, while the data type constant is said to be low level

```
const int const_int = 3;
const int* const ptr = &const_int;
```
> right most is called top level ,since that is object type (const pointer)  and the left most is low level (const int data type) where it says about the data which const_int is holding

```
int i = 5;
const int* a = &i; //  Here the pointeer variable 'a' can piont to different address ie) a = &j; but it cannot the change its value ie) *a = 10; this will error since it is declared as constant

int* const a = &i; // Here pointer variable 'a' cannot point to another address other than 'i' since it is declared as const , but this can change its value by dereferncing it ie) *a = 20; 
```

## Abbreivated unsigned

The keyword 'unsigned' without specifying data type by default points to ***unsigned int***

## decltype type deducer

'decltype' will deduce the type from a funciton or a variable which can then assigned to variable declaration

```
const int ci = 0;
decltype(ci) x = 0; // x will have , [ const int ] as its type deduced from ci

```


# String Manipulation

* cctype has string manipulation function, 


# String Manipulation

  Any include directive which starts with c , is inherited from C library and modified to be used with C++. example) #include \<cctype\> the same is defined in C as #include "ctype.h" 

* cctype has string manipulation function.
