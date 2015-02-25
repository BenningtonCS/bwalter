/*
 *	Q U I C K   S O R T
 */

#include "sort.h"

// partition A[lo] to A[hi] using A[lo] as the pivot
int partition(int A[], int lo, int hi) {
	int pivot = A[lo];
	int lastSmall = lo;
	
	int j;
	for (j=lo+1;j<=hi;j++) {
		if (A[j] < pivot) {
			++lastSmall;
			swap(A, lastSmall, j);
		}
	}
	swap(A, lo, lastSmall);
	return lastSmall;					// division point
}

// sorts A[lo] to A[hi] in ascending order
void quickSort(int A[], int lo, int hi) {
	if (lo < hi) {
		int dp = partition(A, lo, hi);	// division point
		quickSort(A, lo, dp-1);
		quickSort(A, dp+1, hi);
	}
}
