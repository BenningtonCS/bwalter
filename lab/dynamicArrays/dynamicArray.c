/* file: dynamicArray.c
 * date: 2014.09.30
 * author: Brendon Walter
 *
 * Dynamic Arrays Lab problem #2
 */

#include <stdio.h>
#include <stdlib.h>

/* Initializes an array and returns a pointer to said array
 */
int* initArray() {
	int* array = malloc(sizeof(int)*2);	// malloc space for the array
	array[0] = sizeof(int)*2;		// will be used memory
	array[1] = sizeof(int)*2;		// will be available memory
	return array;
}

/* Insert a new element at the end of the list
 */
void insertValue(int* array, int value) {
	int length = getLength(array);
	checkSize(array);			// check to make sure there's enough room
	array[length+2] = value;	// go to end of the list and add the value
	array[0] += sizeof(int);	// increase size of used space
}

/* Checks the size of the array and if there's not enough room, doubles the size
 * It currently returns an int because when it returned void the compiler yelled
 * at me...
 */
int checkSize(int* array) {
	if (array[0] == array[1]) {	// if there's no more room in the array
		array = realloc(array, array[1] * 2);	// double the memory
		array[1] *= 2;			// change array[1] to reflect this change
	}
	return 0;
}

/* Takes a pointer to an array and returns the length as an integer.
 */
int getLength(int* array) {

	// a[0] holds the size of the array, so the length can be found by dividing
	// that number by the size of an int, and subtract the first element from
	// that as it does not contain anything other than the size.
	int length = array[0] / sizeof(int) - 2;
	return length;
}

/* Takes a pointer to an array and prints out each value. Returns nothing.
 */
void printList(int* array) {
	int i, length;
	length = getLength(array);		// find length of array
	for (i=2;i<=length+1;i++)			// print each element
		printf("element %d:\t%d\n", i-2, array[i]);
}

int main(void) {
	int *myarray = initArray();

	int i;
	for (i=0;i<5000;i++) {
		insertValue(myarray, i);
	}	
	printList(myarray);
	printf("\n");
    printf("Used:\t\t%d\n", myarray[0]);
	printf("Available:\t%d\n", myarray[1]);
	printf("Length:\t\t%d\n", getLength(myarray));

    return 0;
}
