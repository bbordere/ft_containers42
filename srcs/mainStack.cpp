#include <iostream>
#include <iomanip>
#include <deque>

#ifndef NP
	#define NP ft
	#include <ft_containers.hpp>
#else
	#include <stack>
	#include <vector>
#endif
using namespace NP;

template<class T, class Container>
std::ostream &operator<<(std::ostream &stream, stack<T, Container> stack)
{
	while (!stack.empty())
	{
		stream << '|' << stack.top() << "|\n";
		stack.pop();
	}
	return (stream);
}

template<class T, class Container>
void	print3Stacks(stack<T, Container> &s1, stack<T, Container> &s2, stack<T, Container> &s3)
{
	std::cout << " s1 " << std::setw(10) << std::setfill(' ');
	std::cout << " s2 " << std::setw(10) << std::setfill(' ');
	std::cout << " s3" << '\n';
	while (!s1.empty())
	{
		std::cout << '|' << s1.top() << '|' << std::setw(10) << std::setfill(' ');
		std::cout << '|' << s2.top() << '|' << std::setw(10) << std::setfill(' ');
		std::cout << '|' << s3.top() << '|' << std::setw(10) << std::setfill(' ');
		s1.pop();
		s2.pop();
		s3.pop();
		std::cout << '\n';
	}
	std::cout << '\n';
}

void	constructorStackTest(void)
{
	std::cout << "Constructor" << '\n';
	stack<int, vector<int> > stVec;
	for (int i = 0; i < 10; ++i)
		stVec.push(i);
	stack<int, vector<int> > stVecCopy(stVec);
	stack<int, vector<int> > stVecAssign;
	stVecAssign = stVecCopy;
	std::cout << stVec << '\n';
	print3Stacks(stVec, stVecCopy, stVecAssign);
}

void	constructor2StackTest(void)
{
	std::cout << "Constructor2" << '\n';
	stack<int, std::deque<int> > stVec;
	for (int i = 0; i < 10; ++i)
		stVec.push(i);
	stack<int, std::deque<int> > stVecCopy(stVec);
	stack<int, std::deque<int> > stVecAssign;
	stVecAssign = stVecCopy;
	std::cout << stVec << '\n';
	print3Stacks(stVec, stVecCopy, stVecAssign);
}

void	compStackTest(void)
{
	stack<int>	st;
	for (int i = 0; i < 20; ++i)
		st.push(i);
	stack<int>	st2(st);
	std::cout << std::boolalpha;
	std::cout << "st == st2 ? " << (st == st2) << '\n';
	std::cout << "st != st2 ? " << (st != st2) << '\n';
	std::cout << "st > st2 ? " << (st > st2) << '\n';
	std::cout << "st < st2 ? " << (st < st2) << '\n';
	std::cout << "st >= st2 ? " << (st >= st2) << '\n';
	std::cout << "st <= st2 ? " << (st <= st2) << '\n';
	std::cout << '\n';
	st.push(42);
	std::cout << std::boolalpha;
	std::cout << "st == st2 ? " << (st == st2) << '\n';
	std::cout << "st != st2 ? " << (st != st2) << '\n';
	std::cout << "st > st2 ? " << (st > st2) << '\n';
	std::cout << "st < st2 ? " << (st < st2) << '\n';
	std::cout << "st >= st2 ? " << (st >= st2) << '\n';
	std::cout << "st <= st2 ? " << (st <= st2) << '\n';
	std::cout << '\n';
}

void	speedStackTest(void)
{
	stack<int, vector<int> > st;
	for (int i = 0; i < 5000000; ++i)
		st.push(i);
	stack<int, vector<int> > stCopy(st);
}

void	pushStackTest(void)
{
	std::cout << "Push" << '\n';
	stack<int> st;
	for (int i = 0; i < 6; ++i)
		st.push(i);
	std::cout << st << '\n';
	std::cout << "Top value: " << st.top() << '\n';
	std::cout << "Size: " << st.size() << '\n';
	st.push(42);
	std::cout << st << '\n';
	std::cout << "Top value: " << st.top() << '\n';
	std::cout << "Size: " << st.size() << '\n' << '\n';
}
