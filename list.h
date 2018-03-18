#ifndef LIST_H
#define LIST_H
#include "node.h"

typedef struct listNode {
	struct vertex* v;
	struct listNode *next;
}*link;

struct vertex* getVerticeFromList(link head);


link initiate_list();

link add2list(link head, struct vertex *e);

int getLowFromListNode (struct listNode* n);
int getDFromListNode (struct listNode* n);
int getIdFromListNode (struct listNode* n);

void setLowFromListNode (struct listNode* n, int low);
void setDFromListNode (struct listNode* n, int d);



void printList(link head);

#endif
