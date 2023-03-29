#ifndef __IS_INTEGRAL_HPP__
#define __IS_INTEGRAL_HPP__

namespace ft
{
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

	template<bool condition, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T, class U>
	struct is_same
	{
		static const bool value = false;
	};
	
	template<class T>
	struct is_same<T, T>
	{
		static const bool value = true;		
	};
}

#endif
