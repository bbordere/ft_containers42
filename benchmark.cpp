#include <bits/stdc++.h>

template<class Container>
long	testGrowVector(int iterations)
{
	Container vec;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < iterations; i++)
		vec.push_back(typename Container::value_type());
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
}

template <class Container>
long	hardTestVector(int iterations)
{
	std::chrono::high_resolution_clock::time_point fstart = std::chrono::high_resolution_clock::now();
	{
		// std::cout << "Copy:" << std::endl;/*VEC*/
		Container vec;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/*VEC*/
		for (int i = 0; i < iterations; i++)
			vec.push_back(i);
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/*VEC*/

		// start = std::chrono::high_resolution_clock::now();/*VEC*/
		Container vec2;
		for (int i = 0; i < 500; i++)
			vec2 = vec;
		// end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Copy: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;/*VEC*/
	}
	{
		// std::cout << "Insert then Erase:" << std::endl;/*VEC*/
		Container vec;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/*VEC*/
		for (int i = 0; i < iterations; i++)
			vec.push_back(i);

		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/*VEC*/
		// start = std::chrono::high_resolution_clock::now();/*VEC*/
		vec.clear();
		// end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Clearing: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/*VEC*/
		// start = std::chrono::high_resolution_clock::now();/*VEC*/
		for (int i = 0; i < iterations; i++)
			vec.push_back(i);
		// end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Reinserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/*VEC*/
		// start = std::chrono::high_resolution_clock::now();/*VEC*/
		for (int i = 0; i < iterations; i++)
			vec.pop_back();
		// end = std::chrono::high_resolution_clock::now();/*VEC*/
		// std::cout << "Erase one by one: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;	/*VEC*/
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << "Total: " << std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count() / 1000 << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count());
}

template<class Container, int nbIter, int nbCycle>
void	testVector(void)
{
	double sum = 0;
	long tmp;
	for (int i = 0; i < nbCycle; i++)
	{
		tmp = hardTestVector<Container>(nbIter);
		sum += tmp;
	}
	std::cout << "Average Routine time: " << (sum / nbCycle) / 1000 << " ms" << std::endl;
}

template<class Container>
long	testGrowMap(u_int64_t iterations)
{
	Container map;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < iterations; i++)
		map.insert({rand(), rand()});
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
}

template <class Container>
long	hardTestMap(int iterations)
{
	std::chrono::high_resolution_clock::time_point fstart = std::chrono::high_resolution_clock::now();
	{
		// std::cout << "Copy:" << std::endl;/**/
		Container map;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < 500; i++)
			map.insert({rand(), rand()});
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/

		// start = std::chrono::high_resolution_clock::now();/**/
		Container map2;
		for (int i = 0; i < 500; i++)
			map2 = map;
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Copy: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;/**/
	}
	{
		// std::cout << "Insert then Erase:" << std::endl;/**/
		Container map;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.insert({rand(), rand()});
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		map.clear();
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Clearing: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.insert({rand(), rand()});
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Reinserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.erase(i);
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Erase one by one: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;	/**/
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << "Total: " << std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count() / 1000 << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count());
}

template<class Container, int nbIter, int nbCycle>
void	testMap(void)
{
	double sum = 0;
	long tmp;
	for (int i = 0; i < nbCycle; i++)
	{
		tmp = hardTestMap<Container>(nbIter);
		sum += tmp;
	}
	std::cout << "Average Routine time: " << (sum / nbCycle) / 1000 << " ms" << std::endl;
}

template <class Container>
long	hardTestSet(int iterations)
{
	std::chrono::high_resolution_clock::time_point fstart = std::chrono::high_resolution_clock::now();
	{
		// std::cout << "Copy:" << std::endl;/**/
		Container map;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < 500; i++)
			map.insert(rand());
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/

		// start = std::chrono::high_resolution_clock::now();/**/
		Container map2;
		for (int i = 0; i < 500; i++)
			map2 = map;
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Copy: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;/**/
	}
	{
		// std::cout << "Insert then Erase:" << std::endl;/**/
		Container map;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.insert(rand());
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		map.clear();
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Clearing: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.insert(rand());
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Reinserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			map.erase(i);
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Erase one by one: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;	/**/
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << "Total: " << std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count() / 1000 << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count());
}

template<class Container, int nbIter, int nbCycle>
void	testSet(void)
{
	double sum = 0;
	long tmp;
	for (int i = 0; i < nbCycle; i++)
	{
		tmp = hardTestSet<Container>(nbIter);
		sum += tmp;
	}
	std::cout << "Average Routine time: " << (sum / nbCycle) / 1000 << " ms" << std::endl;
}

template <class Container>
long	hardTestStack(int iterations)
{
	std::chrono::high_resolution_clock::time_point fstart = std::chrono::high_resolution_clock::now();
	{
		// std::cout << "Copy:" << std::endl;/**/
		Container stack;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < 500; i++)
			stack.push(rand());
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/

		// start = std::chrono::high_resolution_clock::now();/**/
		Container map2;
		for (int i = 0; i < 500; i++)
			map2 = stack;
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Copy: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;/**/
	}
	{
		// std::cout << "Insert then Erase:" << std::endl;/**/
		Container stack;
		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			stack.push(rand());
		// std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Inserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Clearing: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Reinserting: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl;/**/
		// start = std::chrono::high_resolution_clock::now();/**/
		for (int i = 0; i < iterations; i++)
			stack.pop();
		// end = std::chrono::high_resolution_clock::now();/**/
		// std::cout << "Erase one by one: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000 << " ms" << std::endl << std::endl;	/**/
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// std::cout << "Total: " << std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count() / 1000 << " ms" << std::endl;
	return (std::chrono::duration_cast<std::chrono::microseconds>(end - fstart).count());
}

template<class Container, int nbIter, int nbCycle>
void	testStack(void)
{
	double sum = 0;
	long tmp;
	for (int i = 0; i < nbCycle; i++)
	{
		tmp = hardTestStack<Container>(nbIter);
		sum += tmp;
	}
	std::cout << "Average Routine time: " << (sum / nbCycle) / 1000 << " ms" << std::endl;
}

#include "ft_containers.hpp"
// #include "42-ft_containers/includes/vector.hpp"
#include "customAllocators.hpp"
int main(void)
{
	srand(42);
	// testVector<ft::vector<int>, 10000000, 20>();
	// testVector<std::vector<int>, 10000000, 20>();
	const int it = 500000;
	const int cycles = 400;

	std::cout << "ft::map: " << std::endl; 
	testMap<ft::map<int, int>,  it, cycles>();
	std::cout << "std::map: "  << std::endl; 
	testMap<std::map<int, int>, it, cycles>();
	std::cout << std::endl;
	std::cout << "ft::vector: " << std::endl; 
	testVector<ft::vector<int>,  it, cycles>();
	std::cout << "std::vector: " << std::endl; 
	testVector<std::vector<int>, it, cycles>();
	std::cout << std::endl;
	std::cout << "ft::set: " << std::endl; 
	testSet<ft::set<int>,  it, cycles>();
	std::cout << "std::set: " << std::endl; 
	testSet<std::set<int>, it, cycles>();
	std::cout << std::endl;
	std::cout << "ft::stack: " << std::endl;
	testStack<ft::stack<int>,  it, cycles>();
	std::cout << "std::stack: " << std::endl;
	testStack<std::stack<int, std::vector<int> >,  it, cycles>();
	return 0;
}