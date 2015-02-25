/* file: 01.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hacakthon problem 1: "Write a sum function that takes the sum of the contents
 * of circularly linked list of integers"
 */

#include <stdio.h>
#include "../refs/circularLinkedList.h"


/* Paramters: Pointer to top of a linked list
 * Returns: Sum of all nodes, -1 if top is NULL
 * Iterates through a circular linked list and sums up the data from each node
 */
int sumList(NodePtr top) {
	if (top == NULL) return -1;	// NULL check

	NodePtr np = top;
	int sum = 0;

	while (np != NULL) {
		sum += np->data;		// add data from node to the sum
		np = np->next;			// walk through list
		if (np == top) break;	// break once we reach the end of the list
	}

	printf("Sum of list: %d\n", sum);
	return sum;
}

int main(void) {
	NodePtr top = NULL;
	int i;

	for (i=0;i<10;i++) 
		insert(&top, i);

	sumList(top);
}
