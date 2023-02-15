#include "ft_containers.hpp"
#include "test.hpp"
#include <bits/stdc++.h>

#ifndef NP
#define NP ft
#endif




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
	stream << ", size: " << vec.size() << ", capacity: " << vec.capacity();
	return (stream);
}

using namespace NP;


class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

using std::cout;

template <unsigned long long n>
struct facto : integral_constant<unsigned long long, n * facto<n - 1>::value> {};

template<>
struct facto<0> : integral_constant<unsigned long long, 1> {};


int main(void)
{

	std::cout << facto<24>::value << std::endl;
	return 0;
// 	// takeTime();
// // 
// 	modifiersTest();
// 	capacityTest();
// 	iteratorTest();
// 	operationsTest();
// // 
// 	// speed();
// // 
// 	setModifiersTest();
// 	setCapacityTest();
// 	setIteratorTest();
// // 
// 	setSpeed();


	// clock_t	start, end;
	// start = clock();
	// vector<unsigned long> vec;
	// for (int i = 0; i < 50000000; ++i)
	// 	vec.push_back(i);
	// vector<unsigned long> copy(vec);
	// vector<unsigned long> assign(5000000, 4567);
	// assign = copy;
	// end = clock();
	// double time = (double)(end - start) / CLOCKS_PER_SEC;
	// std::cout << time * 1000 << " ms" << '\n';
}
