/* file: 09.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 9: "Write a program the measure the run time of the 
 * following:
 *	- 100,000 operations on a stack implemented as a linked list, vs 100,000
 *	  operations on a stack implemented as a dynamic array
 *	- The memory size allocated for the dynamic array doubles each time more
 *	  space is needed
 *	- The memory size allocated for the dynamic array is halved each time the
 *	  amount of data in the array falls below half the size of the array"
 */

#include <stdio.h>
#include <time.h>
#include "../refs/stack.h"
#include "../refs/dynamicArray.h"
#include "../refs/linkedListInt.h"

#define NUM_RUN_TIMES 10000

double listInsert(Stack s) {
	clock_t begin, end;
	double diff;
	int i;
	begin = clock();

	for (i=0;i<100000;i++)
		push(s, i);


	end = clock();
	diff = (double)(end - begin) / CLOCKS_PER_SEC;
	return diff;

}

double arrayInsert(int* myarray) {
	clock_t begin, end;
	double diff;
	int i;
	begin = clock();
	
	for (i=0;i<100000;i++) {
		insertValue(myarray, i);
	}	

	end = clock();
	diff = (double)(end - begin) / CLOCKS_PER_SEC;
	return diff;

}

int main(void) {
	int *myarray = initArray();
	Stack l = initStack();

	int i;

	double listTime, listTimes[NUM_RUN_TIMES];
/*	
	for (i=0;i<NUM_RUN_TIMES;i++) {
		listTime = listInsert(l);
		listTimes[i] = listTime;
	}
*/
	double arrTime, arrTimes[NUM_RUN_TIMES];

	for (i=0;i<NUM_RUN_TIMES;i++) {
		arrTime = arrayInsert(myarray);
		listTimes[i] = listTime;
	}

	double lt, at;
	lt = at = 0;
	for (i=0;i<NUM_RUN_TIMES;i++) {
		lt += listTimes[i];
	}

	for (i=0;i<NUM_RUN_TIMES;i++) {
		at += arrTimes[i];
	}

	printf("Time to complete %d list operations: %f\nAverage: %f\n\n",
			NUM_RUN_TIMES, lt, lt/NUM_RUN_TIMES);
	printf("Time to complete %d arr operations: %f\nAverage: %f\n\n",
			NUM_RUN_TIMES, at, at/NUM_RUN_TIMES);
}
