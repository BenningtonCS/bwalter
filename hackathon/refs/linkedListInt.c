/* file: circularLinkedList.c
 * date: 2014 October 11
 * author: Brendon Walter
 *
 * implementation of a linked list of ints 
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedListInt.h"


/* Parameters: value of a new node
 * Returns: a pointer to the newly created node
 * creates a new node and puts the given data into it
 */
NodePtr makeNode(int n) {
    NodePtr np = (NodePtr)malloc(sizeof(Node)); // allocate memory
    np->data = n;       // input the data into the new node
    np->next = NULL;    // points to NULL for now  
    return np;          // return the newly created node
}   

/* Parameters: Pointer to top, value of new node
 * Returns: nothing
 * creates a new node and adds it to the head of the linked list
 */
void insertHead(NodePtr *top, int n) {
    NodePtr np = makeNode(n);	// create node
    np->next = *top;			// np points to the previously added node
	*top = np;					// top now points to np
}

/* Parameters: pointer to top of list
 * Returns: nothing
 * deletes node from top of the list
 */
void deleteHead(NodePtr *top) {
	if (top != NULL && *top != NULL) {
		NodePtr old = *top;
		*top = (*top)->next;
		free(old);
	}
}

/* Parameters: pointer to top of list
 * Returns: none
 * iterates through a linked list and prints each node out
 */
void printList(NodePtr top) {
    while (top != NULL) {
		printf("%d\n", top->data);
		top = top->next;
	}
}
