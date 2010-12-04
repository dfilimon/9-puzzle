#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"


long mem = 0;

void * _malloc(int size)
{
     mem += size;
     return malloc(size);
}

void * _calloc(int count, int size)
{
     mem += size * count;
     
     return calloc(count, size);
}

// modificat in urma post-ului de pe forum
// http://cs09.curs.pub.ro/mod/forum/discuss.php?d=2425
void * _realloc(void * old, int oldSize, int size)
{
	mem -= oldSize;
	mem += size;
	return realloc(old, size);
}


void printMem()
{
     printf("Folosesti %ld bytes.\n", mem);
}

