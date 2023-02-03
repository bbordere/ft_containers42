#include <iostream>
#include <string>
#include <deque>

// #ifdef STD //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map.hpp"
// 	#include "stack.hpp"
// 	#include "vector.hpp"
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// // #define MAX_RAM 42949672
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	#ifdef STD
// 	std::cout << "STD" << '\n';
// 	#endif
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << '\n';
// 		std::cerr << "Provide a seed please" << '\n';
// 		std::cerr << "Count value:" << COUNT << '\n';
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << '\n';

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << '\n';
// 	return (0);
// }

// template <typename T, typename U>
// std::ostream &operator<<(std::ostream &stream, std::pair<T, U> const &pair)
// {
// 	stream << '(' << pair.first << ", " << pair.second << ')';
// 	return (stream);
// }

// #include <map>
// #include "RBTreePrinter.hpp"
// #include "set.hpp"
// #include <set>
// #include "customAllocators.hpp"
// int main(void)
// {
// 	std::vector<int> vec2;
// 	std::vector<int> vec1;

// 	for (int i = 0; i < 5000; i++)
// 		vec1.push_back(i);
// 	for (int i = 0; i < 500; i++)
// 		vec2 = vec1;
// }



// #include <iostream>
// #include <cstdlib>
// #include <sys/time.h>
// // #include <chrono> // can be used instead of sys/time.h, but is not c++98 compliant


// #define TESTED_NAMESPACE ft
// // #define STD 0
// #ifdef STD
// # undef TESTED_NAMESPACE
// # define TESTED_NAMESPACE std
// #include <vector>
// #include <map>
// #include <stack>
// #else

// #endif


// int main()
// {
// // # SET_TEST_START #
// 	size_t test_val; // uncomment all the commented lines until '# SET_TEST_END #' to enable custom testing for the vector
// 	// std::cout << "test value: ";
// 	// std::string test_str;
// 	// std::getline(std::cin, test_str);
// 	// if (test_str.length() == 0)
// 		test_val = 50000000;
// 	// else
// 	// 	test_val = std::atoll(test_str.c_str());

// 	// std::cout << "test value set: " << test_val << '\n';

// 	// std::cout << "resize value: ";
// 	size_t resize_val;
// 	// std::string resize_str;
// 	// std::getline(std::cin, resize_str);
// 	// if (resize_str.length() == 0)
// 		resize_val = 500000050;
// 	// else
// 	// 	resize_val = std::atoll(resize_str.c_str());

// 	// std::cout << "resize value set: " << resize_val << '\n';
// // # SET_TEST_END #

// 	struct timeval start, end;
// 	long seconds;
// 	long microseconds;

// 	std::cout << '\n'; << "----------------------------------------" << '\n'; << '\n';

// 	{
// 		// ##### Test of TESTED_NAMESPACE::vector #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::vector#####" << '\n';
// 		#else
// 			std::cout << "#####Test of the std::vector#####" << '\n';
// 		#endif

// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
// 		TESTED_NAMESPACE::vector< int > *vct_1;
// 		try
// 		{
// 			std::cout << "\tcreate vct_1 now with size " << test_val << '\n';
// 			vct_1 = new TESTED_NAMESPACE::vector< int >(test_val);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << "\tvct_1 exception caught!!!! " << e.what() << '\n';
// 			goto next_vct;
// 		}
// 		std::cout << "\tmax_size: " << vct_1->max_size() << '\n';
// 		std::cout << "\tvct_1 size: " << vct_1->size() << '\n';
// 		std::cout << "\tvct_1 capacity: " << vct_1->capacity() << '\n';
// 		try
// 		{
// 			std::cout << "\tresizing vct_1 now to " << resize_val << '\n';
// 			vct_1->resize(resize_val);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << "\tvct_1 exception caught!!!! " << e.what() << '\n';
// 		}
// 		std::cout << "\tvct_1 size: " << vct_1->size() << '\n';
// 		std::cout << "\tvct_1 capacity: " << vct_1->capacity() << '\n';

