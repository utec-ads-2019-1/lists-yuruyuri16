#ifndef LINKED_H
#define LINKED_H

#include <string>
#include <stdexcept>

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    private:
        typedef Node<T>* NodePointer;

    public:
        LinkedList() : List<T>() {}

        T front() {
            return (this->head->data);
        }

        T back() {
            return (this->tail->data);
        }

        void push_front(T value) {
            NodePointer newNode;

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

        void push_back(T value) {
            NodePointer newNode;

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

        void pop_front() {
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

        void pop_back() {
            if (!empty())
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
            this->nodes--;
        }

        T operator[](int index) {
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
            else if (index < 0)
            {
                throw std::invalid_argument("Invalid index.\n");
            }
            else
            {
                throw std::invalid_argument("Index out of range.\n");
            }
        }

        bool empty() {
            return (this->head == nullptr ? true : false);
        }

        int size() {
            return (this->nodes);
        }

        void clear() {
            while (!empty())
            {
                pop_back();
            }
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            NodePointer temp;
            NodePointer current;

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

        std::string name() {
            return ("Linked List");
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            if (empty())
            {
                if (!empty())
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
                    this->tail = list.tail;
                }
            }
            this->nodes = this->nodes + list.nodes;
        }
};

#endif
