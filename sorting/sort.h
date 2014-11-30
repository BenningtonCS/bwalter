#ifndef SORT_H
#define SORT_H

//	swap list[i] and list[j]
void swap(int list[], int i, int j);

// sort list[lo] to list[hi] in ascending order
void insertionSort(int list[], int lo, int hi); 

// A[lo..mid] and A[mid+1..hi] are sorted
// merge the pieces so that A[lo..hi] is sorted
void merge(int A[], int lo, int mid, int hi); 

// use merge sort to sort A[lo..hi]
void mergeSort(int A[], int lo, int hi);

// partition A[lo] to A[hi] using A[lo] as the pivot
int partition(int A[], int lo, int hi);

// sorts A[lo] to A[hi] in ascending order
void quickSort(int A[], int lo, int hi);

//	Return location of smallest from list[lo...hi]
int getSmallest(int list[], int lo, int hi);

//	Selection sort implementation
//	Sort list[lo] to list[hi] in ascending order
void selectionSort(int list[], int lo, int hi); 

#endif
