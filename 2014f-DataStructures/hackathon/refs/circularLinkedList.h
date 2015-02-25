#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

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
void insert(NodePtr *top, int n);

/* Parameters: pointer to top of list, value to search for
 * Returns: Pointer to the found pointer
 * Searches through the list to find a given value, then returns a pointer to it
 */
NodePtr searchList(NodePtr top, int n);

/* Parameters: pointer to top of list, value that you want to find the the 
 * prevoius node of
 * Returns: pointer to the previous node, or NULL if the current node doesn't
 * exist
 * Walks through the list to find the node that points to the node that 
 * contains value 'n'
 */
NodePtr findPrev(NodePtr top, int n);

/* Parameters: pointer to top of the list, value to delete
 * Returns: 0 if value not found, 1 if opperation was a success
 * searches through a list to find the value to delete, fixes pointers of nodes
 * around the node, and then frees its place in memory
 */
int delete(NodePtr *top, int n);

/* Parameters: pointer to top of list
 * Returns: none
 * iterates through a linked list and prints each node out
 */
void printList(NodePtr top);

#endif
