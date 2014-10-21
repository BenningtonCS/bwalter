/* file: main.c
 * date: 2014 October 15
 * author: Brendon Walter
 *
 * Stack Lab problem 3
 */
 
#include <stdio.h>
#include "stack.h"
#include "linkedList.h"

/* Parameters: pointer to the first character of a string
 * Returns: the length of the string or -1 if the string is NULL
 * finds the number of characters in a given string
 */
int getLength(char* string) {
	if (string == NULL) return -1;	// NULL check
	int length = -1;			
	char c;
	while (c != '\0') {				// iterate through string until the end 
		c = string[length+1];		// go to next character 
		length++;					// increment the total length
	}
	return length;
}

/* Paramters: pointer to the first character of a url
 * Returns: 
 * breaks a given URL into sections
 */
char* breakURL(char* url) {
	int i, length = getLength(url);
    NodePtr section = letters = NULL;

    for (i=0;i<length;i++) {
        if (url[i] != '/') 
                
	}
}

int main(void) {

    Stack s = initStack();

	char* url1 = "http://cs.bennington.edu/courses/fs2014/cs4170.01/";
	char* url2 = "http://cs.bennington.edu/courses/fs2014/cs4170.01/index.html";

	breakURL(url1);
}
