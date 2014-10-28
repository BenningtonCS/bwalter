/* file: 05queue.c
 * date: 2014 October
 * author: Brendon Walter
 * 
 * hackathon problem 05: "Modify your stack and queue implementations to also 
 * return a running sum of all the items in the queue and on the stack."
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
	int length;
	int sum;
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
	qp->length = 0;
	qp->sum = NULL;
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

	q->length += 1;
	q->sum += d.val;
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
	q->length -= 1;
	q->sum -= (*d).val;
	return 0;
}

int main(void) {

    Queue q = initQueue();
    QueueData f;
    int i;
    for (i=0;i<5;i++) {
        f.val = i;
        enqueue(q, f);
    }

	printf("Length: %d\tSum: %d\n", q->length, q->sum);

}
