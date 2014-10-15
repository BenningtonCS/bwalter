/* file: stackLinkedList.c
 * date: 2014 October 14
 * 
 * implementation of a stack using liked lists
 */

#include <stdlib.h>
#include "stack.h"

/* Parameters: none
 * Returns: pointer to stack struct
 *			NULL if malloc fails
 * initializes the stack
 */
Stack initStack() {
	Stack sp = (Stack)malloc(sizeof(StackType));
	if (sp == NULL) return NULL;
	sp->top == NULL;
	return sp;
}

/* Parameters: pointer to the stack
 * Returns: 1 if stack is empty
 *			0 if stack is not empty
 *		   -1 if error
 * checks to see if the stack is empty or not
 */
int isEmpty(Stack s) {
	if (s == NULL) return -1;	// stack hasn't been initialized
	return (s->top == NULL);	// returns 1 if true, 0 if false
}

/* Parameters: 
 *		Pointer to the stack
 *		char value to be added to stack
 * Returns: 
 * adds a new integer to the stack
 */
int push(Stack s, char n) {
	if (s == NULL) return -1;
	insertHead(&(s->top), n);		// insert function from linkedList.c
}

/* Parameters:
 *		pointer to the stack
 *		output: char value that is popped
 * Returns: 1 if success
 *			0 if stack is empty
 *		   -1 if error
 * pops the top item from the stack
 */
int pop(Stack s, char *n) {
	if (s == NULL || n == NULL) return -1;
	if (isEmpty(s)) return 0;	// check if stack is empty
	*n = s->top->data;
	
	// for below, could call deleteHead() instead
	NodePtr tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	return 1;
}