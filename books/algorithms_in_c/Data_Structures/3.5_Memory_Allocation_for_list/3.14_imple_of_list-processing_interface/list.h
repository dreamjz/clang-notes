#ifndef LIST_INTERFACE
#define LIST_INTERFACE

struct node {
  int item;
  link next;
};

typedef struct node* link;

void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);

#endif

