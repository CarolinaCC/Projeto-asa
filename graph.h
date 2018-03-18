#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"

#define INFINITY -1

typedef struct graph {
	struct vertex* vertices;
	int numberOfVertexes;

}graph;

graph* initGraph (int size);

void addArc2Graph (graph* g, int verticeOrigem, int verticeChegada);


#endif
