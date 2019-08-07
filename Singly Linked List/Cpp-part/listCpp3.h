#ifndef LCPP_H
#define LCPP_H
#include<iostream>

template<typename T>
class Node
{
	T data;
	Node* next;
public:
	Node(T val, Node<T>* next) :data(val), next(next) {}
	Node() = default;
	~Node() {}
	void setNext(Node<T>* nextNode) { next = nextNode; }
	Node<T>* getNext()const { return next; }
	T& getData() { return data; }
};

template<typename T>
class LinkedList {
	Node<T>* head;
public:
	LinkedList() :head(nullptr) {}
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
	while (head != nullptr)
	{
		temp = head->getNext();
		delete head;
		head = temp;		
	}
}

//add node at beginning (push)
template<typename T>
bool LinkedList<T>::insAtBegin(const T &data)
{
	Node<T>* node = new Node<T>(data,nullptr);
	if (node == nullptr)
		return false;
	node->setNext(head);
	head = node;
	return true;
}

//add node at end
template<typename T>
bool LinkedList<T>::insAtEnd(const T &data)
{
	if (head == nullptr)
	{
		insAtBegin(data);
		return true;
	}
	else
	{
		Node<T>* ptr(head);
		while (ptr->getNext() != nullptr)
		{
			ptr = ptr->getNext();
		}
		Node<T>* node = new Node<T>(data, nullptr);
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
	Node<T>* ptr = head;
	while (ptr != nullptr && --pos)
	{
		ptr = ptr->getNext();
	}
	if (ptr == nullptr)
		return false;
	Node<T>* node = new Node<T>(data,nullptr);
	node->setNext(ptr->getNext());
	ptr->setNext(node);
	return true;
}

//remove
template<typename T>
bool LinkedList<T>::remove(const T &data) {
	if (this->head == nullptr)
		return false; //empty
	if (this->head->getData() == data)
	{
		//first node to be removed
		Node<T>* temp = this->head;
		this->head = this->head->getNext();
		delete temp;
		return true;
	}
	Node<T>* ptr = this->head;
	while (ptr->getNext() != nullptr && ptr->getNext()->getData() != data)
		ptr = ptr->getNext();
	if (ptr->getNext() == nullptr && ptr->getData() != data)
		return false;//not found
	Node<T>* temp = ptr->getNext();
	ptr->setNext(ptr->getNext()->getNext());
	delete temp;
	return true;
}

//print list
template<typename T>
void LinkedList<T>::print() const
{
	Node<T>* ptr = this->head;
	while (ptr != nullptr)
	{
		std::cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}
#endif // !LCPP_H