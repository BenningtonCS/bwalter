/* file: 04queue.c
 * date: 2014 October
 * author: Brendon Walter
 * 
 * hackathon problem 04: "Add a function (or field) to your linked-list-backed 
 * queue implementation that returns the length of the queue."
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
} QueueType, *Queue;

/* Parameters: None
 * Returns: Pointer to a queue
 * Creates a new queue with a head and tail both of which point to NULL
 */
Queue initQueue() {
	Queue qp = (Queue)malloc(sizeof(QueueType));
	if (qp == NULL) exit(1);	// or return NULL
	qp->head = NULL;
	qp->tail = NULL;
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
	if (isEmpty(q)) {	// if this new node is the only node in the queue
		q->head = np;	// both head and tail point to the same thing
		q->tail = np;
	} else {			// if there already are nodes in the queue
		q->tail->next = np;	// previous last node points to new node
		q->tail = np;		// tail points to new node
	} 
	return 0;
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
	return 0;
}

/* Paramters: Pointer to a queue
 * Returns: length of queue, -1 if queue doesn't exist
 * Gets the length of a queue and prints it out
 */
int getLength(Queue q) {
	if (q == NULL) return -1;	// NULL check
	int length = 0;

	NodePtr np = q->head;

	while (np != q->tail) {		// walk through the list 
		np = np->next;
		length += 1;			// add 1 to length for each iteration
	}

	printf("Length: %d\n", length);
	return length;
}

int main(void) {

    Queue q = initQueue();
	Queue a = initQueue();
    QueueData f;
    int i;
    for (i=0;i<5;i++) {
        f.val = i;
        enqueue(q, f);
    }

	getLength(a);
	getLength(q);
}
