/* file: 07.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 7: "Write a function that converts a linked list of 
 * integers into an array of integers. If there are i elements in the linked 
 * list, then there must be exactly i elements in the array as well."
 */

#include <stdio.h>
#include "../refs/linkedListInt.h"

/* Paramters: Pointer to top of linked list
 * Returns: Length of the linked list
 * Finds the length of a given linked list
 */
int getLength(NodePtr top) {
	int length = 0;

	while (top != NULL) {	
		top = top->next;	// iterate through linked list
		length++;			// increment length each pass
	}
	return length;
}

int convertList(NodePtr top, int* arr) {
	int i, length = getLength(top);
	int a[length];

	for (i=0;i<length;i++) {
		a[i] = top->data;
		top = top->next;
	}
	arr = a;

//	return arr;
}

int main(void) {
	NodePtr top = NULL;

	int i, l = 10;
	for (i=0;i<l;i++)
		insertHead(&top, i);

	int arr;
	convertList(top, &arr);

	for (i=0;i<l;i++)
		printf("%d\n", arr[i]);
}
