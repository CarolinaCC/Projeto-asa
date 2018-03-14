#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


node init (int c) {
	node head = malloc (sizeof(struct stacknode));
	head->content = c;
	head->next = NULL;
	return head;
}

int isEmpty (node *head) {
	return (*head == NULL) ? 1 : 0;
}


void push (node *head, int c) {
	node new = malloc (sizeof(struct stacknode));
	new->next = *head;
	new->content = c;
	*head = new;
}

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
