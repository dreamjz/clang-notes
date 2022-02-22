// program 3.16
// Two-dimention Arrays Allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** malloc2d(int r, int c) {
  int** t = malloc(r * sizeof(int*));

  for (int i = 0; i < c; i++) {
    t[i] = malloc(c * sizeof(int));
  }

  return t;
}

int** init2dArray(int r, int c) {
  int** t = malloc2d(r, c);
  for (int i = 0; i < r; i++) {
    memset(t[i], 0, c);
  }
  return t;
}

void print2dArray(int** a, int r, int c) {
  for (int i = 0; i < r; i++) {
    printf("| ");
    for (int j = 0; j < c; j++) {
      printf("%d ", a[i][j]);
    }
    printf("|\n");
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("parameter list cannot be empty");
  }
  int row = atoi(argv[1]);
  int column = atoi(argv[2]);

  printf("Creating Row: %d, Column: %d Martices\n", row, column);
  int** a = init2dArray(row, column);
  print2dArray(a, row, column);
}