#ifndef LCPP_H
#define LCPP_H
#include<iostream>

template<typename T>
class Node {
public:
	Node* next;
	T data;
};

template<typename T>
class LinkedList {
public:
	int length;
	Node<T>* head;

	LinkedList();
	~LinkedList();
	void add(const T data);
	void print();
	void remove(const int pos);
	void find(const T el);
};

template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* ptr = this->head, *next = nullptr;
	while (ptr != nullptr) {
		next = ptr->next;
		delete(ptr);
		ptr = next;
	}
}

//new list
template<typename T>
LinkedList<T>::LinkedList() {
	this->length = 0;
	this->head = nullptr;
}

//add node (push)
template<typename T>
void LinkedList<T>::add(const T data) {
	Node<T>* node = new Node<T>();
	node->data = data;
	node->next = this->head;
	this->head = node;
	this->length++;
}

/*remove node on index pos, if we remove index and just delete head on each call
list behaves like stack (add=push, remove=pop)*/
template<typename T>
void LinkedList<T>::remove(const int pos) {
	if (length < pos) throw XnoIndex();
	if (!length) throw Xempty();
	Node<T>* node = new Node<T>();
	node = head;
	if (!pos) {
		head = head->next;
		delete(node);
		--length;
		return;
	}
	int i = 1;
	while (node != nullptr && i < pos) {		
		node = node->next;
		++i;
	}
	Node<T>* nodeNext = new Node<T>();
	nodeNext = node->next->next;
	delete(node->next);
	node->next = nodeNext;
	--this->length;
}

//find element, save their index-es in new list, print it out then delete temp list
template<typename T>
void LinkedList<T>::find(const T el) {
	Node<T>* node = new Node<T>();
	LinkedList<T>* result = new LinkedList<T>();
	int i = 0;
	node = this->head;
	while (node != nullptr) {
		if (node->data == el)
			result->add(i);
		node = node->next; ++i;
	}
	if (result->length > 0)
		result->print();
	else
		std::cout << "Element not found";
	delete(result);
	delete(node);
}

//print list
template<typename T>
void LinkedList<T>::print() {
	Node<T>* head = this->head;
	int i = 0;
	while (head) {
		std::cout << i << ": " << head->data << std::endl;
		head = head->next;
		i++;
	}
	std::cout << "List length: " << length << std::endl;
	delete(head);
}
#endif // !LCPP_H
