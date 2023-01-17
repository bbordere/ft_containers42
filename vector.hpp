#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <memory>
#include "randomAccessIterators.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			typedef ft::randomAccessIterators<value_type> iterator;
			typedef ft::randomAccessIterators<value_type const> const_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;

		private:
			pointer			_arr;
			size_type 		_size;
			size_type 		_capacity;
			allocator_type	_alloc;
		
		public:
			vector(allocator_type const &alloc = allocator_type()): _arr(NULL), _size(0), _capacity(0), _alloc(alloc) {}

			vector (size_type n, value_type const &val = value_type())
			{
				_arr = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, val);
					
			}

			template <class It>
			vector(It first, It last) {}
			vector (vector const &copy) {}

			iterator begin()
			{
				return (iterator(_arr));
			}

			const_iterator begin() const
			{
				return (const_iterator(_arr));
			}

	};
}

#endif