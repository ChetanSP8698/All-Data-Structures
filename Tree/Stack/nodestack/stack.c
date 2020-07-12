#include <string.h>
#include "stack.h"
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i == MAX;	
}
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, node *tmp) {
	s->a[s->i++] = tmp;
}

node *pop(stack *s) {
	node *temp;
	temp = s->a[s->i - 1];
	s->i--;
	return temp;
}
