/* file: stackArray.c
 * date: 2014 October 14
 *
 * implementation of a stack via arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linkedList.h"

#define MAXSTACK 100	// maximum number of items in the stack

/* Parameters: None
 * Returns: A pointer to a stack
 * initializes a stack and returns a pointer to said stack 
 */
Stack initStack() {
	Stack sp = (Stack)malloc(sizeof(StackType));
	if (sp == NULL) return NULL;	// NULL check malloc
	sp->top = -1;			// set value to top to be -1 as an impossible index
	return sp;
}

/* Parameters: pointer to a stack
 * Returns: 1 if stack is empty
 *			0 if full
 *		   -1 if error
 * checks to see if the given stack is empty or not
 */
int isEmpty(Stack s) {
	if (s == NULL) return -1;	// stack hasn't been initialized
	return (s->top == -1);		// returns 1 if true, 0 if false
}

/* Parmeters: 
 *		Pointer to a stack
 *		NodePtr to linked list to be added
 * Returns: 0 if success
 *		   -1 if failure / error
 *			exits if stack overflow occurs
 * adds value to the stack			
 */
int push(Stack s, NodePtr n) {
	if (s == NULL) return -1;
	if (s->top == MAXSTACK-1) exit(1);	// stack overflow!
	++(s->top);							// increment top
	s->ST[s->top] = n;					// add value to stack
	return 0;
}

/* Parameters: 
 *		pointer to a stack
 *		output: pointer to value that is the restult of pop
 * Returns: n as an output parameter
 *		   -1 if the stack or the value passed in are NULL
 *			0 if stack is empty
 *			1 if success
 * pops the top item off the stack
 */
int pop(Stack s, NodePtr *n) {
	if (s == NULL || n == NULL) return -1;	// check if paramters are valid
	if (isEmpty(s)) return 0;		// check if the stack is empty
	*n = s->ST[s->top];				// set output paramter to popped value
	--(s->top);						// decrement top
	return 1;
}