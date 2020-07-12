
typedef struct graph {
	int n;
	int **a; 
}graph;
typedef struct edge {
	int u, v;
}edge;
typedef struct result {
	int *parent;
	int *distance;
}result;
/* initGraph will allocate the 2-d array of
 * size n by n. Also initialize all edges to be zero.
 */
void initGraph(graph *g, int n);
/* Prints the graph */
void printGraph(graph *g);
int getn(graph *g);
/* Create a graph by reading graph information from a file */
graph *createGraphFromFile(char *filename);

void insertEdge(graph *g, int i, int j, int weight);
void levelwise(graph *g, int start); 
void depthwise(graph *g, int start); 
edge *prims(graph *g, int start); 
result sssp(graph *g, int start);