// 		std::cout << "\tdeleting vct_1 now" << '\n';

// 		delete vct_1;
// 		vct_1 = NULL;

// 		next_vct:
// 		TESTED_NAMESPACE::vector<int> vct_2;
// 		TESTED_NAMESPACE::vector< int >::iterator it;
// 		std::cout << "\n\tfilling vct_2 now" << '\n';
// 		for (size_t i = 0; i < test_val * 2; ++i)
// 		{
// 			try
// 			{
// 				vct_2.push_back(i);
// 			}
// 			catch (std::exception &e)
// 			{
// 				std::cerr << "\tvct_2 exception caught!!!! " << e.what() << '\n';
// 				break ;
// 			}
// 		}
// 		std::cout << "\tvct_2 size: " << vct_2.size() << '\n';
// 		std::cout << "\tvct_2 capacity: " << vct_2.capacity() << '\n';
// 		it = vct_2.begin();
// 		std::cout << "\tprinting the first 5 elements of vct_1" << '\n';
// 		for (size_t i = 0; i < 5 && it != vct_2.end(); ++i)
// 			std::cout << "\telem " << i << ": " << *it++ << '\n';

// 		std::cout << "\terasing vct_2 now" << '\n';
// 		vct_2.erase(vct_2.begin(), vct_2.end());
// 		std::cout << "\tvct_2 size: " << vct_2.size() << '\n';
// 		std::cout << "\tvct_2 capacity: " << vct_2.capacity() << '\n';

// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << '\n'; << "#####ft::vector: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#else
// 			std::cout << '\n'; << "#####std::vector: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#endif
// 	// # LEAK_CHECK_START # //when checking, make sure fsanitize is disabled in the makefile CXXFLAGS
// 		#ifdef LEAK
// 			#ifndef STD
// 				system("leaks ft_containers | tail -3");
// 			#else
// 				system("leaks std_containers | tail -3");
// 			#endif
// 		#endif
// 	// # LEAK_CHECK_END #
// 	}

// 	std::cout << '\n'; << "----------------------------------------" << '\n'; << '\n';

// 	{
// 		// ##### Test of TESTED_NAMESPACE::stack #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::stack#####" << '\n';
// 		#else
// 			std::cout << "#####Test of the std::stack#####" << '\n';
// 		#endif
// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

// 		std::cout << "\tcreate st_1" << '\n';
// 		TESTED_NAMESPACE::stack<int>st_1;

// 		std::cout << "\tst_1 size: " << st_1.size() << '\n';

// 		std::cout << "\tfill with " << test_val << " elements" << '\n';
// 		for (size_t i = 0; i < test_val; i++)
// 			st_1.push(i + 42);

// 		std::cout << "\tst_1 size: " << st_1.size() << '\n';

// 		std::cout << "\tpopping all elements" << '\n';
// 		for (size_t i = 0; i < test_val; i++)
// 			st_1.pop();

// 		std::cout << "\tst_1 size: " << st_1.size() << '\n'; << '\n';

// 		std::cout << "\tcreate st_2" << '\n';
// 		TESTED_NAMESPACE::stack<int> *st_2 = new TESTED_NAMESPACE::stack<int>;

// 		std::cout << "\tst_2 size: " << st_2->size() << '\n';

// 		std::cout << "\tfill with " << test_val * 2 << "elements" << '\n';
// 		for (size_t i = 0; i < test_val * 2 ; i++)
// 			st_2->push(i + 42);

// 		std::cout << "\tst_2 size: " << st_2->size() << '\n';

// 		std::cout << "\tpopping half of the elements" << '\n';
// 		for (size_t i = 0; i < test_val; i++)
// 			st_2->pop();

// 		std::cout << "\tst_2 size: " << st_2->size() << '\n';
// 		std::cout << "\tremaining elements should be handled by the destructor" << '\n';
// 		delete st_2;
// 		st_2 = NULL;

// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << '\n'; << "#####ft::stack: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#else
// 			std::cout << '\n'; << "#####std::stack: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#endif
// 	// # LEAK_CHECK_START # //when checking, make sure fsanitize is disabled in the makefile CXXFLAGS
// 		#ifdef LEAK
// 			#ifndef STD
// 				system("leaks ft_containers | tail -3");
// 			#else
// 				system("leaks std_containers | tail -3");
// 			#endif
// 		#endif
// 	// # LEAK_CHECK_END #
// 	}

// 	std::cout << '\n'; << "----------------------------------------" << '\n'; << '\n';

// 	{
// 		// ##### Test of TESTED_NAMESPACE::map #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::map#####" << '\n';
// 		#else
// 			std::cout << "#####Test of the std::map#####" << '\n';
// 		#endif

// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

// 		TESTED_NAMESPACE::map<int, int> *map_1 = new TESTED_NAMESPACE::map<int, int>;
// 		std::cout << "\tinserting " << test_val / 100 << " elements into map_1" << '\n';
// 		for (size_t i = 0; i < test_val / 100; ++i)
// 		{
// 			map_1->insert(TESTED_NAMESPACE::make_pair(i, i + 1));
// 		}
// 		std::cout << "\tmax_size: " << map_1->max_size() << '\n';
// 		std::cout << "\tmap size: " << map_1->size() << '\n';

// 		std::cout << "\titerating over map using the iterator" << '\n';
// 		TESTED_NAMESPACE::map<int, int>::const_iterator it = map_1->begin();
// 		for (size_t i = 0; i < 15 && it != map_1->end(); ++i)
// 		{
// 			std::cout << "\tkey: " << it->first << "\tvalue: " << it->second << '\n';
// 			++it;
// 		}
// 		std::cout << "\toutput for adding `make_pair(0, 55)`, a duplicate element(this output is a bool): " << map_1->insert(TESTED_NAMESPACE::make_pair(0, 55)).second << '\n';
// 		std::cout << "\tthe insertion of duplicate elements should not change the value of the key:" << '\n';
// 		it = map_1->begin();
// 		std::cout << "\tkey: " << it->first << "\tvalue: " << it->second << '\n';
// 		std::cout << "\tmap size: " << map_1->size() << '\n';
// 		std::cout << "\tthe deletion of the elements is now up to the destructor" << '\n';
// 		delete map_1;
// 		map_1 = NULL;

// 		TESTED_NAMESPACE::map<int, int> map_2;
// 		std::cout << "\tinserting " << test_val / 100 << " elements into map_2" << '\n';
// 		for (size_t i = 0; i < test_val / 100; ++i)
// 		{
// 			map_2.insert(TESTED_NAMESPACE::make_pair(i, i + 1));
// 		}
// 		std::cout << "\tmax_size: " << map_2.max_size() << '\n';
// 		std::cout << "\tmap size: " << map_2.size() << '\n';

// 		std::cout << "\titerating over map using the iterator" << '\n';
// 		TESTED_NAMESPACE::map<int, int>::const_iterator it_2 = map_2.begin();
// 		for (size_t i = 0; i < 15 && it_2 != map_2.end(); ++i)
// 		{
// 			std::cout << "\tkey: " << it_2->first << "\tvalue: " << it_2->second << '\n';
// 			++it_2;
// 		}
// 		std::cout << "\toutput for adding `make_pair(0, 55)`, a duplicate element(this output is a bool): " << map_2.insert(TESTED_NAMESPACE::make_pair(0, 55)).second << '\n';
// 		std::cout << "\tthe insertion of duplicate elements should not change the value of the key" << '\n';
// 		it_2 = map_2.begin();
// 		std::cout << "\tkey: " << it_2->first << "\tvalue: " << it_2->second << '\n';
// 		std::cout << "\tmap size: " << map_2.size() << '\n';
// 		std::cout << "\tclearing map_2" << '\n';
// 		map_2.clear();
// 		std::cout << "\tmap size: " << map_2.size();
// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << '\n'; << "#####ft::map: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#else
// 			std::cout << '\n'; << "#####std::map: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << '\n';
// 			// std::cout << '\n'; << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << '\n';
// 		#endif
// 	// # LEAK_CHECK_START # //when checking, make sure fsanitize is disabled in the makefile CXXFLAGS
// 		#ifdef LEAK
// 			#ifndef STD
// 				system("leaks ft_containers | tail -3");
// 			#else
// 				system("leaks std_containers | tail -3");
// 			#endif
// 		#endif
// 	// # LEAK_CHECK_END #
// 	}

