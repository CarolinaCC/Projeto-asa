#include <stdio.h>
#include "list.h"

vertice createVertex(int id) {
	vertice new;
	new.id = id;
	new.inStack = FALSE;
	new.d = INFINITY;
	new.low = INFINITY;
	new.idMinSCC = NULL;
	new.arcos_lista = initiate_list();
	return new;
}

void addArc (vertice* origem,vertice* destino) {
	origem->arcos_lista = add2list(origem->arcos_lista, destino);
}

link getArcs(vertice* v){
	return v->arcos_lista;
}

void printVertice(vertice* v) {
	printf("%d\n", v->id );
}


int getLow (struct vertex* v) {
	return v->low;
}

int getD (struct vertex* v) {
	return v->d;
}

int getId (struct vertex* v) {
	return v->id;
}

void setLow (struct vertex* v, int low) {
	v->low = low;
}

void setD (struct vertex* v, int d) {
	v->d = d;
}

void setidMinSCC(struct vertex* v, int* minPointer) {
	v->idMinSCC = minPointer;
}

int getidMinSCC(struct vertex* v) {
	return *v->idMinSCC;
}


