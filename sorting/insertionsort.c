/*
 *	I N S E R T I O N   S O R T
 */

#include "sort.h"

// sort list[lo] to list[hi] in ascending order
void insertionSort(int list[], int lo, int hi) {
	int j, k, key;
	for (j=lo+1;j<=hi;j++) {
		key = list[j];
		k = j - 1;			// start comparing with previous item
		while (k >= lo && key < list[k]) {
			list[k+1] = list[k];
			--k;
		}
		list[k+1] = key;
	}
}
