#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <memory>
#include "randomAccessIterators.hpp"
#include "reverseIterators.hpp"
#include "is_integral.hpp"
#include "lexicalComp.hpp"
#include <stdexcept>

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

			typedef ft::reverseIterator<iterator> reverse_iterator;
			typedef ft::reverseIterator<const_iterator> const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;

		private:
		// public:
			pointer			_arr;
			size_type 		_size;
			size_type 		_capacity;
			allocator_type	_alloc;
		
		public:
			explicit vector(allocator_type const &alloc = allocator_type()): _arr(NULL), _size(0), _capacity(0), _alloc(alloc) {}

			explicit vector (size_type n, value_type const &val = value_type(), allocator_type const &alloc = allocator_type()): _alloc(alloc)
			{
				_arr = _alloc.allocate(n);
				_capacity = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, val);
				_size = n;					
			}

			template <class It>
			vector(It first, It last, allocator_type const &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				difference_type size = ft::distance(first, last);
				_alloc = alloc;
				_size = size;
				_capacity = size;
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; first != last; i++)
				{
					_alloc.construct(_arr + i, *first);
					++first;
				}
			}

			vector (vector const &copy): _arr(NULL), _size(copy._size), _capacity(copy._capacity), _alloc(copy._alloc)
			{
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_arr + i, copy[i]);
			}

			~vector(void)
			{
				_deleteArr(_arr);
			}

			vector &operator=(vector const &other)
			{
				if (&other == this)
					return (*this);

				if (_capacity < other._size)
				{
					_deleteArr(_arr);
					_arr = _alloc.allocate(other._size);
				}
				_size = other._size;
				_capacity = other._capacity;
				_alloc = other._alloc;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_arr + i, other._arr[i]);
				return (*this);
			}


			/*ITERATORS*/
			iterator begin()
			{
				return (iterator(_arr));
			}

			const_iterator begin() const
			{
				return (const_iterator(_arr));
			}

			iterator end()
			{
				return (iterator(_arr + _size));
			}

			const_iterator end() const
			{
				return (const_iterator(_arr + _size));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(_arr));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_arr));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(_arr + _size));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_arr + _size));
			}




			/*CAPACITY*/
			size_type size(void) const
			{
				return (_size);
			}

			size_type max_size(void) const
			{
				return (_alloc.max_size());
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw std::length_error("Too large bro !");
				if (n > _capacity)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_arr + i, val);
				}
				else if (n < _size)
				{
					for (size_type i = _size - 1; i >= n; i--)
						_alloc.destroy(_arr + i);
				}
				else
				{
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_arr + i, val);
				}
				_size = n;
			}

			size_type capacity(void) const
			{
				return (_capacity);
			}

			bool	empty(void) const
			{
				return (_size == 0);
			}

			void	reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Too large bro !");
				if (n <= _capacity)
					return;
				pointer newArr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(newArr + i, _arr[i]);
				_deleteArr(_arr);
				_capacity = n;
				_arr = newArr;
			}




			/*ELEMENT ACCESS*/

			reference	operator[](size_type position)
			{
				return (_arr[position]);
			}

			const_reference	operator[](size_type position) const
			{
				return (_arr[position]);
			}

			reference at(size_type n)
			{
				if (_size <= n)
					throw std::out_of_range("WTF BRO");
				return (_arr[n]);
			}

			const_reference at(size_type n) const
			{
				if (_size <= n)
					throw std::out_of_range("WTF BRO");
				return (_arr[n]);
			}

			reference front()
			{
				return (*begin());
			}

			const_reference front() const
			{
				return (*begin());
			}

			reference back()
			{
				return (*--end());
			}

			const_reference back() const
			{
				return (*--end());
			}




			/*MODIFIERS*/
			template <class It> 
			void assign (It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				size_type i = 0;
				resize(distance(first, last));
				while (first != last)
				{
					_alloc.construct(_arr + i, *first);
					first++;
					i++;
				}
			}

			void	assign(size_type n, value_type const &val)
			{
				clear();
				if (!n)
					return;
				resize(n, val);
			}

			void	push_back(value_type const &val)
			{
				if (_size == _capacity)
				{
					reserve(_capacity == 0 ? 1 : _capacity * 2);
					_alloc.construct(_arr + (_size == 0 ? 0 : _size), val);
				}
				else
					_alloc.construct(_arr + _size, val);
				_size++;
			}

			void	pop_back()
			{
				_alloc.destroy(&back());
				_size--;
			}

			iterator insert(iterator position, value_type const &val)
			{
				size_type offset = distance(begin(), position);
				insert(position, 1, val);
				return (iterator(_arr + offset));
			}

			void insert(iterator position, size_type n, value_type const &val)
			{
				size_type offset = distance(begin(), position);
				reserve(_size + n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + _size + i, val);
				for (size_type i = _size - 1; i > 0 && i >= offset; i--)
					_arr[i + n] = _arr[i];
				if (offset == 0)
					_arr[n] = _arr[0];
				for (size_type i = offset; i < offset + n; i++)
					_arr[i] = val;
				_size += n;
			}

			template<class It>
			void	insert(iterator position, It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				size_type	 offset = distance(begin(), position);
				size_type 	nbNewElements = distance(first, last);
				pointer 	oldArr = _allocInsert(_size + nbNewElements);
				for (size_type i = 0; i < nbNewElements; i++)
					_alloc.construct(_arr + _size + i, 45);
				for (size_type i = _size - 1; i > 0 && i >= offset; i--)
					_arr[i + nbNewElements] = _arr[i];
				if (offset == 0)
					_arr[nbNewElements] = _arr[0];
				for (size_type i = offset; i < offset + nbNewElements; i++)
					_arr[i] = *first++;
				_size += nbNewElements;
				if (oldArr)
					_deleteArr(oldArr);
			}

			iterator erase(iterator position)
			{
				iterator res = position;
				_alloc.destroy(&*position);
				while (position != end())
				{
					*position = *(position + 1);
					position++;
				}
				_size--;
				return (res);
			}

			iterator erase(iterator first, iterator last)
			{
				iterator tmp = first;
				while (tmp != last)
				{
					_alloc.destroy(&*(tmp));
					tmp++;
				}
				assign(last, end());
				return (tmp);
			}

			void	swap(vector &other)
			{
				std::swap(_arr, other._arr);
				std::swap(_size, other._size);
				std::swap(_capacity, other._capacity);
				std::swap(_alloc, other._alloc);
			}

			void	clear(void)
			{
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(_arr + i);
				_size = 0;
			}


			/*ALLOCATOR*/
			allocator_type get_allocator(void) const
			{
				return (_alloc);
			}




		private:
			void	_deleteArr(pointer arr)
			{
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(arr + i);
				_alloc.deallocate(arr, _capacity);
			}
			
			pointer	_allocInsert(size_type n)
			{
				pointer res = _arr;
				if (n > max_size())
					throw std::length_error("Too large bro !");
				if (n <= _capacity)
					return (NULL);
				pointer newArr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(newArr + i, _arr[i]);
				_capacity = n;
				_arr = newArr;
				return (res);
			}
	};



/* RELATIONAL OP*/
template <class T, class Alloc>
bool operator==(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!=(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator<=(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>=(ft::vector<T,Alloc> const &lhs, ft::vector<T,Alloc> const &rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
{
	x.swap(y);
}

}



















template <typename T>
std::ostream &operator<<(std::ostream &stream, ft::vector<T> const &vec)
{
	if (vec.empty())
	{
		stream << "[]";
		return (stream);
	}
	stream << '[';
	for (typename ft::vector<T>::iterator it = vec.begin(); it != vec.end() - 1; it++)
		stream << *it << ", ";
	stream << *(vec.end() - 1) << ']';
	return (stream);	
}

#endif