#ifndef __RBTREE_HPP__
#define __RBTREE_HPP__

#include <memory>
#include "RBIterator.hpp"
#include "lexicalComp.hpp"
#include "is_integral.hpp"
#include <iostream>


template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
struct RBTree
{
	typedef RBNode<T>	node_t;
	typedef	node_t		*node_ptr;
	typedef	T			value_type;
	typedef	Alloc		alloc_type;

	typedef	ft::RBIterator<value_type>			iterator;
	typedef	ft::RBConstIterator<value_type>		const_iterator;

	typedef typename Alloc::template rebind<RBNode<value_type> >::other	node_allocator;

	node_ptr	_root;
	node_ptr	_nil;
	node_allocator	_alloc;
	std::size_t	_size;
	Compare		_comp;

	RBTree(void): _alloc(node_allocator())
	{
		_nil = createNil();
		_root = _nil;
		_comp = Compare();
		_size = 0;
	}

	explicit RBTree(Compare const &comp, Alloc const& alloc = node_allocator()): _alloc(alloc), _comp(comp)
	{
		_nil = createNil();
		_root = _nil;
		_size = 0;	
	}

	RBTree(RBTree const &copy): _alloc(copy._alloc), _comp(copy._comp)
	{
		_nil = createNil();
		_root = _nil;
		_size = 0;
		*this = copy;
	}

	void	_dupTree(node_ptr &root, node_ptr parent, node_ptr otherRoot, node_ptr otherNil)
	{
		if (otherRoot == otherNil)
		{
			root = _nil;
			return;
		}
		root = createNode(otherRoot->_val, otherRoot->_color);
		root->_parent = parent;
		_dupTree(root->_left, root, otherRoot->_left, otherNil);
		_dupTree(root->_right, root, otherRoot->_right, otherNil);
	}

	RBTree &operator=(RBTree const &assign)
	{
		if (this != &assign)
		{
			if (_root != _nil)
			{
				clearTree(_root);
				_root = _nil;
			}
			if (assign._root != assign._nil)
				_dupTree(_root, _nil, assign._root, assign._nil);
			_nil->_parent = getMax(_root);
			_size = assign._size;
		}
		return (*this);
	}

	void	clearTree(node_ptr node)
	{
		if (node != _nil)
		{
			clearTree(node->_left);
			clearTree(node->_right);
			destroyNode(node);
		}
	}
	
	~RBTree(void)
	{
		clearTree(_root);
		destroyNode(_nil);
	}

	void	destroyNode(node_ptr node)
	{
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	void swap(RBTree &other)
	{
		std::swap(_root, other._root);
		std::swap(_nil, other._nil);
		std::swap(_alloc, other._alloc);
		std::swap(_size, other._size);
		std::swap(_comp, other._comp);
	}

	node_ptr	createNil(void)
	{
		node_ptr nill = _alloc.allocate(1, _nil);
		_alloc.construct(nill, value_type());
		nill->_color = BLACK;
		nill->_left = NULL;
		nill->_right = NULL;
		nill->_parent = NULL;
		return (nill);
	}

	node_ptr	createNode(value_type val, node_ptr parent)
	{
		node_ptr	newNode = _alloc.allocate(1, _nil);
		_alloc.construct(newNode, val);
		newNode->_parent = parent;
		newNode->_left = _nil;
		newNode->_right = _nil;
		return (newNode);
	}

	node_ptr	createNode(value_type val, bool color)
	{
		node_ptr	newNode = _alloc.allocate(1, _nil->_parent);
		_alloc.construct(newNode, val);
		newNode->_parent = _nil;
		newNode->_left = _nil;
		newNode->_right = _nil;
		newNode->_color = color;
		return (newNode);
	}

	node_ptr	search(value_type const &val) const
	{
		node_ptr	node = _root;
		while (node != _nil)
		{
			if (!_comp(val, node->_val) && !_comp(node->_val, val))
				return (node);
			else if (_comp(node->_val, val))
				node = node->_right;
			else
				node = node->_left;
		}
		return (_nil);
	}

	node_ptr	insert(value_type val)
	{
		node_ptr parent = _nil;
		node_ptr pos = _root;
		while (pos != _nil)
		{
			parent = pos;
			if (_comp(val, pos->_val))
				pos = pos->_left;
			else if (_comp(pos->_val, val))
				pos = pos->_right;
			else
				return (_nil);
		}
		node_ptr newNode = createNode(val, parent);
		if (parent == _nil)
			_root = newNode;
		else if (newNode != _nil && parent != _nil && _comp(val, parent->_val))
			parent->_left = newNode;
		else
			parent->_right = newNode;
		fixInsert(newNode);
		_nil->_parent = getMax(_root);
		_size++;
		return (newNode);
	}

	template <class InputIterator>
	void	insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
	}

