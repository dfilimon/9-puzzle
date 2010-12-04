#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

// un skip-list generic, cu chei de tip void*
// in problema de fata, vor fi noduri

// fragmente din sursele acestea au facut parte din Tema 2 la SD

typedef struct node Node;

struct node {
	void *key;
	int lvl; 	
	Node **Next;
};

typedef struct {
	Node *Head;
} SkipList;

inline void init_skiplist(SkipList *S); // initializarea unei liste goale

void insert(SkipList *S, void* key, int lvl, int (*cmp)(const void*, const void*)); // introduce o cheie de nivel lvl folosind un pointer catre functia cmp de comparatie a 2 elemente de tipul cheii introduse

int is_empty(SkipList S); 

void empty(SkipList *S); // goleste toata lista

#endif
