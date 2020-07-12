#include <stdio.h>
#include "tree.h"
int main() {
	tree t;
	char str[16], *p;
	tinit(&t);

	while(scanf("%s", str) != -1) {
		insert(&t, str);
		printf("Preorder:");
		preorder_norecur(t);
		printf("\n");
		preorder(t);
		printf("\n");
		printtree(t);
		
	}

	while(scanf("%s", str) != -1) {
		printf("Search Result: %s\n", (p = search(t, str)) == NULL ? "NONE": p);
	}
	printf("\n");
	printf("Max: %s\n", max(t));
	
	return 0;
}
