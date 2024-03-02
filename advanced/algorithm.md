## Overview

Algorithms are versatile operations that can be employed across various container types. Instead of tailoring these algorithms for specific containers, they are defined in a universal library **\<algorithm\>**. Additionally, numeric algorithms are outlined in the **\<numeric\>** header.

In general, the syntax of algorithmic functions involves three parameters: the starting range, the end range, and the initial value.

Also there are different variants of alogrithms, Algorithms which operate on 2 sequence or  Alogorithms which operate on single iterator.

```
vector<int> ivec(20);
accumulate(ivec.begin(),ivec.end(),0); // fill the container with integer values incremented by ++1 and starting with 0

equal(ivec.begin(),ivec.end(),ivec2.begin()); // compare each element between the containers. // Note: ivec2 assumes the length to be same as ivec

```

> [!NOTE] 
> Alogrithms uses functional programming style (f(x)), ie) functions are independent of containers.


### Predicates

A predicate is an expression that can be supplied as an additional parameter to algorithmic functions. In such cases, the algorithm is executed only if the specified condition evaluates to true.

### Lambda

Anonmyous function in C++ is called Lambda expression. The syntax is as follows

`[caputre-list](param1,param2)->returnType { //body of function;}`  here parameter list and return types are optional and can be omitted.but capture list is mandatory. So the syntax can be shorten to `[capture-list] { //body of the function }`. 

the capture list is used to capture only non-static variables. static variables can be directly accessed inside lambda without passing to capture list.

```
vector<int> ivec(20);
iota(ivec.begin(),ivec.end(),0);
for_each(ivec.begin(),ivec.end(),[](const int& val){  cout<<val; }); // Lambda expression is passed to the predicate. Function prints the value in the container.
```

### Lambda capture list

* [] -> Empty capture list

* [value1,value2] -> value1 and value2 is from the function body where the lambda is defined and these varibles are **copied** to lambda function. To pass this variable by reference to lambda function use `&` infront of the variable `&value1,&value2`, with this now the varibles are passed to lambda function as reference.

* [&] -> All variables from the function body where the lambda is defined is passed by reference.

* [&,identifier_list] -> All varibles from the function body where the lambda is defined is passed by reference. variables which are additionally passed will be of `pass by value` and must **NOT** include `&`

* [=] -> All variables from the function body where the lambda is defined is passed by value.

* [=,reference_list] -> All values from the function body where the lambda is defined is passed as value. variables  which are additionally passed are `pass by reference` and must **NOT** include `this` keyword.


#### Mutable Lambdas

By default when we use `pass by value` in a lambda capture list , the variables are ready-only. To change the variables to write mode using `pass by value` we to declare the lambda as mutable


```
[=]() mutable  { x = x+5; return x; } // Note mutable keyword here // variable x is from the function scope where lambda is defined.
```


### bind()

bind is a utility function which is defined in `\<funtional\>`  header . bind() function bind one function to another

```
#include <functional>

using namespace std;
using namespace std::placeholders;

void check(string first,string second,int value) {
    cout<<first<<endl;
    cout<<second<<endl;
    cout<<value<<endl;
}

int main()
{
   auto checkable = bind(check,_1,_2,10);
   checkable("Thawfeek","Yahya");
   return 0;
}
```

### ref(object)

Returns a copyable reference object to given parameter. Useful in bind functions when parameters are required to passed as reference.

```
ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

for_each(words.begin(), words.end(),
bind(print, ref(os), _1, ' '));
```

### iostream_iterators

* istream_itreator
* ostream_iterator

```
vector<int> ivec;
istream_iterator<int> istream_iter(cin);
istream_iterator<int> end_iter; // dummy iterator to compare for end

while(istrem_iter != end_iter) {
ivec.push_back(*istream_iter++); // push the scanned value and increment the iterator
}
```


### Iterator types

There are four categories of iterator.

* input iterator
* output iterator
* forward iterator
* bi-directional iterator
* random access iterator
