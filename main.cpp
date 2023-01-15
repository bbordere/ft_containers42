#include "RBNode.hpp"
#include "RBTree.hpp"
#include "RBIterator.hpp"
#include "RBTreePrinter.hpp"
#include "pair.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "lexicalComp.hpp"
#include "map.hpp"

#include "customAllocators.hpp"


int main()
{
	// RBTree<int, std::less<int>, MyAllocator<RBNode<int>>> tree; //8,872,464
	// QueueAllocator<RBNode<int>> aloc;

	RBTree<ft::pair<char, int> , KeyEqual<ft::pair<char, int>>, pairKeyComp<char, int>, QueueAllocator<RBNode<ft::pair<char, int>>>> tree;
	// RBTree<int> tree;

	std::srand(time(0));
	// std::vector<int> values(25);
	std::vector<int> values(500);
	std::generate(values.begin(), values.end(), std::rand);

	// for (auto val : values)
	// 	tree.insert(ft::make_pair('a' + val % 25, val));

	// std::cout <<(tree.isValidTree() ? "" : "NOT VALID");
	// std::cout << tree;

	// tree.insert(ft::make_pair('b', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('a', 23));
	// std::cout << tree;

	// std::cout << *tree.search(ft::make_pair('1', int())) << std::endl;
	// // RBTree<int>::iterator test = tree.begin();
	// // while (test != tree.end())
	// // {
	// // 	std::cout << *test << std::endl;
	// // 	test++;
	// // }

	// ft::map<char, int> myMap;
	// myMap.insert(ft::make_pair('q', 45));
	// myMap.insert(ft::make_pair('a', 12));
	// myMap.insert(ft::make_pair('s', 34));
	// myMap.insert(ft::make_pair('f', 11));
	// myMap.insert(ft::make_pair('u', 45));
	// myMap.insert(ft::make_pair('u', 452));
	// std::cout << myMap;


	ft::map<char, int> map;
	for (auto val : values)
		map.insert(ft::make_pair('a' + (val % 26), val % 1024));
	std::cout << map << std::endl;

	return 0;
}
