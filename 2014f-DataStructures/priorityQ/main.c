/* file: main.c
 * date: 2014 October 21
 * author: Brendon Walter
 *
 * Priority Queue Rodeo: Implementation of a priority queue using linked list 
 * backed queues. 
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
	f.val = 2;
	enqueue(q, f, 2);
    f.val = 3;
	enqueue(q, f, 3);
	f.val = 49;
	enqueue(q, f, 2);
	f.val = 1;
	enqueue(q, f, 5);
	f.val = 19;
	enqueue(q, f, 1);    

    QueueData d;
    int n = dequeue(q, &d);
    while (n == 0) {
        printf("%d\n", d);
        n = dequeue(q, &d);
    }

}
