#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



node init (int c) {
	node head = malloc (sizeof(struct stacknode));
	head->content = c;
	head->next = NULL;
	return head;
}

/****************************
Returns true if stack has   *
no elements on it and false *
otherwise                   *
****************************/
int isEmpty (node *head) {
	return (*head == NULL) ? 1 : 0;
}

/*****************************
Inserts an element in the    *
top of the stack             *
*****************************/
void push (node *head, int c) {
	node new = malloc (sizeof(struct stacknode));
	new->next = *head;
	new->content = c;
	*head = new;
}

/****************************
Removes the top element of  *
the stack                   *
****************************/
int pop (node *head) {
	if (isEmpty(head)) {
		fprintf(stderr, "Pop num stack vazio\n");
		exit (EXIT_FAILURE);
	}
	node aux = *head;
	int value = aux->content;
	*head = (*head)->next;
	free(aux);
	return value;
}

/**************************
Prints the stack          *
**************************/
void printStack(node *head) {
	node aux = *head;
	while (aux != NULL) {
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	printf("\n");
}

int main(){
	node head = init(5);
	push(&head, 3);
	printStack(&head);
	push(&head, 9);
	printStack(&head);
	pop(&head);
	printStack(&head);
	printf("pop return:%d\n", pop(&head));
	printStack(&head);
	pop(&head);
	pop(&head);
}
