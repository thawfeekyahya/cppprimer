## String

Write a program to covert all letters to uppercase

```
#include <string>
#include <cctype>

std::string s = "hello world";

for(auto& c : s) {
	c = std::toupper(c);
}

```

## Iterators

begin() -> Initial element in the container

end() -> one past the last element in the container ie) it denotes non-existing element marking the end of the container. This is also called off-the-end iterator.

cbegin() -> same as begin() but added  constant to its type modifier
cend -> same as end() but added const to its type

size_type -> defines the data type of size() ie) vector::size() 

difference_type -> defines the data when 2 iterators are used to do arthimetic operatrations

```

std::vector<int> n;

auto mid_pos = n.begin() + n.size() / 2;

auto difference_pos = mid_pos - n.begin(); // difference_pos variable has a a type std::vector::difference_type

```

## Functions with varying parameters

useful to pass multiple parameters using the initializer list, ***NOTE*** to enclose the parameters with {}

### Initializer List

```
initializer_list<T> list;

initializer_list<string> str_list;

void error_msg(initializer_list<string> li) {
	for(auto beg = li.begin(); beg = li.end(); ++beg) {
		cout<<*beg<<endl;
	}
}

error_msg({"hello","world","welcome"})

```

## Function with return value as reference are ___lvalues___

```
char& get_val(string& str,string::size_type ix) {
return str[ix];
}

string name("thawfeek");
get_val(name,0) = 'T'; // turns first letter to capital

```


## Function to return empty vector

___{}___ braces along with return statement will retrun empty vector when return type of vector is expected

```

vector<string> getStrings() {
	return {};
}

```

## Funtion return statement

All function will have a return statement , for a function with void as return type an empty ***return*** will inserted by the compiler implicitly
For a function with return statement other than void ,the user must return a value with the exception to main function.


## Specialized Features

* assert , #include \<cassert\> => assert is a macro defined in \<casset\>  to assert a expression /  statement

```

#include <cassert>

int a=1,b=2;
assert(b<1); //This will fail

```

 * NDEBUG => NDEBUG (No-Debug) is a preprocessor variable. By default NDEBUG is not defined. Hence does runtime checks by defaults (assert). When this is varible is defined using #define. Then runtime checks are ignored.


## Specialized Debug parameters

For each function C++ defines some variables,

* \_\_func\_\_ => Prints the name of the function
* \_\_LINE\_\_ => Prints the line number
* \_\_FILE\_\_ => Prints the file name
* \_\_DATE\_\_ => Prints the date compiled
* \_\_TIME\_\_ => Prints the time compiled


## Function Matching for Overloaded function

When we use overloaded function there 3 steps involved by the compiler to determine the correct function to be called

* Candidate functions
* Viable functions
* Best Match
* Ambiguity

```
void f();
void f(int);
void f(int,int);
void f(double,double=2.63);

f(5.62);

```
In the above example the compiler during the __Candidate matching__ phase it ignores the 2 versions of  'f' function 

```
 void f();
 void f(int,int);
```
Since both of these doesn't match our signature ` f(5.62) `.

In the ***Viable*** functions phase it selects both

```
 void f(int,int);  // 5.62 can be converted to int type
 void f(double,double=2.63) // Since only first is mandatory, the compiler selects this as well
```

During the __Best Match phase__ the compiler selects `f(double,double=2.63)` since this the ideal match for function call `f(5.62)`


**Ambiguity** arises when 2 overloaded functions have parameters which can be converted either of the type.

consider the following

```
mainp(long);
mainp(float);

mainp(5.62); // This rises ambiguity 

```

### Function Pointer

Function pointer is a pointer to a function , the syntax is as follows

```

bool lengthCompare(const string&, const string&); // A function which returns bool type with 2 parameters of type string class 

bool (*pf)(const string&,const string&); // This creates a function pointer without the function name 

```

> [!NOTE] 
> the **(\*pf)** function pointer signatue **without** the function name

```
pf = lengthCompare

or

pf = &lenghtCompare   

pf(); // this will call lengthCompare function via the function pointer pf 

```
