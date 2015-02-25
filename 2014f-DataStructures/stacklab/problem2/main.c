/* file: problem2.c
 * date: 2014 October 14
 * author: Brendon Walter
 *
 * Stack Lab problem 2: "Alter your stack data to store a linked list (well, a
 * Node*) as its data. Create a stack of linked lists. Push some number of items
 * onto the stack. Then, pop items off the stack, where each item that gets
 * popped off of the stack is transversed, printed, and freed."
 */

#include <stdio.h>
#include "stack.h"
#include "linkedList.h"


int main(void) {

	NodePtr top1, top2, top3;
	top1 = top2 = top3 = NULL;
	Stack s = initStack();
	int i;
	
	for (i=0;i<5;i++) {				// put values into each linked list
		insertHead(&top1, i);
		insertHead(&top2, i+5);
		insertHead(&top3, i+10);
	}
	
	// print the address of top for each linked list
	printf("1: %p\t2: %p\t3: %p\n\n", top1, top2, top3);
		
	// push each list onto the stack
	push(s, top1);
	push(s, top2);
	push(s, top3);
	
	NodePtr np;
	int a = pop(s, &np);
	while (a != 0) {			// so long as there's data in the stack
		printf("%p\n", np);		// print the address of the top
		printList(np);			// print the list that top points to
		a = pop(s, &np);		// pop the next item
		printf("\n");
	}
}