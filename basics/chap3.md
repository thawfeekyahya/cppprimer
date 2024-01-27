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
