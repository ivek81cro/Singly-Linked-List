#ifndef LCPP_H
#define LCPP_H
#include<iostream>

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node(T val) :data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
	Node<T>* head;
	LinkedList() :head(nullptr) {}
	~LinkedList();
	bool insAtBegin(T data);
	bool insAtEnd(T data);
	bool insAtPosition(int pos, T data);
	bool remove(T data);
	void print();
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* ptr = this->head, *next = NULL;
	while (ptr != nullptr)
	{
		next = ptr->next;
		delete(ptr);
		ptr = next;
	}
}

//add node at beginning (push)
template<typename T>
bool LinkedList<T>::insAtBegin(T data) {
	Node<T>* node = new Node<T>(data);
	node->next = this->head;
	this->head = node;
	return true;
}

//add node at end
template<typename T>
bool LinkedList<T>::insAtEnd(T data) {
	if (head == nullptr) {
		insAtBegin(data);
		return true;
	}
	else {
		Node<T>* node = new Node<T>(data);
		Node<T>* ptr = this->head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = node;
	}
	return true;
}

//insert at position
template<typename T>
bool LinkedList<T>::insAtPosition(int pos, T data) {
	Node<T>* node = new Node<T>(data);
	if (pos == 0) {
		insAtBegin(data);
		return true;
	}
	Node<T>* ptr = this->head;
	while (ptr != nullptr && --pos)
	{
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;//not enough elements
	node->next = ptr->next;
	ptr->next = node;
	return true;
}

//remove
template<typename T>
bool LinkedList<T>::remove(T data) {
	if (this->head == nullptr)
		return false; //empty
	if (this->head->data == data)
	{
		//first node to be removed
		Node<T>* temp = this->head;
		this->head = this->head->next;
		delete(temp);
		return true;
	}
	Node<T>* ptr = this->head;
	while (ptr->next != nullptr && ptr->next->data != data)
		ptr = ptr->next;
	if (ptr->next == nullptr && ptr->data!=data)
		return false;//not found
	Node<T>* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete(temp);
	return true;
}

//print list
template<typename T>
void LinkedList<T>::print() {
	Node<T> *ptr = this->head;
	while (ptr != nullptr)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}
#endif // !LCPP_H
