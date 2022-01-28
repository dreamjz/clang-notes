#include <stdio.h>
#include <stdlib.h>

typedef struct node* Link;
struct node {
    int item;
    Link next;
};

Link reverse(Link head) {
    Link r = NULL;

    for (Link y = head; y != NULL; ) {
        // save y to tmp node
        // The variable is allocated once, when the function is called 
        // (https://stackoverflow.com/questions/7959573/declaring-variables-inside-loops-good-practice-or-bad-practice)
        Link tmp = y->next;
        // y point to r(head of reverse list)
        y->next = r;
        // move tail 
        r = y;
        // move y
        y = tmp;
    }
    // return the new head of reverse list 
    return r;
}

void print_list(Link head) {
    printf("[");
    for (Link x = head; x != NULL; x = x->next) {
        printf("%d ", x->item);
    }
    printf("]");
}

Link new_list(int len) {
    Link head = malloc(sizeof(*head));
    head->item = 0;
    head->next = NULL;

    Link x = head;
    // create a list that item is from 0 to len-1
    for (int i = 1; i < len; i++) {
        Link node = malloc(sizeof(*node));
        node->item = i;

        node->next = x->next;
        x->next = node;
    }
    return head;
}

int main() {
    Link list = new_list(10);
    print_list(list);
    return 0;
}