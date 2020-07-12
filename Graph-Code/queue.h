#define N 16
typedef struct queue {
	int data[N];
	int f, r;
	int count;
}queue;

void qinit(queue *q);
void enq(queue *q, int str);
int deq(queue *q);
int qempty(queue *q);
int qfull(queue *q);
