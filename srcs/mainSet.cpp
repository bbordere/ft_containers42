#include "ft_containers.hpp"
#include <bits/stdc++.h>

#ifndef NP
#define NP ft
#endif

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
	NP::set<char> set;
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
	NP::set<int> set;
	for (int i = 0; i < 15; i++)
		set.insert(i);
	NP::pair<NP::set<int>::const_iterator, bool> inserted = set.insert(42);
	NP::pair<NP::set<int>::const_iterator, bool> dupInserted = set.insert(42);
	if (inserted.first != dupInserted.first || dupInserted.second == true)
		std::cout << "Not good result" << std::endl;
	else
		std::cout << "Good result" << std::endl;
	int next[] = {12, 23, 34, 45, 56, 67, 78};
	set.insert(next, next + 7);
	std::cout << set << '\n';
	set.insert(set.end(), 4242);
	std::cout << set << '\n';

	NP::set<int> set2(set);
	NP::set<int> set3;
	set3 = set2;
	std::cout << set << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';

	set.erase(0);
	set.erase(11);
	set2.erase(++set2.begin());
	NP::set<int>::iterator it = set3.begin();
	++(++(++it));
	set3.erase(set3.begin(), it);
	it = set3.end();
	--(--(--it));
	set3.erase(it, set3.end());
	std::cout << set << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';

	set.swap(set2);
	std::cout << set << '\n';
	std::cout << set2 << '\n';

	set.clear();
	set2.clear();
	set3.clear();
	std::cout << set << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';
}

void	setIteratorTest(void)
{
	std::cout << "---- Iterator test ----" << std::endl;
	NP::set<char> set;
	for (char c = 'a'; c <= 'z'; c++)
		set.insert(c);
	
	std::cout << std::endl;
	for (NP::set<char, int>::const_iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
	for (NP::set<char, int>::const_reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "ASCII code of 'a' is: " << *set.find('a') << std::endl << std::endl;
}

void	setSpeed(void)
{
	std::cout << "---- Speed test ----" << std::endl;
	NP::set<unsigned long long>set;
	for (unsigned long long i = 0; i < 3000000; i++)
		set.insert(i);
	set.find(2500000);
	set.insert(25000);
	NP::set<unsigned long long>set2(set);
	set2.find(2500000);
	NP::set<unsigned long long>set3;
	set3 = set2;
	set3.find(42);
}