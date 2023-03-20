#include <iostream>
#include <iomanip>
#include <deque>
#include "printer.hpp"

#ifndef NP
	#define NP ft
	#include <ft_containers.hpp>
#else
	#include <stack>
	#include <vector>
#endif

template<class T, class Container>
void	print3Stacks(NP::stack<T, Container> &s1, NP::stack<T, Container> &s2, NP::stack<T, Container> &s3)
{
	std::cout << " s1 " << std::setw(10) << std::setfill(' ');
	std::cout << " s2 " << std::setw(10) << std::setfill(' ');
	std::cout << " s3" << '\n';
	while (!s1.empty() && !s2.empty() && !s3.empty())
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
	NP::stack<int, NP::vector<int> > stVec;
	for (int i = 0; i < 10; ++i)
		stVec.push(i);
	NP::stack<int, NP::vector<int> > stVecCopy(stVec);
	NP::stack<int, NP::vector<int> > stVecAssign;
	stVecAssign = stVecCopy;
	std::cout << stVec << '\n';
	print3Stacks(stVec, stVecCopy, stVecAssign);
}

void	constructor2StackTest(void)
{
	std::cout << "Constructor2" << '\n';
	NP::stack<int, std::deque<int> > stVec;
	for (int i = 0; i < 10; ++i)
		stVec.push(i);
	NP::stack<int, std::deque<int> > stVecCopy(stVec);
	NP::stack<int, std::deque<int> > stVecAssign;
	stVecAssign = stVecCopy;
	std::cout << stVec << '\n';
	print3Stacks(stVec, stVecCopy, stVecAssign);
}

void	compStackTest(void)
{
	NP::stack<int>	st;
	for (int i = 0; i < 20; ++i)
		st.push(i);
	NP::stack<int>	st2(st);
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
	NP::stack<int, NP::vector<int> > st;
	for (int i = 0; i < 5000000; ++i)
		st.push(i);
	NP::stack<int, NP::vector<int> > stCopy(st);
}

void	pushStackTest(void)
{
	std::cout << "Push" << '\n';
	NP::stack<int> st;
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
