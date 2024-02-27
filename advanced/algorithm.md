## Overview

Algorithms are versatile operations that can be employed across various container types. Instead of tailoring these algorithms for specific containers, they are defined in a universal library **\<algorithm\>**. Additionally, numeric algorithms are outlined in the **\<numeric\>** header.

In general, the syntax of algorithmic functions involves three parameters: the starting range, the end range, and the initial value.

Also there are different variants of alogrithms, Algorithms which operate on 2 sequence or  Alogorithms which operate on single iterator.

```
vector<int> ivec(20);
accumulate(ivec.begin(),ivec.end(),0); // fill the container with integer values incremented by ++1 and starting with 0

equal(ivec.begin(),ivec.end(),ivec2.begin()); // compare each element between the containers. // Note: ivec2 assumes the length to be same as ivec

```

> [!NOTE] Alogrithms uses functional programming style (f(x)), ie) functions are independent of containers.


### Predicates

A predicate is an expression that can be supplied as an additional parameter to algorithmic functions. In such cases, the algorithm is executed only if the specified condition evaluates to true.

### Lambda

Anonmyous function in C++ is called Lambda expression. The syntax is as follows

`[caputre-list](param1,param2)->returnType { //body of function;}`  here parameter list and return types are optional and cab be omitted.but capture list is mandatory. So the syntax can be shorten to `[capture-list] { //body of the function }`. 

the capture list is used to capture only non-static variables. static variables can be directly accessed inside lambda without passing to capture list.`

```
vector<int> ivec(20);
iota(ivec.begin(),ivec.end(),0);
for_each(ivec.begin(),ivec.end(),[](const int& val){  cout<<val; }); // Lambda expression is passed to the predicate. Function prints the value in the container.
```
