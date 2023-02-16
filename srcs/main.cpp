#include "ft_containers.hpp"
#include "test.hpp"
#include <bits/stdc++.h>

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
	stream << ", size: " << vec.size() << ", capacity: " << vec.capacity();
	return (stream);
}

void	vectorTests(void)
{
	insertVectorTest();
	accessVectorTest();
	iteratorVectorTest();
	capacitySwapVectorTest();
	compVectorTest();
	speedVectorTest();
}

void	setTests(void)
{
	setModifiersTest();
	setCapacityTest();
	setIteratorTest();
	setSpeed();
}

void	mapTests(void)
{
	mapModifiersTest();
	mapCapacityTest();
	mapIteratorTest();
	mapOperationsTest();
	mapSpeed();
}

int main(void)
{
	#ifndef NP
		std::string const npName = "ft";
		#define NP ft
	#else
		std::string const npName = "std";
	#endif
	clock_t	start, end;
	start = clock();
	vectorTests();
	end = clock();
	double timeVector = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	setTests();
	end = clock();
	double timeSet = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	mapTests();
	end = clock();
	double timeMap = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << npName << "::vector routine takes " << timeVector * 1000 << " ms" << '\n';
	std::cout << npName << "::set routine takes " << timeSet * 1000 << " ms" << '\n';
	std::cout << npName << "::map routine takes " << timeMap * 1000 << " ms" << '\n';
}
