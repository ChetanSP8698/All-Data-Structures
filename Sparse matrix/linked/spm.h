typedef struct elem {
	int r, c, v;
	struct elem *rptr, *cptr;
}elem;
typedef struct spm {
	elem **rows;
	elem **cols;
	int nrows, ncols;
}spm;
spm *spmadd(spm *a, spm *b);
spm *spmmult(spm *a, spm *b);
void printspm(spm *m);
void init(spm *m, int, int);
void append(spm *, int, int, int);
