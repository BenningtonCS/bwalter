/* file: 2_4.c
 * date: 2014/09/14
 * author: Brendon Walter
 *
 * Problem 2.4: In main, there are two int variables, a and b. Write a function 
 * which, when called, interchanges the values of a and b so that the changes 
 * is known in main.
 */

#include <stdio.h>

/* When the address of two integers are passed into this function, it switches
 * the values of the two.
 */
void switchInts(int* a, int* b) {
    int A = *a;
    int B = *b;
 
    *a = B;
    *b = A;
}

int main(void) {
    int a = 1;
    int b = 2;

    printf("a: %d\tb: %d\n", a, b);
    
    printf("Calling switchInts()\n");
    switchInts(&a, &b);

    printf("a: %d\tb: %d\n", a, b);
}
