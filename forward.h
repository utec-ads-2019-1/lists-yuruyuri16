#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T>
{
    private:
        typedef Node<T>* NodePointer;
public:
    ForwardList() : List<T>() {}

    T front()
    {
        return this->head->data;
    }

    T back()
    {
        return this->tail->data;
    }

    void push_front(T value)
    {
        NodePointer newNode;

        if (empty())
        {
            this->head = new Node<T>{value, nullptr, nullptr};
        }
        else
        {
            newNode = new Node<T>{value, this->head, nullptr};
            this->head = newNode;
        }
    }

    void push_back(T value)
    {
        // TODO
    }

    void pop_front()
    {
        // TODO
    }

    void pop_back()
    {
        // TODO
    }

    T operator[](int index)
    {
        // TODO
    }

    bool empty()
    {
        return (this->head == nullptr ? true : false);
    }

    int size()
    {
        return (this->nodes);
    }

    void clear()
    {
        // TODO
    }

    void sort()
    {
        // TODO
    }

    void reverse()
    {
        // TODO
    }

    std::string name()
    {
        return ("Forward List");
    }

    ForwardIterator<T> begin()
    {
        // TODO
    }

    ForwardIterator<T> end()
    {
        // TODO
    }

    void merge(ForwardList<T> list)
    {
        // TODO
    }
};

#endif
