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

int main(void)
{
	// takeTime();
	vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	vector<vector<int> >	self_assign;
	vector<vector<int> >	*ptr = &self_assign;
	vector<vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
	vector<vector<int> > JOHN;
	vector<vector<int> > BOB(5, test);

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	vector<vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	// modifiersTest();
	// capacityTest();
	// iteratorTest();
	// operationsTest();

	// // speed();

	// setModifiersTest();
	// setCapacityTest();
	// setIteratorTest();

	// setSpeed();
}
