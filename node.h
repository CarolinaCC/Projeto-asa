#ifndef NODE_H
#define NODE_H
#include "list.h"

typedef struct vertex{

	int id;
	char inStack;
	struct listNode* arcos_lista;
}vertice;

vertice createVertex(int id);




#endif
