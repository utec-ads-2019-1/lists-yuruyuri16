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
    
    LinkedList<int> l1, l2;
    l1.push_back(1);
    l1.push_back(2);

    l2.push_back(3);
    l2.push_back(4);
    l1.merge(l2);

    l1.print();
    //ForwardList<int> l1, l2;

    //l1.push_back(3);
    //l1.push_back(4);

    //l1.merge(l2);

    //.l1.print();

    return (0);
}
