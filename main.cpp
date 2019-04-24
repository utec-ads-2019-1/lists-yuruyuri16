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
	/*LinkedList<int> l1, l2;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << '\n';
	}
	l1.reverse();
	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << '\n';
	}
*/
	return (0);
}
