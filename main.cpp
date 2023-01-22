#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
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
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

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
// 	std::cout << std::endl;
// 	return (0);
// }

template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, std::pair<T, U> const &pair)
{
	stream << '(' << pair.first << ", " << pair.second << ')';
	return (stream);
}

#include <map>
#include "RBTreePrinter.hpp"
#include "set.hpp"
#include <set>
#include "customAllocators.hpp"
int main(void)
{
	std::vector<int> vec2;
	std::vector<int> vec1;

	for (int i = 0; i < 5000; i++)
		vec1.push_back(i);
	for (int i = 0; i < 500; i++)
		vec2 = vec1;
}



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

// 	// std::cout << "test value set: " << test_val << std::endl;

// 	// std::cout << "resize value: ";
// 	size_t resize_val;
// 	// std::string resize_str;
// 	// std::getline(std::cin, resize_str);
// 	// if (resize_str.length() == 0)
// 		resize_val = 500000050;
// 	// else
// 	// 	resize_val = std::atoll(resize_str.c_str());

// 	// std::cout << "resize value set: " << resize_val << std::endl;
// // # SET_TEST_END #

// 	struct timeval start, end;
// 	long seconds;
// 	long microseconds;

// 	std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;

// 	{
// 		// ##### Test of TESTED_NAMESPACE::vector #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::vector#####" << std::endl;
// 		#else
// 			std::cout << "#####Test of the std::vector#####" << std::endl;
// 		#endif

// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
// 		TESTED_NAMESPACE::vector< int > *vct_1;
// 		try
// 		{
// 			std::cout << "\tcreate vct_1 now with size " << test_val << std::endl;
// 			vct_1 = new TESTED_NAMESPACE::vector< int >(test_val);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << "\tvct_1 exception caught!!!! " << e.what() << std::endl;
// 			goto next_vct;
// 		}
// 		std::cout << "\tmax_size: " << vct_1->max_size() << std::endl;
// 		std::cout << "\tvct_1 size: " << vct_1->size() << std::endl;
// 		std::cout << "\tvct_1 capacity: " << vct_1->capacity() << std::endl;
// 		try
// 		{
// 			std::cout << "\tresizing vct_1 now to " << resize_val << std::endl;
// 			vct_1->resize(resize_val);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << "\tvct_1 exception caught!!!! " << e.what() << std::endl;
// 		}
// 		std::cout << "\tvct_1 size: " << vct_1->size() << std::endl;
// 		std::cout << "\tvct_1 capacity: " << vct_1->capacity() << std::endl;

// 		std::cout << "\tdeleting vct_1 now" << std::endl;

// 		delete vct_1;
// 		vct_1 = NULL;

// 		next_vct:
// 		TESTED_NAMESPACE::vector<int> vct_2;
// 		TESTED_NAMESPACE::vector< int >::iterator it;
// 		std::cout << "\n\tfilling vct_2 now" << std::endl;
// 		for (size_t i = 0; i < test_val * 2; ++i)
// 		{
// 			try
// 			{
// 				vct_2.push_back(i);
// 			}
// 			catch (std::exception &e)
// 			{
// 				std::cerr << "\tvct_2 exception caught!!!! " << e.what() << std::endl;
// 				break ;
// 			}
// 		}
// 		std::cout << "\tvct_2 size: " << vct_2.size() << std::endl;
// 		std::cout << "\tvct_2 capacity: " << vct_2.capacity() << std::endl;
// 		it = vct_2.begin();
// 		std::cout << "\tprinting the first 5 elements of vct_1" << std::endl;
// 		for (size_t i = 0; i < 5 && it != vct_2.end(); ++i)
// 			std::cout << "\telem " << i << ": " << *it++ << std::endl;

// 		std::cout << "\terasing vct_2 now" << std::endl;
// 		vct_2.erase(vct_2.begin(), vct_2.end());;
// 		std::cout << "\tvct_2 size: " << vct_2.size() << std::endl;
// 		std::cout << "\tvct_2 capacity: " << vct_2.capacity() << std::endl;

// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << std::endl << "#####ft::vector: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
// 		#else
// 			std::cout << std::endl << "#####std::vector: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
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

// 	std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;

// 	{
// 		// ##### Test of TESTED_NAMESPACE::stack #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::stack#####" << std::endl;
// 		#else
// 			std::cout << "#####Test of the std::stack#####" << std::endl;
// 		#endif
// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

// 		std::cout << "\tcreate st_1" << std::endl;
// 		TESTED_NAMESPACE::stack<int>st_1;

// 		std::cout << "\tst_1 size: " << st_1.size() << std::endl;

// 		std::cout << "\tfill with " << test_val << " elements" << std::endl;
// 		for (size_t i = 0; i < test_val; i++)
// 			st_1.push(i + 42);

// 		std::cout << "\tst_1 size: " << st_1.size() << std::endl;

// 		std::cout << "\tpopping all elements" << std::endl;
// 		for (size_t i = 0; i < test_val; i++)
// 			st_1.pop();

// 		std::cout << "\tst_1 size: " << st_1.size() << std::endl << std::endl;

