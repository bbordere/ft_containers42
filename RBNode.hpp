#ifndef __RBNODE_HPP__
#define __RBNODE_HPP__

#include <ostream>

enum {BLACK, RED};
enum {LEFT, RIGHT};

template <typename T>
struct RBNode
{
	typedef T 			value_type;
	typedef RBNode<T>	node;
	typedef node		*node_ptr;

	value_type	_val;
	node_ptr	_parent;
	node_ptr	_left;
	node_ptr	_right;
	bool		_color;

	RBNode(void): _val(value_type()), _parent(NULL), _left(NULL), _right(NULL), _color(RED) {}

	RBNode(value_type const &val, node_ptr parent, bool color): _val(val), _parent(parent), _left(NULL), _right(NULL), _color(color) {}

	RBNode(value_type const &val): _val(val), _parent(NULL), _left(NULL), _right(NULL), _color(RED) {}

	node	&operator=(node const &assign)
	{
		_val = assign._val;
		_parent = assign._parent;
		_left = assign._left;
		_right - assign._right;
		_color = assign._color;
		return (*this);
	}

	node	&operator=(node const *assign)
	{
		_val = assign->_val;
		_parent = assign->_parent;
		_left = assign->_left;
		_right - assign->_right;
		_color = assign->_color;
		return (*this);
	}

	static	bool	_isNil(node_ptr node) {return (!node->_right && !node->_left);}

	static node_ptr	_increment(node_ptr node)
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

	static node_ptr	_decrement(node_ptr node)
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

	bool	operator==(node const &other) const {return (_val == other._val && _parent == other._parent);}
	bool	operator!=(node const &other) const {return (_val != other._val || _parent != other._parent);}

	bool	operator<(node const *other) const {return (_val < other->_val);}
	bool	operator<=(node const *other) const {return (_val <= other->_val);}
	bool	operator>(node const *other) const {return (_val > other->_val);}
	bool	operator>=(node const *other) const {return (_val >= other->_val);}
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, RBNode<T> const &node)
{
	stream << '{';
	stream << ", val: " << node._val;
	stream << ", left: " << reinterpret_cast<void *>(node._left);
	stream << ", right: " << reinterpret_cast<void *>(node._right);
	stream << ", parent: " << reinterpret_cast<void *>(node._parent);
	stream << ", color: " << node._color;
	stream << "}"; 
	return (stream); 
}


#endif