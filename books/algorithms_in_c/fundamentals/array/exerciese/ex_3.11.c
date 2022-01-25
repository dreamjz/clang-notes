#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 99

void print_arr(int a[], int len);

int main() {
    int *a = malloc(sizeof(int) * N);
    print_arr(a, N);
    memset(a, 0, N);
    print_arr(a, N);
}

void print_arr(int a[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d ");
    }
    printf("]\n");
}