#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 16

typedef struct QUEUE {
	char data[N][16];
	int front,rear;
}QUEUE;

void initq(QUEUE *q)
{
	q->front=q->rear=-1;
}

int isempty(QUEUE *q)
{
	return(q->front==q->rear);
}

int isfull(QUEUE *q)
{
	return((q->rear+1)%N == q->front);
}

void addq(QUEUE *q,char *str)
{
	q->rear=(q->rear+1)%N;
	//q->data[q->rear]=num;
	strcpy(q->data[q->rear], str);
}

char *removeq(QUEUE *q)
{
	q->front=(q->front+1)% N;
	char *t = q->data[q->front];
	return t;
}

void main()
{
int n,choice, i;
QUEUE q1;
initq(&q1);
char s[16];
while(scanf("%s", s) != -1) {
	if(isfull(&q1))
		printf("\nQUEUE OVERFLOW\n");
	else
		addq(&q1, s);
}
while(!isempty(&q1))
	printf("%s\n", removeq(&q1));

/*
do
{
printf("\n1.ADD\n2.DELETE\n3.EXIT\n");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\nEnter element to be added:");
scanf("%d",&n);
if(isfull(&q1))
printf("\nQUEUE OVERFLOW\n");
else
addq(&q1,n);
break;
case 2:
if(isempty(&q1))
printf("\nQueue is empty\n");
else
printf("\nThe deleted element is %d",removeq(&q1));
break;
}
}while(choice!=3);
*/
}
