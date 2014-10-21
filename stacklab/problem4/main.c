/* file: main.c
 * date: 2014 October 20
 * author: Brendon Walter
 *
 * Stack Lab problem 4.
 * Validator program checks to make sure brackets match up in a given string
 */

#include <stdio.h>
#include "stack.h"

/* Parameters: pointer to the stack, pointer to a counter, and the data
 * Returns: nothing
 * goes through a given string and takes out all brackets and puts them on the
 * stack in backwards order
 */
void parseStr(Stack s, int* count, char* str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);   // print out the string being parsed
        if (str[i] == '(' || str[i] == ')' ||   // if any one of these
            str[i] == '[' || str[i] == ']' ||   // characters is in the string
            str[i] == '{' || str[i] == '}') {   
            push(s, str[i]);                    // push it onto the stack
            (*count)++;                         //and increment counter
        }
        i++;
    }
    printf("\n");
}

/* Paramters: pointer to the stack, string being checked
 * Returns: 1 if the brackets line up, 0 if they don't
 * goes through a string and checks to see if the brackets in it match up
 */
int checkBrackets(Stack s, char* str) {
  
    // this functin only works for symetrical brackets (i.e. {[()]} ) but does
    // not work for other legitmate types of brackets (i.e. (){[]} ). I can't 
    // figure out the right algorithm to fix this.

    int i, count;
    i = count = 0;

    parseStr(s, &count, str);       // put brackets onto stack

    if (count%2 == 1) return 0;     // there cannot be an odd number of brackets
    int type[count];                // array holds the type ( () vs [] vs {} )
    int state[count];               // array holds the state ( open or closed)

    char n;
    int a = pop(s, &n);                 // start popping items off the stack
    while (a) {
        if (n == '(' || n == ')') {     // if the brackets are ( )
            type[i] = 0;                // set the type as 0
            if (n == '(') state[i] = 0; // if their open, set state as 0
            else state[i] = 1;          // if closed, state is 1
        }
        if (n == '[' || n == ']') {     // if brackets are [ ] 
            type[i] = 1;                // set type as 1
            if (n == '[') state[i] = 0;
            else state[i] = 1;
        }
        if (n == '{' || n == '}') {     // if brackets are { }
            type[i] = 2;                // set state as 2
            if (n == '{') state[i] = 0;
            else state[i] = 1;
        }
        a = pop(s, &n);                 // pop the next item
        i++;
    }
   
    for (i=0;i<count/2;i++)             // checks to make sure ending brackets
        if (state[i] == 0) return 0;    // are closed

    for (i=count/2;i<count;i++)         // checks to make sure opening brackets 
        if (state[i] == 1) return 0;    // are open

    for (i=0;i<count;i++) {
        if (type[i] != type[count-1-i]) return 0;   // checks bracket against
        if (state[i] == state[count-1-i]) return 0; // bracket for type & state
    }

    return 1;       // if we made it here, all brackets match!
    
    
}

int main(void) {

    Stack s = initStack();

    char* str1 = "while (x-- {y++})";  // everything matches
    char* str2 = "if (x) {j[y})";   // brackets do not match
    char* str3 = "()([{}])";

    if (checkBrackets(s, str1)) printf("works\n\n"); 
    if (!checkBrackets(s, str2)) printf("doesn't work\n\n");
    if (!checkBrackets(s, str3)) printf("doesn't work\n\n");
}
