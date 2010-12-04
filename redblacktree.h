#ifndef __LEFT_LEANING_RED_BLACK_TREES__
#define __LEFT_LEANING_RED_BLACK_TREES__

// implementarea arborilor rosu-negru inclinati la stanga
// Sedgewick, 2007
// http://www.cs.princeton.edu/~rs/talks/LLRB/LLRB.pdf
// http://www.cs.princeton.edu/~rs/talks/LLRB/

// acesti arbori sunt echivalenti cu arborii 2-3 si impun urmatoarele conditii suplimentare
// un nod virtual cu 2 chei se reprezinta prin 2 noduri conectate cu o muchie rosie
// astfel, un nod este rosu daca este in acelasi nod virtual cu parintele sau

// ! orice nod rosu se afla la stanga parintelui
// ! exista acelasi numar de muchii negre pe orice drum de la radacina la frunze (<=> arborele B asociat este perfect echilibrat)

// rotatiile se fac la stanga pentru respectarea conditiei de "left-leaning"
// se mai fac si recolorari, "color-flips" simuland astfel spargerea unui nod din arborele B (split)
// de asemenea daca exista 2 muchii rosii consecutive, se face o rotatie la dreapta urmata de o recolorare

typedef struct rbnode RBNode;

// folosesc vectorul de legaturi pentru ca se pot simplifica prin simetrie anumite operatii
// cum ar fi rotatiile prin evaluarea unei valori dir = directia in care merg
struct rbnode {
	int key;
	char isRed;
	RBNode *link[2]; // link[0] == left si link[1] == right
};

RBNode* RBAllocNode(int key, char isRed);

inline RBNode* RBRotate(RBNode *root, int dir);

inline void RBFlipColors(RBNode *root);

inline int RBIsRed(RBNode *root);

RBNode* RBInsert(RBNode *root, int key);

int RBFind(RBNode *root, int key);

void RBEmpty(RBNode *root);

#endif
