
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct data {
	char name[16];	
	int age;
}data;

#define N 5
data ht[N];
int hash(char *str) {
	return (*str - 'a') % N;
}
void printht() {
	int i;
	for(i = 0;  i < N; i++)
		printf("%10d", i);
	printf("\n");
	for(i = 0;  i < N; i++)
		if(ht[i].age != -1)
			printf("%10s", ht[i].name);
		else 
			printf("%10s", "          ");
	printf("\n");
	for(i = 0;  i < N; i++)
		if(ht[i].age != -1)
			printf("%10d", ht[i].age);
		else
			printf("%10s", "          ");
	printf("\n");
	
}
void initht() {
	int i;	
	for(i = 0; i < N ; i++)
		ht[i].age = -1;
}

void store(data d) {
	int h = hash(d.name);
	int j;
	if(ht[h].age == -1)
		ht[h] = d;
	else {
		j = (h + 1) % N;
		while(j != h && ht[j].age != -1)
			j = (j + 1) % N;
		if(j != h)
			ht[j] = d; 
		else  //ht full
			return;
	}
}
data search(char *name) {
	data m = { "", -1};
	int j;
	int h = hash(name);
	if(strcmp(ht[h].name, name) == 0)
		return ht[h];
	j = (h + 1) % N;
	while(j != h) {
		if(strcmp(ht[j].name, name) == 0)
			return ht[j];
		j = (j + 1) % N;
	}
	return m;
}
int main(int argc, char *argv[]) {
	data d;
	char name[16];	
	initht();
	printht();
	while(scanf("%s%d", d.name, &(d.age)) != -1) {
		store(d);
		printht();
	}
	while(scanf("%s", name) != -1) {
		d = search(name);
		if(d.age != -1)
			printf("%s %d\n", d.name, d.age);
	}
	return 0;
}

