/* file: circularLinkedList.c
 * date: 2014/09/25
 * author: Brendon Walter
 *
 * Linked Lists Assignment task #1
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} Node, *NodePtr;

/* creates a new node that contains value n
 */ 
NodePtr makeNode(NodePtr top, int n) {
	NodePtr np = (NodePtr)malloc(sizeof(Node));	// allocate memory
	np -> data = n;			// set data to the value passed in
	np -> next = top;		// have it point back to top to make it circular
	return np;				// return a pointer to the new node

}

/* Insert a new node with value n at the head of the linked list
 */
void insert(NodePtr top, int n) {
	NodePtr np = makeNode(top, n);	// make a new node pointer
	np -> next = top -> next;		// set the new pointer to point to where 
									// top did
	top -> next = np;				// set top to point to the new pointer
}

/* itterates through the list to find the given value n
 */
NodePtr search(NodePtr top, int n) {
	NodePtr np;
	np = top;
	while(np->data != n) {			// so long as the data is not n
		np = np->next;				// go to the next pointer
		if (np->next == top->next)	// if the next node is top
			return NULL;			// you're at the end of the list
	}
	return np;						// return the found node
}

/* Searches for a node in top with value n. Then deletes it from the list.
 */
void delete(NodePtr top, int n) {
	NodePtr np, prev;
	np = search(top, n);	// set np to the node returned from seach()

	if (np == NULL) {		// if the value doesn't exist
		printf("Node with value %d not found\n", n);
		return;				// return nothing
	}

	prev = top;

	while(prev->next->data != np->data) // find the previous node
		prev = prev->next;

	prev->next = prev->next->next;		// remove node from the list
	
	free(np);	// free space in memory
}


/* Iterates through the linked list and prints out the node address, the data in
 * the node, and a pointer to the address of the next node.
 */
void printList(NodePtr top) {

	NodePtr np = top;
	printf("top : %p\n", top);

	if (np -> next == NULL)			// if np is the only node
		printf("List is empty\n");	// it means the list is empty

	while(np -> next != NULL) {		// while np isn't the only node
		printf("node: %p data: %d next: %p\n", np, np->data, np->next);
		np = np -> next;			// print the data and set np to next node
		if (np->next == top->next)	// keep from printing forever
			break;
	}

}

int main(void) {

	NodePtr top, np, last;
	top -> next = NULL;

	// put intial values into list
	int i;
	for(i=0;i<5;i++) {
		np = makeNode(top, i);
		if(top->next == NULL)
			top->next = np;
		else last->next = np;	// I'm really not sure why this is here
		last = np;				// but it won't run correctly without it :/
	}
	
	printf("\nINITIAL LIST\n");
	printList(top);

	printf("\nADDING 40 TO HEAD\n");
	insert(top, 40);
	printList(top); 

	printf("\nADDING 60 TO HEAD\n");
	insert(top, 60);
	printList(top); 

	printf("\nREMOVING 3 FROM LIST\n");
	delete(top, 3);
	printList(top);

	printf("\nREMOVING 6 FROM LIST\n");
	delete(top, 6);
	printList(top);

	printf("\nSearching for %d, found at %p\n", 2, search(top, 2));
	printf("\nSearching for %d, found at %p\n", 6, search(top, 6));

	return 0;
}