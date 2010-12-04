#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void readMatrix(FILE *in, char state[3][3]) {
	int i, j, tmp;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j) {
			fscanf(in, "%d", &tmp);
			state[i][j] = (char)tmp;
		}
}

void printMatrix(char state[3][3]) {
	int i, j;
	for (i = 0; i < 3; ++ i) {
		for (j = 0; j < 3; ++ j)
			printf("%d ", state[i][j]);
		printf("\n");
	}
}

char equalMatrices(char init[3][3], char final[3][3]) {
	int i, j;
	char err;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j)
			if (init[i][j] != final[i][j]) {
				err = i * 10 + j;
				return err;
			}
	return -1;
}

char isValid(char i) {
	return (i >= 0 && i < 3);
}

char applyMove(char move, char state[3][3]) {
	int di, dj;
	switch (move) {
		case 'U':
			di = -1;
			dj = 0;
			break;
		case 'R':
			di = 0;
			dj  = 1;
			break;
		case 'D':
			di = 1;
			dj = 0;
			break;
		case 'L':
			di = 0;
			dj = -1;
			break;
		default:
			return 1;
	}
	int i, j;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j)
			if (state[i][j] == 0)
				goto validityCheck;
			
validityCheck:
	if (!isValid(i + di) || !isValid(j + dj)) {
		printf("Off the board at %d %d\n", i + di, j + dj);
		return 1;
	}
	char helper = state[i][j];
	state[i][j] = state[i + di][j + dj];
	state[i + di][j + dj] = helper;
	return 0;
}

int main(int argc, const char *argv[]) {
	assert(argc == 3);
	FILE *want = fopen(argv[1], "r"),
	     *test = fopen(argv[2], "r");

	char init[3][3], final[3][3];
	readMatrix(want, init);
	readMatrix(want, final);
	fclose(want);

	int numMoves, i;
	char err, move;
	fscanf(test, "%d\n", &numMoves);
	for (i = 0; i < numMoves; ++ i) {
		fscanf(test, "%c", &move);
		err = applyMove(move, init);
		if (err) {
			printf("Invalid move %c at position %d\n", move, i);
			fclose(test);
			exit(1);
		}
	}
	
	err = equalMatrices(init, final);
	if (err == -1)
		printf("Okay\n");
	else {
		printf("Matrices don't match at %d %d\n", err / 10, err % 10);
		printf("Got\n");
		printMatrix(init);
		printf("Wanted\n");
		printMatrix(final);
	}

	fclose(test);

	return 0;
}
