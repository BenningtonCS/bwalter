/* file: doublyLinkedList.c
 * date: 2014/09/29
 * author: Brendon Walter
 *
 * Linked Lists Assignment task #2
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
} Node, *NodePtr;

/* creates a new node that contains value n
 */ 
NodePtr makeNode(NodePtr top, int n) {
	NodePtr np = (NodePtr)malloc(sizeof(Node));	// allocate memory
	np -> data = n;			// set data to the value passed in
	np -> next = NULL;		// next points to nothing
	np -> prev = NULL;		// neither does prev (yet)
	return np;				// return a pointer to the new node
}

/* Insert a new node with value n at the head of the linked list
 */
void insert(NodePtr top, int n) {

	NodePtr np = makeNode(top, n);
	np -> next = top;
	top -> prev = np;
	top = np;

}


/* Iterates through the linked list and prints out the node address, the data in
 * the node, and a pointer to the address of the next node.
 */
void printList(NodePtr top) {

	NodePtr np = top;
	printf("top : %p\n", top);

	if (np -> next == NULL)			// if np is the only node
		printf("List is empty\n");	// it means the list is empty

	while(np != NULL) {				// while np isn't the last
		printf("node: %p data: %d prev: %p next: %p\n", 
				np, np -> data, np -> prev, np -> next);
		np = np -> next;			// print the data and set np to next node
	}

}

int main(void) {

	NodePtr top, np, last;
	np = makeNode(top, 0);
	top -> next = np;

	insert(top, 1);

	printf("\nINITIAL LIST\n");
	printList(top);


	printf("\nADDING 40 TO HEAD\n");
	insert(top, 40);
	printList(top); 

	printf("\nADDING 60 TO HEAD\n");
	insert(top, 60);
	printList(top);


	return 0;
}