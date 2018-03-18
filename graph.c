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

void tarjan_Visit (graph g, int idVertice) {
	// melhorar ahahahahahhahahahahahha
	vertice* v = getVertice(g, idVertice);
	setLow (v, visited +1);
	setD (v, visited + 1);
	visited ++;
	push(&stack, v);

	for (link aux = v->arcos_lista; aux != NULL; aux = aux->next) {
		//printf("aux: %d\n", aux->v->id);
		vertice* u = aux->v;
		//if (getD(*u) == INFINITY || u->inStack) {
		if(getD(*u) == INFINITY || u->inStack) {
			if(getD(*u) == INFINITY)
				tarjan_Visit(g, u->id);
			setLow(v, MIN(getLow(*v), getLow(*u)));

		}
		/*else if (u->inStack == TRUE)
			setLow(v, MIN(getLow(*v),getD(*u)));*/
		}


	if (getD(*v) == getLow(*v)) {
		//printf("id desejado: %d\n", getId(*v));
		vertice* w;
		int* indice_menor = malloc (sizeof(int));
		*indice_menor = INFINITY;
		number_of_components++;
		do {
			w = pop(&stack);
			//printf("id obtido: %d\n", getId(*u));

			w->idMinSCC = indice_menor;
			if (*indice_menor == INFINITY || getId(*w) < *indice_menor)
				*indice_menor = getId(*w);
		} while (getId(*w) != getId(*v) );
	}
}

void scc_Tarjan (graph g) {

	for (int i = 0 ; i < g.numberOfVertexes; i++) {
		//printf("%d\n", getD(*getVertice(g, i)) );
		if (getD(*getVertice(g, i)) == INFINITY)
			tarjan_Visit(g, i);
	}
}

int main () {
	int n;
	scanf("%d", &n);
	//printf("li o primeiro caracter: %d\n", n );

	if (n < 2)
		exit(-1);

	graph* g = initGraph (n);
	int m;

	scanf("%d", &m);
	if (m < 1)
		exit(-1);


	//printf("li o segundo caracter: %d\n", m );

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		//FIXME
		//printf("arco de %d para %d\n", u  , v  );

		addArc2Graph(g, u -1 , v -1);
	}

	//printGraph(g);

	scc_Tarjan(*g);
	printf("%d\n", number_of_components);


}

