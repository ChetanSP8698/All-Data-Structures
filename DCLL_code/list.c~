#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l){
	l->p = NULL;
	l->q = NULL;
}
void insert(list *l, char *str, int pos) {
	int len;
	int i;
	node *x, *tmp;
	len = length(*l);
	if(pos < 0 || pos > len)
		return;

	x = (node *)malloc(sizeof(node));
	x->str = (char *)malloc(strlen(str) + 1);	
	strcpy(x->str, str);
	if(len == 0) {
		l->p = l->q = x;
		x->prev = x->next = x;
		return;
	}
	tmp = l->p;
	for(i = 0; i < pos - 1; i++)
		tmp = tmp->next;
	if(pos == 0)
		tmp = l->q;

	tmp->next->prev = x;
	x->next = tmp->next;
	tmp->next = x;
	x->prev = tmp;

	if(pos == 0)
		l->p = x;	
	if(pos == len)
		l->q = x;
}
void traverse(list l){
	node *tmp;
	tmp = l.p;
	printf("List: [ ");
	if(!tmp) {
		printf("]\n");
		return;
	}
	do {
		printf("%s ", tmp->str);
		tmp = tmp->next;
	}while(tmp != l.p);
	printf("]\n");

	tmp = l.q;
	printf("Rev: [ ");
	do {
		printf("%s ", tmp->str);
		tmp = tmp->prev;
	}while(tmp != l.q);
	printf("]\n");



}
list merge(list a, list b){
	list c;
	return c;
}
void reverse(list *l){
	node *p, *q, *r, *tmp;
	if(l->p == NULL)
		return;
	q = l->p;
	p = q->next;
	r = p->next;
	while(r != q) {
		p->next = q;
		q = p;
		p = r;
		r = r->next;
	}

	q = l->q;
	p = q->prev;
	r = p->prev;
	while(r != q) {
		p->prev = q;
		q = p;
		p = r;
		r = r->prev;
	}
	
	tmp = l->p;
	l->p = l->q;
	l->q = tmp;
}
void appendright(list *l, char *str){
}
void appendleft(list *l, char *str){
}
char *removeright(list *l){
	return NULL;
}
char *removeleft(list *l){
	return NULL;
}
void sort(list *l){
	int i, n = length(*l);
	node *x = l->p, *y, *min;
	char *tmp;
	
	for(i = 0; i < n -1; i++) {
		//find min from x to q
		min = x;
		y = x->next;

		do {
			if(strcmp(y->str, min->str) < 0)
				min = y;
			y = y->next;
		}while(y != l->p);

		tmp = min->str;
		min->str = x->str;
		x->str = tmp;	
	
		x = x->next;
	}
}
int search(list l, char *str){
	return 0;
}
void destroy(list *l){
}
list split(list *l){
	return *l;
}
int length(list l) {
	int len = 0;
	node *tmp;
	tmp = l.p;
	if(!tmp)
		return 0;
	do {
		tmp = tmp->next;
		len++;
	}while(tmp != l.p);
	return len;
}
