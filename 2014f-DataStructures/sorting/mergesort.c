/*
 *	M E R G E   S O R T
 */

#include "sort.h"

// A[lo..mid] and A[mid+1..hi] are sorted
// merge the pieces so that A[lo..hi] is sorted
void merge(int A[], int lo, int mid, int hi, int maxNum) {
	int T[maxNum];
	int i = lo;
	int j = mid+1;
	int k = lo;
	while (i <= mid || j <= hi) {
		if (i > mid) T[k++] = A[j++];			// A[lo..mid] completely processed
		else if (j > hi) T[k++] = A[i++];		// A[mid+1..hi] completely processed
		else if (A[i] < A[j]) T[k++] = A[i++];	// neither part completed
		else T[k++] = A[j++];
	}
	for (j=lo;j<=hi;j++) A[j] = T[j];			// copy merged elements from T to A
}

// use merge sort to sort A[lo..hi]
void mergeSort(int A[], int lo, int hi, int maxNum) {
	if (lo < hi) {					// list contains more than 2 elements
		int mid = (lo + hi) / 2;	// get the mid-point subscript
		mergeSort(A, lo, mid, maxNum);		// sort first-half
		mergeSort(A, mid+1, hi, maxNum);	// sort second half
		merge(A, lo, mid, hi, maxNum);		// merge the sorted halves
	}
}

