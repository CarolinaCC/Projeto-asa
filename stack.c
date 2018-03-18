#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



linkStacknode init () {
	return NULL;
}

/****************************
Returns true if stack has   *
no elements on it and false *
otherwise                   *
****************************/
int isEmpty (linkStacknode *head) {
	return (*head == NULL) ? 1 : 0;
}

/*****************************
Inserts an element in the    *
top of the stack             *
*****************************/
void push (linkStacknode *head, struct vertex* v) {
	linkStacknode new = malloc (sizeof(struct stacknode));
	new->next = *head;
	new->content = v;
	*head = new;
}

/****************************
Removes the top element of  *
the stack                   *
****************************/
struct vertex* pop (linkStacknode *head) {
	if (isEmpty(head)) {
		fprintf(stderr, "Pop num stack vazio\n");
		exit (EXIT_FAILURE);
	}
	linkStacknode aux = *head;
	struct vertex* value = aux->content;
	*head = (*head)->next;
	free(aux);
	return value;
}

/**************************
Prints the stack          *
**************************/
void printStack(linkStacknode *head) {
	linkStacknode aux = *head;
	while (aux != NULL) {
		printf("%d\n", aux->content->id);
		aux = aux->next;
	}
	printf("\n");
}

