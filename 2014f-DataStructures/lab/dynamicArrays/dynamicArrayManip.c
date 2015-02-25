/* file: dynamicArray.c
 * date: 2014.09.30
 * author: Brendon Walter
 *
 * Dynamic Arrays Lab problem #2 and #3
 */

#include <stdio.h>
#include <stdlib.h>

int used;	// memory in array that is currently being used
int total;	// total memory that the array has available to use

/* Initializes an array and returns a pointer to said array
 */
int* initArray() {
	int* array = malloc(sizeof(int));	// malloc space for the array
	array[0] = 0;
	used = 4;	// 4 bytes of memory being used at init
	total = 4;	// array has a total of 4 bytes of memory currently
	return array;
}

/* Insert a new element at the end of the list
 */
void insertValue(int* array, int value) {
	int length = getLength(array);
	checkSize(array);			// check to make sure there's enough room
	array[length] = value;		// go to end of the list and add the value
	used += sizeof(int);		// increase size of used space
}

/* Insert a new value after a given value into the array
 */
void insertAfter(int* array, int value, int before) {
	int length = getLength(array);		// find the length of the array
	int place = search(array, before);	// find the place of the element
	if (place == -1) return;			// error handling (element not found)
	checkSize(array);					// make sure the array's big enough
	int i = length-1;		
	while (array[i] != before) {		// go through list backwards
		array[i+1] = array[i];			// move each value over until you get
		i--;							// to the one that is before the new one
	}
	array[place+1] = value;				// add new value to the list
	used += sizeof(int);				// increase size of used
}

/* Removes an item from the array by replacing it with -1
 */
void deleteValue(int* array, int value) {
	int place = search(array, value);	// find location of item in list
	if (place == -1) return;			// error checking

	array[place] = -1;					// replace value with -1

	/* I don't like this. This causes a lot of problems where now it prints
	 * out -1 when I print the list. I could change the way printList works,
	 * but then it runs into problems if you're tying to access a value past
	 * a deleted value. You would have to keep tabs on how many elements were
	 * deleted, where they were delted, and then take that into account whenever
	 * you do anything. It would be easier to remove the item and shift
	 * everything over.
 	 */
}

/* Checks the size of the array and if there's not enough room, doubles the size
 * It currently returns an int because when it returned void the compiler yelled
 * at me...
 */
int checkSize(int* array) {
	if (used == total) {	// if there's no more room in the array
		array = realloc(array, total * 2);	// double the memory
		total *= 2;			// change total to reflect this change
	}
	return 0;
}

/* Given an array, searches through the array for a given value. Returns the 
 * index of the value if found and if not found, returns -1.
 */
int search(int* array, int val) {
	int i, length = getLength(array);
	for (i=0;i<=length;i++) {		// search through entire list
		if (array[i] == val)		// if the value is found
			return i;				// return its place
	}
	return -1;						// element not found
}

/* Takes a pointer to an array and returns the length as an integer.
 */
int getLength(int* array) {

	// a[0] holds the size of the array, so the length can be found by dividing
	// that number by the size of an int, and subtract the first element from
	// that as it does not contain anything other than the size.
	int length = used / sizeof(int);
	return length;
}

/* Takes a pointer to an array and prints out each value. Returns nothing.
 */
void printList(int* array) {
	int i, length;
	length = getLength(array);		// find length of array
	for (i=0;i<length;i++)			// print each element
		printf("element %d:\t%d\n", i, array[i]);
}

int main(void) {
	int *myarray = initArray();

	int i;
	for (i=1;i<5;i++) insertValue(myarray, i);
	
	printList(myarray);

	printf("\n");
	insertAfter(myarray, 10, 0);
	insertAfter(myarray, 10, 1);
	insertAfter(myarray, 15, 2);
	insertAfter(myarray, 20, 3);
	insertAfter(myarray, 25, 4);	
	printList(myarray);
	printf("\n");

	printf("\n");
	deleteValue(myarray, 2);	
	printList(myarray);
	printf("\n");

    printf("Used:\t\t%d\n", used);
	printf("Total:\t\t%d\n", total);
	printf("Length:\t\t%d\n", getLength(myarray));

    return 0;
}