// 	std::cout << '\n'; << "----------------------------------------" << '\n'; << '\n';

// 	return (0);
// }

#include "ft_containers.hpp"
#include "RBTreePrinter.hpp"
#include <bits/stdc++.h>
template <class T, class Key, class Compare, class Allocator>

std::ostream &operator<<(std::ostream &stream, std::map<Key, T, Compare, Allocator> &map)
{
	stream << '{';
	if (map.empty())
	{
		stream << '}';
		return (stream);		
	}
	typename std::map<Key, T, Compare, Allocator>::iterator pair = map.begin();
	for (std::size_t i = 0; i < map.size() - 1; i++)
	{
		stream << '\'' << (*pair).first << "': " << (*pair).second << ", ";
		++pair;
	}
	stream << '\'' << (*pair).first << "': " << (*pair).second << '}';
	return (stream);
}

template <class T, class Compare, class Allocator>
std::ostream &operator<<(std::ostream &stream, std::set<T, Compare, Allocator> const &set)
{
	if (set.empty())
	{
		stream << "{}";
		return (stream);
	}
	stream << '{';
	typename std::set<T, Compare, Allocator>::const_iterator val = set.begin();
	for (std::size_t i = 0; i < set.size() - 1; i++)
	{
		stream << *val << ", ";
		++val;
	}
	stream << *val << '}';
	return (stream);
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> const &vec)
{
	if (vec.empty())
	{
		stream << "[]";
		return (stream);
	}
	stream << '[';
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end() - 1; it++)
		stream << *it << ", ";
	stream << *(vec.end() - 1) << ']';
	return (stream);	
}


struct dumb
{
	int i;
	double d;

	dumb()
	{
		i = 0;
		d = 0.0;
	}

	~dumb(){}
	dumb(int i, double d)
	{
		this->i = i;
		this->d = d;
	}

	bool operator==(dumb const &other)
	{
		return (other.i == i && other.d == d);
	}
};

bool operator==(dumb const &lhs, dumb const &rhs)
{
	return (lhs.d == rhs.d && lhs.i == rhs.i);
}

std::ostream &operator<<(std::ostream &ss, dumb const &d)
{
	ss << d.i << ' ' << d.d << ' ';
	return (ss);
}

typedef ft@ext:tonybaloney.vscode-pets::vector<dumb> _vec;
// typedef ft::vector<int> _vec;
typedef _vec::const_iterator const_it;
typedef _vec::iterator _it;

