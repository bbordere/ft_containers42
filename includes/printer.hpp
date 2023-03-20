#include <iostream>

#ifndef NP
	#define NP ft
	#include "ft_containers.hpp"
#else
	#define NP std
	#include <map>
	#include <set>
	#include <stack>
	#include <vector>
#endif

template<class T, class Container>
std::ostream &operator<<(std::ostream &stream, NP::stack<T, Container> stack)
{
	while (!stack.empty())
	{
		stream << '|' << stack.top() << "|\n";
		stack.pop();
	}
	return (stream);
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, NP::pair<T, U> const &pair)
{
	stream << '(' << pair.first << ", " << pair.second << ')';
	return (stream);
}

template <class Key, class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, NP::map<Key, T, Compare, Allocator> &map)
{
	stream << '{';
	if (map.empty())
	{
		stream << '}';
		return (stream);		
	}
	typename NP::map<Key, T, Compare, Allocator>::iterator pair = map.begin();
	for (std::size_t i = 0; i < map.size() - 1; i++)
	{
		stream << '\'' << (*pair).first << "': " << (*pair).second << ", ";
		++pair;
	}
	stream << '\'' << (*pair).first << "': " << (*pair).second << '}';
	return (stream);
}

template <class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, NP::set<T, Compare, Allocator> const &set)
{
	if (set.empty())
	{
		stream << "{}";
		return (stream);
	}
	stream << '{';
	typename NP::set<T, Compare, Allocator>::const_iterator val = set.begin();
	for (std::size_t i = 0; i < set.size() - 1; i++)
	{
		stream << *val << ", ";
		++val;
	}
	stream << *val << '}';
	return (stream);
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, NP::vector<T> const &vec)
{
	if (vec.empty())
	{
		stream << "[]";
		return (stream);
	}
	stream << '[';
	for (typename NP::vector<T>::const_iterator it = vec.begin(); it != vec.end() - 1; it++)
		stream << *it << ", ";
	stream << *(vec.end() - 1) << ']';
	stream << ", size: " << vec.size() << ", capacity: " << vec.capacity();
	return (stream);
}