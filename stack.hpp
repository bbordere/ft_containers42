#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container 	container_type;
			typedef	std::size_t	size_type;

			explicit stack(container_type const &ct = container_type()): c(ct) {}
			
			bool	empty(void) const
			{
				return (c.size() == 0);
			}

			size_type size() const
			{
				return (c.size());
			}

			~stack(void)
			{
				c.clear();
			}

			value_type &top(void)
			{
				return (c.back());
			}

			value_type const &top(void) const
			{
				return (c.back());
			}

			void	push(value_type const &val)
			{
				c.push_back(val);
			}

			void	pop(void)
			{
				c.pop_back();
			}

			template <class T1, class C1>
			friend bool operator==(stack<T1, C1> const &lhs, stack<T1, C1> const &rhs);
		
			template <class T1, class C1>
			friend bool operator<(stack<T1, C1> const &lhs, stack<T1, C1> const &rhs);

		public:
			container_type c;

	};

	template <class T, class Container>
	bool operator==(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator<(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator>(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif