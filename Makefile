.PHONY: clean

CC = gcc
CFLAGS = -Wall
BINARY = tema4

build: $(BINARY) 

$(BINARY): main.c allocator.o\
	logic.o heuristic.o support.o \
	multiwaytree.o binarysearchtree.o priorityqueue.o \
	redblacktree.o skiplist.o
	$(CC) $(CFLAGS) $^ -o $@

allocator.o: allocator.h allocator.c

logic.o: logic.h logic.c

heuristic.o: heuristic.h manhattan.c
	$(CC) $(CFLAGS) -c manhattan.c -o $@

support.o: support.h support.c

multiwaytree.o: multiwaytree.h multiwaytree.c

binarysearchtree.o: binarysearchtree.h binarysearchtree.c
redblacktree.o: redblacktree.h redblacktree.c

priorityqueue.o: priorityqueue.h priorityqueue.c 
skiplist.o: skiplist.h skiplist.c

clean:
	rm -rf *.o *.dSYM *~ tema4

rebuild: clean build

test: build tester.c mychecker.sh
	$(CC) $(CFLAGS) tester.c -o tester
	./mychecker.sh ./$(BINARY) ./tester
