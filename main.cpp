#include <iostream>
#include "test/tester.hpp"

#include "linked.hpp"
#include "forward.hpp"
#include "circular.hpp"

int main(int argc, char **argv)
{
	std::cout << "===========================================================" << endl;
	std::cout << "\tLists Practice" << endl;
	std::cout << "===========================================================" << endl
			  << endl;

	Tester::execute();
	/*
	CircularLinkedList<int> l1, l2;
	l1.push_back(10);
	l1.push_back(2);
	l1.push_back(121);
	l1.push_back(100);

	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << '\n';
	}

	l1.reverse();
	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << '\n';
	}
	for (int i = 0; i < 10; ++i)
	{
		std::cout << l1[i] << '\n';
	}
	*/
	return (0);
}
