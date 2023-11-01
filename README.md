# ft_containers

ft_containers is 42 project that involves the implementation of C++98 STL containers from scratch.

## Overview
This project aims to understand and reproduce templated classes that behave like C++98 STL containers. This includes all methods from the following containers:
``vector``, ``map``, ``set`` and ``stack`` and practical features.

## Installation

Clone the repository:

```shell
# Clone this repository
git clone https://github.com/bbordere/ft_containers42.git

# Go into the repository
cd ft_containers42
```

## Compile and Run
You simply have to run: 
```shell
make
```
This produces two executables that test the different containers.
One uses the STL containers and the other uses our custom containers.

To run the program: 
```shell
./ft_containers <container to test> # Custom containers version

# Or

./std_containers <container to test> # STL containers version
```
If no argument is provided, this tests all containers

## Containers Implemented
- ``vector``: Sequence container representing dynamic array
- ``map``: Associative container that stores the key / value combination
- ``stack``: Container adaptor designed to operate as LIFO structure (Last In First Out)
- ``set``: Container that stores unique elements following a specific order

## Features Implemented
- ``iterators_traits``: Type trait class that provides interfaces for LegacyIterator
- ``reverse_iterator``: Iterator adaptor that reverses the direction of a given iterator
- ``enable_if``: Use the SFINAE rule to a type
- ``is_integral``: Check if given type is an integral type
- ``equal``: Check if two ranges of iterator are equal
- ``lexicographical_compare``: Check if the first range is lexicographically less than the second
- ``pair``: Class template that provides a way to store two heterogeneous objects as a single unit
- ``make_pair``: Creates a ``pair`` object, deducing the target type from the types of arguments

