#include <sys/time.h>
#include <sys/time.h>
#include <cstdlib>
#include <stdint.h>
#include "../ft_containers.hpp"
#include <bits/stdc++.h>
#include <unistd.h>

template <class Key, class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, std::map<Key, T, Compare, Allocator> &map)
{
	stream << '{';
	if (map.empty())
	{
		stream << '}';
		return (stream);		
	}
	typename std::map<Key, T, Compare, Allocator>::iterator pair = map.begin();
	for (std::size_t i = 0; i < map.size() - 1; i++)
	{
		stream << '\'' << (*pair).first << "': " << (*pair).second << ", ";
		++pair;
	}
	stream << '\'' << (*pair).first << "': " << (*pair).second << '}';
	return (stream);
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, std::pair<T, U> const &pair)
{
	stream << '(' << pair.first << ", " << pair.second << ')';
	return (stream);
}

static uint64_t getDiff(timeval const &beg, timeval const &end)
{
	return ((end.tv_sec * 1000 + end.tv_usec / 1000) - (beg.tv_sec * 1000 + beg.tv_usec / 1000));
}

uint64_t takeTime()
{
	static struct timeval	beg, end;
	static bool				finished = false;
	if (!finished)
	{
		gettimeofday(&beg, NULL);
		finished = true;
		return (0);
	}
	gettimeofday(&end, NULL);
	finished = false;
	return (getDiff(beg, end));
}

#ifndef NP
#define NP ft
#endif

#include "../RBTreePrinter.hpp"
void	modifiersTest(void)
{
	NP::map<int, std::string> map;
	std::string numbers[] = {"Zero", "One", "Two", "Three", "Four", "Five"};
	for (int i = 0; i < 6; i++)
		map.insert(NP::make_pair<int, std::string>(i, numbers[i]));
	NP::pair<NP::map<int, std::string>::const_iterator, bool> inserted = map.insert(NP::make_pair<int, std::string>(6, "Six"));
	NP::pair<NP::map<int, std::string>::const_iterator, bool> dupInserted = map.insert(NP::make_pair<int, std::string>(6, "Six Duplicate"));
	if (inserted.first != dupInserted.first || dupInserted.second == true)
		std::cout << "Not good result" << std::endl;
	else
		std::cout << "Good result" << std::endl;
	// std::cout << map << std::endl; /*VERBOSE*/
	NP::pair<int, std::string> next[] = {
									NP::make_pair<int, std::string>(7, "Seven"),
									NP::make_pair<int, std::string>(8, "Eight"),
									NP::make_pair<int, std::string>(9, "Nine"),
									NP::make_pair<int, std::string>(10, "Ten")
								};
	map.insert(next, next + 4);
	// std::cout << map << std::endl; /*VERBOSE*/
	map.insert(map.end(), NP::make_pair<int, std::string>(11, "Eleven"));
	// std::cout << map << std::endl << std::endl; /*VERBOSE*/

	NP::map<int, std::string> map2(map);
	NP::map<int, std::string> map3;
	map3 = map2;
	// std::cout << map << std::endl; /*VERBOSE*/
	// std::cout << map2 << std::endl; /*VERBOSE*/
	// std::cout << map3 << std::endl << std::endl; /*VERBOSE*/
	

	map.erase(0);
	map.erase(11);

	map2.erase(++map2.begin());

	NP::map<int, std::string>::iterator it = map3.begin();
	++(++(++it));
	map3.erase(map3.begin(), it);
	it = map3.end();
	--(--(--it));
	map3.erase(it, map3.end());
	// std::cout << map << std::endl; /*VERBOSE*/
	// std::cout << map2 << std::endl; /*VERBOSE*/
	// std::cout << map3 << std::endl << std::endl; /*VERBOSE*/

	map.swap(map2);
	// std::cout << map << std::endl; /*VERBOSE*/
	// std::cout << map2 << std::endl << std::endl; /*VERBOSE*/

	map.clear();
	map2.clear();
	map3.clear();
	// std::cout << map << std::endl; /*VERBOSE*/
	// std::cout << map2 << std::endl; /*VERBOSE*/
	// std::cout << map3 << std::endl << std::endl; /*VERBOSE*/
}

void	speed(void)
{
	NP::map<unsigned long long, unsigned long long>map;
	for (unsigned long long i = 0; i < 3000000; i++)
		map.insert(NP::make_pair(i, i * i));
	map.find(2500000);
	map.insert(map.end(), NP::make_pair(2500000, 42));
	NP::map<unsigned long long, unsigned long long>map2(map);
}

int main(void)
{
	for (int i = 0; i < 35; i++)
	{
		takeTime();
		modifiersTest();
		speed();
		std::cout << static_cast<double>(takeTime()) / 1000 << std::endl;
	}
}

