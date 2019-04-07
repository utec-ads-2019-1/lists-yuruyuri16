#include "tester.h"

template <typename T>
List<T>* Tester::getCollection(Collection collection) {
    switch (collection) {
        case forward_list: return new ForwardList<T>();
        case linked_list: return new LinkedList<T>();
        case circular_list: return new CircularLinkedList<T>();
        default: throw invalid_argument("Not a valid collection");
    }
}

void Tester::execute() {
    Collection collections[] = { forward_list/*, linked_list, circular_list*/ };
    size_t numberOfCollections = sizeof(collections) / sizeof(collections[0]);

    for (int i = 0; i < numberOfCollections; i++) {
        /*copy(array, array + size, temp);*/
        List<int>* list = getCollection<int>(collections[i]);
        /*sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");*/
    }
}
