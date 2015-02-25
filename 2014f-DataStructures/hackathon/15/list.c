/* file: list.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * linked list for hackathon problem 15
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
 * creates a new node and adds it to the linked list 
 */
void insertItem(NodePtr *top, int n) {
    NodePtr np = makeNode(n);   // create node

	// if new node is the first node in the list
	if (*top == NULL) {
		*top = np;
		return;
	}

	NodePtr prev = *top;
	NodePtr tmp = *top;

	// if the new node has a value less than the first node
	if (np->data < (*top)->data) {
		np->next = *top;
		*top = np;
		return;
	}

	// if there are other nodes and the value of the new node is greater than
	// the first node
	while (np->data >= tmp->data) {
		if (tmp->next == NULL) {	// reached end of list
			tmp->next = np;			// so the last item points to the new item
			return;
		}
		prev = tmp;					// save previous node
		tmp = tmp->next;			// and walk through the list
	}
	prev->next = np;				// previous node points to new node
	np->next = tmp;					// new node points to the next node

}

/* Parameters: pointer to top of list, value 'n' to be deleted
 * Returns: nothing
 * deletes first node in list with value 'n'
 */
void deleteItem(NodePtr *top, int n) {

	NodePtr np, found, prev;
	found = prev = NULL;
	np = *top;

	// value is at top of the list
	if (np->data == n) {
		*top = np->next;
		free(np);
		return;
	}

	// use findItem function to get the node and previous node
	int m = findItem(*top, n, &found, &prev);
	if (m == 0 || (top == NULL && *top == NULL)) return;
	else {
		prev->next = found->next;	// set prev to the next node
		free(found);				// and free the deleted node
	}
}

/* Parameters: pointer to top of a linked list, value to find
 * 		OUTPUT PARAMETERS: found node, node previous to found node
 * Returns: 0 if item not found, 1 if found
 * Finds an item in a linked list and gives that item as well as its previous
 * item as an output parameter
 */
int findItem(NodePtr top, int n, NodePtr *found, NodePtr *prev) {
	while (top->next != NULL) {
		*prev = top;				// save previous node
		
		top = top->next;			// walk through the list
		if (top->data == n) {		// if the data is found in a node
			*found = top;			// return the found node
			return 1;
		}
	}

	if (top->data == n) {			// if the end of the list was reachedb but
		*found = top;				// the node wasn't found, it might be the
		return 1;					// last node. If it is, set found to it.
	}

	return 0;						// if we reached here, the node wasn't found
}

/* Parameters: Pointer to top of list, old value to be modified, new value
 * Returns: None
 * Modifies each node with value 'old' to have the new value 'new'
 */
void modifyItems(NodePtr *top, int old, int new) {
	NodePtr found, prev;
	found = prev = NULL;

	// repeat for each iteration of the same item
	while (findItem(*top, old, &found, &prev)) {
		deleteItem(top, old);	// delete the node with the old value
		insertItem(top, new);	// and insert a node with the new value
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
