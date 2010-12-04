#include "skiplist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

inline void init_skiplist(SkipList *S)
{
	S->Head = NULL;
}

inline int is_empty(SkipList S)
{
	return (S.Head == NULL);
}

void insert(SkipList *S, void *key, int lvl, int (*cmp)(const void*, const void*)) {
	assert(lvl != 0);

	// aloc memorie pentru un nou nod
	Node *helper = (Node*)calloc(1, sizeof(Node));
	helper->lvl = lvl;
	helper->key = key;
	helper->Next = (Node**)calloc(lvl, sizeof(Node*));

	int i;
	if (is_empty(*S)) { // Head este un nod fals, trebuie alocat daca lista este goala
		S->Head = (Node*)calloc(1, sizeof(Node));
		S->Head->lvl = lvl;
		S->Head->key = NULL;
		S->Head->Next = (Node**)calloc(lvl, sizeof(Node*));

		for (i = 0; i < lvl; ++ i)
			S->Head->Next[i] = helper;

		return;
	}

	Node **Update = (Node**)calloc(lvl, sizeof(Node*)); // tablou cu pointerii care vor fi actualizati
	if (lvl > S->Head->lvl) { // daca nodul de fata imi mareste inaltimea skip listului
		S->Head->Next = (Node**)realloc(S->Head->Next, lvl * sizeof(Node*));
		for (i = S->Head->lvl; i < lvl; ++ i) {
			S->Head->Next[i] = NULL;
			Update[i] = S->Head;
		}
		S->Head->lvl = lvl;
	}

	Node *it = S->Head; 
	for (i = S->Head->lvl - 1; i >= 0; -- i) { // pornind de la cel mai inalt nivel din Head
		while (it->Next[i] != NULL &&  cmp(key, it->Next[i]->key) > 0) // si mergand pe 
			it = it->Next[i]; // o lista superioara pana cand nu depasesc pozitia de insertie
		if (i < lvl)
			Update[i] = it; // actualizez tabloul de pointerii de modificat daca nivelul curent e mai mic decat cel al nodului
	}
	
	for (i = 0; i < lvl; ++ i) { // insertia efectiva
		helper->Next[i] = Update[i]->Next[i];
		Update[i]->Next[i] = helper;
	}

	free(Update);
}

// golesc un skip list
void empty(SkipList *S)
{
	Node *curr, *helper;
	for (curr = S->Head->Next[0]; curr != NULL;) {
		helper = curr->Next[0];
		free(curr->Next);
		free(curr);
		curr = helper;
	}

	free(S->Head->Next);
	free(S->Head);
	S->Head = NULL;
}

