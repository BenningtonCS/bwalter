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

/* Parameters: Length of the new queue you want to make
 * Returns: A pointer to the created queue
 * Creates a queue of a certain length
 */
Queue makeQueue(int length) {
	Queue q = initQueue(length);
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

	// there are fewer items in the queue than it can hold
	if (q->usedLen < q->totLen) {
		if (isEmpty(q)) {	// if this new node is the only node in the queue
			q->head = np;	// both head and tail point to the same thing
			q->tail = np;
			q->tail->next = q->head;	// tail points to head
		} else {			// if there already are nodes in the queue
			q->tail->next = np;	// previous last node points to new node
			q->tail = np;		// tail points to new node
			q->tail->next = q->head;	// tail points to head
		} 	
	
	// there are already the max number of items in the queue
	} else {
		QueueData f;
		q->tail->next = np;			// tail pointer points to np (new head)
		q->tail = np;				// switch tail to be the new node
		np->next = q->head->next;	// new node points passed old head
		NodePtr oldHead = q->head;	// save reference to old head
		q->head = q->head->next;	// set head to the next item
	   	free(oldHead);				// and free the old head
		q->usedLen -= 1;
	}

	q->usedLen += 1;
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
	q->usedLen -= 1;
	return 0;
}

/* Parameters: Pointer to queue
 * Returns: none
 * Iterates through a list and prints out the data in each node
 */
void printQueue(Queue q) {
	NodePtr np = q->head;
	while (np->next != q->head) {
		printf("%d\n", np->data.val);
		np = np->next;
	}
	printf("%d\n", np->data.val);
}

int main(void) {
	Queue q = makeQueue(10);

	int i;
	QueueData d;
	
	// as this adds 15 items to a queue that can only hold 10, the first 5
	// items (0 - 4) are replaced with 10 - 14
	for (i=0;i<15;i++) {
		d.val = i;
		enqueue(q, d);
	}

	printQueue(q);
}

