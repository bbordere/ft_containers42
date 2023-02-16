#include "ft_containers.hpp"
#include <bits/stdc++.h>


#ifndef NP
	#define NP ft
#endif
using namespace NP;

template <class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, std::set<T, Compare, Allocator> const &set)
{
	if (set.empty())
	{
		stream << "{}";
		return (stream);
	}
	stream << '{';
	typename std::set<T, Compare, Allocator>::const_iterator val = set.begin();
	for (std::size_t i = 0; i < set.size() - 1; i++)
	{
		stream << *val << ", ";
		++val;
	}
	stream << *val << '}';
	return (stream);
}

void	setCapacityTest(void)
{
	std::cout << "---- Capacity test ----" << std::endl;
	set<char> set;
	std::cout << (set.empty() ? "set is empty" : "set isn't empty") << std::endl;
	for (char c = 'a'; c <= 'z'; c++)
		set.insert(c);
	std::cout << (set.empty() ? "set is empty" : "set isn't empty") << std::endl;
	std::cout << "Current set size: " << set.size() << std::endl;
	std::cout << "Max Alloc Size: " << set.max_size() << std::endl;
}

void	setModifiersTest(void)
{
	std::cout << "---- Modifiers test ----" << std::endl;
	set<int> set1;
	for (int i = 0; i < 15; i++)
		set1.insert(i);
	pair<set<int>::const_iterator, bool> inserted = set1.insert(42);
	pair<set<int>::const_iterator, bool> dupInserted = set1.insert(42);
	if (inserted.first != dupInserted.first || dupInserted.second == true)
		std::cout << "Not good result" << std::endl;
	else
		std::cout << "Good result" << std::endl;
	int next[] = {12, 23, 34, 45, 56, 67, 78};
	set1.insert(next, next + 7);
	std::cout << set1 << '\n';
	set1.insert(set1.end(), 4242);
	std::cout << set1 << '\n';

	set<int> set2(set1);
	set<int> set3;
	set3 = set2;
	std::cout << set1 << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';

	set1.erase(0);
	set1.erase(11);
	set2.erase(++set2.begin());
	set<int>::iterator it = set3.begin();
	++(++(++it));
	set3.erase(set3.begin(), it);
	it = set3.end();
	--(--(--it));
	set3.erase(it, set3.end());
	std::cout << set1 << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';

	set1.swap(set2);
	std::cout << set1 << '\n';
	std::cout << set2 << '\n';

	set1.clear();
	set2.clear();
	set3.clear();
	std::cout << set1 << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';
}

void	setIteratorTest(void)
{
	std::cout << "---- Iterator test ----" << std::endl;
	set<char> set1;
	for (char c = 'a'; c <= 'z'; c++)
		set1.insert(c);
	
	std::cout << std::endl;
	for (set<char, int>::const_iterator it = set1.begin(); it != set1.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
	for (set<char, int>::const_reverse_iterator it = set1.rbegin(); it != set1.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "ASCII code of 'a' is: " << *set1.find('a') << std::endl << std::endl;
}

void	setSpeed(void)
{
	std::cout << "---- Speed test ----" << std::endl;
	set<unsigned long long>set1;
	for (unsigned long long i = 0; i < 3000000; i++)
		set1.insert(i);
	set1.find(2500000);
	set1.insert(25000);
	set<unsigned long long>set2(set1);
	set2.find(2500000);
	set<unsigned long long>set3;
	set3 = set2;
	set3.find(42);
}