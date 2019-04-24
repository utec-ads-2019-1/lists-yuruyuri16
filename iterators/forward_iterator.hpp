#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.hpp"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
			this->current = other.current;
			return (this->current);
        }

        bool operator!=(ForwardIterator<T> other) {
			return (this->current != other.current);
        }

        ForwardIterator<T> operator++() {
			this->current = this->current->next;
			return (this->current);
        }

        T operator*() {
			return (this->current->data);
        }
};

#endif