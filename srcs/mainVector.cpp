#include "ft_containers.hpp"
#include <vector>
#include <iostream>
#include "printer.hpp"

#define SIZE 10000000

void	insertVectorTest(void)
{
	{
		std::cout << "Insert" << '\n';
		NP::vector<int> vec;
		vec.insert(vec.begin(), 10, 42);
		std::cout << vec << '\n';
		NP::vector<int>::const_iterator it = vec.insert(vec.end(), 24);
		std::cout << *it << '\n';
		std::cout << vec << '\n' << '\n';
	}
	{
		std::cout << "Insert with array" << '\n';
		NP::vector<double> vec;
		double arr[9] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0};
		vec.insert(vec.begin(), arr, arr + 9);
		std::cout << vec << '\n' << '\n';
	}
	{
		std::cout << "Copy and assign op" << '\n';
		NP::vector<int> vec;
		for (int i = 0; i < 16; ++i)
			vec.push_back(i);
		NP::vector<int> copy(vec);
		NP::vector<int> assign;
		assign = copy;
		std::cout << "vec: " << vec << '\n';
		std::cout << "copy: " << copy << '\n';
		std::cout << "assign: " << assign << '\n';
		std::cout << '\n';
	}
	{
		std::cout << "Assign" << '\n';
		NP::vector<int> vec(5, 42);
		NP::vector<int> vec2;
		std::cout << vec << '\n';
		vec.assign(4, 21);
		std::cout << vec << '\n';
		vec2.assign(vec.begin(), vec.end());
		std::cout << vec2 << '\n';
	}
	std::cout << '\n';
}

void	accessVectorTest(void)
{
	std::cout << "Access" << '\n';
	NP::vector<std::string> vec;
	vec.push_back("Hello world !");
	vec.push_back("What's up ?");
	vec.insert(vec.end(), 3, "Fine :)");
	std::cout << vec << '\n';
	std::cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';
	std::cout << vec.front() << ' ' << vec.back() << ' ' << vec.data()[1] << '\n';
	try
	{
		vec.at(4242);
		std::cout << "EXPLOSIOOOON !" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
}

void	iteratorVectorTest(void)
{
	std::cout << "Iterator" << '\n';
	NP::vector<int> vec;
	vec.reserve(21);
	for (int i = 0; i < 21; ++i)
		vec.push_back(i);
	for (NP::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	for (NP::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	for (NP::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	for (NP::vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	vec.resize(5);
	std::cout << vec << '\n';
	NP::vector<int>::iterator it = vec.begin();
	for (int i = 0; i < 5; ++i)
	{
		*it += i;
		++it;
	}
	std::cout << vec << '\n';
	std::cout << '\n';
}

void	capacitySwapVectorTest(void)
{
	std::cout << "Capacity" << '\n';
	NP::vector<std::string> vec;
	std::string msg[] = {"Ceci", "est", "un", "message", "top", "secret", "/!\\"};
	vec.insert(vec.begin(), msg, msg + 7);
	std::cout << vec << " max size = " << vec.max_size() << '\n';
	std::cout << std::boolalpha;
	std::cout << "vec is empty ? " << vec.empty() << '\n';
	vec.clear();
	std::cout << "vec is empty ? " << vec.empty() << '\n';
	vec.reserve(42);
	std::cout << vec << " max size = " << vec.max_size() << '\n';
	std::cout << '\n';
	std::cout << "Swap" << '\n';

	vec.insert(vec.begin(), msg, msg + 7);
	std::string msg2[] = {"Ceci", "n'est", "pas", "un", "message", "cache", "(:"};
	NP::vector<std::string> vec2;
	vec2.insert(vec2.begin(), msg2, msg2 + 7);

	std::cout << vec << '\n';
	std::cout << vec2 << '\n';
	vec.swap(vec2);
	std::cout << vec << '\n';
	std::cout << vec2 << '\n';
	std::cout << '\n';
}

void	compVectorTest(void)
{
	std::cout << "Comp" << '\n';
	NP::vector<std::string> vec;
	NP::vector<std::string> vec2;
	vec.push_back("1");
	vec.push_back("2");
	vec.push_back("3");
	vec.push_back("4");
	vec2 = vec;
	std::cout << vec << '\n';
	std::cout << vec2 << '\n';
	std::cout << std::boolalpha;
	std::cout << "vec == vec2 ? " << (vec == vec2) << '\n';
	std::cout << "vec != vec2 ? " << (vec != vec2) << '\n';
	std::cout << "vec > vec2 ? " << (vec > vec2) << '\n';
	std::cout << "vec < vec2 ? " << (vec < vec2) << '\n';
	std::cout << "vec <= vec2 ? " << (vec <= vec2) << '\n';
	std::cout << "vec >= vec2 ? " << (vec >= vec2) << '\n';
	std::cout << '\n';
}

struct uselessStruct
{
	int _n;

	uselessStruct(void): _n(31) {}
	uselessStruct(int n): _n(n) {}
	uselessStruct(uselessStruct const &copy): _n(copy._n) {}
	uselessStruct &operator=(uselessStruct const &assign) {_n = assign._n; return (*this);}
	bool operator==(uselessStruct const &rhs){ return (_n == rhs._n);}
	bool operator!=(uselessStruct const &rhs){ return (_n != rhs._n);}
	bool operator<(uselessStruct const &rhs){ return (_n < rhs._n);}
	bool operator>(uselessStruct const &rhs){ return (_n > rhs._n);}
	bool operator<=(uselessStruct const &rhs){ return (_n <= rhs._n);}
	bool operator>=(uselessStruct const &rhs){ return (_n >= rhs._n);}
};


void	speedVectorTest(void)
{
	NP::vector<uselessStruct> vec;
	NP::vector<uselessStruct> assign;
	for (int i = 0; i < SIZE; ++i)
		vec.push_back(uselessStruct(i));
	NP::vector<uselessStruct> copy(vec);
	assign = copy;
	vec.clear();
	vec.assign(copy.begin(), copy.end());
	vec.insert(vec.end(), copy.begin(), copy.end());
	vec.clear();
}