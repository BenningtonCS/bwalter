/* file: main.c
 * date: 2014 October 15
 * author: Brendon Walter
 *
 * Stack Lab problem 3
 */
 
#include <stdio.h>
#include "stack.h"

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

/* Paramters: pointer to a stack, pointer to the first character of a url
 * Returns: none
 * breaks a given URL into sections and pushes them onto the stack
 */
void breakURL(Stack s, char* url) {
    
    // this doesn't currently work. I can't figure out how to make it work. It's
    // supposed to take a string and go through it until it hits a '/' or a ':'.
    // When it does, it takes all previous characters and puts it into a string
    // and that string is then pushed onto the stack. When the next character is
    // a '/' or a ':', it's supposed to go past those characters and then 
    // continue to put all legal characters into a new string which is then once
    // again added to the stack.
    // Currently, all /s and :s are being added, and instead of creating a
    // string for just the current chunk between /s, it adds everything to a new
    // string. At least it's no longer seg faulting... 

    int length = getLength(url);
    int i, j = 0;
    int slength = 0;
    char c;

    while (j <= length) {               // go through entire string
   
        printf("%c\n", c);

        if (c == ':' || c == '/') {     // when the current character is illegal
            c = url[slength];           // go to the next character
            slength++;                  
        } else {                        // otherwise character is legal

            while (c != '/' && c != ':') {  // walk through string until a / or
                c = url[slength];           // a : is reached and
                slength++;
            }

            printf("slength: %d\n", slength);

            char chunk[slength];        // create a string the length of the
                                        // chunk between /s
            for (i=0;i<slength;i++) {
                chunk[i] = url[i];      // add characters to the chunk
                printf("chunk[%d]: %c\turl[%d]: %c\n", i, chunk[i], i, url[i]);
            }

            push(s, chunk);             // push that chunk onto the stack
            length -= slength;  // indicate that we've gone through a section
        }
        j++;
    }

}

int main(void) {

	Stack s = initStack();

	char* url1 = "http://cs.bennington.edu/courses/fs2014/cs4170.01/";
	char* url2 = "http://cs.bennington.edu/courses/fs2014/cs4170.01/index.html";

    breakURL(s, url1);

    char* n;
    pop(s, &n);
    printf("%s\n", n);
}
