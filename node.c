#include <stdio.h>
#include "list.h"

vertice createVertex(int id) {
	vertice new;
	new.id = id;
	new.inStack = FALSE;
	new.d = INFINITY;
	new.low = INFINITY;
	new.arcos_lista = initiate_list();
	return new;
}

void addArc (vertice* origem,vertice* destino) {
	origem->arcos_lista = add2list(origem->arcos_lista, destino);
}

int getLow (struct vertex v) {
	return v.low;
}

int getD (struct vertex v) {
	return v.d;
}

int getId (struct vertex v) {
	return v.id;
}

void setLow (struct vertex* v, int low) {
	v->low = low;
}

void setD (struct vertex* v, int d) {
	v->d = d;
}


