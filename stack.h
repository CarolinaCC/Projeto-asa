#ifndef STACK_H
#define STACK_H

typedef struct stacknode {
	int content;
	struct stacknode *next;

}*node;

node init(int c);

int isEmpty(node *head);

void push(node *head, int c);

int pop(node *head);

void printStack(node *head);

#endif
