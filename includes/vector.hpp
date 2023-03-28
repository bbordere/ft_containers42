#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <memory>
#include "randomAccessIterators.hpp"
#include "reverseIterators.hpp"
#include "is_integral.hpp"
#include "lexicalComp.hpp"
#include <stdexcept>

#include <stdint.h>

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

			typedef ft::randomAccessIterators<value_type>		iterator;
			typedef ft::randomAccessIterators<value_type const>	const_iterator;

			typedef ft::reverseIterator<iterator>		reverse_iterator;
			typedef ft::reverseIterator<const_iterator>	const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;
		
		public:
			explicit vector(allocator_type const &alloc = allocator_type()): _alloc(alloc), _arr(NULL), _size(0), _capacity(0)  {}

			explicit vector (size_type n, value_type const &val = value_type(), allocator_type const &alloc = allocator_type()):
							_alloc(alloc), _arr(NULL), _size(0), _capacity(0)
			{
				if (n >= _alloc.max_size())
					throw std::length_error("Above the max size");
				_arr = _alloc.allocate(n);
				_capacity = n;
				_size = n;
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(_arr + i, val);			
			}

			template <class It>
			vector(It first, It last, allocator_type const &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
				_arr = NULL;
				assign(first, last);
			}

			vector (vector const &copy): _alloc(copy._alloc), _arr(_alloc.allocate(copy._size)),
					_size(copy._size), _capacity(copy._size)
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_arr + i, copy[i]);
			}

			virtual ~vector(void)
			{
				_deleteArr(_arr);
			}

			vector &operator=(vector const &other)
			{
				if (&other != this)
				{
					_alloc = other._alloc;
					assign(other.begin(), other.end());
				}
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
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
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
				if (!n)
				{
					clear();
					return;
				}
				if (n > max_size())
					throw std::length_error("Above the max size");
				if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_arr + i);
				}
				else if (n > _size)
					insert(end(), n - _size, val);
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
					throw std::length_error("vector::reserve");
				if (n <= _capacity)
					return;
				pointer newArr = _alloc.allocate(n, _arr + n);
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
					throw std::out_of_range("vector::at : n >= this->size() !");
				return (_arr[n]);
			}

			const_reference at(size_type n) const
			{
				if (_size <= n)
					throw std::out_of_range("vector::at : n >= this->size() !");
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

			pointer data()
			{
				return (_arr);
			}

			const_pointer data() const
			{
				return (_arr);
			}

			/*MODIFIERS*/
			template <class It> 
			void assign (It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				_assignDispatch(first, last, typename ft::iterator_traits<It>::iterator_category());
			}

			void	assign(size_type n, value_type const &val)
			{
				if (n > _alloc.max_size())
					throw (std::length_error("Over max size"));
				if (n > _capacity)
				{
					_deleteArr(_arr);
					_arr = _alloc.allocate(n);
					_capacity = n;
					_size = n;
					for (size_type i = 0; i < n; ++i)
						_alloc.construct(_arr + i, val);
					return;
				} 
				pointer tmp = _arr;
				for (size_type i = 0; i < n; i++)
				{
					if (i < _size)
						*tmp = val;
					else
						_alloc.construct(tmp, val);
					++tmp;
				}
				if (_size >= n)
				{
					for (size_type i = n; i < _size; ++i)
						_alloc.destroy(tmp++);
				}
				_size = n;
			}

			void	push_back(value_type const &val)
			{
				if (_size == _capacity)
					reserve(_capacity == 0 ? 1 : _capacity << 1);
				_alloc.construct(_arr + _size, val);
				_size++;
			}

			void	pop_back()
			{
				_alloc.destroy(_arr + --_size);
			}

			iterator insert(iterator position, value_type const &val)
			{
				size_type offset = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(_arr + offset));
			}

			void insert(iterator pos, size_type n, value_type const &val)
			{
				if (!n)
					return;
				if (_size + n > _alloc.max_size())
					throw (std::length_error("Above the max size"));
				if (!_size)
				{
					assign(n, val);
					return;
				}
				if (_capacity >= _size + n)
				{
					if (pos != end())
						_insertRightWay(pos, n, val);
					else
					{
						for (size_type i = 0; i < n; ++i)
							push_back(val);
					}
				}
				else
				{
					pointer oldArr = NULL;
					size_type oldCap = 0;
					size_type oldSize = 0;
					difference_type index = pos - begin();
					if ((_size << 1) < _size + n)
						oldArr = _reserveNoDelete(_size + n, oldCap, oldSize);
					else
						oldArr = _reserveNoDelete(_size << 1, oldCap, oldSize);
					_moveConstruct(n, val, index);
					if (!oldArr)
						return ;
					for (size_type i = 0; i < oldSize; ++i)
						_alloc.destroy(oldArr + i);
					_alloc.deallocate(oldArr, oldCap);
				}
			}

			template<class It>
			void	insert(iterator position, It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				if (_capacity)
					_insertDispatch(position, first, last, typename ft::iterator_traits<It>::iterator_category());
				else
					assign(first, last);
			}

			iterator erase(iterator position)
			{
				iterator res = position;
				while (position != end() - 1)
				{
					*position = *(position + 1);
					position++;
				}
				_alloc.destroy(&*position);
				_size--;
				return (res);
			}

			iterator erase(iterator first, iterator last)
			{
				difference_type diff = last - first;
				if (first == last)
					return (iterator(first));

				if (last == end())
				{
					for (difference_type i = 0; i < diff; ++i)
						_alloc.destroy(&(*first) + i);
					_size -= diff;
					return (iterator(first));
				}

				iterator tmp(first);
				_copyRange(last, end(), tmp);
				for (difference_type i = 0; i < diff; ++i)
					_alloc.destroy(_arr + _size - 1 - i);
				_size -= diff;	
				return (iterator(first));
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
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_arr + i);
				_size = 0;
			}

			/*ALLOCATOR*/
			allocator_type get_allocator(void) const
			{
				return (_alloc);
			}

		private:

			allocator_type	_alloc;
			pointer			_arr;
			size_type 		_size;
			size_type 		_capacity;

			template<class It, class Ot>
			void _copyRange(It first, It last, Ot destFirst)
			{
				while (first != last)
				{
					*destFirst = *first;
					++destFirst;
					++first;
				}
			}

			void	_deleteArr(pointer arr)
			{
				if (!arr)
					return;
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(arr + i);
				_alloc.deallocate(arr, _capacity);
				arr = NULL;
			}

			pointer		_reserveNoDelete(size_type n, size_type &oldCap, size_type &oldSize)
			{
				pointer res = _arr;
				oldCap = _capacity;
				oldSize = _size;
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n <= _capacity)
					return (NULL);
				pointer newArr = _alloc.allocate(n, _arr + n);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(newArr + i, _arr[i]);
				_capacity = n;
				_arr = newArr;
				return (res);
			}

			void	_insertRightWay(iterator pos, size_type n, value_type const &val)
			{
				pointer end = _arr + _size;
				pointer tmp_end = end - 1;
				pointer	new_end = end + n - 1;
				while (tmp_end != pos.base())
				{
					if (end > new_end)
						*new_end = *tmp_end;
					else
						_alloc.construct(new_end, *tmp_end);
					--new_end;
					--tmp_end;
				}

				if (end > new_end)
					*new_end = *tmp_end;
				else
					_alloc.construct(new_end, *tmp_end);

				pointer tmp = pos.base();
				for (size_type i = 0; i < n; ++i)
				{
					if (end > tmp)
						*tmp = val;
					else
						_alloc.construct(tmp, val);
					++tmp;
				}
				_size += n;
			}

			template <class It>
			void	_insertRightWay(size_type diff, iterator pos, It first, It last)
			{
				pointer end = _arr + _size;
				pointer tmp_end = end - 1;
				pointer	new_end = end + diff - 1;
				while (tmp_end != pos.base())
				{
					if (end > new_end)
						*new_end = *tmp_end;
					else
						_alloc.construct(new_end, *tmp_end);
					--new_end;
					--tmp_end;
				}

				if (end > new_end)
					*new_end = *tmp_end;
				else
					_alloc.construct(new_end, *tmp_end);

				pointer tmp = pos.base();
				while (first != last)
				{
					if (end > tmp)
						*tmp = *first;
					else
						_alloc.construct(tmp, *first);
					++first;
					++tmp;
				}
				_size += diff;
			}

			template <class It>
			iterator	_insertDispatch(iterator pos, It first, It last, std::input_iterator_tag)
			{
				vector copy(first, last);
				_insertDispatch(pos, copy.begin(), copy.end(), std::random_access_iterator_tag());
				return (pos);
			}


			template <class It>
			void	_moveConstruct(size_type diff, It first, size_type startIndex, typename ft::enable_if<!ft::is_integral<It>::value, bool>::type = true)
			{
				for (size_type i = diff + _size - 1; i > startIndex + diff - 1; --i)
				{
					_alloc.construct(_arr + i, *(_arr + (i - diff)));
					_alloc.destroy(_arr + (i - diff));
				}
				for (size_type i = startIndex; i < startIndex + diff; ++i)
					_alloc.construct(_arr + i, *first++);
				_size += diff;
			}

			void	_moveConstruct(size_type n, value_type const &val, size_type startIndex)
			{
				for (size_type i = n + _size - 1; i > startIndex + n - 1; --i)
				{
					_alloc.construct(_arr + i, *(_arr + (i - n)));
					_alloc.destroy(_arr + (i - n));
				}
				for (size_type i = startIndex; i < startIndex + n; ++i)
					_alloc.construct(_arr + i, val);
				_size += n;
			}

			template <class It>
			iterator	_insertDispatch(iterator pos, It first, It last, std::random_access_iterator_tag)
			{
				if (first == last)
					return (pos);
				size_type diff = last - first;
				if (_size + diff > _alloc.max_size())
					throw (std::length_error("Above the max size"));
				if (!_size)
				{
					assign(first, last);
					return (begin());
				}
				if (_capacity >= _size + diff)
				{
					if (pos != end())
						_insertRightWay(diff, pos, first, last);
					else
					{
						while (first != last)
							push_back(*first++);
					}
				}
				else
				{
					pointer oldArr = NULL;
					size_type oldCap = 0;
					size_type oldSize = 0;
					difference_type index = pos - begin();
					if ((_size << 1) < _size + diff)
						oldArr = _reserveNoDelete(_size + diff, oldCap, oldSize);
					else
						oldArr = _reserveNoDelete(_size << 1, oldCap, oldSize);
					_moveConstruct(diff, first, index);
					if (!oldArr)
						return (pos);
					for (size_type i = 0; i < oldSize; ++i)
						_alloc.destroy(oldArr + i);
					_alloc.deallocate(oldArr, oldCap);
				}
				return (pos);
			}
			
			template <class It>
			void	_assignDispatch(It first, It last, std::input_iterator_tag)
			{
				size_type oldSize = _size;
				pointer tmp = _arr;
				_size = 0;
				while (first != last)
				{
					if (oldSize)
					{
						if (_size > _alloc.max_size())
							throw (std::length_error("Above the max size"));
						*tmp = *first;
						++tmp;
						--oldSize;
						++_size;
					}
					else
						push_back(*first);
					++first;
				}
				for (size_type i = 0; i < oldSize; ++i, ++tmp)
					_alloc.destroy(tmp);
			}

			template <class It>
			void	_assignDispatch(It first, It last, std::random_access_iterator_tag)
{
				size_type i = 0;
				size_type len = last - first;
				if (len > _alloc.max_size())
					throw (std::length_error("Above the max size"));
				if (_capacity < len)
				{
					_deleteArr(_arr);
					_capacity = len;
					if (_capacity)
						_arr = _alloc.allocate(_capacity);
					while (first != last)
					{
						_alloc.construct(_arr + i, *first);
						++first;
						++i;
					}
				}
				else
				{
					pointer end = _arr + _size;
					pointer tmp = _arr;
					_size = 0;
					while (first != last)
					{
						if (tmp < end)
							*tmp = *first;
						else
							_alloc.construct(tmp, *first);
						++tmp;
						++first;
						++i;
					}
					while (tmp < end)
						_alloc.destroy(tmp++);
				}
				_size = i;
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

#endif