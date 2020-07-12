#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
int readline(FILE *fp, char *line, int n) {
	int ch;
	int i = 0;
	while((ch = fgetc(fp)) != '\n' && ch != -1) 
		line[i++] = ch;
	line[i] = '\0';
	return i;
}
int search(char *citynames[], char *name, int n) {
	int i;
	for(i = 0; i < n; i++) 
		if(strcmp(citynames[i], name) == 0)
			return i;
	return -1;
}
char **citynames;
graph *createGraphFromMap(char *filename) {
	FILE *fp;
	int n = 0, x, found, i, j;
	graph *g;
	char line[128], *token1, *token2, *token3;
	citynames = (char **)malloc(sizeof(char *) * 128);

	fp = fopen(filename, "r");
	if(fp == NULL)
		return NULL;
	g = (graph *)malloc(sizeof(graph));	
	/* 1. Find n */
	while(1) {
		x = readline(fp, line, 128);
		if(x == 0)
			break;
		token1 = strtok(line, " \t");
		found = search(citynames, token1, n);
		if(found == -1) {
			citynames[n] = (char *)malloc(strlen(token1) + 1);
			strcpy(citynames[n], token1);
			n++;
		}
		token2 = strtok(NULL, " \t");
		found = search(citynames, token2, n);
		if(found == -1) {
			citynames[n] = (char *)malloc(strlen(token2) + 1);
			strcpy(citynames[n], token2);
			n++;
		}
	}
	printf("%d\n", n);
	/* 2. Init graph with n */
	initGraph(g, n);	
	/* 3. fill in the adjancency matrix */
	fseek(fp, SEEK_SET, 0);
	while(1) {
		x = readline(fp, line, 128);
		if(x == 0)
			break;
		token1 = strtok(line, " \t");
		token2 = strtok(NULL, " \t");
		token3 = strtok(NULL, " \t\n");
	
		i = search(citynames, token1, n);	
		j = search(citynames, token2, n);	
		insertEdge(g, i, j, atoi(token3));
		insertEdge(g, j, i, atoi(token3));
	}		
	return g;
}

void printpath(int *parent, int n, int start) {
	if(parent[start] == -1) {
		printf("%s ", citynames[start]);
		return;
	}
	printpath(parent, n, parent[start]);
	printf("%s ", citynames[start]);
}

void printPaths(graph *g) {
	int n = getn(g);
	int i, j;
	result result;
	for( i = 0; i < n; i++) {
		result = sssp(g, i);
		for(j = 0; j < getn(g); j++) {
			printf("%4d: ", result.distance[j]);
			printpath(result.parent, n, j);
			printf("\n");
		} 
		printf("\n");
	}
}

