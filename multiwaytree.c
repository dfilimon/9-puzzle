#include "multiwaytree.h"

#include "allocator.h"

#include "heuristic.h"

#include <assert.h>

#define Node struct nod

// fac conexiunile necesare in arborele multicai
// si setez g si h pentru determinarea prioritatii
void linkNode(Node *root, Node *next) {
	root->link = (Node**)_realloc(root->link, (root->numLinks) * sizeof(Node), (root->numLinks + 1) * sizeof(Node));
	root->link[(int)root->numLinks ++] = next;
	next->pred = root;
	next->g = root->g + 1; // distanta de la radacina la nod
	next->h = heuristic(next->matrix); // euristica
}

Node* allocNode(int key, char dir, Node *pred) {
	Node *ret = (Node*)_calloc(1, sizeof(Node));
	int i, j;
	for (i = 2; i >= 0; -- i)
		for (j = 2; j >= 0; -- j) {
			ret->matrix[i][j] = key % 10;
			key /= 10;
		}
	ret->dir = dir;
	ret->pred = pred;
	return ret;
}

void freeNode(Node *root) {
	free(root);
}

void freeTree(Node *root) {
	if (!root)
		return;
	int i;
	for (i = 0; i < root->numLinks; ++ i) {
		if (root->link[i])
			assert(root->link[i]->pred == root);
		freeTree(root->link[i]);
	}
	free(root->link);
	free(root);
}