// 		std::cout << "\tcreate st_2" << std::endl;
// 		TESTED_NAMESPACE::stack<int> *st_2 = new TESTED_NAMESPACE::stack<int>;

// 		std::cout << "\tst_2 size: " << st_2->size() << std::endl;

// 		std::cout << "\tfill with " << test_val * 2 << "elements" << std::endl;
// 		for (size_t i = 0; i < test_val * 2 ; i++)
// 			st_2->push(i + 42);

// 		std::cout << "\tst_2 size: " << st_2->size() << std::endl;

// 		std::cout << "\tpopping half of the elements" << std::endl;
// 		for (size_t i = 0; i < test_val; i++)
// 			st_2->pop();

// 		std::cout << "\tst_2 size: " << st_2->size() << std::endl;
// 		std::cout << "\tremaining elements should be handled by the destructor" << std::endl;
// 		delete st_2;
// 		st_2 = NULL;

// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << std::endl << "#####ft::stack: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
// 		#else
// 			std::cout << std::endl << "#####std::stack: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
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

// 	std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;

// 	{
// 		// ##### Test of TESTED_NAMESPACE::map #####
// 		#ifndef STD
// 			std::cout << "#####Test of my ft::map#####" << std::endl;
// 		#else
// 			std::cout << "#####Test of the std::map#####" << std::endl;
// 		#endif

// 		gettimeofday(&start, NULL);
// 		// std::chrono::steady_clock::time_point end;
// 		// std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

// 		TESTED_NAMESPACE::map<int, int> *map_1 = new TESTED_NAMESPACE::map<int, int>;
// 		std::cout << "\tinserting " << test_val / 100 << " elements into map_1" << std::endl;
// 		for (size_t i = 0; i < test_val / 100; ++i)
// 		{
// 			map_1->insert(TESTED_NAMESPACE::make_pair(i, i + 1));
// 		}
// 		std::cout << "\tmax_size: " << map_1->max_size() << std::endl;
// 		std::cout << "\tmap size: " << map_1->size() << std::endl;

// 		std::cout << "\titerating over map using the iterator" << std::endl;
// 		TESTED_NAMESPACE::map<int, int>::const_iterator it = map_1->begin();
// 		for (size_t i = 0; i < 15 && it != map_1->end(); ++i)
// 		{
// 			std::cout << "\tkey: " << it->first << "\tvalue: " << it->second << std::endl;
// 			++it;
// 		}
// 		std::cout << "\toutput for adding `make_pair(0, 55)`, a duplicate element(this output is a bool): " << map_1->insert(TESTED_NAMESPACE::make_pair(0, 55)).second << std::endl;
// 		std::cout << "\tthe insertion of duplicate elements should not change the value of the key:" << std::endl;
// 		it = map_1->begin();
// 		std::cout << "\tkey: " << it->first << "\tvalue: " << it->second << std::endl;
// 		std::cout << "\tmap size: " << map_1->size() << std::endl;
// 		std::cout << "\tthe deletion of the elements is now up to the destructor" << std::endl;
// 		delete map_1;
// 		map_1 = NULL;

// 		TESTED_NAMESPACE::map<int, int> map_2;
// 		std::cout << "\tinserting " << test_val / 100 << " elements into map_2" << std::endl;
// 		for (size_t i = 0; i < test_val / 100; ++i)
// 		{
// 			map_2.insert(TESTED_NAMESPACE::make_pair(i, i + 1));
// 		}
// 		std::cout << "\tmax_size: " << map_2.max_size() << std::endl;
// 		std::cout << "\tmap size: " << map_2.size() << std::endl;

// 		std::cout << "\titerating over map using the iterator" << std::endl;
// 		TESTED_NAMESPACE::map<int, int>::const_iterator it_2 = map_2.begin();
// 		for (size_t i = 0; i < 15 && it_2 != map_2.end(); ++i)
// 		{
// 			std::cout << "\tkey: " << it_2->first << "\tvalue: " << it_2->second << std::endl;
// 			++it_2;
// 		}
// 		std::cout << "\toutput for adding `make_pair(0, 55)`, a duplicate element(this output is a bool): " << map_2.insert(TESTED_NAMESPACE::make_pair(0, 55)).second << std::endl;
// 		std::cout << "\tthe insertion of duplicate elements should not change the value of the key" << std::endl;
// 		it_2 = map_2.begin();
// 		std::cout << "\tkey: " << it_2->first << "\tvalue: " << it_2->second << std::endl;
// 		std::cout << "\tmap size: " << map_2.size() << std::endl;
// 		std::cout << "\tclearing map_2" << std::endl;
// 		map_2.clear();
// 		std::cout << "\tmap size: " << map_2.size();
// 		gettimeofday(&end, NULL);
// 		// end = std::chrono::steady_clock::now();

// 		seconds = (end.tv_sec - start.tv_sec);
// 		microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
// 		#ifndef STD
// 			std::cout << std::endl << "#####ft::map: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tft::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
// 		#else
// 			std::cout << std::endl << "#####std::map: " << (microseconds / 1000000) << "," << (microseconds % 1000000) << " seconds#####" << std::endl;
// 			// std::cout << std::endl << "\tstd::vector took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds to run." << std::endl;
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

// 	std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;

// 	return (0);
// }
