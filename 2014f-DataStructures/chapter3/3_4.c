/* file: 3_4.c
 * date: 2014 October 12
 * author: Brendon Walter
 *
 * Problem 3.4: "Write a function to free all the nodes of a given linked list"
 */

#include <stdio.h>
#include "circularLinkedList.h"

/* Parameters: pointer to top of linked list
 * Returns: nothing
 * Calls delete to delete all items in a linked list starting from the top
 */
void deleteAll(NodePtr *top) {
    while (*top != NULL) {          // so long as there are more nodes
        delete(top, (*top)->data);  // delete the top node
    }
}


int main(void) {
    NodePtr top;
    int i;
    for (i=0;i<10;i++)
        insert(&top, i);

    printf("Initial list\n");
    printList(top);
    printf("Deleting all nodes\n");
    deleteAll(&top);
    printf("All nodes deleted. New list:\n");
    printList(top);
}
