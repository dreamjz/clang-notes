#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Link;
struct Node {
  int item;
  Link next;
};

Link generate_random_list(int len) {
  Link head = malloc(sizeof(*head));
  // head is a dummy node
  Link t = head;
  for (int i = 0; i < len; i++) {
    t->next = malloc(sizeof(*t));
    // move top node to next
    t = t->next;
    t->next = NULL;
    t->item = rand() % 100;
  }
  return head;
}

void print_list(Link head) {
  printf("[");
  // head is a dummy node
  for (Link t = head->next; t != NULL; t = t->next) {
    printf("%d ", t->item);
  }
  printf("]");
}

void print_node_verbose(Link node) {
  printf("{Item: %d, Next: %p}", node->item, node->next);
}

Link insertion_sort(Link inHead) {
  // dummy node
  Link outHead = malloc(sizeof(*outHead));
  outHead->next = NULL;

  // traverse input list
  for (Link x = inHead->next; x != NULL;) {
    Link tmp = x->next;
    Link y;
    for (y = outHead; y->next != NULL; y = y->next) {
      if (x->item < y->next->item) {
        break;
      }
    }
    x->next = y->next;
    y->next = x;
    x = tmp;
  }
  // inHead is no longer to use
  // release memory
  free(inHead);
  return outHead;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: ListInsertion list_length");
    return 1;
  }
  Link list = generate_random_list(atoi(argv[1]));
  print_list(list);
  printf("\n");
  Link sortedList = insertion_sort(list);
  print_list(sortedList);
  return 0;
}