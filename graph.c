#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"

// ele poem igual a zero por definicao
int visited;


graph* initGraph (int size) {
	graph* newGraph = malloc (sizeof (graph));
	newGraph->vertices = (struct vertex*) malloc (sizeof(struct vertex) * size);
	newGraph->numberOfVertexes = size;
	for (int i = 0; i<size; i++ ) {
		newGraph->vertices[i] = createVertex (i + 1);
	}
	return newGraph;
}

void addArc2Graph (graph* g, int verticeOrigem, int verticeChegada) {
	addArc(&(g->vertices[verticeOrigem]), &(g->vertices[verticeChegada]));
}

void Tarjan_Visit (graph g, int idVertice) {
	g.vertices[idVertice]


	visited ++;

}



