#ifndef LIST_H
#define LIST_H
#include "node.h"

typedef struct listNode {
	struct vertex* v;
	struct listNode *next;
}*link;


link initiate_list();

link add2list(link head, struct vertex *e);

void printList(link head);

#endif
