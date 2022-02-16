#ifndef LIST_INTERFACE
#define LIST_INTERFACE

typedef struct node* link;
struct node {
  int item;
  link next;
};

void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);

#endif
