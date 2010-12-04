#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

// coada de prioritati implementata printr-un skip list
// astfel, extractia minimului se face in O(1)
// insertia se face in O(logN) <- amortizat

// daca functiile exportate sunt respectate, ar trebui sa se poata inlocui skiplist.{c,h} cu o implementarea bazata pe heap-uri

#include "skiplist.h"

#include "multiwaytree.h"
#define KeyType struct nod // nodul folosit in logic.c
// ATTN: defintia comparatorului este in priorityqueue.c

typedef SkipList PriorityQueue; // va fi coada de noduri folosita in algoritmul de cautare

void PQInit(PriorityQueue *Q);

void PQPush(PriorityQueue *Q, KeyType *key); // inserez in coada prioritara o cheie de tipul Nod* cu prioritatea specificata intern

KeyType* PQTop(PriorityQueue Q); // intoarce capul cozii

void PQPop(PriorityQueue *Q); // sterge capul cozii (elementul cu cheia "maxima")

int PQIsEmpty(PriorityQueue Q); // verifica daca coada este goala

void PQEmpty(PriorityQueue *Q); // goleste coada

#endif
