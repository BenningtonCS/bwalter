/* file: 16.c
 * date: 2014 October
 * author: Brendon Walter
 *
 * hackathon problem 16: "Write a function that tells the user if a queue is 
 * sorted. Also write a function that tells a user if a stack is sorted."
 */

#include <stdio.h>

typedef struct {
	int val;
} QueueData;

#include "queue.h"

/* Parameters: Pointer to queue
 * Returns: 0 if not sorted, 1 if sorted
 * Walks through a queue and tells if the list is sorted or not
 */
int isSorted(Queue q) {
	NodePtr np = q->head;
	NodePtr prev = q->head;
		
	while (np != q->tail) {
		if (prev->data.val > np->data.val)
			return 0;		// if next value is larger than current, not sorted
		prev = np;	
		np = np->next;		// walk through list
			
	}
	return 1;
}

int main(void) {
	Queue q = initQueue();

	QueueData f;
	int i;
	for (i=0;i<10;i++) {
		f.val = i;
		enqueue(q, f);
	}

	if (isSorted(q)) printf("queue is sorted\n");
	else printf("queue is not sorted\n");
}
