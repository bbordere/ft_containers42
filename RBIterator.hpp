#ifndef __RBTREE_ITERATOR_HPP__
#define __RBTREE_ITERATOR_HPP__

#include "RBNode.hpp"
#include "iterator_utils.hpp"


template <class T>
class RBIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
{
	public:
		typedef RBNode<T>		node;
		typedef	node*			node_ptr;
		typedef	T				value_type;
		typedef	T&				reference;
		typedef	T*				pointer;
		typedef RBIterator<T>	iterator;

	private:
		node_ptr _ptr;

	public:
		bool	_isNil(node_ptr node) {return (!node->_right && !node->_left);}

		RBIterator(void): _ptr(NULL) {}
		RBIterator(node_ptr ptr): _ptr(ptr) {}

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

		iterator	&operator++(void)
		{
			_ptr = _increment(_ptr);
			return (*this);
		}

		iterator	operator++(int)
		{
			iterator temp = *this;
			_ptr = _increment(_ptr);
			return (temp);
		}

		iterator	&operator--(void)
		{
			_ptr = _decrement(_ptr);
			return (*this);
		}

		iterator	operator--(int)
		{
			iterator temp = *this;
			_ptr = _decrement(_ptr);
			return (temp);
		}
		node_ptr base() const
		{
			return (_ptr);
		}

		operator RBIterator<T const>(void) const
		{
			return (RBIterator<T const>(this->_ptr));
		}

		friend bool	operator==(iterator const& x, iterator const& y) {
			return x.base() == y.base();
		}

		friend bool	operator!=(iterator const& x, iterator const& y) {
			return x.base() != y.base();
		}
};


#endif