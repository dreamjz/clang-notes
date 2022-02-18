// program 3.16
// Sorting array of strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000
#define Mmax 10000

// byte buffer
char buf[Mmax];
int M = 0;

int compare(const void *i, const void *j) {
  return strcmp(*(char **)i, *(char **)j);
}

int main() {
  int i, N;
  // array of strings
  char* a[Nmax];

  printf("Please enter the strings: ");
  for (N = 0; N < Nmax; N++) {
    a[N] = &buf[M];
    if (scanf("%s", a[N]) == EOF) {
      break;
    }
    // all input save to buffer
    // "+1" is the \0 
    M += strlen(a[N]) + 1;
  }
  qsort(a, N, sizeof(char *), compare);
  // print string
  printf("Sorted: ");
  for (i = 0; i < N; i++) {
    printf("%s ", a[i]);
  }
  return 0;
}