#ifndef __LEXICAL_HPP__
#define __LEXICAL_HPP__

#include <iostream>
#include <vector>
#include "pair.hpp"

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}
		
	template <class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (comp(*first1 < *first2))
				return (true);
			if (comp(*first2 < *first1))
				return (false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template <class InputIt1, class InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
}

// int main(int argc, char const *argv[])
// {
// 	std::vector<char> al1 = {'a', 'b', 'c'};
// 	std::vector<char> al2 = {'a', 'b', 'd'};

// 	std::cout << ft::lexicographical_compare(al1.begin(), al1.end(), al2.begin(), al2.end()) << std::endl;

// 	return (0);
// }

#endif