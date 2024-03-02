## Smart Pointers

C++ Provides of 3 types of smart pointers

* unique_ptr // gets deleted when the object goes out of scope
* shared_ptr // uses reference couting mechanism . gets deleted when cout becomes 0.
* weak_ptr // should be used along side with shared_ptr


### make_shared

make_shared is used to create a shared pointer.

```
shared_ptr<int> iptr = make_shared<int>(5);
```

### shared_ptr.get()

The get method in shared_ptr class has to be used with **caution** . It is meant to be used on legacy code or there is no other way to pass the shared_ptr except the explicit pointer. 

* Do not use the get method to initialize another shared_ptr
* Do not use the get method along with reset function of shared_ptr
* Do not use get with delete operator to delete the underlying ptr object.

### shared_ptr.reset(q)

Resets frees the ptr reference which pointer is holding.

```
    shared_ptr<int> iptr = make_shared<int>(5);
    shared_ptr<int> iptr2 = iptr;
    shared_ptr<int> iptr3 = iptr;
    cout<<iptr3.use_count()<<endl; //output : 3

    iptr3.reset());
    cout<<iptr3.use_count()<<endl; //ouput : 0
---
    iptr3.reset(new int(30)); 
    cout<<iptr3.use_count()<<endl; //output: 1

```

### shared_ptr(T,deleter)

In the constructor version of shared_ptr, it is possible to provide a custom deleter function. If the reference count reaches zero, rather than utilizing the delete operator on the stored pointer, it will invoke the specified custom deleter function.

NOTE: custom deleter is **NOT** supported with `make_shared` function.
```
void deleter(int* iptr) {
    cout<<"Pointer is about to be deleted";
    delete iptr;
}
shared_ptr<int> iptr4(new int(3),(*deleter));
```

### unique_ptr 

Unlike shared_ptr unique_ptr does **NOT** have function like `make_unique` instead we need to use regular `new` operator to initialize unique ptr

```
unique_ptr<int> iuniq(new int(2));
```

Since there can be only one copy of unique pointer attempting to store unique pointer in another pointer throws error.

```
unique_ptr<int> iuniq(new int(5));
unique_ptr<int> iuniq2 = iuniq; // throws ERROR!
```

### unique_ptr.release()

Although unique pointers cannot be copied it can transfer the ownership of the object it holds.

NOTE: calling release() without **capturing** will cause memory leak. `uniq.ptr.release()` . The right way to do this to capture in another pointer or using a varible and later delete it.

```
unique_ptr<int> iuniq(new int(20));
unique_ptr<int> iuniq2(iuniq.release());

iuniq.release(); // ERROR, reference to the pointer lost.
auto p = iuniq.release(); // capture the pointer
delete p; // delte the captured pointer.
```

### weak_ptr

weak ptr is meant to be used along side with shared_ptr. While using the weak ptr it does not increases the reference count and can be deleted if the parent shared_ptr reference ptr goes to zero.

```
shared_ptr<int> iptr = make_shared<int>(5);
weak_ptr<int> wiptr = iptr;  // reference count does not increase
```

### weake_ptr.lock()

Since a pointer which weak_ptr is referring to can be deleted at any time, we cannot directly use weak_ptr to access the pointer which it is pointing , we need to use lock() function to access the pointer.

```
shared_ptr<int> iptr = make_shared<int>(5);
weak_ptr<int> iwptr = iptr;

//To access the pointer inside weak pointer

shared_ptr<int> toUse = iwptr.lock();  // this will increase the reference count
```

### allocator

Allocator allows to allocate memory for the give type without calling the contructor. It allocates raw memory.

```
    allocator<int> alloc;
    auto p = alloc.allocate(5);
    auto q = p;
    alloc.construct(q++,1);
    alloc.construct(q++,2);
    alloc.construct(q++,3);
    alloc.construct(q++,4);
    cout<<*(p+2); //output: 3
```
