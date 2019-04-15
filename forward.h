#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class ForwardList : public List<T>
{
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
        Node<T> *newNode;

        if (empty())
        {
            newNode = new Node<T>{value, nullptr, nullptr};
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            newNode = new Node<T>{value, this->head, nullptr};
            this->head->prev = newNode;
            this->head = newNode;
        }
        this->nodes++;
    }

    void push_back(T value)
    {
        Node<T> *newNode;

        if (empty())
        {

            newNode = new Node<T>{value, nullptr, nullptr};
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            newNode = new Node<T>{value, nullptr, this->tail};
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->nodes++;
    }

    void print()
    {
        Node<T> *current;

        if (empty())
        {
            std::cout << "empty\n";
        }
        else
        {
            current = this->head;
            while (current != nullptr)
            {
                std::cout << current->data << '\n';
                current = current->next;
            }
        }
    }

    void print_reverse()
    {
        Node<T> *current;

        if (empty())
        {
            std::cout << "empty\n";
        }
        else
        {
            current = this->tail;
            while (current != nullptr)
            {
                std::cout << current->data << '\n';
                current = current->prev;
            }
        }
    }


    void pop_front()
    {
        if (!empty())
        {
            if (this->nodes == 1)
            {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            }
            else
            {
                this->head = this->head->next;
                delete this->head->prev;
                this->head->prev = nullptr;
            }
        }
        this->nodes--;
    }

    void pop_back()
    {
        if (!empty())
        {
            if (this->head == this->tail)
            {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            }
            else
            {
                this->tail = this->tail->prev;
                delete this->tail->next;
                this->tail->next = nullptr;
            }
        }
        this->nodes--;
    }

    T operator[](int index)
    {
        Node<T> *current;
        int i;

        if (this->nodes == 0)
        {
            throw std::invalid_argument("List is empty.\n");
        }
        else if (this->nodes > index && index >= 0)
        {
            current = this->head;
            i = 0;
            while (i < index)
            {
                current = current->next;
                ++i;
            }
            return current->data;
        }
        else
        {
            throw std::invalid_argument("Index out of range.\n");
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
        while(!empty())
        {
            pop_back();
        }
    }

    void sort()
    {
        if (this->nodes > 1)
        {
            //TODO
        }
    }

    void reverse()
    {
        Node<T> *temp;
        Node<T> *current;

        temp = this->head;
        this->head = this->tail;
        this->tail = temp;

        current = this->head;
        while (current != nullptr)
        {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->next;
        }
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
        if (empty())
        {
            if (!list.empty())
            {
                this->head = list.head;
                this->tail = list.tail;
            }
        }
        else
        {
            if (!list.empty())
            {
                this->tail->next = list.head;
                list.head->prev = this->tail;
                this->tail = list.tail;
            }
        }
            }
};

#endif
