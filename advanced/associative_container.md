## Associative container

There are 2 kinds of primary associative contianers

* map 
* set

The STL provides 8 different types of associative containers from the 2 base variants

1. map
2. set
3. multimap // Allows multiple keys of same name
4. multiset // Allows multiple keys of same name
5. unordered_map // Uses hash to order
6. unordered_set // Uses has to order
7. unordered_multimap // Multi-keys with hash
8. unordered_multiset // Multi-keys with hash


### map(key,value)

map takes a key and a value.

```
#include <map>

    map<string,uint> word_count; //declare a map string as key and int as value
    string word;
    while(cin>>word) {
        ++word_count[word]; // increment the count , if the input is "Hi" given twice then word_count["Hi"] would return 0 for the first time and the second time it incrments the count
    }
    
    for(auto& key_map : word_count) {  loop through all the key value pairs in the given map
        cout<<key_map.first<<" occurs "<<key_map.second<<endl; //map.first would return the key , map.second would return the value
    }

```

### set(key){values}


A set a has a group of values for a key.

```
#include <set>
#include <sstream>

set<string> filter {"C++","Programming","beauty"};
string input;
ostringstream output;

while(cin>>input) {
	if(filter.find(input) == filter.end())  output<<input;
}

cout<<output.str();
```
`input: Welcome to C++ Programming Language beauty`
`output: Welcome to Language`


### pair(first,second)

A pair is a utility class which can make two variables as a pair. pair is defined in \<parir\> header. A pair can be also created by the utility function `make_pair(value1,value2)`

In map the internal values (key,values) are stored in pairs.
```
pair<string,name> mypair;
pair<string, vector<int>> mypair2;

cout<<pair.first;
cout<<pair.second;
```
### Associative container type aliases

* **key_type** Type of the key 
* **mapped_type** Type of the value // Applicable for **maps** only
* **value_type** //for sets same as key_type //for maps pair\<key_type,mapped_type\>


### Unordered map & Unordered set

 The unordered map and unordered set employ a hashing mechanism to store data, with the data itself residing in buckets. Consider the following example where we have a set of data:

 (1.2, 8.0, 1.7, 2.5, 5.2, 6.2, 3.0, 8.7, 2.5, 11.7, 10.7). 

The values are hashed and stored accordingly. The advantage is that instead of searching the entire dataset, the container can search only the specific bucket where the hashed value of the key matches.

```
    0            1            2        3     
                                             
│  1.2    │  │  8.0    │ │ 1.7    │ │  2.5  │
│  5.2    │  │  3.0    │ │ 8.7    │ │       │
│  6.2    │  │         │ │ 11.7   │ │       │
│         │  │         │ │ 10.7   │ │       │
│         │  │         │ │        │ │       │
│         │  │         │ │        │ │       │
└────┬────┘  └─────┬───┘ └────┬───┘ └───┬───┘
     │             │          │         │    
     │             │          │         │    
     │             │          │         │    
     │             │          │         │    
     └─────────────┴───┬──────┴─────────┘    
                       │                     
                       │                     
                   Buckets                   
```
