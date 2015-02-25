#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node *next;
} Node, *NodePtr;

/* Parameters: value of a new node
 * Returns: a pointer to the newly created node 
 * creates a new node and puts the given data into it
 */
NodePtr makeNode(int n);

/* Parameters: Pointer to top, value of new node
 * Returns: nothing     
 * creates a new node and adds it to the linked list
 */
void insertItem(NodePtr *top, int n);

/* Parameters: pointer to top of list
 * Returns: nothing
 * deletes node int list with value 'n'
 */     
void deleteItem(NodePtr *top, int n);

/* Parameters: pointer to top of a linked list, value to find
 *      OUTPUT PARAMETERS: found node, node previous to found node
 * Returns: None
 * Finds an item in a linked list and gives that item as well as its previous
 * item as an output parameter
 */
int findItem(NodePtr top, int n, NodePtr *found, NodePtr *prev);

/* Parameters: Pointer to top of list, old value to be modified, new value
 * Returns: None
 * Modifies each node with value 'old' to have the new value 'new'
 */
void modifyItems(NodePtr *top, int old, int new);

#endif
