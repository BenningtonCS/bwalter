/* file: 16stack.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 16: "Write a function that tells the users if a stack is
 * sorted."
 */

#include <stdio.h>
#include "../refs/stack.h"

/* Parameters: Pointer to top of stack
 * Returns: 0 if not sorted, 1 if sorted
 * Iterates through a stack and tells if it's sorted or not
 */
int isSorted(Stack s) {
	NodePtr np = s->top;

	while (np->next != NULL) {
		if (np->data > np->next->data) return 0; // next is bigger than current
		np = np->next;				// walk through list
	}

	return 1;
}

int main(void) {
	Stack s = initStack();
	Stack u = initStack();

	int i;

	// unsorted stack
	for (i=0;i<10;i++)
		push(u, i);

	// sorted stack
	for (i=10;i>0;i--)
		push(s, i);

	if(isSorted(s)) printf("stack s is sorted\n");
	if(!isSorted(u)) printf("stack u is not sorted\n");

}
