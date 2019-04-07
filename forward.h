#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if (!this->head) {
                throw out_of_range("There are no elements in the list");
            }

            return this->head->data;
        }

        T back() {
            if (!this->head) {
                throw out_of_range("There are no elements in the list");
            }

            Node<T>* next = this->head;
            while (next) {
                if (next->next == NULL) {
                    break;
                }
                next = next->next;
            }

            return next->data;
        }

        void push_front(T value) {
            Node<T>* temp = new Node<T>;
            temp->data = value;
            temp->next = this->head;
            this->head = temp;
        }

        void push_back(T value) {
            Node<T>* temp = new Node<T>;
            temp->data = value;
            temp->next = nullptr;

            if (this->head == nullptr) {
                this->head = temp;
            } else {
                Node<T>* next = this->head;
                while (next) {
                    if (next->next == nullptr) {
                        break;
                    } 
                    next = next->next;
                }

                next->next = temp;
            }

            this->nodes++;
        }

        void pop_front() {
            if (this->head != nullptr) {
                Node<T>* temp = this->head;
                this->head = this->head->next;
                delete temp;
                this->nodes--;
            }
        }

        void pop_back() {
            if (this->head != nullptr) {
                if (this->head->next == nullptr) {
                    delete this->head;
                    this->head = nullptr;
                    this->nodes = 0;
                } else {
                    Node<T>* current = this->head;
                    Node<T>* next = current->next;
                    while (next) {
                        if (next->next == nullptr) {
                            current->next = nullptr;
                            delete next;
                            this->nodes--;
                            break;
                        } 
                        current = next;
                        next = next->next;
                    }
                }
            }
        }

        T operator[](int index) {
            if (index >= this->nodes) {
                throw out_of_range("Position out of bounds");
            }

            Node<T>* next = this->head;
            for (int i = 0; i < index; i++) {
                next = next->next;
            }

            return next->data;
        }

        bool empty() {
            return this->head == nullptr ? true : false;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            Node<T>* next = this->head;

            while (next) {              
                Node<T>* temp = next;
                next = next->next;    
                delete temp;
            } 

            this->head = nullptr;
            this->nodes = 0;
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            ForwardList<T>* reverse = new ForwardList<T>; 
            Node<T>* next = this->head;
            while (next) {
                reverse->push_front(next->data);
                next = next->next;
            }

            Node<T>* temp = this->head;
            this->head = reverse->head;
            delete temp;
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            return ForwardIterator<T>(nullptr);
        }

        void merge(ForwardList<T> list) {
            for (int i = 0; i < list.size(); ++i) {
                push_back(list[i]);
            }
        }
};

#endif