#include <stdio.h>
#include "list.h"

vertice createVertex(int id) {
	vertice new;
	new.id = id;
	new.inStack = 0;
	new.arcos_lista = initiate_list();
	return new;
}



