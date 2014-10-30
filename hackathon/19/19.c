/* file: 19.c
 * date: 2014 October 21
 * author: Brendon Walter
 *
 * hackathon problem 19: "Using a priority queue, keep a counter that is 
 * incremented every time an item is accessed, and use that count as the 
 * priority (sorting criterion)."
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int val;
} QueueData;

#include "queue.h"

int main(void) {

	Queue q = initQueue();
    QueueData f;
	
	int i;
	for (i=0;i<5;i++) {
		f.val = i;
		enqueue(q, f, 1);
	}

	printf("inital queue\n");
	printQueue(q);

	f.val = 2;
	accessNode(q, f);
	f.val = 0;
	accessNode(q, f);
	f.val = 3;
	accessNode(q, f);
	f.val = 3;
	accessNode(q, f);

	printf("\naccessed nodes\n");
	printQueue(q);
}
