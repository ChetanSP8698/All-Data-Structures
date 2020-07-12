typedef struct elem {
	int r, c, v;
}elem;
typedef struct spm {
	elem arr[128];
	int nrow, ncol, nelem;
}spm;
spm *spmadd(spm *a, spm *b);
void printspm(spm *m);
void init(spm *m, int, int);
