/* file: 17queue.c
 * date: 2014 October
 * author: Brendon Walter
 * 
 * hackathon problem 17: "Implement a fixed-size linked-list-backed queue that
 * behaves like a ring buffer."
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int val;
} QueueData;

typedef struct {
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr head, tail;
	int totLen;
	int usedLen;
} QueueType, *Queue;

/* Parameters: None
 * Returns: Pointer to a queue
 * Creates a new queue with a head and tail both of which point to NULL
 */
Queue initQueue(int length) {
	Queue qp = (Queue)malloc(sizeof(QueueType));
	if (qp == NULL) exit(1);	// or return NULL
	qp->head = NULL;
	qp->tail = NULL;
	qp->totLen = length;
	qp->usedLen = 0;
	return qp;
}

/* Parameters: pointer to a queue
 * Returns: -1 if queue doesn't exist, 0 if not empty, 1 if empty 
 * Checks a queue to see if it's empty
 */
int isEmpty(Queue q) {
	if (q == NULL) return -1;
	return(q->head == NULL);	// returns 1 if empty, 0 if not
}

/* Parameters: Pointer to queue, data to but put into queue
 * Returns: -1 if error, 0 if success
 * Puts data into the queue (at the back (head) of the queue)
 */
int enqueue(Queue q, QueueData d) {
	
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	if (np == NULL) return -1;
	np->data = d;		// put data into node
	np->next = NULL;	// new node currently doesn't point to anything

	printf("%d\t%p\n", d.val, q->head);
	if (q->usedLen < q->totLen) {
		if (isEmpty(q)) {	// if this new node is the only node in the queue
			q->head = np;	// both head and tail point to the same thing
			q->tail = np;
		} else {			// if there already are nodes in the queue
			q->tail->next = np;	// previous last node points to new node
			q->tail = np;		// tail points to new node
		} 

		q->usedLen += 1;
		return 0;
	
	} else {
		QueueData d;
		np = q->head->next;
		q->head = np;
		dequeue(q, &d);
		q->usedLen += 1;
		return 0;
	}
}

/* Parameters: Pointer to  a queue, output parameter
 * Returns: -1 if error, 0 if success
 * Takes the item at the front of the line and returns it as an output
 * parameter
 */
int dequeue(Queue q, QueueData *d) {
	if (q == NULL || isEmpty(q)) return -1;
	*d = q->head->data;			// puts data in output parameter
	NodePtr oldHead = q->head;	// make a new pointer to the deleted node
	q->head = q->head->next;
    free(oldHead);				// and then free it
	q->usedLen -= 1;
	return 0;
}

Queue makeQueue(int length) {
	Queue q = initQueue(length);
}

void printQueue(Queue q) {
	NodePtr np = q->head;
	while (np != q->tail) {
		printf("%d\n", np->data.val);
		np = np->next;
	}
}

int main(void) {
	Queue q = makeQueue(10);

	int i;
	QueueData d;
	for (i=0;i<20;i++) {
		d.val = i;
		enqueue(q, d);
	}

	printQueue(q);
}

