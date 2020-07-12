#include <stdio.h>
#include "spm.h"
int main() {
	spm a, b, *c;
	int row, col, val;
	init(&a, 2, 3);
	init(&b, 2, 3);
	/* code to read spm a */
	while(scanf("%d%d%d", &row, &col, &val) != EOF)
		append(&a, row, col, val);
	printspm(&a);
	/* code to read spm b */
	while(scanf("%d%d%d", &row, &col, &val) != EOF)
		append(&b, row, col, val);
	c = spmadd(&a, &b);
	printspm(&b);
	printspm(c);
	return 0;	
}
