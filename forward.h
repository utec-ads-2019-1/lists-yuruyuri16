#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include <iostream>

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

    void print()
    {
        NodePointer current;

        if (empty())
        {
            std::cout << "Empty list.\n";
            return ;
        }

        current = this->head;
        while (current != nullptr)
        {
            std::cout << current->data << '\n';
            current = current->next;
        }
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
        this->nodes++;
    }

    void push_back(T value)
    {
        NodePointer last_node;
        if (empty())
        {
            this->head = new Node<T>{value, nullptr, nullptr};
        }
        else
        {
            last_node = get_last_node();
            last_node->next = new Node<T>{value, nullptr, nullptr};
        }
        this->nodes++;
    }

    NodePointer get_last_node()
    {
        NodePointer current;
        
        current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return (current);
    }

    void pop_front()
    {
        NodePointer temp;

        if (!empty())
        {
            temp = this->head;
            this->head = this->head->next;
            delete temp;
            temp = nullptr;
        }
        this->nodes--;
    }

    void pop_back()
    {
        NodePointer penultimate_node;

        if (!empty())
        {
            if (this->nodes == 1)
            {
                delete this->head;
                this->head = nullptr;
            }
            else
            {
                penultimate_node = get_penultimate_node();
                delete penultimate_node->next;
                penultimate_node->next = nullptr;
            }
        }
        this->nodes--;
    }

    NodePointer get_penultimate_node()
    {
        NodePointer current;

        current = this->head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        return (current);
    }

    T operator[](int index)
    {
        NodePointer current;
        int i;

        if (this->nodes == 0)
        {
            throw std::invalid_argument("List is empty.\n");
        }
        if (this->nodes > index && index >= 0)
        {
            current = this->head;
            i = 0;
            while (i < index)
            {
                current = current->next;
                ++i;
            }
            return (current->data);
        }
        else
        {
            throw std::invalid_argument("Invalid index.\n");
        }
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
        while (!empty())
        {
            pop_front();
        }
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
        NodePointer last_node;

        if (!list.empty())
        {
            if (empty())
            {
                this->head = list.head;
            }
            else
            {
                last_node = get_last_node();
                last_node->next = list.head;
            }
        }
        this->nodes = this->nodes + list.nodes;
    }
};

#endif
