## Types of sequential containers

* array  // Fixed size, Fast Random Access , Cannot add or remove elements //  
>  [!NOTE] 
>  This is a STL array not built-in 
* vector // Flexible size, Fast Random Access , Fast Insert / Delete only at the back
* deque // Double ended queue , Supports Fast Random Access , Fast insert / delete either at front or back
* list // Doubly linked list, Bi-directional sequential access, Fast insert / delete at any point in the list
* forward_list // Singly linked list, Squential access only in one direction , Fast insert / Delete at any point in the list
* string // Specialized container for handling charcters, Fast random access, Fast insert / delete at the back


| Container    |Fast Random Access | Bi-Directional | Fast Insert at back | Fast Insert at Front | Fast delete at back | Fast delete at front | Insertion / deletion at any point  |
|:------------:|:------------------:|:--------------:|:-------------------:|:--------------------:|:-------------------:|:--------------------:| :------------------------------:|
|  **array**       |![](./images/check.png)|![](./images/check.png)|![](./images/cross.png)|![](./images/cross.png)|![](./images/cross.png)|![](./images/cross.png)|![](./images/cross.png)|
|  **vector**      |![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/cross.png)|![](./images/check.png)|![](./images/cross.png)|![](./images/check_w.png)|
| **deque**        |![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check_w.png)|
| **list**         |![](./images/cross.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|
| **forward_list** |![](./images/cross.png)|![](./images/cross.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|
| **string**       |![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|![](./images/check.png)|


## Container Operations

### Types
------------------------

* iterator
* reverse_iterator
* const_iterator
* const_reverse_iterator
* size_type
* difference_type
* value_type
* reference
* const_reference

### Obtaining Iteators
-----------------------

* begin()
* cbegin()
* end()
* cend()
* rbegin()
* rend()
* crbegin()
* crend()

###  Functions
------------------------

* insert()
* emplace()
* erase()
* clear()

### std::array vs built-in

Arrays cannot be copied while using built-in arrays in contrast to std arrays can be copied.

```
std::array<int,5> array1{1,2,3,4,5}
std::array<int,5> copy = array;
```

### Initialize from range of iterators

Containers can be initialized with the existing range of iterators from another container

```
vector<string> s1{"Hi","Hello","World","welcome","to","cpp","programming"};
vector<string>::iterator end = s1.begin()+5;
vector<string> s2(s1.begin(),end);
vector<string> s3(s1.begin(),s1.end());
```

### assign() 

Apart from arrays all sequential containers have a method named assign which is used to assign elements to the container either from existing another container's **iterator**  or assign a new list of values.

```
vector<strings> vec_str;
vector<char*> vec_char {"Hi","Hello"};

vec_str.assign(vec_char.begin(),vec_char.end()); // elements are assigned even both are different types and if able to covert to assigned type

//OR

vec_str.assign(10,"Hello"); //Assign 10 "Hello" to the vector
```

### swap()

Swaps elements between 2 containers. Elements themselves are not swapped rather its interal data structure is . swap is guranteed to be faster at  O(1) except **std::array**  .

```
vector<strings> vec1(10,"hi");
vector<strings> vec2(20,"hello");

swap(vec1,vec2);
```


### Add operation inside containers

|Operation   |push\_back| push\_front | emplace\_front | emplace\_back | insert | emplace| 
|:------------:|:------------------:|:--------------:|:-------------------:|:---------:|:---------:|:---------:|
|  **array**       | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/cross.png) |  
|  **vector**      | ![](./images/check.png) | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/check.png) | ![](./images/check_w.png) | ![](./images/check.png) |   
| **deque**        | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check_w.png) | ![](./images/check.png) |   
| **list**         | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/check.png) |  
| **forward_list** | ![](./images/cross.png) | ![](./images/check.png) | ![](./images/check.png) | ![](./images/cross.png) | ![](./images/check.png) | ![](./images/check.png) | 
| **string**       | ![](./images/check.png) | ![](./images/cross.png) | ![](./images/cross.png) | ![](./images/check.png) | ![](./images/check_w.png) | ![](./images/check.png) |

### insert()

The insert operation inserts an element before the inseration point (iterator).


