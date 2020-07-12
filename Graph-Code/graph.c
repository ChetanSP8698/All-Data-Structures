#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"
int getn(graph *g) {
	return g->n;
}
/* initGraph will allocate the 2-d array of
 * size n by n. Also initialize all edges to be zero.
 */
void initGraph(graph *g, int n){
	int i, j;
	g->a = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++) {
		g->a[i] = (int *)malloc(sizeof(int) * n);	
		for(j = 0; j < n; j++)
			g->a[i][j] = 0;
	}
	g->n = n;
}
void insertEdge(graph *g, int i, int j, int weight) {
	if(i < 0 || i >= g->n || j < 0 || j >= g->n)
		return;
	g->a[i][j] = weight;
}
/* Prints the graph */
void printGraph(graph *g){
	int i, j;
	for(i = 0; i < g->n; i++) {
		for(j = 0; j < g->n; j++)
			printf("%4d", g->a[i][j]);
		printf("\n");
	}
}

/* Create a graph by reading graph information from a file */
graph *createGraphFromFile(char *filename){
	graph *g;
	int n, i, j;
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		return NULL;
 	g = (graph *)malloc(sizeof(graph));
	fscanf(fp, "%d", &n);	
	initGraph(g, n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			fscanf(fp, "%d", &(g->a[i][j]));		
	fclose(fp);
	return g;
}

void levelwise(graph *g, int start){
	int x, *visited, i;
	queue q;

	visited = (int *)malloc(sizeof(int) * g->n);
	for(i = 0; i < g->n; i++)
		visited[i] = 0;
	qinit(&q);
	enq(&q, start);
	visited[start] = 1;
	while(!qempty(&q)) {	
		x = deq(&q);
		printf("%d ", x);
		for(i = 0; i < g->n; i++)
			if(g->a[x][i] != 0 && !visited[i]) {
				enq(&q, i);
				visited[i] = 1;
			}
	}	
	printf("\n");
} 
void depthwise(graph *g, int start){
} 
/* The caller should free the memory allocated and returned */
edge *prims(graph *g, int start) {
	int t = 0, i, j, minweight = INT_MAX, k;
	int *visited = (int *)malloc(sizeof(int) * g->n);
	edge e;
	edge *T = (edge *)malloc(sizeof(edge) * (g->n -1));
	for(i = 0; i < g->n; i++)
		visited[i] = 0;
	//vertices W = start;
	visited[start] = 1;
	for(k = 0; k < g->n - 1; k++) {
		minweight = INT_MAX;
		for(i = 0; i < g->n; i++) {
			if(visited[i]) {
				for(j = 0; j < g->n; j++) {
					if(g->a[i][j] && !visited[j]) {
						/* i,j is a candidate edge */
						if(g->a[i][j] < minweight) {
							minweight = g->a[i][j];
							e.u = i;
							e.v = j;
						}
					}
				}
			}
		}
		/*find min cost edge e = <u, v> s.t.  u Belongs to W and v doesnt belong to W and e is least cost. */
		T[t++] = e;
		visited[e.v] = 1;
	}
	free(visited);
	return T;
}
int findmin(int *distance, int *visited, int n) {
	int i, minvertex, min= INT_MAX;
	for(i = 0; i < n; i++) {
		if(!visited[i] && distance[i] < min) {
			min = distance[i];
			minvertex = i;
		}
	}
	return minvertex;
}
result sssp (graph *g, int start) {
	result result;
	int *distance = (int *)malloc(sizeof(int) * g->n);
	int *parent = (int *)malloc(sizeof(int) * g->n);
	int *visited = (int *)malloc(sizeof(int) * g->n);
	int i, j, k, u, newdistance;

	for(i = 0; i < g->n; i++) {
		visited[i] = 0;
		distance[i] = g->a[start][i] ? g->a[start][i] : INT_MAX;
		parent [i] = g->a[start][i] ? start : -1;
	}	
	visited[start] = 1;
	distance[start] = 0;

	for(k = 0; k < g->n - 1; k++) {
		u = findmin(distance, visited, g->n);
		visited[u] = 1;
		// update distance using edges starting at u
		// consider edges (u, v) s.t. v is not visited
		// if distance[u] + (u, v) < distance[v]	
		for(j = 0; j < g->n; j++) {
			if(!visited[j]) {
				if(g->a[u][j]) {
					newdistance = distance[u] + g->a[u][j];
					if(newdistance < distance[j]) {
						distance[j] = newdistance;
						parent[j] = u;
					}
				}
			}
		}
	}
	result.distance = distance;
	result.parent = parent;
	return result;	
}
