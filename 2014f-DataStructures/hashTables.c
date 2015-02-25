/*
		hashTables.c
		2014 December 2
		Brendon Walter

		Implementation of a hash table in C
*/

#include <stdio.h>

#define N 12
#define EMPTY 0
#define DELETE -1

/*
	Paramters: table of ints, key to be found / inserted
	Returns: location of the key
	Finds the given key and if it's not found, insert it
*/
int findOrInsert(int t[], int key) {
	int loc = key % N;
	while (t[loc] != EMPTY && t[loc] != DELETE && t[loc] != key) loc = (loc+1) % N;
	if (t[loc] == EMPTY || t[loc] == DELETE) 
		t[loc] = key;		// key found at t[loc]
	return loc;				// t[loc] has the key already
	
}

/*
	Paramters: table of ints, key to be deleted
	Returns: none
	Searches through a hash table and deletes the key by changing its value to -1
*/
void delete(int t[], int key) {
	int loc = key % N;
	while (t[loc] != EMPTY && t[loc] != key) loc = (loc+1) % N;
	if (t[loc] == key) t[loc] = DELETE;
}

/*
	Parameters: table to be printed
	Returns: None
	Iterates through the table and prints out each value
*/
void printTable(int t[]) {
	int i;
	for (i=0;i<N;i++) 
		printf("%d ", t[i]);
	printf("\n");
}

int main(void) {
	// init hash table w/ EMPTY in all places
	int t[N];	// hash table

	int i;
	for (i=0;i<N;i++) t[i] = 0;	

	findOrInsert(t, 33);
	findOrInsert(t, 84);
	findOrInsert(t, 43);
	findOrInsert(t, 52);
	findOrInsert(t, 16);
	findOrInsert(t, 59);
	findOrInsert(t, 31);
	findOrInsert(t, 23);
	findOrInsert(t, 61);

	printTable(t);

	delete(t, 33);
	printTable(t);
	findOrInsert(t, 33);
	printTable(t);
}
