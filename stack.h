#ifndef STACK_H
#define STACK_H
#include "node.h"

typedef struct stacknode {
	struct vertex* content;
	struct stacknode *next;

}*linkStacknode;

linkStacknode init();

int isEmpty(linkStacknode *head);

void push(linkStacknode *head, struct vertex* v);

struct vertex* pop(linkStacknode *head);

void printStack(linkStacknode *head);

#endif
