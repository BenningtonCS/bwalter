/* file: 03.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 3: "Implement binary search over a sorted array of integer
 * pointers."
 */

#include <stdio.h>

/* Paramters: Address of array of pointers, value to find, length of list
 * Returns: Index of the value found (-1 if value doesn't exist)
 * Implementation of a binary search through an array of pointers
 */
int binSearch(int *a[], int key, int max) {
	int min = 0;
	while(max >= min) {
		int mid = (min + max) / 2;	// compute midpoint
		if(*a[mid] == key) return mid;
		if(*a[mid] < key) min = mid + 1; 
		if(*a[mid] > key) max = mid - 1;
	}
	return -1;	// value not found
}

int main(void) {

	int a, b, c, d, e;
	a=1; b=2; c=3; d=4; e=5;
	int* arr[5] = {&a, &b, &c, &d, &e};

	int found = binSearch(&arr, 4, 4);
	printf("Value %d found at index %d\n", 4, found);
	found = binSearch(&arr, 1, 4);
	printf("Value %d found at index %d\n", 1, found);
	found = binSearch(&arr, 6, 4);
	printf("Value %d found at index %d\n", 6, found);
}
