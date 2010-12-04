#include "redblacktree.h"

#include <stdlib.h>
#include <assert.h>

RBNode* RBAllocNode(int key, char isRed) {
	RBNode *ret = (RBNode*)calloc(1, sizeof(RBNode));
	ret->key = key;
	ret->isRed = isRed;
	ret->link[0] = ret->link[1] = NULL;
	return ret;
}

#define opposite(dir) \
	((dir + 1) % 2)

// o rotatie stanga / dreapta data de directiea
// dir == 0 : rotatie la stanga
// dir == 1 : rotatie la dreapta
// reprezentarea cu link permite consolidarea functiei rotateLeft si rotateRight intr-una singura
RBNode* RBRotate(RBNode *root, int dir) {
	RBNode *newRoot = root->link[opposite(dir)];

	root->link[opposite(dir)] = newRoot->link[dir];
	newRoot->link[dir] = root;

	newRoot->isRed = root->isRed;
	root->isRed = 1;

	return newRoot;
}

 void RBFlipColors(RBNode *root) {	
	root->isRed = !root->isRed;
	root->link[0]->isRed = !root->link[0]->isRed;
	root->link[1]->isRed = !root->link[1]->isRed;
}

 int RBIsRed(RBNode *root) {
	if (!root) // muchiile care pleaca din frunze sunt mereu negre (NULL)
		return 0;
	return 1;
}

RBNode* RBInsert(RBNode *root, int key) {
	if (!root)
		return RBAllocNode(key, 1);
	if (root->key == key)
		return root;

	int dir = root->key < key;
	root->link[dir] = RBInsert(root->link[dir], key); // pentru refacerea legaturilor recursiv

	if ( RBIsRed(root->link[1]) ) // nod rosu la dreapta => rotatie stanga
		root = RBRotate(root, 0);
	if ( RBIsRed(root->link[0]) && RBIsRed(root->link[0]->link[0]) ) // succesiune de noduri rosii => rotatie dreapta
		root = RBRotate(root, 1);
	if ( RBIsRed(root->link[0]) && RBIsRed(root->link[1]) ) // noduri rosii si la stanga si la dreapta => schimbare de culori
		RBFlipColors(root);
		
	return root;
}

// la fel ca in orice arbore binar
int RBFind(RBNode *root, int key) {
	if (!root)
		return 0;
	if (root->key == key)
		return 1;
	int dir = root->key < key;

	return RBFind(root->link[dir], key);
}

void RBEmpty(RBNode *root) {
	if (!root)
		return;
	RBEmpty(root->link[0]);
	RBEmpty(root->link[1]);
	free(root);
}
