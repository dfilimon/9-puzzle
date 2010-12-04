#include "priorityqueue.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

int cmp(const void *a, const void *b) {
	if (!a || !b)
		return 0;
	KeyType *_a = (KeyType*)a, *_b = (KeyType*)b;
	return (_a->g + _a->h - _b->g - _b->h);
}

void PQInit(PriorityQueue *Q) {
	Q->Head = NULL;
	srand(time(NULL));
}

int genlvl(int sup) {
	const int maxLvl = 20; // nu vrem o lista cu mai mult de 20 de nivele
	int i, sample = rand(); // apelez doar 1 data random; ! 1 singur int e suficient deoarece are 32 de biti iar nivelul maxim al listei este 20 !

	for (i = 0; i < maxLvl; ++ i) // si probabilitatea p == 1 / 2 
		if (sample & (1 << i)) // analizez bitii lui sample sa determin rezultatele aruncarilor de monede
			continue;
		else
			break;
	if (i + 1 > sup) // cresc nivelul cu un singur nivel doar
		return sup + 1;
	return i + 1;
}

void PQPush(PriorityQueue *Q, KeyType *key) {
	int lvl;
	if (PQIsEmpty(*Q)) // o lista nou creata presupun ca va avea nivelul 1
		lvl = 1;
	else
		lvl = genlvl(Q->Head->lvl);
	insert(Q, key, lvl, cmp);
}
KeyType* PQTop(PriorityQueue Q) {
	if (is_empty(Q))
		return NULL;
	return (KeyType*)Q.Head->Next[0]->key;
}

void PQPop(PriorityQueue *Q) { // extrag minimul dintr-o lista
	int i; 
	Node *tmp = Q->Head->Next[0];
	// daca un nivel inferior al listei este gol
	// sigur si toate nivele de deasupra sunt goale fiindca daca un nod de nivel 
	// m > n are _toate_ nivelele completate
	for (i = 0; i < tmp->lvl; ++ i)
		Q->Head->Next[i] = tmp->Next[i];
	
	while (Q->Head->lvl > 0 && !Q->Head->Next[Q->Head->lvl - 1])
		-- Q->Head->lvl;

	free(tmp->Next);
	free(tmp); // !!!! tmp nu este *cheia*, este doar un nod al cozii !!!!
	// ! nu sterg cheia in sine ! ea face parte si din arbore, key nu e sters
	if (Q->Head->lvl == 0) {
		free(Q->Head->Next);
		free(Q->Head);
		Q->Head = NULL;
	}
}

int PQIsEmpty(PriorityQueue Q) {
	return is_empty(Q);
}
void PQEmpty(PriorityQueue *Q) {
	empty(Q);
}

