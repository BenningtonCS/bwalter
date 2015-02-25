/*
		prob1.c
		2014 November 30
		Brendon Walter

		Chapter 6 problem 1: "Write a program to compare the performance of the sorting methods [selection, insert, quicksort, and mergesort] with respect to "number of comparisons" and "number of assignments". For quicksort, compare the performance of choosing the first element as the pivot and with choosing [the median] element. 

		Run the program to sort 10, 100, 1000, 10000, and 100000 elements supplied in random order.

		Run the program to sort 10, 100, 1000, 10000, and 100000 elements which are already sorted."
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define MAXNUM 10000

void makeLists(int num, int random[], int sorted[]) {
	int i;
	for (i=0;i<num;i++) {
		random[i] = rand()/(RAND_MAX+1.0)*(99);	// sort of random, but not perfect
		sorted[i] = i;
	}
}

int checkOrder(int A[], int length) {
	int i;
	for (i=0;i<length;i++) if (A[i]>A[i+1]) return 0;
	return 1;
}

int main(void) {
	clock_t start, end;
	double diff;
	int random[MAXNUM], sorted[MAXNUM];


	printf("\n\nSELECTION SORT\n\n");
	makeLists(MAXNUM, random, sorted);

	start = clock();
	selectionSort(random, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Random order took %f seconds to complete\n", diff);

	start = clock();
	selectionSort(sorted, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Sorted order took %f seconds to complete\n", diff);



	printf("\n\nQUICK SORT\n\n");
	makeLists(MAXNUM, random, sorted);

	start = clock();
	quickSort(random, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Random order took %f seconds to complete\n", diff);
	
	start = clock();
	quickSort(sorted, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Sorted order took %f seconds to complete\n", diff);

	
	
	printf("\n\nINSERTION SORT\n\n");
	makeLists(MAXNUM, random, sorted);

	start = clock();
	insertionSort(random, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Random order took %f seconds to complete\n", diff);
	
	start = clock();
	insertionSort(sorted, 0, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Sorted order took %f seconds to complete\n", diff);



	printf("\n\nMERGE SORT\n\n");
	makeLists(MAXNUM, random, sorted);
	
	start = clock();
	mergeSort(random, 0, MAXNUM, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Random order took %f seconds to complete\n", diff);
	
	start = clock();
	mergeSort(sorted, 0, MAXNUM, MAXNUM);
	end = clock();
	diff = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Sorted order took %f seconds to complete\n", diff);
}
