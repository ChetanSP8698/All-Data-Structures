#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
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

char *max(tree t) {
	char *a[64], *ch;
	int i = 0, j, k;
	stack c;
	node *tmp;
	if(t == NULL)
		return NULL;
	init(&c);
	push(&c, t);

	while(!isempty(&c)) {
		tmp = pop(&c);
		a[i++] = tmp->str;
		if(tmp->right != NULL)
			push(&c, tmp->right);
		if(tmp->left != NULL)
			push(&c, tmp->left);
	}

	for (j = 0; j < i - 1; j++) {
		for(k = j + 1; k < i; k++) {
			if (strcmp(a[j], a[k]) < 0) {
				strcpy(ch, a[j]);
				strcpy(a[j], a[k]);
				strcpy(a[k], ch);
			}
		}

	}	
	return search(t, a[0]);
}

void preorder_norecur(tree t) {
	stack s;
	node *tmp;
	if(t == NULL)
		return;
	init(&s);
	push(&s, t);

	while(!isempty(&s)) {
		tmp = pop(&s);
		printf("%s ", tmp->str);
		if(tmp->right != NULL)
			push(&s, tmp->right);
		if(tmp->left != NULL)
			push(&s, tmp->left);

	}
	printf("\n");
}

char *search(tree t, char *str) {
	node *p;
	int res;
	
	p = t;
	while(p) {
		res = strcmp(p->str, str);
		if(res < 0) {
			p = p->right;
		}
		else if(res > 0){
			p = p->left;
		}
		else {
			break;	
		}
	}	

	if(!p)
		return NULL;

	return p->str;
}

void tabs(char ch, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%c", ch);
	}

}

void printnode(tree t, int l, int h) {
	int k;
	if(t == NULL) {
		tabs(' ', h);
		return;
	}
	
	if (l == -1) {
		for (k = 0; k < 7; k++) {
			tabs(' ', h);
		}		
		printf("%s", t->str);
	}
	else if (l > -1) {

		printnode(t->left, l - 1, h - 1);
		printnode(t->right, l - 1, h + 2);
			
	}
	return;	
}

void printtree(tree t) {
	int d = depth(t), i;
	for (i = -1; i < d; i++) {
		//printf("%d\n", d);
		printnode(t, i, d);
		printf("\n-----------------------------------------------------------\n");
		printf("\n");
	}
}

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
