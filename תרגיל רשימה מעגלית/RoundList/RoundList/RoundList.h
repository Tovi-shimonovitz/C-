#pragma once
#include "List.h"

	class RoundList:public List
{
public:
	RoundList() { head = nullptr; }
	RoundList(const RoundList& other)
	{
		if (other.isEmpty())
		{
			head = nullptr;
			return;
		}
		
		add(other.head->next->value); 
		Node* src = other.head->next;
		
		while (src->next != other.head->next)
		{
			src = src->next;
			addToEnd(src->value);
		}
		
	}
	~RoundList()
	{
		clear();
	}
	void add(int value)
	{
		if (isEmpty())
		{
			head = new Node(value, head);
			head->next = head;

		}
		else
		{
			head->next = new Node(value, head->next);
		}

	}
	int firstElement() const
	{
		if (!head)
			throw "List is empty, can not return first element";
		return head->next->value;
	}
	bool search(int value) const
	{
		if (head->next->value == value)
			return true;
		for (Node* tmp = head->next;tmp != head; tmp = tmp->next)
		{
			if (tmp->value == value)
				return true;
		}
		return false;
	}
	void clear()
	{
		if (head == nullptr)
			return;

		Node* p = head->next;   

		while (p != head)
		{
			Node* temp = p;
			p = p->next;
			delete temp;
		}

		delete head;
		head = nullptr;
	}
	void removeFirst()
	{
		if (isEmpty()) return;
		Node* tmp = head->next;
		if (head == head->next) {
			head = nullptr;
			return;
		}
			
		head->next = head->next->next;
		delete tmp;
	}
	void addToEnd(int val)
	{
		
		add(val);
		head = head->next;
	}
	int search(int n)
	{
		
		if (head == nullptr || n<0)
			return -1;
		Node* ptr = head->next;
		while (n > 0) {
			ptr = ptr->next;
			n--;
		}
		return ptr->value;

	}
	friend ostream& operator << (ostream& os, RoundList& r)
	{
		if (!r.head)
			return os;
		if (r.head == r.head->next) {
			os << r.head->value;
			return os;
		}
			
		Node* ptr = r.head->next;
		os << ptr->value << "  ";
		ptr = ptr->next;
		while (ptr != r.head->next)
		{
			os << ptr->value << "  ";
			ptr = ptr->next;
		}
		return os;
	}
};