	void lRotate(node_ptr x)
	{
		node_ptr y;
		y = x->_right;
		x->_right = y->_left;
		if (y->_left != _nil)
			y->_left->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent == _nil)
			_root = y;
		else
		{
			if (x == x->_parent->_left)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
		}
		y->_left = x;
		x->_parent = y;
	}

	void rRotate(node_ptr x)
	{
		node_ptr y;
		y = x->_left;
		x->_left = y->_right;
		if (y->_right != _nil)
			y->_right->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent == _nil)
			_root = y;
		else
		{
			if (x == x->_parent->_right)
				x->_parent->_right = y;
			else
				x->_parent->_left = y;
		}
		y->_right = x;
		x->_parent = y;
	}

	void	fixInsert(node_ptr node)
	{
		if (!_nil->_parent)
			_nil->_parent = node;
		else if (_nil->_parent && _comp(_nil->_parent->_val, node->_val))
			_nil->_parent = node;
		while (node->_parent->_color == RED)
		{
			if (node->_parent == node->_parent->_parent->_right)
			{
				node_ptr uncle = node->_parent->_parent->_left;
				if (uncle->_color == RED)
				{
					uncle->_color = BLACK;
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node = node->_parent->_parent;
				}
				else
				{
					if (node == node->_parent->_left)
					{
						node = node->_parent;
						rRotate(node);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					lRotate(node->_parent->_parent);
				}
			}
			else
			{
				node_ptr uncle = node->_parent->_parent->_right;
				if (uncle->_color == RED)
				{
					uncle->_color = BLACK;
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node = node->_parent->_parent;
				}
				else
				{
					if (node == node->_parent->_right)
					{
						node = node->_parent;
						lRotate(node);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					rRotate(node->_parent->_parent);
				}
			}
		}
		_root->_color = BLACK;
	}

	void	transplant(node_ptr u, node_ptr v)
	{
		if (u->_parent == _nil)
			_root = v;
		else if (u == u->_parent->_left)
			u->_parent->_left = v;
		else
			u->_parent->_right = v;
		v->_parent = u->_parent;
	}

	node_ptr	getMin(node_ptr	node) const
	{
		if (node == _nil)
			return (_nil);
		node_ptr	temp = node;
		while(temp->_left != _nil)
			temp = temp->_left;
		return (temp);
	}

	node_ptr	 getMax(node_ptr	node) const
	{
		if (node == _nil)
			return (_nil);
		node_ptr	temp = node;
		while(temp->_right != _nil)
			temp = temp->_right;
		return (temp);
	}

	node_ptr	delOneChild(node_ptr fix, node_ptr toDel)
	{
		if (toDel->_left == _nil)
		{
			fix = toDel->_right;
			transplant(toDel, fix);
		}
		else if (toDel->_right == _nil)
		{
			fix = toDel->_left;
			transplant(toDel, fix);
		}
		return (fix);
	}

	node_ptr	fixLeftCase(node_ptr node)
	{
		node_ptr	parent = node->_parent;
		node_ptr	s = parent->_right;

		if (s->_color == RED)
		{
			s->_color = BLACK;
			parent->_color = RED;
			lRotate(parent);
			s = parent->_right;
		}

		if (s->_left->_color == BLACK && s->_right->_color == BLACK)
		{
			s->_color = RED;
			node = parent;
		}
		else
		{
			if (s->_right->_color == BLACK)
			{
				s->_left->_color = BLACK;
				s->_color = RED;
				rRotate(s);
				s = parent->_right;
			}
			s->_color = parent->_color;
			parent->_color = BLACK;
			s->_right->_color = BLACK;
			lRotate(parent);
			node = _root;
		}
		return (node);
	}

	node_ptr	fixRightCase(node_ptr node)
	{
		node_ptr	parent = node->_parent;
		node_ptr	s = parent->_left;

		if (s->_color == RED)
		{
			s->_color = BLACK;
			parent->_color = RED;
			rRotate(parent);
			s = parent->_left;
		}

		if (s->_left->_color == BLACK && s->_right->_color == BLACK)
		{
			s->_color = RED;
			node = parent;
		}
		else
		{
			if (s->_left->_color == BLACK)
			{
				s->_right->_color = BLACK;
				s->_color = RED;
				lRotate(s);
				s = parent->_left;
			}
			s->_color = parent->_color;
			parent->_color = BLACK;
			s->_left->_color = BLACK;
			rRotate(parent);
			node = _root;
		}
		return (node);
	}

	void	fixDelete(node_ptr node)
	{
		while (node != _root && node->_color == BLACK)
		{
			if (node->_parent->_left == node)
				node = fixLeftCase(node);
			else
				node = fixRightCase(node);
		}
		node->_color = BLACK;
	}

	bool	deleteNode(value_type val)
	{
		node_ptr toDel = search(val);
		if (toDel == _nil)
			return (false);

		node_ptr fix = _nil;
		bool	oriColor = toDel->_color;
		if (toDel->_right == _nil || toDel->_left == _nil)
			fix = delOneChild(fix, toDel);
		else
		{
			node_ptr succ = getMin(toDel->_right);
			oriColor = succ->_color;
			fix = succ->_right;
			if (succ->_parent == toDel)
				fix->_parent = succ;
			else
			{
				transplant(succ, succ->_right);
				succ->_right = toDel->_right;
				succ->_right->_parent = succ;
			}
			transplant(toDel, succ);
			succ->_left = toDel->_left;
			succ->_left->_parent = succ;
			succ->_color = toDel->_color;
		}
		if (oriColor == BLACK)
			fixDelete(fix);
		destroyNode(toDel);
		_size--;
		_nil->_parent = getMax(_root);
		return (true);
	}

	iterator	begin(void)
	{
		return (iterator(getMin(_root)));
	}

	iterator	end(void)
	{
		return(iterator(_nil));
	}

	const_iterator	begin(void) const
	{
		return (const_iterator(getMin(_root)));
	}

	const_iterator	end(void) const
	{
		return(const_iterator(_nil));
	}

	iterator	lower_bound(value_type const &key)
	{
		iterator it = begin();
		while (it != end() && _comp(*it, key))
			++it;
		return (it);
	}

	const_iterator	lower_bound(value_type const &key) const
	{
		const_iterator it = begin();
		while (it != end() && _comp(*it, key))
			++it;
		return (it);
	}

	iterator	upper_bound(value_type const &key)
	{
		iterator it = begin();
		while (it != end() && (_comp(*it, key) || (!_comp(*it, key) && !_comp(key, *it))))
			++it;
		return (it);
	}

	const_iterator	upper_bound(value_type const &key) const
	{
		const_iterator it = begin();
		while (it != end() && (_comp(*it, key) || (!_comp(*it, key) && !_comp(key, *it))))
			++it;
		return (it);
	}


	int	getBlackHeight(node_ptr node)
	{
		if (node == _nil)
			return (0);
		int	 left = getBlackHeight(node->_left);
		int	 right = getBlackHeight(node->_right);
		int	 cur = node->_color == BLACK ? 1 : 0;
		if (left == -1 || right == -1 || left != right)
			return (-1);
		else
			return (left + cur);
	}

	bool redChildAreBlack(node_ptr node)
	{
		bool left = true;
		bool right = true;
		if (node == _nil)
			return (true);
		if (node->_color == RED)
		{
			if (node->_left != _nil)
				left = node->_left->_color == BLACK;
			if (node->_right != _nil)
				right = node->_right->_color == BLACK;
		}
		return (_root->_color == BLACK && right && left && redChildAreBlack(node->_left) && redChildAreBlack(node->_right));
	}

	bool isValidTree(void)
	{
		return (getBlackHeight(_root) >= 0 && redChildAreBlack(_root));
	}
};

template <class T, class Compare, class Alloc>
bool operator==(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (x._size == y._size && ft::equal(x.begin(), x.end(), y.begin()));
}

template <class T, class Compare, class Alloc>
bool operator!=(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (!(x == y));
}

template <class T, class Compare, class Alloc>
bool operator<(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
}

template <class T, class Compare, class Alloc>
bool operator<=(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (!(y < x));
}

template <class T, class Compare, class Alloc>
bool operator>(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (y < x);
}

template <class T, class Compare, class Alloc>
bool operator>=(RBTree<T, Compare, Alloc> const &x, RBTree<T, Compare, Alloc> const &y)
{
	return (!(x < y));
}


#endif

