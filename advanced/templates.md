## Templates

Templates provides way to do generic programming in C++

### Function templates

Function templates allows to create generic function without dependent on the type

```

template <typename T>
int compare(const T& v1, const T& v2) {
if(v1 < v2) return -1;
if(v2 < v1) return 1;
return 0;
}

```

### Class template

Class template allows to create generic programming for class. its the blueprint for generating classes.

Usually templates are defined inside the header itself, the reason is ,  compiler needs to see both the declaration and definition of the template when instantiating it with specific types.

But can be defined outside the class as well.In this case, the cpp source file has to be included at the end of the header.

```
// classA.h
template<typename T>
class A {
    public:
        T getValue();
        void setValue(T val);
    private:
        T value;
};

#include classA.cpp //Include the implementation file, compiler needs to see the definition of templates in ordered to generate the required code.

// classA.cpp
template<typename T>
T A<T>::getValue() {
    return value;
}


// classA.cpp
template<typename T>
void A<T>::setValue(T val) {
    value = val;
}
```
