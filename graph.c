#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "stack.h"

// ele poem igual a zero por definicao
int visited;
linkStacknode stack;


graph* initGraph (int size) {
	graph* newGraph = malloc (sizeof (graph));
	newGraph->vertices = (struct vertex*) malloc (sizeof(struct vertex) * size);
	newGraph->numberOfVertexes = size;
	for (int i = 0; i<size; i++ ) {
		newGraph->vertices[i] = createVertex (i);
	}
	return newGraph;
}

struct vertex* getVertice(graph g, int id) {
	return &(g.vertices[id]);
}

void addArc2Graph (graph* g, int verticeOrigem, int verticeChegada) {
	addArc(&(g->vertices[verticeOrigem]), &(g->vertices[verticeChegada]));
}

void tarjan_Visit (graph g, int idVertice) {
	// melhorar ahahahahahhahahahahahha
	vertice* v = getVertice(g, idVertice);
	setLow (v, visited);
	setD (v, visited);
	visited ++;
	push(&stack, v);

	for (link aux = v->arcos_lista; aux != NULL; aux = aux->next) {
		vertice* u = aux->v;
		if (getD(*u) == INFINITY || u->inStack) {
			if (getD(*u) == INFINITY)
				tarjan_Visit(g, u->id);
			setLow(v, MIN(getLow(*v),getLow(*u)));
		}
	}

	if (getD(*v) == getLow(*v)) {
		vertice* u;
		do {
			u = pop(&stack);
		} while (getId(*u) != getId(*v) );
	}
}

void scc_Tarjan (graph g) {

	for (int i = 0 ; i < g.numberOfVertexes; i++) {
		if (getD(*getVertice(g, i)) == INFINITY)
			tarjan_Visit(g, i);
	}
}



