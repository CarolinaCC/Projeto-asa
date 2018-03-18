#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include "list.h"
#include "stack.h"

/*estrutura*/
typedef struct graph {
	struct vertex* vertices;
	int numberOfVertexes;

}graph;

/*variaveis globais*/
int visited;
linkStacknode stack;
int number_of_components;


/*funcoes*/
graph* initGraph (int size);

void addArc2Graph (graph* g, int verticeOrigem, int verticeChegada);

void tarjan_Visit (graph *g, int idVertice);

void scc_Tarjan (graph* g);




#endif
