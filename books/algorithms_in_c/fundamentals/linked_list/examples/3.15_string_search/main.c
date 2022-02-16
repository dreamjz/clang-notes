// program_3.15 String Search
#include <stdio.h>
#define N 10000

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Parameter list cannot be empty");
    return 1;
  }

  char* p = argv[1];
  char a[N];

  printf("String: %s\n", p);

  // read entered string
  char t;
  for (int i = 0; i < N; i++) {
    t = getchar();
    if (t == EOF) {
      a[i] = 0;
      break;
    }
    a[i] = t;
  }
  // search string
  for (int i = 0; a[i] != 0; i++) {
    int j;
    for (j = 0; p[j] != 0; j++) {
      if (a[i + j] != p[j]) {
        break;
      }
    }
    if (p[j] == 0) {
      printf("Pos: %d, ", i);
    }
  }
  printf("\n");
}