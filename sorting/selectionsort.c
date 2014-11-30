/*
 *	S E L E C T I O N   S O R T
 */

#include "sort.h"

//	Return location of smallest from list[lo...hi]
int getSmallest(int list[], int lo, int hi) {
	int j, small = lo;
	for (j=lo+1;j<=hi;j++)
		if (list[j] < list[small]) small = j;
	return small;
}

//	Selection sort implementation
//	Sort list[lo] to list[hi] in ascending order
void selectionSort(int list[], int lo, int hi) {
	int j;
	for (j=lo;j<hi;j++) {
		int s = getSmallest(list, j, hi);
		swap(list, j, s);
	}
}
