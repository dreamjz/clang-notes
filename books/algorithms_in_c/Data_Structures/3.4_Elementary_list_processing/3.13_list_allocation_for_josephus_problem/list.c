#include "list.h"

#include <stdlib.h>

link freeList;

void initNodes(int N) {
  freeList = malloc((N + 1) * (sizeof(*freeList)));
  for (int i = 0; i < N + 1; i++) {
    freeList[i].next = &freeList[i + 1];
  }
  freeList[N].next = NULL;
}

link newNode(int i) {
  link x = deleteNext(freeList);
  x->item = i;
  x->next = x;
  return x;
}

void freeNode(link x) { insertNext(freeList, x); }

void insertNext(link x, link t) {
  t->next = x->next;
  x->next = t;
}

link deleteNext(link x) {
  link t = x->next;
  x->next = t->next;
  return t;
}

link Next(link x) { return x->next; }

int Item(link x) { return x->item; }