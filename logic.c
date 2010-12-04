#include <math.h>
#include <assert.h>

#include "logic.h"

#include "heuristic.h"

#include "support.h"

#include "multiwaytree.h"

#include "binarysearchtree.h"

#include "priorityqueue.h"

#define Node struct nod

const int di[] = {-1, 0,  +1,  0}; // vectorul de directii pe axe: i = linii
const int dj[] = { 0, +1,  0, -1}; // j = coloane
		 //U,  R,  D,  L

int getNewKey(Node *root, int dir) { // generez o cheie noua printr-o mutare
	char temp[3][3];
	int i, j, iz, jz;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j) {
			temp[i][j] = root->matrix[i][j];
			if (temp[i][j] == 0) { // trebuie interschimbat un caracter
				iz = i;        // cu pozitia lui 0
				jz = j;
			}
		}
	if (!isValid(iz + di[dir]) || !isValid(jz + dj[dir])) // doar daca mutarea e valida
		return -1;
	char helper = temp[iz][jz];
	temp[iz][jz] = temp[iz + di[dir]][jz + dj[dir]];
	temp[iz + di[dir]][jz + dj[dir]] = helper;

	return getKey(temp); // transform matricea in mutarea asociata
}


void AStar(Node *start) {
	BSTNode *KeyTree = NULL;

	PriorityQueue Q;
	PQInit(&Q);
	PQPush(&Q, start);

	int i;
	Node *root;
	while (1) { // cat timp o solutie n-a fost gasita
		root = PQTop(Q); // extrag primul element din coada
		PQPop(&Q);	 // cel mai *promitator* elemenent
		if (heuristic(root->matrix) == 0) { // daca am ajuns la solutie
			while (root) { // retin mutarile
				addMove(root->dir);
				root = root->pred;
			}
			break;
		}
		// nodul extras trebuie introdus in arborele de chei fiind expandat
		KeyTree = BSTInsert(KeyTree, getKey(root->matrix));

		// trec prin toate directiile posibile
		for (i = 0; i < 4; ++ i) {
			int newKey = getNewKey(root, i);
			if (newKey == -1 || BSTFind(KeyTree, newKey))
				continue;
			// daca obtin o stare valida, o salvez
			linkNode(root, allocNode(newKey, i, root));
		}
		
		// fii valizi sunt introdusi in coada de prioritati
		for (i = 0; i < root->numLinks; ++ i)
			PQPush(&Q, root->link[i]);
	}

	while ( !PQIsEmpty(Q) ) { // daca am gasit o solutie
		root = PQTop(Q);  // ma opresc si eliberez toate
		PQPop(&Q);	  // structurile de date: coada de prioritati
	}
	freeTree(start); // si arborele multicai
	BSTEmpty(KeyTree); // si arborele binar de cautare
}

char finalPos[3 * 3]; // codific pozitia unui numar la final ca sa pot cauta rapid
void solve(char init[3][3], char final[3][3]) {
	Node *root = allocNode(0, -1, NULL);

	int i, j;
	for (i = 0; i < 3; ++ i)
		for (j = 0; j < 3; ++ j) {
			assert(final[i][j] < 10);
			// o pozitie finala va fi un numar de 2 cifre
			// prima cifra fiind linia si a doua cifra fiind coloana
			finalPos[(int)final[i][j]] = i * 10 + j;

			root->matrix[i][j] = init[i][j];
		}
	AStar(root); // execut algoritmul de cautare a solutiei
}
