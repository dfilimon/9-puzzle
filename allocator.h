#ifndef ALLOCATOR
#define ALLOCATOR

#include <stdio.h>
#include <stdlib.h>

void * _malloc(int size);

void * _calloc(int count, int size);

void * _realloc(void * old, int oldSize, int size);

void printMem();

#endif

