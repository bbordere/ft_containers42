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

	// RBTree<ft::pair<char, int> , KeyEqual<ft::pair<char, int>>, pairKeyComp<char, int>, QueueAllocator<RBNode<ft::pair<char, int>>>> tree;

	// typedef RBTree<int, ft::KeyEqual<int>, std::less<int>, QueueAllocator<RBNode<int>>> RBTCustom;
	// RBTCustom tree;

	// RBTree<int, KeyEqual<int>> tree;

	// std::srand(time(0));
	// // std::vector<int> values(25);
	// std::vector<int> values(25);
	// std::generate(values.begin(), values.end(), std::rand);

	// for (auto val : values)
	// 	tree.insert(val % 1024);
	// std::cout << tree;

	// std::cout <<(tree.isValidTree() ? "" : "NOT VALID");
	// std::cout << tree;

	// tree.insert(ft::make_pair('b', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('c', 1));
	// tree.insert(ft::make_pair('a', 23));
	// std::cout << tree;

	// std::cout << *tree.search(ft::make_pair('1', int())) << std::endl;
	// RBTCustom::iterator test = tree.begin();
	// while (test != tree.end())
	// {
	// 	std::cout << *test << std::endl;
	// 	test++;
	// }

	// ft::map<char, int> myMap;
	// for (char c = 'a'; c != 'z' + 1; c++)
	// 	myMap.insert(ft::make_pair(c, static_cast<int>(c)));
	// myMap.insert(ft::make_pair('a', 345));
	// std::cout << myMap << std::endl;
	// std::cout << myMap._tree <<(myMap._tree.isValidTree() ? "" : "NOT VALID") << std::endl;
	// // std::cout << myMap.size() << ' ' << myMap.max_size();

	// // std::cout << *myMap.lower_bound('b');
	// // std::cout << *myMap.upper_bound('d');

	// std::cout << myMap['a'];
	// myMap['0'];
	// std::cout << myMap['0'];
	// std::cout << myMap._tree ;

	// // ft::map<int, int> map;
	// // for (auto val : values)
	// // 	map.insert(ft::make_pair(val % 1024, val % 2048));
	// // std::cout << map << std::endl;


	// ft::map<int, std::string, std::less<ft::pair<int, std::string> >> myMap;
	// myMap.insert(ft::make_pair(1, "un"));
	// myMap.insert(ft::make_pair(2, "deux"));
	// myMap.insert(ft::make_pair(3, "trois"));
	// myMap.insert(ft::make_pair(4, "quatre"));
	// myMap.insert(ft::make_pair(5, "cinq"));
	// myMap.insert(ft::make_pair(6, "six"));
	// myMap.insert(ft::make_pair(7, "sept"));
	// myMap.insert(ft::make_pair(8, "huit"));
	// myMap.insert(ft::make_pair(9, "neuf"));
	// myMap.insert(myMap.begin(), ft::make_pair(10, "dix"));

	// // std::cout << myMap << std::endl;
	// // myMap.erase(myMap.begin());
	// // std::cout << myMap << std::endl;
	// // myMap.erase(5);
	// // std::cout << myMap << std::endl;
	// // myMap.erase(myMap.begin(), myMap.end());
	// // std::cout << myMap << std::endl;

	// // ft::map<int, std::string, std::less<ft::pair<int, std::string> >> myMap2;
	// // myMap2.swap(myMap);
	// std::cout << myMap << " " << myMap.count(11) << " " << myMap.count(5) << std::endl;

// 	ft::map<char,int> mymap;

//   mymap['x'] = 100;
//   mymap['y'] = 200;
//   mymap['z'] = 300;
//   auto test = mymap.begin();
// //   std::cout << *mymap.end()._ptr << std::endl;
// //   std::cout << mymap << std::endl;
// 	// std::cout << *test << std::endl;
// 	// --test;
// 	// std::cout << *test << std::endl;
//   // show content:
//   ft::map<char,int>::reverse_iterator rit;
//   for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
//     std::cout << rit->first << " => " << rit->second << '\n';
	// ft::map<int, int, std::less<ft::pair<int, int>>, QueueAllocator<ft::pair<int, int>> > map;
	ft::map<int, int> map;
	for (int i = 0; i < 500000; i++)
		map.insert(ft::make_pair(i, i * 2));
	std::cout << map._tree.isValidTree() << std::endl;



  return 0;
}