#include "customAllocators.hpp"
int main(void)
{
	// ft::map<char, int> map;
	// dumb test = {};
	// test.str = "Ceci est un test";
	// std::cout << test << '\n';

	_vec vec(500000);
	_vec vec2;

	for (int i = 0; i < 500000; i++)
		vec.push_back(dumb(i, (double)(i * 2)));
		// vec[i] = i;

	for (int i = 0; i < 1; i++)
	{
		vec2 = vec;
		// std::cout << std::boolalpha << (vec == vec2) << '\n';
	}
	
	// std::cout << map << '\n';
	// std::cout << vec2 << '\n';


	// std::cout << (map['a'] = 97) << std::endl;
	// std::cout << (map['a'] = 97) << std::endl;
	// std::cout << (map['a'] = 97) << std::endl;
	// std::cout << (map['a'] = 97) << std::endl;
	// std::cout << (map['a'] = 97) << std::endl;
	// std::cout << (map['b'] = 96) << std::endl;
	// std::cout << map << std::endl;

	// _set set;
	// for (int i = 0; i < 10; i++)
	// 	set.insert(i);
	// std::cout << *set.find(1) << std::endl;


	// _vec vct(5);
	// _vec vct2;
	// const int cut = 3;
	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 7;
	// std::cout << vct << std::endl;
	// std::cout << vct.size() << std::endl;
	// vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	// std::cout << vct2 << std::endl;
	// std::cout << vct2.size() << std::endl;

// 	std::map<int, int> map;
// 	for (int i = 0; i < 50000; i++)
// 		map.insert(std::make_pair(i, i * 2));
// 	std::map<int, int> map2(map);


//  	ft::map<int, char> alice;
// 	alice.insert(ft::make_pair(1, 'a'));
// 	alice.insert(ft::make_pair(2, 'b'));
// 	alice.insert(ft::make_pair(3, 'c'));

//  	ft::map<int, char> bob;
// 	bob.insert(ft::make_pair(7, 'Z'));
// 	bob.insert(ft::make_pair(8, 'Y'));
// 	bob.insert(ft::make_pair(9, 'X'));
// 	bob.insert(ft::make_pair(10, 'W'));

// 	ft::map<int, char> eve;
// 	eve.insert(ft::make_pair(1, 'a'));
// 	eve.insert(ft::make_pair(2, 'b'));
// 	eve.insert(ft::make_pair(3, 'c'));
	
	
//    std::cout << std::boolalpha;
 
//     // Compare non equal containers
//     std::cout << "alice == bob returns " << (alice == bob) << '\n';
//     std::cout << "alice != bob returns " << (alice != bob) << '\n';
//     std::cout << "alice <  bob returns " << (alice < bob) << '\n';
//     std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
//     std::cout << "alice >  bob returns " << (alice > bob) << '\n';
//     std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
//     std::cout << '\n';
 
//     // Compare equal containers
//     std::cout << "alice == eve returns " << (alice == eve) << '\n';
//     std::cout << "alice != eve returns " << (alice != eve) << '\n';
//     std::cout << "alice <  eve returns " << (alice < eve) << '\n';
//     std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
//     std::cout << "alice >  eve returns " << (alice > eve) << '\n';
//     std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	// ft::map<int, int>::const_iterator end = ap2.end();
	// for (ft::map<int, int>::const_iterator it = ap2.begin(); it != ap2.end(); it++)
		// std::cout << &it << " " << &end << std::endl;
	

	// for (int i = 0; i < 10; i++)
	// {
	// 	map.insert(ft::make_pair(i * 2, i));
	// }
	// for (ft::map<int, int>::const_reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
	// 	std::cout << *it << '\n';
	// for (ft::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
	// 	(*it).second += 42;
	// for (ft::map<int, int>::const_reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
	// 	std::cout << *it << '\n';
	// ft::vector<int> vec;
	// for (int i = 0; i < 25; i++)
	// 	vec.push_back(i);
	// ft::vector<int>::const_reverse_iterator it = vec.rbegin();
	// for (ft::vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	// 	std::cout << *it << '\n';
	// for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	// 	(*it) += 42;
	// for (ft::vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	// 	std::cout << *it << '\n';

	// ft::set<int> set;
	// std::set<int> setSTD;
	// for (int i = 0; i < 500000; i++)
	// {
	// 	setSTD.insert(i);
	// 	set.insert(i);
	// }
	// std::set<int>::iterator itSTD = setSTD.begin();
	// for (ft::set<int>::iterator it = set.begin(); it != set.end(); it++)
	// {
	// 	if (*itSTD != *it)
	// 		std::cout << "C LA MERDE" << std::endl;
	// 	itSTD++;
	// }
}