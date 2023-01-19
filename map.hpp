#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <memory>
#include "pair.hpp"
#include "RBTree.hpp"
#include "lexicalComp.hpp"
#include "RBIterator.hpp"

namespace ft
{

	template <class T, class U>
	class pairKeyComp
	{
		public:
			bool	operator()(ft::pair<T, U> const &lhs, ft::pair<T, U> const &rhs) const
			{
				return (lhs.first < rhs.first);
			}
	};

	template <class T>
	struct	KeyEqual
	{
		bool	operator()(T const &x, T const &y) const
		{
			return (x == y);
		}
	};

	template <class T, class U>
	struct	KeyEqual<ft::pair<T, U> >
	{
		bool	operator()(ft::pair<T, U> const &lhs, ft::pair<T, U> const &rhs) const
		{
			return (lhs.first == rhs.first);
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
	class map
	{
		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef	ft::pair<Key, T>			value_type;
			typedef Compare						key_compare;
			typedef Alloc						allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;


			typedef RBIterator<value_type>		iterator;
			typedef RBConstIterator<value_type> const_iterator;

			typedef RBReverseIterator<iterator> reverse_iterator;
			typedef RBReverseIterator<const_iterator> const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;

			class value_compare: public std::binary_function <value_type, value_type, bool>
			{
				private:
					friend class map;

				protected:
					key_compare comp;
					value_compare	(key_compare c) : comp(c) {}

				public:
					bool operator()	(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			typedef	RBNode<value_type>			node;
			typedef	node*						node_ptr;

			typedef RBTree<value_type, value_compare, allocator_type> treeType;

		public:
			treeType _tree;

		public:
			map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(treeType(value_compare(comp), alloc)) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(comp, alloc)
			{
				insert(first, last);
			}

			map (map const &copy): _tree(copy._tree) {}

			map &operator=(map const &assign) {_tree = assign._tree;}

			~map() {}

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

			ft::pair<iterator, bool> insert(value_type const &val)
			{
				node_ptr pos = _tree.insert(val);
				if (pos == _tree._nil)
					return (ft::make_pair(find(val.first), false));
				return (ft::make_pair(find(val.first), true));
			}

			void	insert(iterator first, iterator last)
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

			void	erase(const_iterator position)
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

			void	erase(const_iterator first, const_iterator last)
			{
				if (first == begin() && last == end())
				{
					clear();
					return;
				}
				while (first != last)
					erase(first++);
			}

			void	clear(void)
			{
				_tree.clearTree(_tree._root);
				_tree._root = _tree._nil;
				_tree._root->_parent = _tree._nil;
			}

			void	swap(map &other)
			{
				_tree.swap(other._tree);
			}

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

			iterator lower_bound(key_type const &key)
			{
				iterator res = _tree.lower_bound(ft::make_pair(key, T()));
				return (res);
			}

			iterator upper_bound(key_type const &key)
			{
				iterator res = _tree.upper_bound(ft::make_pair(key, T()));
				return (res);
			}

			mapped_type	&operator[](key_type const &key)
			{
				node_ptr node = _tree.search(ft::make_pair(key, mapped_type()));
				if (node == _tree._nil)
					return (insert(ft::make_pair(key, mapped_type())).first->second);
				return (node->_val.second);
			}

			ft::pair<iterator, iterator>	equal_range(key_type const &k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			key_compare key_comp(void) const
			{
				return (key_compare());
			}

			value_compare val_comp(void) const
			{
				return (value_compare());
			}

			allocator_type get_allocator(void) const
			{
				return (allocator_type());
			}
	};

}

template <class Key, class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, ft::map<Key, T, Compare, Allocator> &map)
{
	stream << '{';
	if (map.empty())
	{
		stream << '}';
		return (stream);		
	}
	typename ft::map<Key, T, Compare, Allocator>::iterator pair = map.begin();
	for (std::size_t i = 0; i < map.size() - 1; i++)
	{
		stream << '\'' << (*pair).first << "': " << (*pair).second << ", ";
		++pair;
	}
	stream << '\'' << (*pair).first << "': " << (*pair).second << '}';
	return (stream);
}
#endif