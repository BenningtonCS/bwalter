/* File: 1_8.c
 * Author: Brendon Walter
 * Date: 2014.09.07
 *
 * Problem 1.9: "A file contains the names and distances jumped by athletes in a
 * long jump competition. Using a structure to hold a name and distance, write a
 * program to read the data and print a list of names and distance jumped in
 * order of merit."
 */

#include <stdio.h>

#define MAXPEOPLE 5

typedef struct {
	char name[31];
	int distance;
} Athelete;

void sort(Athelete a[], int n) {
	// sort the atheletes by the distance they jumped
	
	Athelete temp;
	int j, k;
	for(j=1;j<n;j++) {
		temp = a[j];
		k = j -1;
		while(k>=0 && strcmp(temp.name, a[k].name) < 0) {
			a[k+1] = a[k];
			k -= 1;
		}
	}
	a[k+1] = temp;
}

int main(void) {

	Athelete scores[MAXPEOPLE];

	FILE* in = fopen("1_9.txt", "r");

	int i;
    for(i=0;i<MAXPEOPLE;i++) {
        fscanf(in, "%s%d", scores[i].name, &scores[i].distance);
    }

	sort(scores, MAXPEOPLE);

	for(i=0;i<MAXPEOPLE;i++)
		printf("%s: %d\n", scores[i].name, scores[i].distance);

	return 0;
}
