/* file: queue.c
 * date: 2014 October 21
 * author: Brendon Walter
 *
 * Priority Queue Rodeo: Implementation of a priority queue using linked list 
 * backed queues. 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	QueueData data;
	int priority;
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

/* Parameters: Pointer to queue, data to but put into queue, priority of data
 * Returns: -1 if error, 0 if success
 * Puts data into the queue (at the back (head) of the queue)
 * Priority ranges so 1 is highest priority. The smaller the number, the lower
 * the priority.
 */
int enqueue(Queue q, QueueData d, int p) {
	NodePtr np = (NodePtr)malloc(sizeof(Node));
	NodePtr prev = q->head;
	NodePtr tmp = q->head;
	if (np == NULL) return -1;
	np->data = d;		// put data into node
	np->priority = p;	// put priority of data
	np->next = NULL;	// new node currently doesn't point to anything

    // if the new node is the only one in the queue
	if (isEmpty(q)) {
		q->head = np;	// head and tail will both point to the new node
		q->tail = np;
        return 0;
	}

    // if the new node has a higher priority than the first node
    if (np->priority < q->head->priority) { 
        np->next = q->head; 
        q->head = np;
        return 0;
    }

	// if there already are nodes in the queue
	while (np->priority >= tmp->priority) {
        // if we've reached the end of the list
		if (tmp == q->tail) {
			tmp->next = np;
			q->tail = np;
			return 0;
		}
        prev = tmp;         // save the current node
		tmp = tmp->next;    // and walk through the list
	}
    prev->next = np;        // set the new node in place in the list
    np->next = tmp;
	return 0;
}

/* Parameters: Pointer to  a queue, output parameter
 * Returns: -1 if nothing to dequeue, 0 if success
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
