#include <iostream>
#include <cstdlib>
#include "printer.hpp"

void	mapModifiersTest(void)
{
	std::cout << "---- Modifiers test ----" << std::endl;
	NP::map<int, std::string> map1;
	std::string numbers[] = {"Zero", "One", "Two", "Three", "Four", "Five"};
	for (int i = 0; i < 6; i++)
		map1.insert(NP::make_pair<int, std::string>(i, numbers[i]));
	NP::pair<NP::map<int, std::string>::const_iterator, bool> inserted = map1.insert(NP::make_pair<int, std::string>(6, "Six"));
	NP::pair<NP::map<int, std::string>::const_iterator, bool> dupInserted = map1.insert(NP::make_pair<int, std::string>(6, "Six Duplicate"));
	if (inserted.first != dupInserted.first || dupInserted.second == true)
		std::cout << "Not good result" << std::endl;
	else
		std::cout << "Good result" << std::endl;
	std::cout << map1 << std::endl; /*VERBOSE*/
	NP::pair<int, std::string> next[] = {
									NP::make_pair<int, std::string>(7, "Seven"),
									NP::make_pair<int, std::string>(8, "Eight"),
									NP::make_pair<int, std::string>(9, "Nine"),
									NP::make_pair<int, std::string>(10, "Ten")
								};
	map1.insert(next, next + 4);
	std::cout << map1 << std::endl; /*VERBOSE*/
	map1.insert(map1.end(), NP::make_pair<int, std::string>(11, "Eleven"));
	std::cout << map1 << std::endl << std::endl; /*VERBOSE*/

	NP::map<int, std::string> map2(map1);
	NP::map<int, std::string> map3;
	map3 = map2;
	std::cout << map1 << std::endl; /*VERBOSE*/
	std::cout << map2 << std::endl; /*VERBOSE*/
	std::cout << map3 << std::endl << std::endl; /*VERBOSE*/
	

	map1.erase(0);
	map1.erase(11);

	map2.erase(++map2.begin());

	NP::map<int, std::string>::iterator it = map3.begin();
	++(++(++it));
	map3.erase(map3.begin(), it);
	it = map3.end();
	--(--(--it));
	map3.erase(it, map3.end());
	std::cout << map1 << std::endl; /*VERBOSE*/
	std::cout << map2 << std::endl; /*VERBOSE*/
	std::cout << map3 << std::endl << std::endl; /*VERBOSE*/

	map1.swap(map2);
	std::cout << map1 << std::endl; /*VERBOSE*/
	std::cout << map2 << std::endl << std::endl; /*VERBOSE*/

	map1.clear();
	map2.clear();
	map3.clear();
	std::cout << map1 << std::endl; /*VERBOSE*/
	std::cout << map2 << std::endl; /*VERBOSE*/
	std::cout << map3 << std::endl << std::endl; /*VERBOSE*/
}

void	mapCapacityTest(void)
{
	std::cout << "---- Capacity test ----" << std::endl;
	NP::map<char, int> map;
	std::cout << (map.empty() ? "Map is empty" : "Map isn't empty") << std::endl;
	for (char c = 'a'; c <= 'z'; c++)
		map.insert(NP::make_pair(c, static_cast<int>(c)));
	std::cout << (map.empty() ? "Map is empty" : "Map isn't empty") << std::endl;
	std::cout << "Current map size: " << map.size() << std::endl;
	std::cout << "Max Alloc Size: " << map.max_size() << std::endl;
}

void	mapIteratorTest(void)
{
	std::cout << "---- Iterator test ----" << std::endl;
	NP::map<char, int> map1;
	for (char c = 'a'; c <= 'z'; c++)
		map1.insert(NP::make_pair(c, static_cast<int>(c)));
	
	std::cout << std::endl;
	for (NP::map<char, int>::const_iterator it = map1.begin(); it != map1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (NP::map<char, int>::iterator it = map1.begin(); it != map1.end(); it++)
		(*it).second += 42;
	std::cout << std::endl;
	for (NP::map<char, int>::const_iterator it = map1.begin(); it != map1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	for (NP::map<char, int>::const_reverse_iterator it = map1.rbegin(); it != map1.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (NP::map<char, int>::reverse_iterator it = map1.rbegin(); it != map1.rend(); it++)
		(*it).second -= 42;
	std::cout << std::endl;
	for (NP::map<char, int>::const_reverse_iterator it = map1.rbegin(); it != map1.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "ASCII code of 'a' is: " << map1['a'] << std::endl << std::endl;
}

void	mapSpeed(void)
{
	std::cout << "---- Speed test ----" << std::endl;
	NP::map<unsigned long long, unsigned long long>map1;
	srand(42);
	for (unsigned long long i = 0; i < 3000000; i++)
		map1.insert(NP::make_pair(rand(), i * i));
	map1.find(2500000);
	map1.insert(map1.end(), NP::make_pair(2500000, 42));
	NP::map<unsigned long long, unsigned long long>map2(map1);
	map2.find(25000000);
	NP::map<unsigned long long, unsigned long long>map3;
	map3 = map2;
	map3.find(42);
}

void	mapOperationsTest(void)
{
	std::cout << "---- Operations test ----" << std::endl;
	NP::map<unsigned long long, unsigned long long>map1;
	for (unsigned long long i = 0; i < 1000; i++)
		map1.insert(NP::make_pair(i, i * i));
	NP::map<unsigned long long, unsigned long long>::const_iterator it = map1.find(42);
	std::cout << (it != map1.end() ? "Found !" : "Not Found !") << std::endl;
	it = map1.find(424242);
	std::cout << (it != map1.end() ? "Found !" : "Not Found !") << std::endl;
	std::cout << "21 appears " << map1.count(21) << " times in map" << std::endl;
	std::cout << "213124 appears " << map1.count(213124) << " times in map" << std::endl;
	std::cout << *map1.lower_bound(42) << std::endl;
	std::cout << *map1.upper_bound(42) << std::endl;
	NP::pair<NP::map<unsigned long long, unsigned long long>::iterator, NP::map<unsigned long long, unsigned long long>::iterator> range;
	range = map1.equal_range(42);
	std::cout << "Range: " << *range.first << ", " << *range.second << std::endl;

	NP::map<int, char> alice;
	alice.insert(NP::make_pair(1, 'a'));
	alice.insert(NP::make_pair(2, 'b'));
	alice.insert(NP::make_pair(3, 'c'));

	NP::map<int, char> bob;
	bob.insert(NP::make_pair(7, 'Z'));
	bob.insert(NP::make_pair(8, 'Y'));
	bob.insert(NP::make_pair(9, 'X'));
	bob.insert(NP::make_pair(10, 'W'));

	NP::map<int, char> eve;
	eve.insert(NP::make_pair(1, 'a'));
	eve.insert(NP::make_pair(2, 'b'));
	eve.insert(NP::make_pair(3, 'c'));

	std::cout << std::boolalpha;
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
	std::cout << std::endl;
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}