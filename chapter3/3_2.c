/* file: 3_2.c
 * date: 2014 October 11
 * author: Brendon Walter
 *
 * problem 3.2: "Write code to reverse the nodes of a linked list by 
 * manipulating pointer fields only. No new nodes must be created."
 */

#include <stdio.h>
#include "circularLinkedList.h"


void reverse(NodePtr *top) {
    NodePtr np, prev;
    np = *top;
   
    int i=0; 
    while (prev->next != *top) {
        prev = findPrev(*top, np->data);
        np->next = prev;
        np = np->next;
        printf("%d", i);
        i++;
    }

    *top = np;
}


int main(void) {
    NodePtr top = NULL;
    int i;
    for (i=0;i<5;i++)
        insert(&top, i);

    printList(top);
    reverse(&top);
    printList(top);
}
