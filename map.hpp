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
	struct	KeyEqual<ft::pair<T, U>>
	{
		bool	operator()(ft::pair<T, U> const &lhs, ft::pair<T, U> const &rhs) const
		{
			return (lhs.first == rhs.first);
		}
	};

	template <class Key, class T, class Compare = pairKeyComp<Key, T>, class Alloc = std::allocator<ft::pair<Key, T> > >
	class map
	// RBTree<ft::pair<char, int> , KeyEqual<ft::pair<char, int>>, pairKeyComp<char, int>, QueueAllocator<RBNode<ft::pair<char, int>>>> tree;
	{
		public:
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef	ft::pair<const Key, T>		value_type;
			typedef Compare						key_compare;
			typedef pairKeyComp<Key, T>			val_compare;
			typedef Alloc						allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;


			typedef RBIterator<value_type>		iterator;
			typedef RBConstIterator<value_type> const_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef std::size_t												size_type;

		private:
			typedef	RBNode<value_type>			node;
			typedef	node*						node_ptr;

			typedef RBTree<value_type, KeyEqual<value_type>, key_compare> treeType;

		private:
		public:
			treeType _tree;

		public:
			map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):
					_tree(comp, alloc) {}

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

			iterator find(Key const &key)
			{
				node_ptr ptr = _tree.search(ft::make_pair(key, T()));
				if (ptr == _tree._nil)
					return (_tree.end());
				return (iterator(ptr));
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


			iterator begin(void)
			{
				return (_tree.begin());
			}

			iterator end(void)
			{
				return (_tree.end());
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
	};

}

template <class Key, class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, ft::map<Key, T, Compare, Allocator> &map)
{
	auto it = map.begin();
	stream << '{';
	while (it != map.end())
	{
		stream << *it << ", ";
		++it;
	}
	stream << '}';
	return (stream);
}
#endif