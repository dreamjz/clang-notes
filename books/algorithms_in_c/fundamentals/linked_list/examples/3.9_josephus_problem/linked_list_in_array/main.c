#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_arr(int a[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void print_indices(int len) {
     printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d ", i);
    }
    printf("]\n");
}

void print_all(int item[], int next[], int N, char* msg) {
    printf("%s:\n\t",msg);
    print_indices(N);
    printf("\t");
    print_arr(item, N);
    printf("\t");
    print_arr(next, N);
}

int main(int argc, char* argv[]) {
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int* item = malloc(sizeof(int) * N);
    int* next = malloc(sizeof(int) * N);

    memset(item, 0, N);
    memset(next, 0, N);

    // start time
    clock_t begin = clock();

    for (int i = 1; i <= N; i++) {
        item[i - 1] = i;
        next[i - 1] = i;
        if(i == N) {
            next[i - 1] = 0;
        }
    }

    // print_all(item, next, N, "Before");

    int x = N - 1;
    for (; item[x] != item[next[x]];) {
        for (int j = 1; j < M; j++){
            x = next[x];
        }
        // remove Mth item
        next[x] = next[next[x]];
    }

    // end time
    clock_t end = clock();

    printf("Result: %d\n", item[x]);
    // print_all(item, next, N, "After");

    printf("Mem usage: %d bytes\n", (sizeof(item) + sizeof(next)) * N);
    printf("Time spent: %f s", (double)(end - begin)/CLOCKS_PER_SEC);
}