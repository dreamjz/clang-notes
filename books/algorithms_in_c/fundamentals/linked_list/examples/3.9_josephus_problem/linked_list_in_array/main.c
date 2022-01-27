#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char* argv[]) {
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int* item = malloc(sizeof(int) * N);
    int* next = malloc(sizeof(int) * N);

    memset(item, 0, N);
    memset(next, 0, N);

    for (int i = 1; i <= N; i++) {
        item[i - 1] = i;
        next[i - 1] = i;
        if(i == N) {
            next[i - 1] = 0;
        }
    }
    
    // print_indices(N);
    // print_arr(item, N);
    // print_arr(next, N);

    int x = next[N - 1];
    for (;;){
        for (int j = 1; j < M; j++){
            x = next[x];
        }
        // remove Mth item
        next[x] = next[next[x]];
        if(item[next[x]] == item[x]){
            break;
        }
    }
    printf("Result: %d\n", item[x]);
    print_indices(N);
    print_arr(item, N);
    print_arr(next, N);
}