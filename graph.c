#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "stack.h"
#include "list.h"




graph* initGraph (int size) {
	graph* newGraph = malloc (sizeof (graph));
	newGraph->vertices = (struct vertex*) malloc (sizeof(struct vertex) * size);
	newGraph->numberOfVertexes = size;
	for (int i = 0; i<size; i++ ) {
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

/*
void printGraph(graph* f) {
	printf("Numero de vertices %d\n", f->numberOfVertexes);
	for(int i = 0; i < f->numberOfVertexes; i++) {
		printf("Vertice %d:\n", f->vertices[i].id +1);
		vertice v = f->vertices[i];
		struct listNode* l = v.arcos_lista;

		while(l != NULL){
			printf("Arco de %d para %d\n", f->vertices[i].id +1, l->v->id +1);
			l = l->next;
		}
	}

}
*/

void tarjan_Visit (graph *g, int idVertice) {
	// melhorar ahahahahahhahahahahahha
	vertice* v = getVertice(g, idVertice);
	setLow (v, visited);
	setD (v, visited);
	visited ++;
	push(&stack, v);

	for (link aux = getArcs(v); aux != NULL; aux = aux->next) {
		vertice* u = getVerticeFromList(aux);
		if(getD(u) == INFINITY || u->inStack) {
			if(getD(u) == INFINITY)
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

			setidMinSCC(w, indice_menor);

			if (*indice_menor == INFINITY || getId(w) < *indice_menor)
				*indice_menor = getId(w);
		} while (getId(w) != getId(v) );
	}
}

void scc_Tarjan (graph *g) {

	for (int i = 0 ; i < g->numberOfVertexes; i++) {
		if (getD(getVertice(g, i)) == INFINITY)
			tarjan_Visit(g, i);
	}
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
		//FIXME

		addArc2Graph(g, u -1 , v -1);
	}

	visited = 1;

	scc_Tarjan(g);
	printf("%d\n", number_of_components);


}

