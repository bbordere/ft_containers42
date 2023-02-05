#include "ft_containers.hpp"
#include "test.hpp"
#include <bits/stdc++.h>

#ifndef NP
#define NP ft
#endif




template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> const &vec)
{
	if (vec.empty())
	{
		stream << "[]";
		return (stream);
	}
	stream << '[';
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end() - 1; it++)
		stream << *it << ", ";
	stream << *(vec.end() - 1) << ']';
	return (stream);	
}

int main(void)
{
	// takeTime();
	modifiersTest();
	capacityTest();
	iteratorTest();
	operationsTest();
	speed();
	setModifiersTest();
	setCapacityTest();
	setIteratorTest();
	setSpeed();



}
