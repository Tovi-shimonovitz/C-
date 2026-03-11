#pragma once
#include<iostream>
using namespace std;
class List
{

public :class Node
	{
	public:
		
		Node(int NodeValue) :value(NodeValue), next(nullptr) {}
		Node(int NodeValue, Node* nextPtr) :value(NodeValue), next(nextPtr) {}
		Node(const Node& other) :value(other.value), next(nullptr) {}
		int value;
		Node* next;
	};	
protected:

	Node* head;
public:
	
	List() { head = nullptr; }
	List(const List& other)
	{
		if (other.isEmpty())
		{
			head = nullptr;
			return;
		}
	
		add(other.head->value); //head = new Node(src->value);
		Node* src = other.head;
		Node* trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Node(src->next->value);
			src = src->next;
			trg = trg->next;
		}
	}
	~List()
	{
		clear();
	}

	
	void add(int value)
	{
		if (isEmpty())
		{
			head = new Node(value, nullptr);
		}
		else
		{
		head = new Node(value, head);
		}
	}
	int firstElement() const
	{
		if (!head)
			throw "List is empty, can not return first element";
		return head->value;
	}
	bool search(int value) const
	{
		for (Node* tmp = head;tmp != nullptr; tmp = tmp->next)
		{
			if (tmp->value == value)
				return true;
		}
		return false;
	}

	bool isEmpty() const { return head == nullptr; }
	void removeFirst()
	{
		if (isEmpty()) return;
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	void clear()
	{
		while (!isEmpty())
		{
			removeFirst();
		}
	}


};
//void main()
//{
//	try
//	{
//		List l;
//			cout << l.firstElement();
//		l.add(1);
//		l.add(2);
//		l.add(3);
//		l.clear();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//};

