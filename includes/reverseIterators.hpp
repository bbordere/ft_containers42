#ifndef __REVERSE_ITERATOR_HP__
#define __REVERSE_ITERATOR_HP__

#include "iterator_traits.hpp"

namespace ft
{
	template<class Iter>
	class reverseIterator: public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category,
											typename ft::iterator_traits<Iter>::value_type,
											typename ft::iterator_traits<Iter>::difference_type,
											typename ft::iterator_traits<Iter>::pointer,
											typename ft::iterator_traits<Iter>::reference>
	{
		private:
			typedef typename ft::iterator_traits<Iter> _type;

		public:
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer 			pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

		protected:
			iterator_type	_it;

		public:
			reverseIterator(void): _it() {}

			explicit reverseIterator(iterator_type it): _it(it) {}

			template <class It>
			reverseIterator(reverseIterator<It> const &copy): _it(copy.base()) {}

			~reverseIterator() {}

			template <class It>
			reverseIterator &operator=(reverseIterator<It> const &assign)
			{
				if (*this != assign)
					_it = assign.base();
				return (*this);
			}

			pointer operator->(void) const
			{
				return (&(operator*()));
			}

			reference operator*(void) const
			{
				iterator_type tmp = _it;
				return (*--tmp);
			}

			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}

			reverseIterator &operator++(void)
			{
				--_it;
				return (*this);
			}

			reverseIterator operator++(int)
			{
				reverseIterator	tmp(*this);
				--_it;
				return (tmp);
			}

			reverseIterator &operator--(void)
			{
				++_it;
				return (*this);
			}

			reverseIterator operator--(int)
			{
				reverseIterator	tmp(*this);
				++_it;
				return (tmp);
			}

			reverseIterator	operator+(difference_type n) const
			{
				return (reverseIterator(_it - n));
			}

			reverseIterator	&operator+=(difference_type n)
			{
				_it -= n;
				return (*this);
			}

			reverseIterator	operator-(difference_type n) const
			{
				return (reverseIterator(_it + n));
			}

			reverseIterator	&operator-=(difference_type n)
			{
				_it += n;
				return (*this);
			}	

			iterator_type base() const
			{
				return (_it);
			}
	};

	template <class T>
	reverseIterator<T> operator+(typename reverseIterator<T>::difference_type n, reverseIterator<T> const &rhs)
	{
		return (rhs + n);
	}
	template <class Iter1, class Iter2>
	typename reverseIterator<Iter1>::difference_type operator-(reverseIterator<Iter1> const &lhs, reverseIterator<Iter2> const &rhs)
	{
		return  rhs.base() - lhs.base();
	}

	template <class T>
	bool	operator<(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T>
	bool	operator<=(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class T>
	bool	operator>(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class T>
	bool	operator>=(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class T>
	bool	operator==(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T>
	bool	operator!=(reverseIterator<T> const& lhs, reverseIterator<T> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

	//CONST COMP
	template <class T, class U>
	bool	operator<(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T, class U>
	bool	operator<=(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class T, class U>
	bool	operator>(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class T, class U>
	bool	operator>=(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class T, class U>
	bool	operator==(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T, class U>
	bool	operator!=(reverseIterator<T> const& lhs, reverseIterator<U> const& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
