#include "sort.h"

void swap(int list[], int i, int j) {
	int hold = list[i];
	list[i] = list[j];
	list[j] = hold;
}
