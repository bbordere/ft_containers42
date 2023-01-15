#ifndef __RBNODE_HPP__
#define __RBNODE_HPP__

#include <ostream>

enum {BLACK, RED};
enum {LEFT, RIGHT};

template <typename T>
struct RBNode
{
	typedef T 			value_type;
	typedef RBNode<T>	*node_ptr;
	typedef RBNode<T>	node;

	value_type	_val;
	node_ptr	_parent;
	node_ptr	_left;
	node_ptr	_right;
	bool		_color;

	RBNode(void): _val(value_type()), _parent(NULL), _left(NULL), _right(NULL), _color(RED) {}

	RBNode(value_type const &val, node_ptr parent, bool color): _val(val), _parent(parent), _left(NULL), _right(NULL), _color(color) {}


	RBNode(value_type const &val): _val(val), _parent(NULL), _left(NULL), _right(NULL), _color(RED) {}

	RBNode(node const &copy): _val(copy._val), _parent(copy._parent), _left(copy._left), _right(copy._right), _color(copy._color) {}
	RBNode(node const *copy): _val(copy->_val), _parent(copy->_parent), _left(copy->_left), _right(copy->_right), _color(copy->_color) {}

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