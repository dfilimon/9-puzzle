#include "binarysearchtree.h"

// doar wrappere peste implementarea rosu-negru

BSTNode* BSTInsert(BSTNode *root, int key) {
	return RBInsert(root, key);
}

int BSTFind(BSTNode *root, int key) {
	return RBFind(root, key);
}

void BSTEmpty(BSTNode *root) {
	RBEmpty(root);
}

