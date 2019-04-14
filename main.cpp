#include <iostream>
#include "test/tester.h"
#include "forward.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl
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
    l.print_reverse();
    return EXIT_SUCCESS;
}
