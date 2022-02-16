#ifndef LIST_INTERFACE
#define LIST_INTERFACE

typedef struct node* Link;

struct node {
  int item;
  Link next;
};

typedef Link Node;

void initNodes(int);
Link newNode(int);
void freeNode(Link);
void insertNext(Link, Link);
Link deleteNext(Link);
Link Next(Link);
int Item(Link);

#endif

