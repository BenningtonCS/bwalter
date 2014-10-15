#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    char data;
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
void insertHead(NodePtr *top, int n);

/* Parameters: pointer to top of list
 * Returns: nothing
 * deletes node from top of the list
 */
void deleteHead(NodePtr *top);

/* Parameters: pointer to top of list
 * Returns: none
 * iterates through a linked list and prints each node out
 */
void printList(NodePtr top);

#endif