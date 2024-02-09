
## IO Headers

\<iostream\> -> header for handling streams

* fstream [class] -> Read / Write files
* ofstream [class] -> Write files
* ifstream [class] -> Read files
* istringstream [class] -> Read  string buffers
* ostringstream [class] -> Write string buffers
* stringstream  [class] -> Read / Write string  buffers 


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

## IO State

IO library defines states which inidcates the condition of the stream

* strm::iostate //intergal type represents the condition of the state
* strm::badbit  // stream is corrupted
* strm::failbit // IO Operation failed
* strm::goodbit // Not in error state
* strm::eofbit  // stream is at the end of the file

Corresponding functions to check

* obj.eof() // is end of file
* obj.fail() // if fail or bad bit is set for obj
* obj.good() // true if is in good state
* obj.clear() // reset state
* obj.clear(flags) // reset the condition of flags of type strm::iostate
* obj.setstate(flags) // Add flag to obj

## File Modes

* in -> Open for input // Applicable only for ofstream or fstream
* out -> Open for ouput // write // Applicable only for ofstream or fstream
* app -> Seek to end before write
* ate -> Seek to end immediately after open
* trucn -> truncate the file 
* binary -> Do IO operation in binary mode

By Default file is opened in trunc mode when output is set.

```
ofstream out;
out.open("file.txt",ofstream::app);
```


## String Steams

Similar to file streams , string stream helps to deal with string buffers

* istringstream // Read string streams
* ostringstream // Write string streams
* stringstreams // Read / Write String streams

**Read using string stream**

```

istringstream in("1 2 3 4 ");
    int total,temp;
    
    while(in>>temp) {
        cout<<total;
        total += temp;
    }
    
    std::cout<<"Total "<<total;

```

**Write using string streams**

```
ostringstream out;
    string temp;
    
    while(cin>>temp) {
        out << temp << " ";
    }
    
    std::cout<<"Details "<<out.str();

```

