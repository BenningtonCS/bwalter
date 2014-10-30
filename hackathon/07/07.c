/* file: 07.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 7: "Write a function that converts a linked list of 
 * integers into an array of integers. If there are i elements in the linked 
 * list, then there must be exactly i elements in the array as well."
 */

#include <stdio.h>
#include <stdlib.h>
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

/* Parameters: Pointer to top of linked list to be converted
 * Returns: Converted array of ints
 * Converts a linked list to an array of the same length
 */
int* convertList(NodePtr top) {
	int i, length = getLength(top);	// get length of linked list
	int *arr = (int*)malloc(sizeof(int) * length);	// initialize array
	if (arr == NULL) exit(1);

	for (i=0;i<length;i++) {	// for each element of the list
		arr[i] = top->data;		// copy the data from the list to the array
		top = top->next;		// walk to next node in linked list
	}

	return arr;
}

int main(void) {
	NodePtr top = NULL;

	int i, l = 10;
	for (i=0;i<l;i++)
		insertHead(&top, i);

	int* arr = convertList(top);

	for (i=0;i<l;i++)
		printf("%d\n", arr[i]);
}
