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
	NodePtr top = NULL;
	Stack s = initStack();
	int i;
	NodePtr n;
	
	for (i=0;i<5;i++)
		insertHead(&top, i);
	
	printf("%p\n", top);
		
	push(s, top);
	pop(s, &n);
	
	printf("%p\n", n);
	
}