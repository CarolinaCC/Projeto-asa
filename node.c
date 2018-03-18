#include <stdio.h>
#include "list.h"

vertice createVertex(int id) {
	vertice new;
	new.id = id;
	new.inStack = 0;
	new.arcos_lista = initiate_list();
	return new;
}

void addArc (vertice* origem,vertice* destino) {
	origem->arcos_lista = add2list(origem->arcos_lista, destino);
}


