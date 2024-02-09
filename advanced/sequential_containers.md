## Types of sequential containers

* array // Fixed size, Fast Random Access , Cannot add or remove elements
* vector // Flexible size, Fast Random Access , Fast Insert / Delete only at the back
* deque // Double ended queue , Supports Fast Random Access , Fast insert / delete either at front or back
* list // Doubly linked list, Bi-directional sequential access, Fast insert / delete at any point in the list
* forward_list // Singly linked list, Squential access only in one direction , Fast insert / Delete at any point in the list
* string // Specialized container for handling charcters, Fast random access, Fast insert / delete at the back


| Container    |     Fast Random Access | Bi-Directional | Fast Insert at back | Fast Insert at Front | Fast delete at back | Fast delete at front |
|:------------:|    :------------------:|:--------------:|:-------------------:|:--------------------:|:-------------------:|:--------------------:|
|  **array**       | !(images/check.png)|                |                     |                      |                     |                      |
|  **vector**      | !(images/check.png)|                |                     |                      |                     |                      |
| **deque**        | !(images/check.png)|                |                     |                      |                     |                      |
| **list**         | !(images/cross.png)|                |                     |                      |                     |                      |
| **forward_list** | !(images/cross.png)|                |                     |                      |                     |                      |
| **string**       | !(images/check.png)|                |                     |                      |                     |                      |
