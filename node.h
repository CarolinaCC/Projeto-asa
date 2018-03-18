#ifndef NODE_H
#define NODE_H
#include "list.h"

#define TRUE 1
#define FALSE 0
//FIXME
#define INFINITY -1

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

typedef struct vertex{

	int id;
	char inStack;
	int d, low;
	// id do valor do vertice minimo da CFL a que este node pertence
	int* idMinSCC;
	struct listNode* arcos_lista;
}vertice;

vertice createVertex(int id);
void addArc (vertice* origem,vertice* destino);
struct listNode* getArcs(vertice* v);

void printVertice(vertice* v);


int getLow (struct vertex* v);
int getD (struct vertex* v);
int getId (struct vertex* v);
int getidMinSCC(struct vertex* v);


void setLow (struct vertex* v, int low);
void setD (struct vertex* v, int d);
void setidMinSCC(struct vertex* v, int* minPointer);








#endif
