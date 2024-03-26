## Copy Control Member

* Copy Constructor `T::T(const T&)`  // argument pass by reference 
* Copy Assignment Operator `T& T::=operator(const T&)`  // argument pass by reference // return type is pass by reference
* Move Construtor `T::T(const T&&) noexcept`  //argument pass by **rvalue-reference** // should not throw any exception
* Move Assignment Operator `T& T::=operator(const T&&) noexcept` // argument pass by **rvalue-reference** // return type is pass by reference // Should not throw any exceptions
* Destrcutor `~T::T()` 

> [!NOTE]
> The Destructor does not directly delete the members of the class . Members are deleted as part of impilicit destrcution phase. A destrction body executes in addition to memberwise destruction.

> [!CAUTION]
> Unlike copy assignment , Move assignment cannot assign to itself hence ` this != rhs ` is required before any operation on using move assignnment.

### delete keyword for copy constructor

When delete keyword is used in copy constructor or copy assignment then it implies those won't be generated / available for that class.

```
struct A {
	A(const A&) = delete; //no copy constructor
        A& operator=(const A&) = delete; //no copy assignment
}
```

> [!CAUTION]
> A destructor cannot not have delete keyword . If delete keyword is used in destructor that object never gets destroyed even when used in stack memory.

> [!WARNING]
> If a class has deleted the destructor `~classA()=delete` then the copy constructor and default constructor will be defined as deleted unless not provided by the user.  

### Copy Assignemnt 

While executing copy assignment its important to capture the data in way that it should work even if we are trying to copy the same object to itself. Or the code should have condition check to block assigning to value itself by using condition check ` this != rhs`

```
class ClassA() {
	public:
	ClassA::operator=(const ClassA& rhs);
	string* name; // Uses Heap / dynamic memory
	int i;
}

// correct way ------------------------

ClassA& ClassA::operator=(const ClassA& rhs) {
	 auto tempName = *rhs.name; // temporarily store the dynamic member's value
	 delete name;  // Delete the dynamic member
	 name = new string(*tempName); //Copy the temporary value to name
	 i = rhs.i;
	 return *this;
}

//wrong way ----------------------------


ClassA& ClassA::operator=(const ClassA& rhs) {
	 delete name;  // Delete the dynamic member
	 name = new string(*(rhs.name)); // ERROR! if we were to copy the same object, since this is trying to copy the deleted member
	 i = rhs.i;
	 return *this;
}
```

### Synthesized move control members

Compiler will **NOT** generate synthesized move operations if the class already defines copy assignement and copy constrcutor. In that case compiler will use copy constrcutor instead of move operations where ever applicable.

It will generate move operations only if copy operations were not defined.o


### std::move(object)

This utility function utilizes move constrcutor/ assignment to assign values .When using move on object, where move-is-from must be destructible. ie)  **User should NOT dependent on values from moved-from-object**. The value might be default initialized / or undefined behavior.



```
ClassA a;
ClassA b = std::move(a);

```


## Operator Overloading

A Class can overload all existing operators. But it cannot define new operators. For a binary operator the function takes 2 parameters. If the function is defined as member then the first parameter is implicitly points to `this` of the class and second parameter will bind to the second operand.

Since overloaded member functions takes the first argument to point itself. If we want to pass another class type then that function cannot be member function of the class 

```
ostream& operator<<(ostream& os, classA& a) // first member is not of the type classA // non-member operator overloaded function
```

operator overloaded can be called as like a normal function as well

```
class classA {
	classA operator+(classA& obj1,classA& obj2);
};


a.operator+(objA2) // this keyword is implicitly binded to the first argument (objA1)

a.operator+(objA1,objA2) // like normal function

objA1 + objA2; //normal expression

```

### Implementing -> and * operators

```

class A {
    public:
    
    int i;
    
    A() { cout<< "constrcutor called"<<endl; }
    A(const A& a) { cout<< "copy construtor called"<<endl; }
    A(const A&& a) { cout<< "move constrcutor called"<<endl; }
    
    A& operator*() { return *this; }
    
    A* operator->() { return &operator*(); }
    
};

ostream& operator<<(ostream& os, A& a) {
    os<< &(*a);
    return os;
}

A* a = new A();
a->i = 20;
cout<<a->i<<endl;

```

### Function call opeator ()

The function call operator `()` can be overloaded like other operators.

```
class A {
    int operator(int valueA) const {
       return valueA-20; // some expression
    }
}

int value = A(30); //passes 30 to () operator function 

```

### Library Defined Function Objects

The standard library defines set of operations which is equivalent to arthimetic , relational and logical operators

* Arthimetic
	* plus\<T\>
	* minus\<T\>
	* multiplies\<T\>
	* divides\<T\>
	* modulus\<T\>
	* negate\<T\>

* Relational 
	* equal_to\<T\>
	* not_equal_to\<T\>
	* greater\<T\>
	* greater_equal\<T\>
	* less\<T\>
	* less_equal\<T\>

* Logical 
	* logical_and\<T\>
	* logical_or\<T\>
	* logical_not\<T\>

### Function template in functional library.

STL defines a function template where we can assign functions to it.

```
#include <functional>

int testfun(int a, int b) {
    return a+b;
}

function<int(int,int)> f1 = testfun;

f1(); // will call testfunc
```


## Class Inhertiance

### Base class virtual destrcutor

Even though the base class destrcutor does nothing , classes intended for inheritance requries a virtual destrcutor on base classes.

### Private inheritance and `using` keyword

While using private inheritance all the public and protected memebers of the base class becomes private, to access public members of base class while inheriting via private inheritance `using` keyword can be used to access those members.

```
class A {
    
    public:
        int x = 1;
    private:
        int y = 3;
};

class B : private A {
    public:
        using A::x;
};
```

### Inheriting Constructor

We can inherit base class constrcutor by utlilizing the `using` keyword

```
class A {
    A(string name,string place);
};

class B : public A {
	using A::A; // Inherit A class's constructor
};
```
