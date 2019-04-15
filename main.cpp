#include <iostream>
#include "test/tester.h"
#include "forward.h"

int main(int argc, char **argv)
{
    std::cout << "===========================================================" << endl;
    std::cout << "\tLists Practice" << endl;
    std::cout << "===========================================================" << endl
         << endl;

    // Tester::execute();
    ForwardList<int> l;
    ForwardList<int> l1;
    l.push_back(1);
    l.push_back(2);

    l1.push_back(3);
    l1.push_back(4);
    l.merge(l1);
    l.print();
    l.reverse();
    l.print();

    ForwardList<int> l2;
    l2.push_back(123);
    l2.reverse();
    l2.print();
    return (0);
}
