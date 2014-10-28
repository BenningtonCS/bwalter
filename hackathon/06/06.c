/* file: 06.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 6: "Write a function that takes as its input a pointer to
 * the top of a stack containing some number of items. This function then takes
 * that stack, and divides it into two new stacks, with one stack containing the
 * first half of the items, while the second stack holds the second half of the
 * items."
 */

#include <stdio.h>
#include "../refs/stack.h"

/* Parameters: pointer to stack to be broken, pointers to two stacks for the 
 * 	first stack to be broken into
 * Returns: 0 if error, 1 if success
 * Breaks a stack in half and puts the stacks into two seperate stacks
 */
int breakStack(Stack s, Stack one, Stack two) {

	if (s == NULL || one == NULL || two == NULL) return 0;

	Stack tmp = initStack();	// create temporary stack

	int length = getLength(s);	// total length of initial stack
	int half = length / 2;		// half the length of init stack
	int i, d, n;

	d = pop(s, &n);				// pop items off the init stack
	while (d == 1) {			// and so long as there are items in it
		push(tmp, n);			// put it into the temporary stack
		d = pop(s, &n);			// and continue
	}

	for (i=0;i<half;i++) {		// put the first half of the items from tmp
		pop(tmp, &n);			// into the first stack
		push(one, n);
	}

	for (i=half;i<length;i++) {	// and the second half into the other
		pop(tmp, &n);
		push(two, n);
	}

	return 1;
	
}

int main(void) {

	// initialize stacks
	Stack s = initStack();
	Stack one = initStack();
	Stack two = initStack();

	int i;
	for (i=0;i<10;i++)
		push(s, i);				// fill init stack

	breakStack(s, one, two);

	int n, d = pop(one, &n);

	printf("first list:\n");	// print out contents of first list
	while (d == 1) {
		printf("%d\n", n);
		d = pop(one, &n);
	}

	d = pop(two, &n);
	printf("second list:\n");	// and then the contents of the second`
	while (d == 1) {
		printf("%d\n", n);
		d = pop(two, &n);
	}
}
