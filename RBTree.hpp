#ifndef __RBTREE_HPP__
#define __RBTREE_HPP__

#include <memory>
#include "RBIterator.hpp"
#include <iostream>


template <class T, class KeyEqual, class Compare = std::less<T>, class Alloc = std::allocator<RBNode<T>>>
class RBTree
{

	public:
		typedef RBNode<T>	node;
		typedef	node		*node_ptr;
		typedef	T			value_type;
		typedef	Alloc		alloc_type;

		typedef	RBIterator<value_type>			iterator;


		typedef	RBIterator<value_type const>	const_iterator; // NOT WORKING NEED REWORK NODE STRUCTURE REWORK

	private:
	public:
		node_ptr	_root;
		node_ptr	_nil;
		alloc_type	_alloc;
		std::size_t	_size;
		Compare		_comp;
		KeyEqual	_keyEqual;

	RBTree(void): _alloc(alloc_type())
	{
		_nil = createNil();
		_comp = Compare();
		_root = _nil;
		_size = 0;
	}

	void	clearTree(node_ptr node)
	{
		if (node != _nil)
		{
			clearTree(node->_left);
			clearTree(node->_right);
			destroyNode(node);
			node = _nil;
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

	node_ptr	createNil(void)
	{
		node_ptr nill = _alloc.allocate(1);
		_alloc.construct(nill, value_type());
		nill->_color = BLACK;
		nill->_left = NULL;
		nill->_right = NULL;
		nill->_parent = NULL;
		return (nill);
	}

	node_ptr	createNode(value_type val, node_ptr parent)
	{
		node_ptr	newNode = _alloc.allocate(1);
		_alloc.construct(newNode, val, parent, RED);

		newNode->_left = _nil;
		newNode->_right = _nil;
		return (newNode);
	}

	node_ptr	search(value_type val)
	{
		node_ptr	node = _root;
		while (node != _nil)
		{
			if (_keyEqual(node->_val, val))
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
		node_ptr pos = search(val);
		if (pos != _nil)
			return (_nil);
		
		node_ptr parent = _nil;
		pos = _root;
		while (pos != _nil)
		{
			parent = pos;
			if (_comp(val, pos->_val))
				pos = pos->_left;
			else
				pos = pos->_right;
		}
		node_ptr newNode = createNode(val, parent);
		if (parent == _nil)
			_root = newNode;
		else if (newNode != _nil && parent != _nil && _comp(val, parent->_val))
			parent->_left = newNode;
		else
			parent->_right = newNode;
		fixInsert(newNode);
		return (newNode);
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
		_nil->_parent = _root;
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

	node_ptr	getMin(node_ptr	node)
	{
		node_ptr	temp = node;
		while(temp->_left != _nil)
			temp = temp->_left;
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
		_nil->_parent = _root;
		destroyNode(toDel);
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

#endif