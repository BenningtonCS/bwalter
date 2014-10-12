/* file: 3_1.c
 * date: 2014 October 11
 * author: Brendon Walter
 *
 * chapter 3 problem 1 from Data Structure in C: "Write a function which, given 
 * a pointer to a linked list of integers, returns 1 if the list is sorted in 
 * ascending order and 0 if otherwise."
 */

#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"

/* Parameters: pointer to top
 * Returns: 1 if the list is sorted in ascending order, 0 if not
 * Checks a linked list of integers to see if they're in ascending order or not
 */
int isAscending(NodePtr top) {
    if (top == NULL) {              // if top points to nothing
        printf("List is empty\n");  // the list is empty
        return 0;                   // and thus can't be in ascending order
    }

    NodePtr np = top->next;         // create new pointer at head of list

    while (np->next->data >= np->data) {    // check if next data is larger
        np = np->next;                      // if it is, walk through the list
        if (np->next->data >= top->next->data)  // check for end of list
            return 1;           // if you made it here, it's in ascending order
    }

    return 0;                   // otherwise it's not
}

int main(void) {
    NodePtr sTop, nTop, test;
    sTop = NULL;    // sorted in ascending order
    nTop = NULL;    // non-ascended sort 

    int i;
    for (i=0;i<5;i++)
        insert(&nTop, i);
    for (i=4;i>=0;i--)
        insert(&sTop, i);

    printf("sTop\n");
    printList(sTop);
    printf("\nnTop\n");
    printList(nTop);

    printf("\n");
    if (isAscending(sTop)) printf("sTop is in ascending order\n");
    if (!isAscending(nTop)) printf("nTop is not in ascending order\n");
}
