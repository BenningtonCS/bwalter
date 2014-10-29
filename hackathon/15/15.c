/* file: 15.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 15: "Implement a sorted linked list, where the contents of
 * the list are kept sorted at all times. Support at least the following 
 * functions: insertItem, deleteItem, findItem (by value), modifyItems (modifies
 * all items in the list with original value of V to have new value W)."
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	NodePtr top = NULL;

	insertItem(&top, 5);
	insertItem(&top, 4);
	insertItem(&top, 2);
	insertItem(&top, 10);
	insertItem(&top, 5);
	insertItem(&top, 7);

	printf("\nInitial list\n");
	printList(top);

	NodePtr f, p;
	printf("\nSearching for 8\n");
	if (findItem(top, 8, &f, &p))
		printf("%d found at %p\n", f->data, f);
	printf("\nSearching for 5\n");
	if (findItem(top, 5, &f, &p))
		printf("%d found at %p\n", f->data, f);

	printf("\nDeleting 2 and 7\n");
	deleteItem(&top, 2);
	deleteItem(&top, 7);
	printList(top);

	printf("\nModifying 5 to 11\n");
	modifyItems(&top, 5, 11);
	printList(top);
}
