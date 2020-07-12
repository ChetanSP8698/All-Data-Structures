#include <string.h>
#include "queue.h"
void qinit(queue *q){
	q->count = 0;
	q->f = 0;
	q->r = -1;
	/* Initialization could be done in other ways also */
}
void enq(queue *q, int str){
	q->r = (q->r + 1) % N;
	q->data[q->r] = str;
	(q->count)++;
}
int deq(queue *q){
	int tmp = q->data[q->f];
	q->f = (q->f + 1) % N;
	(q->count)--;	
	return tmp;
}
int qempty(queue *q){
	return q->count == 0;
}
int qfull(queue *q){
	return q->count == N;
}
