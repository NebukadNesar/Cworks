#ifndef TREE_STRUCT_H
#define TREE_STRUCT_H
typedef struct NODE_T{
  struct NODE_T *left;
  struct NODE_T *right;
  int value;
} Node;

typedef struct TREE_T {
  Node *head;
} Tree;
#endif
