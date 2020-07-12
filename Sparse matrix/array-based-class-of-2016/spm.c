#include <stdio.h>
#include <stdlib.h>
#include "spm.h"
void init(spm *a, int row, int col) {
	a->nrow = row;
	a->ncol = col;
	a->nelem = 0;
}
void append(spm *a, int row, int col, int val) {
	a->arr[a->nelem].r = row;
	a->arr[a->nelem].c = col;
	a->arr[a->nelem].v = val;
	a->nelem++;
}
void printspm(spm *a) {
	int i;
	printf("nrow = %d ncol = %d nelem = %d\n",
		a->nrow, a->ncol, a->nelem);
	for(i = 0; i < a->nelem; i++) {
		printf("%d) %d  %d %d \n", i, a->arr[i].r, 
			a->arr[i].c, a->arr[i].v);
	}
}
int cmp(int ra, int ca, int rb, int cb) { 
	if(ra < rb)
		return -1;
	if(ra > rb)
		return 1;
	if(ca < cb) 
		return -1;
	if(ca > cb)
		return 1;
	return 0;
}
spm *spmadd(spm *a, spm *b){
	spm *c;
	int i, j, k, res, sum;
	if(a->nrow != b->nrow || a->ncol != b->ncol)
		return NULL;
	c = (spm *)malloc(sizeof(spm));
	i = j = k = 0;
	/* i is index in a, j is index in b
	   k is index in c */
	while(i < a->nelem && j < b->nelem)  {
		res = cmp(a->arr[i].r, a->arr[i].c, 
			  b->arr[j].r, b->arr[j].c);
		if (res == -1) { 
			c->arr[k] = a->arr[i];
			i++;
			k++;
		}
		else if (res == 1) {
			c->arr[k] = b->arr[j];
			j++;
			k++;
		}
		else  {
			sum = a->arr[i].v + b->arr[j].v; 
			if(sum) {
				c->arr[k].r = a->arr[i].r; 
				c->arr[k].c = a->arr[i].c; 
				c->arr[k].v = sum; 
				k++;
			}
			i++; j++;
		}
	}
	/* either i == a->nelem or j == b->nelem */	
	if(i == a->nelem) {
		while(j < b->nelem)
			c->arr[k++] = b->arr[j++];
	} else {
		while(i < a->nelem)
			c->arr[k++] = a->arr[i++];
	}
	c->nrow = a->nrow;
	c->ncol = a->ncol;
	c->nelem = k;
	return c;
}
