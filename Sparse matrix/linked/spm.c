#include <stdio.h>
#include <stdlib.h>
#include "spm.h"
spm *spmadd(spm *a, spm *b){
	return NULL;
}
spm *spmmult(spm *a, spm *b){
	int i, j, sum;
	elem *p, *q;
	if(a->ncols != b->nrows)
		return NULL;
	spm *c = (spm *)malloc(sizeof(spm));
	init(c, a->nrows, b->ncols); 
	for(i = 0; i < a->nrows; i++) {
		for(j = 0; j < b->ncols; j++) {
			sum = 0;
			/* compute sum */
			p = a->rows[i];
			q = b->cols[j];
			while(p && q) {
				if(p->c < q->r)
					p = p->rptr;
				else if(p->c > q->r)
					q = q->cptr;
				else {
					sum += p->v * q->v;
					p = p->rptr;
					q = q->cptr;
				}
			}
			if(sum) append(c, i, j, sum);
		}
	}
	return c;
}
void printspm(spm *m){
	int i, j;
	elem *p;
	for(i = 0; i < m->nrows; i++) {
		/* printing i'th row */
		p = m->rows[i];
		j = 0;
		while(p && j < m->ncols) {
			while(j < p->c){
				printf("0 ");
				j++;
			}
			printf("%d ", p->v);
			p = p->rptr;
			j++;
		}
		while(j < m->ncols) {
			printf("0 ");
			j++;
		}
		printf("\n");
	}
}
void append(spm *m, int row, int col, int val) {
	elem *p, *q;
	elem *tmp;
	if(val == 0)
		return;
	if(row >= m->nrows || col >= m->ncols)
		return;
	tmp = (elem *)malloc(sizeof(elem));
	tmp->r = row; tmp->c = col; tmp->v = val;
	/* insert the node into a proper row-chain*/
	p = m->rows[row];
	while(p && p->c < col) {
		q = p;
		p = p->rptr;
	}
	if(p == m->rows[row]) { /* inserting in first location */
		m->rows[row] = tmp;
		tmp->rptr = p;
	} else {
		q->rptr = tmp; tmp->rptr = p;
	}
	/* insert the node into a proper col-chain*/
	p = m->cols[col];
	while(p && p->r < row) {
		q = p;
		p = p->cptr;
	}
	if(p == m->cols[col]) { /* inserting in first location */
		m->cols[col] = tmp;
		tmp->cptr = p;
	} else {
		q->cptr = tmp; tmp->cptr = p;
	}

}
void init(spm *m, int row, int col){
	int i;
	m->nrows = row;
	m->ncols = col;
	m->rows = (elem **)malloc(sizeof(elem *)*row);
	m->cols = (elem **)malloc(sizeof(elem *)*col);
	for(i = 0; i < row; i++) 
		m->rows[i] = NULL;
	for(i = 0; i < col; i++) 
		m->cols[i] = NULL;
}
