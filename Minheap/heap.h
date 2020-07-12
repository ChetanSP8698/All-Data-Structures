#define MAX 32
typedef struct heap {
	int a[MAX];
	int n;
}heap;

void heapInit(heap *h);
void heapInsert(heap *h, int val);
int heapRemove(heap *h);
int heapEmpty(heap *h);
int heapFull(heap *h);
