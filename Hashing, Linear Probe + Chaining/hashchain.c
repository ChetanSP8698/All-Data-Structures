/* A program using hashing, using chaining for collision resolution
 * Stores "data"
 * Key is "score"
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
typedef struct data {
	char name[16];
	int age;
	int score;
	struct data *next;
}data;
data *ht[SIZE];

int hash(int key) {
	return key % 7;
}

data *search(int score) {
	int h = hash(score);
	data *p = ht[h];
	while(p) {
		if(p->score == score) {
			return p;
		}
		p = p->next;
	}
	/* Not found */
	return  NULL;
}
void store(data x) {
	int h = hash(x.score);
	data *tmp;
	/* store record x in the linked list at index h */

	tmp = (data *)malloc(sizeof(data));
	*tmp = x;

	tmp->next = ht[h];
	ht[h] = tmp;
			
}
void initht() {
	int i;
	for(i = 0; i < SIZE; i++)
		ht[i] = NULL;	
}
void printht() {
	int i;
	data *p;
	for(i = 0; i < SIZE; i++) {
		printf("%d : ", i);
		p = ht[i];
		while(p) {
			printf("%s %d %d\t", p->name, p->age, p->score);
			p = p->next;	
		}
		printf("\n");
	}
}
int main() {
	/* Store data */
	data d, *p;
	int score;
	initht();
	while(scanf("%s%d%d", d.name, &d.age, &d.score) && d.score != -1)  {
		store(d);	
		printht();
	}
	/* Many search operations */
	while(scanf("%d", &score) != -1) {
		p = search(score);
		if(p)
			printf("%s %d %d \n", p->name, p->age, p->score);
		else
			printf("Not found \n");
	}
	return 0;
}
