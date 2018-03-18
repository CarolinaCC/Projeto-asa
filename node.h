#ifndef NODE_H
#define NODE_H
#include "list.h"

typedef struct vertex{

	int id;
	char inStack;
	int d, low;
	struct listNode* arcos_lista;
}vertice;

vertice createVertex(int id);
void addArc (vertice* origem,vertice* destino);

int getLow (struct vertex v);
int getD (struct vertex v);
int getId (struct vertex v);

void setLow (struct vertex* v, int low);
void setD (struct vertex* v, int d);





#endif
