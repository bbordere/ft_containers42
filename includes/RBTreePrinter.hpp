#ifndef __PRINTER_HPP__
#define __PRINTER_HPP__

#include <iostream>
#include <string>
#include "RBTree.hpp"
#include "RBNode.hpp"

#define RED_COLOR "\e[0;31m"
#define BLACK_COLOR "\e[0;35m"
#define RESET_COLOR "\e[0;0m"

struct subTree
{
	subTree *_prev;
	std::string _str;

	subTree(subTree *prev, std::string str) : _prev(prev), _str(str)	{}
};

void printTrunks(std::ostream &stream, subTree *p)
{
	if (!p)
		return;
	printTrunks(stream, p->_prev);
	stream << p->_str;
}

template<typename T>
void printTree(std::ostream &stream, RBNode<T>* node, RBNode<T>* nil, subTree *prev, bool isLeft)
{
	if (node == nil)
		return;
	std::string prev_str = "    ";
	subTree sub = subTree(prev, prev_str);
	printTree(stream, node->_right, nil, &sub, true);
	if (!prev)
		sub._str = "———";
	else if (isLeft)
	{
		sub._str = ",———";
		prev_str = "   |";
	}
	else
	{
		sub._str = "`———";
		prev->_str = prev_str;
	}
	printTrunks(stream, &sub);
	stream << " " << (node->_color == RED ? RED_COLOR : BLACK_COLOR) <<  node->_val << RESET_COLOR << std::endl;
	if (prev)
		prev->_str = prev_str;
	sub._str = "   |";
	printTree(stream, node->_left, nil, &sub, false);
}

template <class T, class Compare, class Alloc>
std::ostream &operator<<(std::ostream &stream, RBTree<T, Compare, Alloc> & tree)
{
	printTree(stream, tree._root, tree._nil, NULL, false);
	stream << std::endl;
	return (stream);
}

#endif
