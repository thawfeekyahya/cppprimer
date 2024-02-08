## Wide charcter 

To support wide charcters , the library defines set of objects and types to manipulate whcar_t . The names of wide charcters begin with w, For Example:

* wcin
* wcout 
* wcerr

## Copy and Assignement of IO Objects

IO Objects does not support copy or assignment operators

```
ofstream stream1,stream2;
stream2 = stream1; // Error: not possible with IO Objects
```

## Output Buffers

Each output stream manages a buffer which holds the data of the program reads and writes. Using a buffer allows a program to store several output operations of program to a single system-level write, this provides a significant preformance boost.

**Flushing buffers**

* endl // adds a new line and flushes the buffer
* flush // Simply flushes the buffer adds no extra charcters
* ends // adds a null then flushes the buffer
