/* file: 00.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 0: "Write a function that computes the average contents of 
 * a linked list of integers."
 */

#include <stdio.h>
#include "../refs/linkedListInt.h"

/* Parameters: Pointer to top of linked list
 * Returns: mean of list, -1 if list is empty
 * Goes through a linked list of ints and sums up the values of each node. 
 * Divides the total but the number of nodes and then both prints and returns 
 * the resulting mean.
 */
float averageList(NodePtr top) {
	if (top == NULL) return -1;	// NULL check

	float average = 0;
	int count = 0;
	
	while (top != NULL) {		// so long as we're not at the end of the list
		average += top->data;	// add the number in the node to the total
		count++;				// increase the count
		top = top->next;		// walk through the list
	}
	average /= count;			// the mean is the total divided by the size

	printf("Average: %.2f\n", average);
	return average;
}

int main(void) {
	NodePtr top = NULL;
	int i;
	
	for (i=12;i<17;i++) {
		insertHead(&top, i);
	}

	averageList(top);
}
