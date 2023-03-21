#ifndef __SET_HPP__
#define __SET_HPP__

#include "RBTree.hpp"
#include "lexicalComp.hpp"
#include "RBIterator.hpp"
#include "reverseIterators.hpp"
#include <memory>

namespace ft
{
	template <class T, class Compare=std::less<T>, class Alloc=std::allocator<T> >
	class set
	{
		public:
			typedef	T 			value_type;
			typedef	T 			key_type;
			typedef Compare		key_compare;
			typedef Compare		value_compare;
			typedef Alloc 		allocator_type;

			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;

			typedef RBConstIterator<value_type>					iterator;
			typedef RBConstIterator<value_type>					const_iterator;

			typedef ft::reverseIterator<iterator>		reverse_iterator;
			typedef ft::reverseIterator<const_iterator> const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;

		private:
			typedef RBTree<value_type, value_compare, allocator_type>	treeType;
			typedef	RBNode<value_type>*									node_ptr;

			treeType	_tree;
		
		public:
			explicit set(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()): _tree(comp, alloc) {}

			template <class It>
			set (It first, It last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()): _tree(comp, alloc)
			{
				insert(first, last);
			}

			set(set const &copy): _tree(copy._tree) {}

			set &operator=(set const &assign)
			{
				if (this != &assign)
					_tree = assign._tree;
				return (*this);
			}

			virtual ~set() {}

			/*ITERATORS*/
			iterator begin(void)
			{
				return (_tree.begin());
			}

			iterator end(void)
			{
				return (_tree.end());
			}

			const_iterator begin(void) const
			{
				return (_tree.begin());
			}

			const_iterator end(void) const
			{
				return (_tree.end());
			}

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rbegin(void) const
			{
				return (_tree.end());
			}

			const_reverse_iterator rend(void) const
			{
				return (_tree.begin());
			}

			/*CAPACITY*/
			bool	empty(void) const
			{
				return (_tree._root == _tree._nil);
			}

			size_type	size(void) const
			{
				return (_tree._size);
			}

			size_type	max_size(void) const
			{
				return (_tree._alloc.max_size());
			}

			/*MODIFIERS*/
			ft::pair<iterator, bool> insert(value_type const &val)
			{
				node_ptr pos = _tree.insert(val);
				if (pos == _tree._nil)
					return (ft::make_pair(find(val), false));
				return (ft::make_pair(iterator(pos), true));
			}

			template <class InputIterator>			
			void	insert(InputIterator first, InputIterator last)
			{
				_tree.insert(first, last);
			}

			iterator insert (iterator position, const value_type& val)
			{
				static_cast<void>(position);
				return (insert(val).first);
			}

			void	erase(iterator position)
			{
				_tree.deleteNode(*position);
			}

			size_type erase(value_type const &key)
			{
				size_type oldSize = _tree._size;
				_tree.deleteNode(key);
				return (oldSize - _tree._size);
			}

			void	erase(iterator first, iterator last)
			{
				if (first == begin() && last == end())
				{
					clear();
					return;
				}
				while (first != last)
					erase(first++);
			}

			void swap(set &other)
			{
				_tree.swap(other._tree);
			}

			void clear(void)
			{
				_tree.clearTree(_tree._root);
				_tree._root = _tree._nil;
				_tree._root->_parent = _tree._nil;
				_tree._size = 0;
			}

			/*OBSERVERS*/

			key_compare key_comp(void) const
			{
				return (key_compare());
			}

			value_compare value_comp(void) const
			{
				return (value_compare());
			}

			/*OPERATIONS*/

			iterator find(value_type const &key) const
			{
				node_ptr ptr = _tree.search(key);
				if (ptr == _tree._nil)
					return (_tree.end());
				return (iterator(ptr));
			}

			size_type count(value_type const &val) const
			{
				return (_tree.search(val) == _tree._nil ? 0 : 1);
			}

			iterator lower_bound(value_type const &val) const
			{
				iterator res = _tree.lower_bound(val);
				return (res);
			}

			iterator upper_bound(value_type const &val) const
			{
				iterator res = _tree.upper_bound(val);
				return (res);
			}

			ft::pair<iterator, iterator> equal_range(value_type const &val) const
			{
				return (ft::make_pair(lower_bound(val), upper_bound(val)));
			}

			/*ALLOCATOR*/
			allocator_type get_allocator(void)
			{
				return (allocator_type());
			}

			template <class _T, class _Compare, class _Alloc>
			friend bool	operator==(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y);

			template <class _T, class _Compare, class _Alloc>
			friend bool	operator<(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y);
			
	};

	template <class _T, class _Compare, class _Alloc>
	void swap(set<_T, _Compare, _Alloc> &lhs,set<_T, _Compare, _Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

	template <class _T, class _Compare, class _Alloc>
	bool	operator==(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (x._tree == y._tree);
	}
	template <class _T, class _Compare, class _Alloc>
	bool	operator<(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (x._tree < y._tree);
	}

	template <class _T, class _Compare, class _Alloc>
	bool	operator!=(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (!(x == y));
	}

	template <class _T, class _Compare, class _Alloc>
	bool	operator<=(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (!(y < x));
	}

	template <class _T, class _Compare, class _Alloc>
	bool	operator>(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (y < x);
	}

	template <class _T, class _Compare, class _Alloc>
	bool	operator>=(set<_T, _Compare, _Alloc> const &x, set<_T, _Compare, _Alloc> const &y)
	{
		return (!(x < y));
	}
}

#endif