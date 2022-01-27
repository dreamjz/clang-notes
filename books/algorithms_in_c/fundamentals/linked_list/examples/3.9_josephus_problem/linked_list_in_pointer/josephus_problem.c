#include <stdio.h>
#include <stdlib.h>

typedef struct node* Link;
struct node {
    int item;
    Link next;
};

int main(int argc, char* argv[]) {
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    Link t = malloc(sizeof(*t));
    Link x = t;
    t->item = 1;
    t->next = t;

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
        for (int i = 1; i < M; i++) {
            x = x->next;
        }
        // delete node x
        Link d = x->next;
        x->next = d->next;
        // release mem
        free(d);
        N--;
    }
    printf("Result: %d\n", x->item);
}