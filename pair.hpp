#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace ft
{
	template <typename T1, typename T2>
	class pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			
			first_type	first;
			second_type	second;

			pair(): first(), second() {}
			
			template <class U, class V>
			pair(const pair<U, V> &pr): first(pr.first), second(pr.second) {}
			
			pair(const first_type &a, const second_type &b): first(a), second(b) {}
			
			pair &operator=(pair const &pr)
			{
				if (pr != *this)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			}
			
			~pair() {};
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

	template <class T1, class T2>
	bool operator== (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (l.first == r.first && l.second == r.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (!(l == r));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (l.first < r.first || (!(r.first < l.first) && l.second < r.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (!(r < l));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (r < l);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2> &l, const pair<T1,T2> &r)
	{
		return (!(l < r));
	}
}

template <class T, class U>
std::ostream &operator<<(std::ostream &stream, ft::pair<T, U> const &pair)
{
	stream << '(' << pair.first << ", " << pair.second << ')';
	return (stream);
}

#endif
