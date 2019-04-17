#include <iostream>
#include "test/tester.h"

#include "linked.h"
#include "forward.h"

int main(int argc, char **argv)
{
    std::cout << "===========================================================" << endl;
    std::cout << "\tLists Practice" << endl;
    std::cout << "===========================================================" << endl
         << endl;

    // Tester::execute();
    ForwardList<int> l;
    l.push_front(10);
    l.push_front(3);

    l.print();

    return (0);
}
