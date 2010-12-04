#ifndef _LOGIC_H_
#define _LOGIC_H_

// interfata exportata catre main
// orice algoritm care implementeaza solve() poate fi folosit cu acelasi main()

#include "allocator.h" // necesar pentru printMem()

extern char *Moves, numMoves; // solutia trebuie afisata
void solve(char init[3][3], char final[3][3]); // functia pentru rezolvare

#endif
