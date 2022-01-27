#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* Link;
struct node {
    int item;
    Link next;
};

void print_node(Link n) {
    printf("[item: %d, next: %d]\n", n->item, n->next->item);
}

int main(int argc, char* argv[]) {
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    Link t = malloc(sizeof(*t));
    Link x = t;
    t->item = 1;
    t->next = t;

    // start time
    clock_t begin = clock();

    // create a circular list
    for (int i = 2; i <= N; i++) {
        x->next = malloc(sizeof(*x));
        // move to next
        x = x->next;
        x->item = i;
        // create a circle
        x->next = t;
    }
    
    // remove Mth item
    // now x pointing to N, and next is 1
    while(x != x->next) {
        // printf("%-7s","Before:");
        // print_node(x);
        for (int i = 1; i < M; i++) {
            x = x->next;
        }
        // delete node x
        Link d = x->next;
        x->next = d->next;
        // release mem
        free(d);
        // printf("%-7s","After:");
        // print_node(x);
    }

    // start time
    clock_t end = clock();

    printf("Result: %d\n", x->item);
    printf("Max mem usage: %d bytes\n", sizeof(*t) * N);
    printf("Time spent: %f s", (double)(end - begin)/CLOCKS_PER_SEC);

}