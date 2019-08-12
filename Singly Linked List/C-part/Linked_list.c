#include<stdio.h>
#include"listC.h"
//Node structure
struct Node 
{
	list_element_t m_data;
	struct Node *m_next;
};

//List structure
struct list_tag 
{
	struct Node *m_head;
	int m_size;
};

//create new list
list_t list_new() 
{
	list_t list = malloc(sizeof(struct list_tag));
	if (list == NULL)
		return -1;//!!!ne znam sta da ovdije stavim za return jer vraca listu!!!
	list->m_head = NULL;
	list->m_size = 0;
	return list; 
}

//delete list
void list_delete(list_t list) 
{
	while (list->m_head != NULL) 
	{
		struct Node *temp = list->m_head;
		list->m_head = list->m_head->m_next;
		free(temp);
		temp = NULL;
	}
	free(list);
}

//add element to list
int list_push(list_t list, list_element_t elem) 
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	if (node == NULL)
		return -1;

	node->m_data = elem;
	node->m_next = list->m_head;
	list->m_head = node;
	++list->m_size;
}
//insert element at position pos
void list_insert_at(list_t list, list_element_t elem, int pos) 
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));	
	if (node == NULL)
		return -1;
	node->m_data = elem;	
	if (!list->m_size && pos==0) 
	{
		node->m_data = elem;
		node->m_next = NULL;
		list->m_head = node;
		++list->m_size;
	}

	else if (!list->m_size && pos != 0) 
	{
		return;
	}

	else 
	{
		struct Node *prevNode = list->m_head;
		int i = 1;					
		while (i < pos) {
			prevNode = prevNode->m_next;
			++i;
		}
		node->m_next = prevNode->m_next;
		prevNode->m_next = node;
	}
}

//print all elements of list
void list_print(list_t list)
{
	struct Node *node = list->m_head;
	while (node != NULL)	{
		printf(" %d ", node->m_data);
		node = node->m_next;
	}
}

//check if exists element, returns 1 if true
int list_ifExists_element(list_t list, list_element_t elem) 
{
	struct Node *node = list->m_head;
	while (node != NULL) 
	{
		if (node->m_data == elem) return 1;
		node = node->m_next;
	}
	return -1;
}

// delete element from list at index, or can be changed to by value(m_data)
int list_delete_element(list_t list, int index) 
{
	if (index > list->m_size - 1)
		return -1;

	if (list->m_size == 0)
		return -2;

	struct Node *temp = list->m_head;
	if (index == 0)
	{
		list->m_head = temp->m_next;
		free(temp);
		temp = NULL;
		return 0;
	}

	// Previous node from the one designated for delete
	for (int i = 0; temp != NULL && i < index-1; i++)
		temp = temp->m_next;
	//Node m_next from one to be deleted
	struct Node *m_next = temp->m_next->m_next;
	free(temp->m_next);
	temp = NULL;
	temp->m_next = m_next;
	list->m_size--;
	return 0;
}

