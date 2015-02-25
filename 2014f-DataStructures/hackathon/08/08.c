/* file: 08.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 8: "Write a function to merge two sorted queues."
 */

#include <stdio.h>

typedef struct {
	int val;
} QueueData;

#include "queue.h"

void merge(Queue merger, Queue q1, Queue q2) {
	QueueData d;
	int n = dequeue(q1, &d);
	while (n == 0) {
		enqueue(merger, d);
		n = dequeue(q1, &d);
	}

	n = dequeue(q2, &d);
	while (n == 0) {
		enqueue(merger, d);
		n = dequeue(q2, &d);
	}
}

int main(void) {
	Queue q1 = initQueue();
	Queue q2 = initQueue();
	Queue merger = initQueue();

	QueueData f;
	int i;
	for (i=0;i<=10;i+=2) {
		f.val = i;
		enqueue(q1, f);
		printf("%d added to q1\n", i);
	}

	for (i=1;i<=10;i+=2) {
		f.val = i;
		enqueue(q2, f);
		printf("%d added to q2\n", i);
	}

	merge(merger, q1, q2);

	printf("Merged queue has the values:\n");
	QueueData d;
	int n = dequeue(merger, &d);
	while (n == 0) {
		printf("%d\n", d.val);
		n = dequeue(merger, &d);
	}
}	

