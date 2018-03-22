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


	if (head == NULL) {
		link newNode = malloc (sizeof (link));
		newNode->v = e;
		newNode->next = NULL;
		networks++;
		return newNode;
	}

	if(*head->v->idMinSCC == *e->idMinSCC) return head;


	link newNode = malloc(sizeof (link));
	newNode->v = e;
	newNode->next = NULL;

	if (*e->idMinSCC < *head->v->idMinSCC){
		newNode->next = head;
		networks++;
		return newNode;
	}

	link temp ,prev;
	temp = head->next;
	prev = head;
	while(temp != NULL && *temp->v->idMinSCC < *e->idMinSCC) {
	    prev = temp;
	    temp = temp->next;
	}

	if(prev != NULL && temp != NULL)
		if(*temp->v->idMinSCC == *e->idMinSCC || *prev->v->idMinSCC == *e->idMinSCC)
			return head;
	newNode->next = temp;
	prev->next = newNode;
	networks++;

	return head;



	/*
	while (aux->next != NULL && (*(aux->next->v->idMinSCC) < *(e->idMinSCC))) {
		aux = aux->next;

	}


	// ultimo
	if(aux->next == NULL) {
		link newNode = malloc (sizeof (link));
		newNode->v = e;
		newNode->next = NULL;
		aux->next = newNode;
		return head;

	}
	// SAO IGUAIS
	if (aux->next->v->idMinSCC == e->idMinSCC || aux->v->idMinSCC == e->idMinSCC) {
		return head;
	}

	link newNode = malloc (sizeof (link));
	newNode->v = e;
	// substituit head
	if (aux == head) {
		newNode->next = aux;
		return newNode;
	}


	newNode->next = aux->next;
	aux->next = newNode;
	return head;*/
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
