#include "tree.h"
#define MAX 32
typedef struct stack{
	node *a[MAX];
	int i;
}stack;

int isempty(stack *s);
int isfull(stack *s);
void init(stack *s);
void push(stack *s, node *t);
node *pop(stack *s);

