#include <stdio.h>
#include "heap.h"
void heapInit(heap *h){
	h->n = 0;
}
void swap(int *a, int x, int y) {
	int temp;	
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
void heapInsert(heap *h, int val){
	int c, p;
	h->a[h->n] = val;
	c = h->n;
	p = (c - 1) / 2;
	while(c > 0) {
		if(h->a[c] < h->a[p]) {
			swap(h->a, c, p);
			c = p;
			p = (c - 1) / 2;
		} else {
			break;	
		}
	}
	(h->n)++;
}
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int findsmallest(int *p, int a, int b, int c) {
	int x = MIN(p[a], p[b]);
	int y = MIN(x, p[c]);
	if(y == p[a])
		return a;
	if(y == p[b])
		return b;
	if(y == p[c])
		return c;
	return -1;
}
int heapRemove(heap *h){
	int x = h->a[0], p, c1, c2, smallest;
	h->a[0] = h->a[h->n - 1];
	(h->n)--;
	p = 0;
	c1 = 2 * p + 1;
	c2 = 2 * p + 2;
	while(c1 < h->n) {
		smallest = findsmallest(h->a, p, c1, c2);
		if(smallest == p)
			break;
		swap(h->a, p, smallest);
		p = smallest;
		c1 = 2 * p + 1;
		c2 = 2 * p + 2;
	}
	return x;
}
int heapEmpty(heap *h){
	return h->n == 0;
}
int heapFull(heap *h){
	return h->n == MAX;
}
void heapPrint(heap *h) {
	int i;
	for(i = 0; i < h->n; i++)
		printf("%d ", h->a[i]);
	printf("\n");
}
int main() {
	heap h;
	int x;
	heapInit(&h);
	while(scanf("%d", &x) != -1)  {
		heapInsert(&h, x);
		heapPrint(&h);
	}
	while(!heapEmpty(&h)){
		printf("%d ", heapRemove(&h));
	}	
	printf("\n");
}
