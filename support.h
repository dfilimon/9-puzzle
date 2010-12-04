#ifndef _SUPPORT_H_
#define _SUPPORT_H_

// functii suport pentru algoritmul solutiei

#include "binarysearchtree.h"

extern char *Moves, numMoves;
extern BSTNode *KeyTree;

int getKey(char state[3][3]);

inline char isValid(char i);

inline void addMove(char dir);

#endif
