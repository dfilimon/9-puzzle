#ifndef _MULTIWAY_TREE_H_
#define _MULTIWAY_TREE_H_

// opresc "padding-ul" structurii ca sa fie mai bine comprimate
// g si h sunt cele 2 masuri ale eficientei unei stari
// g = distanta de la radacina la starea curenta
// h = estimarea euristicii a distantei pana la solutie

#pragma pack(push)
#pragma pack(1)
typedef struct nod {
	char matrix[3][3], numLinks, dir;
	char g, h; 	
	struct nod* *link, *pred;
} *Nod;
#pragma pack(pop)

void linkNode(struct nod *root, struct nod *next);

struct nod* allocNode(int key, char dir, struct nod *pred);

void freeTree(struct nod *root);

#endif
