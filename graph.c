#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "stack.h"
#include "list.h"

graph* colapse;
int networks;


int cmpfunc(const void	 * a, const void * b) {
	return ( *colapse->vertices[*(int*)a].idMinSCC  - *colapse->vertices[* (int*) b].idMinSCC);
}

graph* initGraph (int size) {
	graph* newGraph = malloc (sizeof (graph));
	newGraph->vertices = (struct vertex*) malloc (sizeof(struct vertex) * size);
	newGraph->numberOfVertexes = size;
	for (int i = 0; i < size; i++ ) {
		newGraph->vertices[i] = createVertex (i);
	}
	return newGraph;
}

struct vertex* getVertice(graph* g, int id) {
	return &(g->vertices[id]);
}

void addArc2Graph (graph* g, int verticeOrigem, int verticeChegada) {
	addArc(getVertice(g, verticeOrigem), getVertice(g, verticeChegada));
}



void sortGraph(graph* g) {
	int vec[g->numberOfVertexes];
	for (int i = 0; i < g->numberOfVertexes; i++){
		vec[i] = i;
	}

	qsort(vec, g->numberOfVertexes, sizeof(int), cmpfunc);

	for (int i = 0; i < g->numberOfVertexes; i++) {
		vertice v = g->vertices[vec[i]];
		struct listNode* l = v.arcos_lista;

		while (l != NULL) {
			printf("%d %d\n", *v.idMinSCC, *l->v->idMinSCC);
			l = l->next;
		}
	}

}


void tarjan_Visit (graph *g, int idVertice) {
	vertice* v = getVertice(g, idVertice);
	setLow (v, visited);
	setD (v, visited);
	visited ++;
	push(&stack, v);

	for (link aux = getArcs(v); aux != NULL; aux = aux->next) {
		vertice* u = getVerticeFromList(aux);
		if (getD(u) == INFINITY || u->inStack) {
			if (getD(u) == INFINITY)
				tarjan_Visit(g, u->id);
			setLow(v, MIN(getLow(v), getLow(u)));

		}
	}


	if (getD(v) == getLow(v)) {
		vertice* w;
		int* indice_menor = malloc (sizeof(int));
		*indice_menor = INFINITY;
		number_of_components++;
		do {
			w = pop(&stack);
			//Se der seg fault
			setNumberSCC(w, number_of_components - 1);
			setidMinSCC(w, indice_menor);

			if (*indice_menor == INFINITY || getId(w) + 1 < *indice_menor)
				*indice_menor = getId(w) + 1;
		} while (getId(w) != getId(v) );
	}
}

void scc_Tarjan (graph *g) {

	for (int i = 0 ; i < g->numberOfVertexes; i++) {
		if (getD(getVertice(g, i)) == INFINITY)
			tarjan_Visit(g, i);
	}
}

void addArcOrdered2Graph(graph* g, int verticeOrigem, int verticeChegada) {
	addOrderedArc(getVertice(g, verticeOrigem), getVertice(g, verticeChegada));
}

void findConnections (graph* g) {

	graph* newGraph = initGraph(number_of_components);

	for (int i = 0; i < g->numberOfVertexes; i++) {
		vertice* v = getVertice(g, i);
		if ((getVertice(newGraph, v->numberSCC)->idMinSCC) == NULL) {
			setidMinSCC(getVertice(newGraph, v->numberSCC), v->idMinSCC);

		}

	}

	for (int i = 0; i < g->numberOfVertexes; i++) {
		vertice* v = getVertice(g, i);

		for (link aux = getArcs(v); aux != NULL; aux = aux->next) {
			if (*v->idMinSCC != *aux->v->idMinSCC) {
				addArcOrdered2Graph(newGraph, v->numberSCC, aux->v->numberSCC);

			}

		}
	}
	colapse = newGraph;
	printf("%d\n", networks );
	sortGraph(newGraph);
}


int main () {
	int n;
	scanf("%d", &n);

	if (n < 2)
		exit(-1);

	graph* g = initGraph (n);
	int m;

	scanf("%d", &m);
	if (m < 1)
		exit(-1);

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);

		addArc2Graph(g, u - 1 , v - 1);
	}

	visited = 1;

	scc_Tarjan(g);

	printf("%d\n", number_of_components);
	findConnections(g);
}
