#ifndef __RANDOM_ITERATOR_HP__
#define __RANDOM_ITERATOR_HP__

#include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class randomAccessIterators: ft::iterator<std::random_access_iterator_tag, T>
	{
		private:
			typedef ft::iterator<std::random_access_iterator_tag, T> _type;
	
		public:
			typedef typename _type::iterator_category			iterator_category;
			typedef typename _type::difference_type				difference_type;
			typedef typename _type::pointer 					pointer;
			typedef typename _type::reference					reference;
			typedef T											value_type;

		protected:
			pointer	_ptr;

		public:
			randomAccessIterators(void): _ptr(NULL) {}
			randomAccessIterators(pointer ptr): _ptr(ptr) {}
			randomAccessIterators(randomAccessIterators const &copy): _ptr(copy._ptr) {}
			~randomAccessIterators() {}
			randomAccessIterators &operator=(randomAccessIterators const &assign)
			{
				if (*this != assign)
					_ptr = assign._ptr;
				return (*this);
			}

			reference operator*(void) const { return (*_ptr);}

			pointer operator->(void) const { return (_ptr);}

			reference operator[](difference_type n) const
			{
				return (_ptr[n]);
			}

			randomAccessIterators	&operator++(void)
			{
				++_ptr;
				return (*this);
			}

			randomAccessIterators	operator++(int)
			{
				randomAccessIterators temp = *this;
				++_ptr;
				return (temp);
			}

			randomAccessIterators	&operator--(void)
			{
				--_ptr;
				return (*this);
			}

			randomAccessIterators	operator--(int)
			{
				randomAccessIterators temp = *this;
				--_ptr;
				return (temp);
			}

			randomAccessIterators	operator+(difference_type n) const
			{
				return (randomAccessIterators(_ptr + n));
			}

			difference_type	operator+(randomAccessIterators const &n) const
			{
				return ((_ptr + n._ptr));
			}

			randomAccessIterators	&operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}

			randomAccessIterators	operator-(difference_type n) const
			{
				return (randomAccessIterators(_ptr - n));
			}

			difference_type	operator-(randomAccessIterators const &n) const
			{
				return ((_ptr - n._ptr));
			}

			randomAccessIterators	&operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}	

			pointer base() const
			{
				return (_ptr);
			}

			operator randomAccessIterators<T const>(void) const
			{
				return (randomAccessIterators<T const>(this->_ptr));
			}
	};

	template <class T>
	randomAccessIterators<T> operator+(typename randomAccessIterators<T>::difference_type n, randomAccessIterators<T> const &rhs)
	{
		return (rhs + n);
	}

	template <class Iter1, class Iter2>
	typename randomAccessIterators<Iter1>::difference_type operator-(randomAccessIterators<Iter1> const &lhs, randomAccessIterators<Iter2> const &rhs)
	{
		return  lhs.base() - rhs.base();
	}

	template <class T>
	bool	operator<(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class T>
	bool	operator<=(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class T>
	bool	operator>(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T>
	bool	operator>=(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class T>
	bool	operator==(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T>
	bool	operator!=(randomAccessIterators<T> const& lhs, randomAccessIterators<T> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

	//CONST COMP
	template <class T, class U>
	bool	operator<(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class T, class U>
	bool	operator<=(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class T, class U>
	bool	operator>(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T, class U>
	bool	operator>=(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class T, class U>
	bool	operator==(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T, class U>
	bool	operator!=(randomAccessIterators<T> const& lhs, randomAccessIterators<U> const& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
