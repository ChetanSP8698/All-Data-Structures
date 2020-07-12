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
#include "graph.h"
graph *createGraphFromMap(char *filename);
void printPaths(graph *g);

int main(int argc, char *argv[]) {
	graph  *g;
	if(argc != 3)
		return EINVAL;
	//g = createGraphFromFile(argv[1]);
	g = createGraphFromMap(argv[1]);
	printGraph(g);
	printPaths(g);
	
	return 0;
}
