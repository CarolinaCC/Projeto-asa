#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "stack.h"

// ele poem igual a zero por definicao
int visited;
linkStacknode stack;

int number_of_components;


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
		int* indice_menor = malloc (sizeof(int));
		*indice_menor = INFINITY;
		number_of_components++;
		do {
			u = pop(&stack);
			u->idMinSCC = indice_menor;
			if (*indice_menor == INFINITY || getId(*u) < *indice_menor)
				*indice_menor = getId(*u);
		} while (getId(*u) != getId(*v) );
	}
}

void scc_Tarjan (graph g) {

	for (int i = 0 ; i < g.numberOfVertexes; i++) {
		if (getD(*getVertice(g, i)) == INFINITY)
			tarjan_Visit(g, i);
	}
}

int main () {
	int n;
	scanf("%d", &n);
	printf("li o primeiro caracter: %d\n", n );

	if (n < 2)
		exit(-1);

	graph* g = initGraph (n);
	int m;

	scanf("%d", &m);
	if (m < 1)
		exit(-1);


	printf("li o segundo caracter: %d\n", m );

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		//FIXME
		printf("arco de %d para %d\n", u, v );

		addArc2Graph(g, u -1, v -1);
	}

	scc_Tarjan(*g);
	printf("%d\n", number_of_components);


}

