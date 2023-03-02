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

void	vectorTests(bool checkLeak)
{
	insertVectorTest();
	accessVectorTest();
	iteratorVectorTest();
	capacitySwapVectorTest();
	compVectorTest();
	if (!checkLeak)
		speedVectorTest();
}

void	setTests(bool checkLeak)
{
	setModifiersTest();
	setCapacityTest();
	setIteratorTest();
	if (!checkLeak)
		setSpeed();
}

void	mapTests(bool checkLeak)
{
	mapModifiersTest();
	mapCapacityTest();
	mapIteratorTest();
	mapOperationsTest();
	if (!checkLeak)
		mapSpeed();
}

void	stackTests(bool checkLeak)
{
	pushStackTest();
	constructorStackTest();
	constructor2StackTest();
	compStackTest();
	if (!checkLeak)
		speedStackTest();
}

#include "RBTreePrinter.hpp"

int main(int ac, char **av)
{
	#ifndef NP
		std::string const npName = "ft";
		#define NP ft
	#else
		std::string const npName = "std";
	#endif
// 
	std::string containers;
	for (int i = 1; i < ac - 1; ++i)
		containers += std::string(av[i]) + std::string(", ");
	if (ac != 1)
		containers += std::string(av[ac - 1]);
	for (std::size_t i = 0; i < containers.length(); ++i)
		containers[i] = std::tolower(containers[i]);
// 
	double timeVector = -1.0;
	double timeSet = -1.0;
	double timeMap = -1.0;
	double timeStack = -1.0;
	clock_t	start, end;
// 
	bool	checkLeak = containers.find("leak") != std::string::npos;
	bool	testAll = containers.empty() || containers == "leak";
	if (testAll || containers.find("vector") != std::string::npos)
	{
		start = clock();
		vectorTests(checkLeak);
		end = clock();
		timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	}
// 
	if (testAll || containers.find("map") != std::string::npos)
	{
		start = clock();
		mapTests(checkLeak);
		end = clock();
		timeMap = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	}
// 
	if (testAll || containers.find("stack") != std::string::npos)
	{
		start = clock();
		stackTests(checkLeak);
		end = clock();
		timeStack = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	}
// 
	if (testAll || containers.find("set") != std::string::npos)
	{
		start = clock();
		setTests(checkLeak);
		end = clock();
		timeSet = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	}
// 
	if (timeVector != -1.0)
		std::cout << npName << "::vector routine takes " << timeVector * 1000 << " ms" << '\n';
	if (timeSet != -1.0)
		std::cout << npName << "::set routine takes " << timeSet * 1000 << " ms" << '\n';
	if (timeMap != -1.0)
		std::cout << npName << "::map routine takes " << timeMap * 1000 << " ms" << '\n';
	if (timeStack != -1.0)
		std::cout << npName << "::stack routine takes " << timeStack * 1000 << " ms" << '\n';


// (void)ac;
// (void)av;
// 	ft::vector<int> vec(5, 100);
// 	vec.reserve(521);
// 	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	// std::cout << vec << '\n';
// 	vec.insert(vec.begin(), arr, arr+10);
// 	vec.insert(vec.begin(), vec.begin(), vec.end());
// 	std::cout << vec << '\n';
// 

}