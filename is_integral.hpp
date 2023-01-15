template <typename T, T val>
struct integral_constant
{
	static const	T value = val;
	typedef			T value_type;
	typedef			integral_constant<T, val> type;
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <typename T>
struct is_integral : false_type {};

template <>
struct is_integral<bool> : true_type {};

template <>
struct is_integral<char> : true_type {};

template <>
struct is_integral<unsigned char> : true_type {};

template <>
struct is_integral<signed char> : true_type {};

template <>
struct is_integral<wchar_t> : true_type {};

template <>
struct is_integral<short> : true_type {};

template <>
struct is_integral<unsigned short> : true_type {};

template <>
struct is_integral<int> : true_type {};

template <>
struct is_integral<unsigned int> : true_type {};

template <>
struct is_integral<long> : true_type {};

template <>
struct is_integral<unsigned long> : true_type {};

template <>
struct is_integral<long long> : true_type {};

template <>
struct is_integral<unsigned long long> : true_type {};



#include <iostream>

template <unsigned int n>
struct facto : integral_constant<unsigned int, n * facto<n - 1>::value> {};

template<>
struct facto<0> : integral_constant<unsigned int, 1> {};

int main()
{
	integral_constant<int, 45>::value_type test = 78;
	std::cout << test << std::endl;
	std::cout << facto<5>::value << std::endl;
	std::cout << is_integral<char *>::value << std::endl;
	std::cout << is_integral<char>::value << std::endl;
	return 0;
}

