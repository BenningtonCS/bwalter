/* file: 3_3.c
 * date: 2014 October 12
 * author: Brendon Walter
 *
 * Problem 3.3: "Write a function to sort a linked list of integers as follows:
 *      (a) Find the largest value in the list.
 *      (b) Delete it from its position and insert it at the head of the list.
 *      (c) Starting from what is now the second element, repeat (a) and (b).
 *      (d) Starting from what is now the third element, repeat (a) and (b).
 *
 *      Continue until the list is sorted."
 */

#include <stdio.h>
#include "circularLinkedList.h"

/* Parameters: pointer to top of linked list
 * Returns: node with largest value or NULL if the list is empty
 * Finds the node in a linked list that has the largest integer
 */
NodePtr findLargest(NodePtr top) {
    NodePtr np = top;
    NodePtr largest;
	largest->data = -1;

    if (top == NULL) {					
        printf("List is empty\n");
        return NULL;
    }

	// while loop checks to see if the current node is larger than the largest
	// one found. If it is, it sets it as the new largest and continues to
	// walk through the list
    while (np != NULL) {		
        if (np->data > largest->data)	
            largest = np;
        np = np->next;			// walk through list
        if (np == top) break;	// reached end of list
    }

    return largest;				// return the largest node
}

int main(void) {
    NodePtr top = NULL;
    int i;

    for (i=0;i<10;i+=2)
        insert(&top, i);
    for (i=1;i<10;i+=2)
        insert(&top, i);
    
    printf("Original list\n");
    printList(top);

	findLargest(top);
    //sortList(&top);
    printf("Sorted list\n");
    printList(top);
}
