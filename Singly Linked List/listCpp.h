#ifndef LCPP_H
#define LCPP_H
#include<iostream>
#include <new>

template<typename T>
class Node
{
	T m_data;
	Node* m_next;
public:
	Node(T val, Node<T>* next):m_data(val), m_next(next) {}
	Node() = default;
	~Node() = default;
	void setNext(Node<T>* nextNode) { m_next = nextNode; }
	Node<T>* getNext()const { return m_next; }
	T& getData() { return m_data; }
};

template<typename T>
class LinkedList 
{
	Node<T>* m_head;
public:
	LinkedList() :m_head(nullptr) {}
	~LinkedList();
	bool insAtBegin(const T &data);
	bool insAtEnd(const T &data);
	bool insAtPosition(unsigned pos, const T &data);
	bool remove(const T &data);
	void print() const;
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp;

	while (m_head != nullptr)
	{
		temp = m_head->getNext();
		delete m_head;
		m_head = temp;		
	}
}

//add node at beginning (push)
template<typename T>
bool LinkedList<T>::insAtBegin(const T &data)
{
	Node<T>* node = new (std::nothrow) Node<T>(data,nullptr);
	if (node==nullptr)
		return false;

	node->setNext(m_head);
	m_head = node;
	return true;
}

//add node at end
template<typename T>
bool LinkedList<T>::insAtEnd(const T &data)
{
	if (m_head == nullptr)
	{
		insAtBegin(data);
		return true;
	}
	else
	{
		Node<T>* ptr(m_head);
		while (ptr->getNext() != nullptr)
		{
			ptr = ptr->getNext();
		}
		Node<T>* node = new (std::nothrow) Node<T>(data, nullptr) ;
		if (node == nullptr)
			return false;

		ptr->setNext(node);
		return true;
	}
	return false;
}

//insert at position
template<typename T>
bool LinkedList<T>::insAtPosition(unsigned pos, const T &data)
{
	if (pos == 0)
	{
		insAtBegin(data);
		return true;
	}

	Node<T>* ptr = m_head;
	while (ptr != nullptr && --pos)
	{
		ptr = ptr->getNext();
	}
	if (ptr == nullptr)
		return false;

	Node<T>* node = new (std::nothrow) Node<T>(data,nullptr);
	if (node == nullptr)
		return false;

	node->setNext(ptr->getNext());
	ptr->setNext(node);
	return true;
}

//remove
template<typename T>
bool LinkedList<T>::remove(const T &data) 
{
	if (m_head == nullptr)
		return false; //empty

	if (m_head->getData() == data)
	{
		//first node to be removed
		Node<T>* temp = m_head;
		m_head = m_head->getNext();
		delete temp;
		temp = nullptr;
		return true;
	}

	Node<T>* ptr = m_head;
	while (ptr->getNext() != nullptr && ptr->getNext()->getData() != data)
		ptr = ptr->getNext();

	if (ptr->getNext() == nullptr && ptr->getData() != data)
		return false;//not found

	Node<T>* temp = ptr->getNext();
	ptr->setNext(ptr->getNext()->getNext());
	delete temp;
	temp = nullptr;
	return true;
}

//print list
template<typename T>
void LinkedList<T>::print() const
{
	Node<T>* ptr = m_head;
	while (ptr != nullptr)
	{
		std::cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}
#endif // !LCPP_H