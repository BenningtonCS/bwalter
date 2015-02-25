/* file: 05stack.c
 * date: 2014 October
 * author: Brendon Walter
 * 
 * hacakathon problem 5: "Modify your stack and queue implementations to also
 * return a running sum of all the items in the queue and on the stack." 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "../refs/linkedListInt.h"
 
// struct for stack
typedef struct {
	NodePtr top;
	int length;
	int sum;
} StackType, *Stack;

/* Parameters: none
 * Returns: pointer to stack struct
 *			NULL if malloc fails
 * initializes the stack
 */
Stack initStack() {
	Stack sp = (Stack)malloc(sizeof(StackType));
	if (sp == NULL) return NULL;
	sp->top == NULL;
	sp->length = 0;
	sp->sum = NULL;
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
 *		int value to be added to stack
 * Returns: 
 * adds a new integer to the stack
 */
int push(Stack s, int n) {
	if (s == NULL) return -1;
	insertHead(&(s->top), n);		// insert function from linkedListInt.c
	s->length += 1;
	s->sum += n;
}

/* Parameters:
 *		pointer to the stack
 *		output: int value that is popped
 * Returns: 1 if success
 *			0 if stack is empty
 *		   -1 if error
 * pops the top item from the stack
 */
int pop(Stack s, int *n) {
	if (s == NULL || n == NULL) return -1;
	if (isEmpty(s)) return 0;	// check if stack is empty
	*n = s->top->data;
	
	// for below, could call headDelete() instead
	NodePtr tmp = s->top;
	s->top = s->top->next;
	s->length -= 1;
	s->sum -= *n;
	free(tmp);
	return 1;
}

int main(void) {
	Stack s = initStack();

	int i;
	for (i=0;i<5;i++)
		push(s, i);

	int d;
	printf("Length: %d\tSum: %d\n", s->length, s->sum);
	pop(s, &d);
	printf("Length: %d\tSum: %d\n", s->length, s->sum);
	pop(s, &d);
	printf("Length: %d\tSum: %d\n", s->length, s->sum);
}
