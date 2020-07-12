typedef struct matrix {
	int **a;
	int nc, nr;
}matrix;

void init(matrix *m, int nc, int nr) {
	int i, j;
	m->nc = nc;
	m->nr = nr;
	m->a = (int **) malloc(sizeof(int *)* nr);
	for(i = 0; i < nr; i++)
		m->a[i] = (int *)malloc(sizeof(int) * nc);
		for(j = 0; j < nc; j++)
			m->a[i][j] = 0;
}
matrix *mult(matrix *p, matrix *q) {
	int i, j, k;
	if(p->nc != q->nr)
		return NULL;
	matrix *c = (matrix *)malloc(sizeof(matrix));
	init(c, p->nr, q->nc);
	for(i = 0; i < 	p->nr; i++)
		for(j = 0; j < q->nc; j++) {
			// calculate result[i][j]
			result = 0;
			for(k = 0; k < q->nc; k++) 
				result += p->a[i][k] * q->a[k][j];
			c->a[i][j] = result;
		}
	return c;
}
void mprint(matrix *p) {
}
