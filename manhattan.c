#include "heuristic.h"
#include <math.h>
#include <stdlib.h>

int manhattan(char state[3][3]) {
	int i, j, sum = 0;

	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j) {
			if (!state[i][j])
				continue;
			sum += abs( i - finalPos[(int)state[i][j]] / 10) +
				abs( j - finalPos[(int)state[i][j]] % 10);
		}

	return sum;
}

int heuristic(char state[3][3]) {
	return manhattan(state);
}

