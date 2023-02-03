#ifndef __ITERATOR_UTILS_HPP__
# define __ITERATOR_UTILS_HPP__

#include <cstddef>

namespace   ft 
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: input_iterator_tag {};
	struct bidirectional_iterator_tag: forward_iterator_tag {};
	struct random_access_iterator_tag: bidirectional_iterator_tag {};

	template <class Category, class T, class Diff = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_tye;
		typedef	Diff		difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type 
	distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type res = 0;
		while (first != last)
		{
			first++;
			res++;
		}
		return res;
	}

	template<class InputIterator, class OutputIterator>
	inline OutputIterator _copy_element (InputIterator first, InputIterator last, OutputIterator result)
	{
		while (first!=last)
		{
			*result = *first;
			// *first = *result;
			++result;
			++first;
		}
		return result;
	}
}

#endif