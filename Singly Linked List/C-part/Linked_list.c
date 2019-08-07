#include<stdio.h>
#include"listC.h"
//Node structure
struct Node {
	list_element_t data;
	struct Node *next;
};
//List structure
struct list_tag {
	struct Node *head;
	int size;
};
//create new list
list_t list_new() {
	list_t list = malloc(sizeof(struct list_tag));
	list->head = NULL;
	list->size = 0;
	return list; 
}
//delete list
void list_delete(list_t list) {
	while (list->head != NULL) {
		struct Node *temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	free(list);
}
//add element to list
void list_push(list_t list, list_element_t elem) {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = elem;
	node->next = list->head;
	list->head = node;
	++list->size;
}
//insert element at position pos
void list_insert_at(list_t list, list_element_t elem, int pos) {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));	
	node->data = elem;	
	if (!list->size && pos==0) {
		node->data = elem;
		node->next = NULL;
		list->head = node;
		++list->size;
	}
	else if (!list->size && pos != 0) {
		return;
	}
	else {
		struct Node *prevNode = list->head;
		int i = 1;					
		while (i < pos) {
			prevNode = prevNode->next;
			++i;
		}
		node->next = prevNode->next;
		prevNode->next = node;
	}
}
//print all elements of list
void list_print(list_t list){
	struct Node *node = list->head;
	while (node != NULL)	{
		printf(" %d ", node->data);
		node = node->next;
	}
}
//check if exists element, returns 1 if true
int list_ifExists_element(list_t list, list_element_t elem) {
	struct Node *node = list->head;
	while (node != NULL) {
		if (node->data == elem) return 1;
		node = node->next;
	}
	return -1;
}
// delete element from list at index, or can be changed to by value(data)
int list_delete_element(list_t list, int index) {
	if (index > list->size - 1)
		return -1;
	if (list->size == 0)
		return -2;
	struct Node *temp = list->head;
	if (index == 0){
		list->head = temp->next;
		free(temp);
		return 0;
	}
	// Previous node from the one designated for delete
	for (int i = 0; temp != NULL && i < index-1; i++)
		temp = temp->next;
	//Node next from one to be deleted
	struct Node *next = temp->next->next;
	free(temp->next);
	temp->next = next;
	list->size--;
	return 0;
}

