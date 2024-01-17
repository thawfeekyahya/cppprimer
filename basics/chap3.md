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
