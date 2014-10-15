/* file: problem1.c
 * date: 2014 October 14
 * author: Brendon Walter
 *
 * Stack Lab problem 1: "Using a character-based linked-list-backed stack, write
 * a program that prompts the user to enter a string, and reads that string from 
 * the keyboard into a stack, and then prints the string out in reverse 
 * character order to the screen."
 */

#include <stdio.h>
#include "stack.h"

/* Parameters: pointer to a stack
 * Returns: none
 * gets a string from the user and puts it character by character into the stack
 */
void getString(Stack s) {
	char c = getchar();		// get char
	while (c != '\n') {		// so long as the user doesn't hit enter
		push(s, c);			// put the character onto the stack
		c = getchar();		// and get another character
	}
}

/* Paramters: Pointer to a stack
 * Returns: none
 * pops each character off the stack and prints the character as it goes
 */
void printBack(Stack s) {
	char c;					// value to store each popped item
	int n = pop(s, &c);		// pop the first item
	while(n != 0) {			// so long as there are more items on the stack
		printf("%c", c);	// print the poppped item
		n = pop(s, &c);		// and get the next one
		
	}
	printf("\n");
}

int main(void) {
	Stack s = initStack();
	getString(s);
	printBack(s);
}