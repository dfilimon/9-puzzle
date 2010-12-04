#include <stdio.h>
#include <assert.h>

#include "logic.h"

void readMatrix(FILE *in, char state[3][3]) {
	int i, j, tmp;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j) {
			fscanf(in, "%d", &tmp);
			state[i][j] = (char)tmp;
		}
}

void printSolution(FILE *out) {
	fprintf(out, "%d\n", numMoves - 1);
	
	int i;
	char dir;
	for (i = numMoves - 2; i >= 0; -- i) {
		switch (Moves[i]) {
			case 0:
				dir = 'U';
				break;
			case 1:
				dir = 'R';
				break;
			case 2:
				dir = 'D';
				break;
			case 3:
				dir = 'L';
				break;
			default: // NU ar trebui sa fiu aici
				assert(0 == 1);
		}
		fprintf(out, "%c", dir);
	}
	fprintf(out, "\n");
}

int main(int argc, const char *argv[]) {
	assert(argc == 3);
	FILE *in = fopen(argv[1], "r"),
	     *out = fopen(argv[2], "w");

	char init[3][3], final[3][3];
	readMatrix(in, init);
	readMatrix(in, final);
	fclose(in);

	solve(init, final);

	printSolution(out);
	fclose(out);
	free(Moves);

	printMem();
	return 0;
}

