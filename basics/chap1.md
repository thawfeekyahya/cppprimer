## Program input & output using file redirection 
```
./program < input.txt > ouput.txt
```


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
