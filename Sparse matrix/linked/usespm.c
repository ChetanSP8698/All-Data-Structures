#include <stdio.h>
#include "spm.h"
int main() {
	spm a, b, *c;
	int row, col, val, n, i, p, q, r;
	scanf("%d%d", &p, &q);
	init(&a, p, q);
	//printf("inited a %d %d\n", p, q);
	scanf("%d%d", &q, &r);
	init(&b, q, r);
	//printf("inited b %d %d\n", q, r);
	/* code to read spm a */
	scanf("%d", &n);
	//printf("n for a = %d\n", n);
	for(i = 0; i < n; i++) {
		scanf("%d%d%d", &row, &col, &val);
		append(&a, row, col, val);
		//printf("insert in a: %d %d %d\n", row, col, val);
	}
	printf("Matrix A\n");
	printspm(&a);
	/* code to read spm b */
	scanf("%d", &n);
	//printf("n for b = %d\n", n);
	for(i = 0; i < n; i++) {
		scanf("%d%d%d", &row, &col, &val);
		append(&b, row, col, val);
		//printf("insert in b: %d %d %d\n", row, col, val);
	}
	printf("Matrix B\n");
	printspm(&b);
	c = spmmult(&a, &b);
	printf("Matrix C\n");
	printspm(c);
	return 0;	
}
