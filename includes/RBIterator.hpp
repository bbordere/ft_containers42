#ifndef __RBTREE_ITERATOR_HPP__
#define __RBTREE_ITERATOR_HPP__

#include "RBNode.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template <class T>
	class RBIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef	T				value_type;
			typedef	T&				reference;
			typedef	T*				pointer;

		private:
			typedef RBNode<T>		node_t;
			typedef	node_t*			node_ptr;
			typedef RBIterator<T>	iterator;
			node_ptr _ptr;
			bool	_isNil(node_ptr node) {return (!node->_right && !node->_left);}

		public:

			RBIterator(void): _ptr(NULL) {}
			RBIterator(node_ptr ptr): _ptr(ptr) {}
			RBIterator(RBIterator const &copy): _ptr(copy._ptr) {}

			node_ptr	_increment(node_ptr node)
			{
				if (_isNil(node))
					node = node->_parent;
				else if (!_isNil(node->_right)) 
				{
					node = node->_right;
					while (!_isNil(node->_left))
						node = node->_left;
				}			
				else 
				{
					node_ptr	y = node->_parent;
					while (!_isNil(y) && node == y->_right) 
					{
						node = y;
						y = y->_parent;
					}
					node = y;
				}
				return node;
			}

			node_ptr	_decrement(node_ptr node)
			{
				if (_isNil(node))
					node = node->_parent;
				else if (!_isNil(node->_left)) 
				{
					node = node->_left;
					while (!_isNil(node->_right))
						node = node->_right;
				}			
				else 
				{
					node_ptr	y = node->_parent;
					while (!_isNil(y) && node == y->_left) 
					{
						node = y;
						y = y->_parent;
					}
					node = y;
				}
				return node;
			}

			reference operator*(void) const { return (_ptr->_val);}

			pointer operator->(void) const { return (&_ptr->_val);}

			iterator &operator=(iterator const &assign)
			{
				if (this != &assign)
					_ptr = assign._ptr;
				return (*this);
			}

			iterator	&operator++(void)
			{
				_ptr = node_t::_increment(_ptr);
				return (*this);
			}

			iterator	operator++(int)
			{
				iterator temp = *this;
				_ptr = node_t::_increment(_ptr);
				return (temp);
			}

			iterator	&operator--(void)
			{
				_ptr = node_t::_decrement(_ptr);
				return (*this);
			}

			iterator	operator--(int)
			{
				iterator temp = *this;
				_ptr = node_t::_decrement(_ptr);
				return (temp);
			}
			node_ptr base() const
			{
				return (_ptr);
			}

			// friend bool	operator==(iterator const& x, iterator const& y) {
			// 	return x.base() == y.base();
			// }

			// friend bool	operator!=(iterator const& x, iterator const& y) {
			// 	return x.base() != y.base();
			// }

			// operator RBIterator<T const>(void) const
			// {
			// 	return (RBIterator<T const>(_ptr));
			// }
	};


	template <class T>
	class RBConstIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	const T&						reference;
			typedef	const T*						pointer;
			typedef std::ptrdiff_t					difference_type;

		private:
			typedef RBNode<T>						node_t;
			typedef	node_t*							node_ptr;
			typedef RBIterator<T>			iterator;
			typedef RBConstIterator<T>		const_iterator;
			node_ptr _ptr;

		public:
			RBConstIterator(void): _ptr(NULL) {}
			RBConstIterator(node_ptr ptr): _ptr(ptr) {}
			RBConstIterator(const RBConstIterator &it): _ptr(it._ptr) {}
			RBConstIterator(const iterator &it): _ptr(it.base()) {}

			reference operator*(void) const { return (_ptr->_val);}

			pointer operator->(void) const { return (&_ptr->_val);}

			const_iterator	&operator++(void)
			{
				_ptr = node_t::_increment(_ptr);
				return (*this);
			}

			const_iterator	operator++(int)
			{
				const_iterator temp = *this;
				_ptr = node_t::_increment(_ptr);
				return (temp);
			}

			const_iterator	&operator--(void)
			{
				_ptr = node_t::_decrement(_ptr);
				return (*this);
			}

			const_iterator	operator--(int)
			{
				const_iterator temp = *this;
				_ptr = node_t::_decrement(_ptr);
				return (temp);
			}
			node_ptr base() const
			{
				return (_ptr);
			}

			// friend bool	operator==(const_iterator const& x, const_iterator const& y) {
			// 	return x.base() == y.base();
			// }

			// friend bool	operator!=(const_iterator const& x, const_iterator const& y) {
			// 	return x.base() != y.base();
			// }

			// operator RBIterator<T const>(void) const
			// {
			// 	return (RBIterator<T const>(_ptr));
			// }
	};

	template <class ValueType1, class ValueType2>
	bool operator == (const RBIterator< ValueType1>& lhs, const RBIterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator == (const RBConstIterator< ValueType1>& lhs, const RBIterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator == (const RBIterator< ValueType1>& lhs, const RBConstIterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator == (const RBConstIterator< ValueType1>& lhs, const RBConstIterator< ValueType2>& rhs) {
		return ( lhs.base() == rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator != (const RBIterator< ValueType1>& lhs, const RBIterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator != (const RBConstIterator< ValueType1>& lhs, const RBIterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator != (const RBIterator< ValueType1>& lhs, const RBConstIterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	}

	template <class ValueType1, class ValueType2>
	bool operator != (const RBConstIterator< ValueType1>& lhs, const RBConstIterator< ValueType2>& rhs) {
		return ( lhs.base() != rhs.base());
	}
}
#endif