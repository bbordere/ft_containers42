#include <iostream>
#include <cstdlib>
#include "printer.hpp"

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
	NP::set<int> set1;
	for (int i = 0; i < 15; i++)
		set1.insert(i);
	NP::pair<NP::set<int>::const_iterator, bool> inserted = set1.insert(42);
	NP::pair<NP::set<int>::const_iterator, bool> dupInserted = set1.insert(42);
	if (inserted.first != dupInserted.first || dupInserted.second == true)
		std::cout << "Not good result" << std::endl;
	else
		std::cout << "Good result" << std::endl;
	int next[] = {12, 23, 34, 45, 56, 67, 78};
	set1.insert(next, next + 7);
	std::cout << set1 << '\n';
	set1.insert(set1.end(), 4242);
	std::cout << set1 << '\n';

	NP::set<int> set2(set1);
	NP::set<int> set3;
	set3 = set2;
	std::cout << set1 << '\n';
	std::cout << set2 << '\n';
	std::cout << set3 << '\n';

	set1.erase(0);
	set1.erase(11);
	set2.erase(++set2.begin());
	NP::set<int>::iterator it = set3.begin();
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
	NP::set<char> set1;
	for (char c = 'a'; c <= 'z'; c++)
		set1.insert(c);
	
	std::cout << std::endl;
	for (NP::set<char, int>::const_iterator it = set1.begin(); it != set1.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
	for (NP::set<char, int>::const_reverse_iterator it = set1.rbegin(); it != set1.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "ASCII code of 'a' is: " << *set1.find('a') << std::endl << std::endl;
}

void	setSpeed(void)
{
	std::cout << "---- Speed test ----" << std::endl;
	NP::set<unsigned long long>set1;
	for (unsigned long long i = 0; i < 3000000; i++)
		set1.insert(i);
	set1.find(2500000);
	set1.insert(25000);
	NP::set<unsigned long long>set2(set1);
	set2.find(2500000);
	NP::set<unsigned long long>set3;
	set3 = set2;
	set3.find(42);
}