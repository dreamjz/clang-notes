#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
struct node {
  int item;
  link next;
};

link reverse(link head) {
  link r = NULL;

  for (link y = head; y != NULL;) {
    // save y to tmp node
    // The variable is allocated once, when the function is called
    // (https://stackoverflow.com/questions/7959573/declaring-variables-inside-loops-good-practice-or-bad-practice)
    link tmp = y->next;
    // y point to r(head of reverse list)
    y->next = r;
    // move r to y
    r = y;
    // move y to next
    y = tmp;
  }
  // return the new head of reverse list
  return r;
}

void print_list(link head) {
  printf("[");
  for (link x = head; x != NULL; x = x->next) {
    printf("%d ", x->item);
  }
  printf("]");
}

void print_node(link node) {
  printf("{item: %d, next: %p", node->item, node->next);
}

void print_list_verbose(link head) {
  printf("[");
  for (link x = head; x != NULL; x = x->next) {
    print_node(x);
    printf(", ");
  }
  printf("]");
}

link new_list(int len) {
  link head = malloc(sizeof(*head));
  head->item = 0;
  head->next = NULL;

  link x = head;
  // create a list that item is from 0 to len-1
  for (int i = 1; i < len; i++) {
    link node = malloc(sizeof(*node));
    node->item = i;

    // add to tail of the lists
    node->next = x->next;
    x->next = node;
    // move x to next
    x = node;
  }
  return head;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: ListReversal list_length");
    return 1;
  }
  int n = atoi(argv[1]);
  link list = new_list(n);
  printf("Before: \n");
  print_list(list);
  printf("\n");
  link reverseLink = reverse(list);
  printf("\nAfter: \n");
  print_list(reverseLink);
  printf("\n");
  return 0;
}