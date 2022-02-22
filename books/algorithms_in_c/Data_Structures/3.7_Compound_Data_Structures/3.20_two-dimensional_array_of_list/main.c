#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "point.h"

typedef struct node* Link;
struct node {
  Point p;
  Link next;
};

Link** grid;
int G;
int cnt = 0;
float d;

void gridInsert(float x, float y) {
  int i, j;
  Link s;
  int X = x * G + 1;
  int Y = y * G + 1;

  Link t = malloc(sizeof *t);
  t->p.x = x;
  t->p.y = y;

  for (i = X - 1; i <= X + 1; i++) {
    for (j = Y - 1; j <= Y + 1; j++) {
      for (s = grid[i][j]; s != NULL; s = s->next) {
        if (distance(s->p, t->p) < d) {
          cnt++;
        }
      }
    }
  }
  t->next = grid[X][Y];
  grid[X][Y] = t;
}

Link** malloc2d(int r, int c) {
  Link** t = malloc(r * sizeof(Link*));
  for (int i = 0; i < r; i++) {
    t[i] = malloc(c * sizeof(Link));
  }
  return t;
}

float randFloat() { return 0.1 * rand() / RAND_MAX; }

int main(int argc, char* argv[]) {
  int i, j;
  int N = atoi(argv[1]);
  d = atof(argv[2]);
  G = 1 / d;
  grid = malloc2d(G + 2, G + 2);

  for (i = 0; i < G + 2; i++) {
    for (j = 0; j < G + 2; j++) {
      grid[i][j] = NULL;
    }
  }

  for (i = 0; i < N; i++) {
    gridInsert(randFloat(), randFloat());
  }
  printf("%d edges shorter than %f\n", cnt, d);
}