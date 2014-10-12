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

int main(void) {
    NodePtr sTop, nTop;
    sTop = NULL;    // sorted in ascending order
    nTop = NULL;    // non-ascended sort 

    int i;
    for (i=0;i<10;i++)
        insert(&sTop, i);
    for (i=9;i>=0;i++)
        insert(&nTop, i);

    printf("am I here?\n");

    printList(sTop);
    printList(nTop);

}
