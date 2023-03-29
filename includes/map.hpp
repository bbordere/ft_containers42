#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iterator>

#include <memory>
#include "pair.hpp"
#include "RBTree.hpp"
#include "lexicalComp.hpp"
#include "RBIterator.hpp"
#include "reverseIterators.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef	ft::pair<const Key, T>		value_type;
			

			typedef Compare						key_compare;
			typedef Alloc						allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;


			typedef ft::RBIterator<value_type>		iterator;
			typedef ft::RBConstIterator<value_type> const_iterator;

			typedef ft::reverseIterator<iterator>		reverse_iterator;
			typedef ft::reverseIterator<const_iterator> const_reverse_iterator;
			
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t	size_type;


			class value_compare: public std::binary_function<value_type, value_type, bool>
			{
				private:
					friend class map;

				protected:
					key_compare comp;
					value_compare	(key_compare c) : comp(c) {}

				public:
  					typedef bool		result_type;
  					typedef value_type	first_argument_type;
  					typedef value_type	second_argument_type;
					bool operator()	(value_type const &x, value_type const &y) const
					{
						return (comp(x.first, y.first));
					}
			};

		private:
			typedef	RBNode<value_type>			node;
			typedef	node*						node_ptr;
			typedef RBTree<value_type, value_compare, allocator_type> treeType;			
			treeType	_tree;

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(treeType(value_compare(comp), alloc)) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(treeType(value_compare(comp), alloc))
			{
				insert(first, last);
			}

			map (map const &copy): _tree(copy._tree) {}

			map &operator=(map const &assign)
			{
				if (this != &assign)
					_tree = assign._tree;
				return (*this);
			}

			virtual ~map() {}

			/*ITERATORS*/			
			iterator begin(void)
			{
				return (_tree.begin());
			}

			const_iterator begin(void) const
			{
				return (_tree.begin());
			}

			iterator end(void)
			{
				return (_tree.end());
			}

			const_iterator end(void) const
			{
				return (_tree.end());
			}

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(begin()));
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

			/*ELEMENT ACCESS*/
			mapped_type	&operator[](key_type const &key)
			{
				return (insert(ft::make_pair(key, mapped_type())).first->second);
			}

			mapped_type	&at(key_type const &key)
			{
				iterator i = find(key);
				if (i == end())
					throw (std::out_of_range("map::at"));
				return ((*i).second);
			}

			mapped_type const	&at(key_type const &key) const
			{
				const_iterator i = find(key);
				if (i == end())
					throw (std::out_of_range("map::at"));
				return ((*i).second);
			}


			/*MODIFIERS*/
			ft::pair<iterator, bool> insert(value_type const &val)
			{
				node_ptr pos = _tree.insert(val);
				if (pos == _tree._nil)
					return (ft::make_pair(find(val.first), false));
				return (ft::make_pair(iterator(pos), true));
			}

			iterator insert (iterator position, const value_type& val)
			{
				static_cast<void>(position);
				return (insert(val).first);
			}

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				_tree.insert(first, last);
			}

			void	erase(iterator position)
			{
				_tree.deleteNode(*position);
			}

			size_type erase(key_type const &key)
			{
				size_type oldSize = _tree._size;
				_tree.deleteNode(ft::make_pair(key, mapped_type()));
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

			void	swap(map &other)
			{
				_tree.swap(other._tree);
			}

			void	clear(void)
			{
				_tree.clearTree(_tree._root);
				_tree._root = _tree._nil;
				_tree._root->_parent = _tree._nil;
				_tree._size = 0;
			}

			key_compare key_comp(void) const
			{
				return (key_compare());
			}

			value_compare value_comp(void) const
			{
				return (value_compare(key_comp()));
			}

			iterator find(key_type const &key)
			{
				node_ptr ptr = _tree.search(ft::make_pair(key, T()));
				if (ptr == _tree._nil)
					return (_tree.end());
				return (iterator(ptr));
			}

			const_iterator find(key_type const &key) const
			{
				node_ptr ptr = _tree.search(ft::make_pair(key, T()));
				if (ptr == _tree._nil)
					return (_tree.end());
				return (const_iterator(ptr));
			}

			size_type	count(key_type const &k) const
			{
				return (_tree.search(ft::make_pair(k, mapped_type())) == _tree._nil ? 0 : 1);
			}

			iterator lower_bound(key_type const &key)
			{
				iterator res = _tree.lower_bound(ft::make_pair(key, T()));
				return (res);
			}
			
			const_iterator lower_bound(key_type const &key) const
			{
				const_iterator res = _tree.lower_bound(ft::make_pair(key, T()));
				return (res);
			}

			iterator upper_bound(key_type const &key)
			{
				iterator res = _tree.upper_bound(ft::make_pair(key, T()));
				return (res);
			}

			const_iterator upper_bound(key_type const &key) const
			{
				const_iterator res = _tree.upper_bound(ft::make_pair(key, T()));
				return (res);
			}

			ft::pair<iterator, iterator>	equal_range(key_type const &k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator(void) const
			{
				return (allocator_type());
			}

			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool	operator==(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y);

			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool	operator<(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y);
	};

	template <class _Key, class _T, class _Compare, class _Alloc>
	void swap(map<_Key, _T, _Compare, _Alloc> &lhs,map<_Key, _T, _Compare, _Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator==(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (x._tree == y._tree);
	}
	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator<(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (x._tree < y._tree);
	}

	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator!=(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (!(x == y));
	}

	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator<=(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (!(y < x));
	}

	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator>(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (y < x);
	}

	template <class _Key, class _T, class _Compare, class _Alloc>
	bool	operator>=(map<_Key, _T, _Compare, _Alloc> const &x, map<_Key, _T, _Compare, _Alloc> const &y)
	{
		return (!(x < y));
	}
}
#endif
