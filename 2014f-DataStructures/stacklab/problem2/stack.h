#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100

#include "linkedList.h"


// struct for stack
typedef struct {
	int top;
	NodePtr ST[MAXSTACK];	// creates an array of pointers to linked lists
} StackType, *Stack;

/* Parameters: none
 * Returns: pointer to stack struct, NULL if malloc fails
 * initializes the stack
 */
Stack initStack();

/* Parameters: pointer to the stack
 * Returns: 1 if stack is empty, 0 if stack is not empty, -1 if error
 * checks to see if the stack is empty or not
 */
int isEmpty(Stack s);

/* Parameters: Pointer to the stack, int value to be added to stack
 * Returns: 
 * adds a new integer to the stack
 */
int push(Stack s, NodePtr n);

/* Parameters: pointer to the stack, output: int value that is popped
 * Returns: 1 if success, 0 if stack is empty, -1 if error
 * pops the top item from the stack
 */
int pop(Stack s, NodePtr *n);

#endif