#ifndef __RBTREE_ITERATOR_HPP__
#define __RBTREE_ITERATOR_HPP__

#include "RBNode.hpp"
#include "iterator_utils.hpp"

namespace ft
{
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

		public:
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

			iterator &operator=(iterator const &assign)
			{
				_ptr = assign._ptr;
				return (*this);
			}

			iterator	&operator++(void)
			{
				_ptr = node::_increment(_ptr);
				return (*this);
			}

			iterator	operator++(int)
			{
				iterator temp = *this;
				_ptr = node::_increment(_ptr);
				return (temp);
			}

			iterator	&operator--(void)
			{
				_ptr = node::_decrement(_ptr);
				return (*this);
			}

			iterator	operator--(int)
			{
				iterator temp = *this;
				_ptr = node::_decrement(_ptr);
				return (temp);
			}
			node_ptr base() const
			{
				return (_ptr);
			}

			friend bool	operator==(iterator const& x, iterator const& y) {
				return x.base() == y.base();
			}

			friend bool	operator!=(iterator const& x, iterator const& y) {
				return x.base() != y.base();
			}

			operator RBIterator<T const>(void) const
			{
				return (RBIterator<T const>(_ptr));
			}
	};


	template <class T>
	class RBConstIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef RBNode<T>				node;
			typedef	node*					node_ptr;
			typedef	T						value_type;
			typedef	const T&				reference;
			typedef	const T*				pointer;
			typedef RBIterator<T>			iterator;
			typedef RBConstIterator<T>		const_iterator;

		public:
			node_ptr _ptr;

		public:
			RBConstIterator(void): _ptr(NULL) {}
			RBConstIterator(node_ptr ptr): _ptr(ptr) {}
			RBConstIterator(const iterator &it): _ptr(it._ptr) {}

			reference operator*(void) const { return (_ptr->_val);}

			pointer operator->(void) const { return (&_ptr->_val);}

			const_iterator	&operator++(void)
			{
				_ptr = node::_increment(_ptr);
				return (*this);
			}

			const_iterator	operator++(int)
			{
				const_iterator temp = *this;
				_ptr = node::_increment(_ptr);
				return (temp);
			}

			const_iterator	&operator--(void)
			{
				_ptr = node::_decrement(_ptr);
				return (*this);
			}

			const_iterator	operator--(int)
			{
				const_iterator temp = *this;
				_ptr = node::_decrement(_ptr);
				return (temp);
			}
			node_ptr base() const
			{
				return (_ptr);
			}

			friend bool	operator==(const_iterator const& x, const_iterator const& y) {
				return x.base() == y.base();
			}

			friend bool	operator!=(const_iterator const& x, const_iterator const& y) {
				return x.base() != y.base();
			}

			operator RBIterator<T const>(void) const
			{
				return (RBIterator<T const>(_ptr));
			}
	};

	template <class Iter>
	class RBReverseIterator: public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category,
												typename ft::iterator_traits<Iter>::value_type,
												typename ft::iterator_traits<Iter>::difference_type,
												typename ft::iterator_traits<Iter>::pointer,
												typename ft::iterator_traits<Iter>::reference>
	{
		private:
			typedef typename ft::iterator_traits<Iter> _type;
		public:
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef Iter								iterator_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer 			pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

		protected:
			iterator_type	_it;
		
		public:
			RBReverseIterator(void): _it() {}
			RBReverseIterator(iterator_type it): _it(it) {}

			template<class It>
			RBReverseIterator(RBReverseIterator<It> const &copy)
			{
				*this = copy;
			}

			~RBReverseIterator() {}

			template<class It>
			RBReverseIterator<It>	&operator=(RBReverseIterator<It> const &assign)
			{
				if (*this != assign)
					this->_it = assign.base();
				return (*this);
			}

			iterator_type base(void) const
			{
				return (this->_it);
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

			RBReverseIterator &operator++(void)
			{
				--_it;
				return (*this);
			}

			RBReverseIterator operator++(int)
			{
				RBReverseIterator	tmp(*this);
				--_it;
				return (tmp);
			}

			RBReverseIterator &operator--(void)
			{
				++_it;
				return (*this);
			}

			RBReverseIterator operator--(int)
			{
				RBReverseIterator	tmp(*this);
				++_it;
				return (tmp);
			}

	
			template <class T>
			operator RBReverseIterator<T const>(void) const
			{
				return (RBReverseIterator<T const>(_it));
			}
	};

	template <class iter1, class iter2>
	bool operator==(const RBReverseIterator<iter1>& x, const RBReverseIterator<iter2>& y)
	{
		return (x.base() == y.base());
	}

	template <class iter1, class iter2>
	bool operator!=(const RBReverseIterator<iter1>& x, const RBReverseIterator<iter2>& y)
	{
		return (x.base() != y.base());
	}
}
#endif