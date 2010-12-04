#include <assert.h>
#include <stdlib.h>

#include "support.h"

int getKey(char state[3][3]) {
	int newKey = 0, i, j;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j)
			newKey = newKey * 10 + (int)state[i][j];
	return newKey;
}

inline char isValid(char i) {
	return (i >= 0 && i < 3);
}

char *Moves = NULL, numMoves = 0;
inline void addMove(char dir) {
	Moves = (char*)realloc(Moves, (numMoves + 1) * sizeof(char));
	Moves[(int)numMoves ++] = dir;
}

