#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

typedef struct data {
	char name[16];
	int age;
}data;
typedef int key;
void printht(data ht[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("---[%1d]", i);
	printf("\n"); /*
	for(i = 0; i < n; i++)
		printf("------");
	printf("\n"); */
	for(i = 0; i < n; i++)
		if(ht[i].age != -1)
			printf("%6s", ht[i].name);
		else 
			printf("      ");
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%6d", ht[i].age);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("------");
	printf("\n");
}
void initht(data ht[], int n) {
	int i;
	for(i = 0; i < n; i++)
		ht[i].age = -1;
}
int hash(key k) {
	return k % 7;
}
void store(data ht[], int n, data e) {
	int h, j;
	h  = hash(e.age);
	if(ht[h].age == -1) 
		ht[h] = e;
	else {
		j = (h + 1) % n;
		while(j != h) {
			if(ht[j].age == -1) {
				ht[j] = e;
				return;
			}
			else
				j = (j + 1) % n;
		}
	}
}
data *search(data ht[], int n, key k) {
	int h, j;
	h = hash(k);
	if(ht[h].age == k)
		return &ht[h];
	else {
		/*linear search for element with key = k */
		j = (h + 1) % n;
		while(j != h) {
			if(ht[j].age == k)
				return &ht[j];
			else
				j = (j + 1) % n;
		}
		return NULL;
	}
}
int main() {
	data ht[N];
	data d, *dp;
	int age;

	initht(ht, N);	
	printht(ht, N);
	while(scanf("%s%d", d.name, &(d.age)) != -1) {
		store(ht, N, d);
		printht(ht, N);
	}
	
	printf("Please enter search values:\n");
	while(scanf("%d", &age) != -1) {
		dp = search(ht, N, age);
		if(dp)
			printf("%s %d\n", dp->name, dp->age);
		else
			printf("Not found\n");
	}
	return 0;
}
