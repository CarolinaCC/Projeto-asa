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

link addSorted2list (link head, struct vertex *e) {
	
	link aux = head;

	while (aux->next != NULL && *(aux->next->idMinSCC) >= *(e->idMinSCC)) {
		aux = aux->next;
	}	
	link newNode = malloc (sizeof (link));
	newNode->v = e;

	if (aux == head) {
		newNode->next = aux;
		return newNode;
	}

	newNode->next = aux->next;
	aux->next = newNode;
	return head;
}




void printList(link head) {
	link aux = head;
	while (aux != NULL){
		printVertice(aux->v);
		aux = aux->next;
	}
}

vertice* getVerticeFromList(link head) {
	return head->v;
}

int getLowFromListNode (struct listNode* n) {
	return getLow(n->v);
}

int getDFromListNode (struct listNode* n) {
	return getD (n->v);
}

int getIdFromListNode (struct listNode* n) {
	return getId (n->v);
}

void setLowFromListNode (struct listNode* n, int low) {
	setLow(n->v, low);
}

void setDFromListNode (struct listNode* n, int d) {
	setD(n->v, d);
}
