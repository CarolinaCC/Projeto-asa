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



int getLowFromListNode (struct listNode n) {
	return getLow(*n.v);
}

int getDFromListNode (struct listNode n) {
	return getD (*n.v);
}

int getIdFromListNode (struct listNode n) {
	return getId (*n.v);
}

void setLowFromListNode (struct listNode* n, int low) {
	setLow(n->v, low);
}

void setDFromListNode (struct listNode* n, int d) {
	setD(n->v, d);
}
