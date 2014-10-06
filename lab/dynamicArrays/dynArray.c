/* file: dynArray.c
 * date: 2014.09.30
 * author: Brendon Walter
 *
 * Dynamic Arrays Lab problem #1
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    // allocates memory for 5 000 integers (20 000) bytes
    // same as int myarray[5000]
    int* myarray = malloc(sizeof(int)*5000); 
    
    int i;
    for (i=0;i<5000;i++)
        myarray[i] = i;
    for (i=0;i<5000;i++)
        printf("%d\n", myarray[i]);

    free(myarray);
}
