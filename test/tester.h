#ifndef TESTER_H
#define TESTER_H

#include <stdexcept>
#include <iostream>
#include <assert.h>

#include "../mock/mocker.h"
#include "../forward.h"
#include "../linked.h"
#include "../circular.h"
#include "../iterators/forward_iterator.h"
#include "../iterators/bidirectional_iterator.h"

using namespace std;

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

enum Collection { forward_list, linked_list, circular_list };

class Tester {
    private:
        //static Mocker mocker;

        template <typename T>
        static List<T>* getCollection(Collection);

    public:
        static void execute();
};

#endif