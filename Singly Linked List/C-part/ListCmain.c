#include"listC.h"

int main(void) {

	list_t list = list_new();
	list_push(list, 5);
	list_push(list, 4);
	list_push(list, 3);
	list_push(list, 2);

	list_print(list);
	putchar('\n');
	list_delete_element(list, 2);
	list_print(list);
	putchar('\n');
	list_insert_at(list, 4, 2);
	list_print(list);
	printf("\n%s\n", list_ifExists_element(list, 5) ? "Exists" : "Doesn't exist");

	list_t list2 = list_new();
	list_push(list2, 40);
	list_push(list2, 41);
	list_insert_at(list2, 45 , 1);
	list_print(list2);

	list_delete(list);
	list_delete(list2);

	return 0;
}