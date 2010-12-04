#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

// arborele binar de cautare foloseste un arbore rosu-negru inclinat la stanga intern
// pentru echilibrarea mai simpla

#include "redblacktree.h"

#define BSTNode RBNode // ideal ar fi fost in POO ca RBNode sa deriveze din BSTNode

BSTNode* BSTInsert(BSTNode *root, int key);

int BSTFind(BSTNode *root, int key);

void BSTEmpty(BSTNode *root);

#endif
