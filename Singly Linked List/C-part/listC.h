#ifndef LISTC_H
#define LISTC_H

typedef int list_element_t;  //list element type definition
typedef struct list_tag *list_t; //list structure def

list_t list_new(); //new empty list
void list_delete(list_t list); //delete list
void list_push(list_t list, list_element_t elem);//add element to list (push)
void list_insert_at(list_t list, list_element_t elem, int pos);//insert at position pos
void list_print(list_t list);//print all list elements
int list_delete_element(list_t list, int index);//delete element
int list_ifExists_element(list_t list, list_element_t elem);//check if exists element, returns 1 if true

#endif // !LISTC_H
