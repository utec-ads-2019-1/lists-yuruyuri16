#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>
#include "list.hpp"
#include "iterators/bidirectional_iterator.hpp"

template <typename T>
class CircularLinkedList : public List<T>
{
private:
	typedef Node<T> *NodePointer;

public:
	CircularLinkedList() : List<T>() {}

	T front()
	{
		return (this->head->data);
	}

	T back()
	{
		return (this->tail->data);
	}

	void push_front(T value)
	{
		NodePointer newNode;

		if (empty())
		{
			newNode = new Node<T>{value, nullptr, nullptr};
			newNode->next = newNode;
			newNode->prev = newNode;
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode = new Node<T>{value, this->head, this->tail};
			this->head->prev = newNode;
			this->head = newNode;
			this->tail->next = this->head;
		}
		this->nodes++;
	}

	void push_back(T value)
	{
		NodePointer newNode;

		if (empty())
		{
			newNode = new Node<T>{value, nullptr, nullptr};
			newNode->next = newNode;
			newNode->prev = newNode;
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode = new Node<T>{value, this->head, this->tail};
			this->tail->next = newNode;
			this->tail = newNode;
			this->head->prev = this->tail;
		}
		this->nodes++;
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
				this->head->prev = this->tail;
				this->tail->next = this->head;
			}
		}
		this->nodes--;
	}

	void pop_back()
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
				this->tail = this->tail->prev;
				delete this->tail->next;
				this->tail->next = this->head;
				this->head->prev = this->tail;
			}
		}
		this->nodes--;
	}

	T operator[](int index)
	{
		NodePointer current;
		int i;

		if (this->nodes == 0)
		{
			throw std::invalid_argument("List is empty.\n");
		}
		if (index >= 0)
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
		return "Circular Linked List";
	}

	BidirectionalIterator<T> begin()
	{
		return BidirectionalIterator<T>(this->head);
	}

	BidirectionalIterator<T> end()
	{
		return BidirectionalIterator<T>(this->head);
	}

	void merge(CircularLinkedList<T> list)
	{
		if (!list.empty())
		{
			if (empty())
			{
				this->head = list.head;
				this->tail = list.tail;
			}
			else
			{
				this->tail->next = list.head;
				list.head->prev = this->tail;
				list.tail->next = this->head;
				this->head->prev = list.tail;
				this->tail = list.tail;
			}
		}
		this->nodes = this->nodes + list.nodes;
	}
};

#endif
