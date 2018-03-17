#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"



link initiate_list() {
	return NULL;
}

link add2list(link head, struct vertex *e) {
	link newNode = malloc(sizeof (link));
	newNode->v = e;
	newNode->next = head;
	return newNode;
}



void printList(link head) {
	link aux = head;
	while (aux != NULL){
		//fazer printNode
		aux = aux->next;
	}



}


