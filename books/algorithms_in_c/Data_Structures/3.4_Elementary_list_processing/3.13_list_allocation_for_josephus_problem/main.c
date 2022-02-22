#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char* argv[]) {
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  initNodes(N);
  link x = newNode(1);
  for (int i = 2; i < N + 1; i++) {
    link t = newNode(i);
    insertNext(x, t);
    x = t;
  }

  for (; x != Next(x);) {
    for (int i = 1; i < M; i++) {
      x = Next(x);
    }
    freeNode(deleteNext(x));
  }
  printf("%d\n", Item(x));
}