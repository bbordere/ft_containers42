#include "RBNode.hpp"
#include "RBTree.hpp"
#include "RBIterator.hpp"
#include "RBTreePrinter.hpp"
#include "pair.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "lexicalComp.hpp"
#include "map.hpp"
// #include "stack.hpp"

#include "customAllocators.hpp"
#include "randomAccessIterators.hpp"
#include "vector.hpp"
#include "reverseIterators.hpp"

#include <stack>

template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> const &vec)
{
	if (vec.empty())
	{
		stream << "[]";
		return (stream);
	}
	stream << '[';
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end() - 1; it++)
		stream << *it << ", ";
	stream << *(vec.end() - 1) << ']';
	return (stream);	
}

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


	// ft::map<int, std::string> myMap;
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
	// std::cout << myMap;

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
	// // ft::map<int, int> map;
	// // ft::map<int, int> map;
	// for (int i = 0; i < 50000; i++)
	// 	map.insert(ft::make_pair(i, i * 2));
	// std::cout << map._tree.isValidTree() << std::endl;
	// std::cout << map << std::endl;

	// ft::vector<float, QueueAllocator<float>> vec(100000, 56.323);
	// ft::vector<int> vec(static_cast<std::size_t>(100), 42);
	// ft::vector<int> vec2(vec.begin(), vec.end());
	// ft::vector<int> vec3;
	// vec3 = vec;
	// ft::vector<int> vec4(vec3);
	// std::cout << vec4 << std::endl;

	// ft::vector<float>::iterator test = vec.begin();
	// ft::vector<float>::const_iterator test2 = vec.begin();
	// std::cout << (test == test2) << std::endl;
	// std::cout << (test != test2) << std::endl;
	// std::cout << (test >= test2) << std::endl;
	// std::cout << (test > test2) << std::endl;
	// std::cout << (test <= test2) << std::endl;
	// std::cout << (test < test2) << std::endl;

	// ft::vector<int> v(vec.begin(), vec.end());

	// ft::vector<int> vec;
	// for (int i = 0; i < 50; i++)
	// 	vec.push_back(i % 2);
	// std::cout << vec << std::endl;
	// vec.resize(55);
	// std::cout << vec << std::endl;
	// std::cout << vec.size() << std::endl;
	// vec.resize(1);
	// std::cout << vec << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;

	// ft::vector<int> vec;
	// for (int i = 0; i < 50; i++)
	// 	vec.push_back(i);
	// std::cout << vec.back() << std::endl;
	// vec.pop_back();
	// std::cout << vec.back() << std::endl;
	// std::cout << vec << std::endl;

	// ft::vector<int> vec;
	// for (int i = 0; i < 12; i++)
	// 	vec.push_back(i);
	// std::cout << vec << std::endl;
	// vec.insert(vec.begin(), 5, 42);
	// std::cout << vec << std::endl;
	// vec.insert(vec.begin(), 56);
	// std::cout << vec << std::endl;
	// vec.insert(vec.end(), 10, 6969);
	// std::cout << vec << std::endl;

	// ft::vector<int> vec;
	// for (int i = 0; i < 10; i++)
	// 	vec.push_back(i);
	// ft::vector<int> fill(15, 69);

	// vec.insert(vec.end(), fill.begin(), fill.end());
	// std::cout << vec << std::endl;
	// ft::vector<int> first;
	// ft::vector<int> second;
	// ft::vector<int> third;

	// first.assign (7,100);             // 7 ints with a value of 100

	// ft::vector<int>::iterator it;
	// it=first.begin()+1;

	// second.assign (it,first.end()-1); // the 5 central values of first

	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);   // assigning from array.

	// std::cout << "Size of first: " << int (first.size()) << '\n';
	// std::cout << first << std::endl;
	// std::cout << "Size of second: " << int (second.size()) << '\n';
	// std::cout << second << std::endl;
	// std::cout << "Size of third: " << int (third.size()) << '\n';
	// std::cout << third << std::endl;

	// ft::vector<int> myvector;

	// // set some values (from 1 to 10)
	// for (int i=1; i<=10; i++) myvector.push_back(i);

	// // erase the 6th element
	// myvector.erase (myvector.begin()+5);

	// // erase the first 3 elements:
	// myvector.erase (myvector.begin(),myvector.begin()+3);

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); ++i)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// ft::vector<int> foo (3,100);   // three ints with a value of 100
	// ft::vector<int> bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (unsigned i=0; i<foo.size(); i++)
	// std::cout << ' ' << foo[i];
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (unsigned i=0; i<bar.size(); i++)
	// std::cout << ' ' << bar[i];
	// std::cout << '\n';

	// ft::vector<int> foo (3,100);   // three ints with a value of 100
	// ft::vector<int> bar (3,100);   // two ints with a value of 200

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	// unsigned int i;
	// ft::vector<int> foo (3,100);   // three ints with a value of 100
	// ft::vector<int> bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
	// std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
	// std::cout << ' ' << *it;
	// std::cout << '\n';
	

	// ft::stack<int> foo;
	// ft::stack<int> bar;

	// foo.push(12);
	// bar.push(12);

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	return 0;
}

