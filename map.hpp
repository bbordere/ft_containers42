#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <memory>
#include "pair.hpp"
#include "RBTree.hpp"
#include "lexicalComp.hpp"
#include "RBIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
	class map
	// RBTree<ft::pair<char, int> , KeyEqual<ft::pair<char, int>>, pairKeyComp<char, int>, QueueAllocator<RBNode<ft::pair<char, int>>>> tree;
	{
		public:
			typedef RBTree<ft::pair<Key, T>, KeyEqual<ft::pair<Key, T>>, pairKeyComp<Key, T>> treeType;
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef	ft::pair<const Key, T> value_type;
			typedef RBIterator<ft::pair<Key, T>> iterator;
			typedef	RBNode<ft::pair<Key, T>> node;
			typedef	node*	node_ptr;

		private:
		public:
			treeType _tree;

		public:
			map(void) {}

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

			~map() {}

			iterator begin(void)
			{
				return (_tree.begin());
			}

			iterator end(void)
			{
				return (_tree.end());
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